/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	This file contains the implementation of the ChMsgConn class, used to
	manage a connection for sending ChMsg objects.

		sockbuf			(sockinetbuf on the client)
			ChConn
			ChMsgConn

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChMsgCon.cpp,v 2.7 1995/11/07 02:11:17 coyote Exp $

#if (CH_UNIX)
	#include <string.h>
	#include <malloc.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <strstream.h>
	#include <netinet/in.h>
	#include <stdio.h>
#endif

#include "headers.h"

#include <ChMsgCon.h>
#include <ChCore.h>

/*----------------------------------------------------------------------------
	ChMsgConn class
----------------------------------------------------------------------------*/

ChMsgConn::ChMsgConn( const char *pstrHost, chuint16 suPort ) :
				ChConn(), m_lModuleID( 2 )
{
	lReadCount = 0;
	lReadNeeded = 0;

	connect( pstrHost, suPort );
}

#if defined( CH_MSW )

ChMsgConn::ChMsgConn( const char *pstrHost, chuint16 suPort,
						ChSocketHandler pHandler, chparam userData ) :
			ChConn( pHandler, userData ), m_lModuleID( 2 )
{
	lReadCount = 0;
	lReadNeeded = 0;

	connect( pstrHost, suPort );
}
#endif // defined( CH_MSW )


void ChMsgConn::Post( ChMsg& msg, chflag16 fPriority ) const
{
	ChMsgPacket		*pPacket;
	chuint32		luDataLen;
	chuint32		luPacketLen;
	
	luDataLen = msg.GetSize();
	luPacketLen = luDataLen + sizeof( ChMsgPacket );

	pPacket = (ChMsgPacket *)new chuint8[luPacketLen];
	memset( (void *)pPacket, 0, sizeof( ChMsgPacket ) );

											/* Construct the packet in network
												byte order */
	pPacket->packet_type = 1;
	if (msg.GetDestinationModule())
		pPacket->idModule = htonl( msg.GetDestinationModule() );
	else
		pPacket->idModule = htonl( m_lModuleID );
	pPacket->message_type = htonl( msg.GetMessage() );
	pPacket->param1 = htonl( msg.GetParam1() );
	pPacket->param2 = htonl( msg.GetParam2() );
	pPacket->version = htonl( msg.GetVersion().GetPacked() );
	pPacket->data_length = htonl( luDataLen );

	if (luDataLen)
	{										/* Copy the data associated with
												the message to the end of the
												packet */

		ChMemCopy( pPacket + 1, msg.GetBuffer(), luDataLen );
	}

	SendBlock( pPacket, luPacketLen );

	#if defined( CH_VERBOSE )
	{
//		LogPacket( (chuint8 *)pPacket, luPacketLen );
	}
	#endif	// defined( CH_VERBOSE )
											// Free the packet storage
	delete pPacket;
}


void ChMsgConn::Post( chint32 lMessage, chparam param1,
						chparam param2, chflag16 fPriority ) const
{
	ChMsg	msg( lMessage, param1, param2 );

	Post( msg, fPriority );
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChMsgConn::ProcessInput

------------------------------------------------------------------------------

	Reads the contents of the socket and attempts to interpret the data as
	a packet.

----------------------------------------------------------------------------*/

chint32 ChMsgConn::ProcessInput()
{
	chuint32	luLen;

	ASSERT( this );

	luLen = GetBytesAvailable();

	if (luLen > 0)
	{
		if (lReadCount + luLen > 2048)
		{
			#if defined( CH_VERBOSE )
//			cerr << "ChMsgConn::ProcessInput( socketBuf ): "
//					"buffer overrun" << endl;
			#endif

			return -1;
		}
											/* Read the contents of the socket
												to the end of 'inputbuf' */
		read( inputbuf + lReadCount, (chuint)luLen );
		lReadCount += luLen;
											/* Process the contents of the
												internal buffer */
		ProcessBuffer();
	}

	return 0;
}


chint32 ChMsgConn::ProcessInput( void *pBuf, chint32 lLen )
{
	#if defined( CH_VERBOSE )
	{
//		cerr << "ChMsgConn::ProcessInput lLen=" << lLen << endl;
//		LogPacket( (chuint8 *)pBuf, lLen );
	}
	#endif

	if (lReadCount + lLen > 2048)
	{
		#if defined( CH_VERBOSE )
		cerr << "ChMsgConn::ProcessInput: buffer overrun" << endl;
		#endif
		return -1;
	}
											// Append 'buf' to 'inputbuf'

	ChMemCopy( inputbuf + lReadCount, pBuf, lLen );
	lReadCount += lLen;
											/* Process the contents of the
												internal buffer */
	ProcessBuffer();

	return 0;
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChMsgConn::ResetPacketBuffer

------------------------------------------------------------------------------

	Resets the packet construction buffer to recieve a new packet
	or to process an already-received one which follows the just-processed
	one in 'inputbuf'.

----------------------------------------------------------------------------*/

void ChMsgConn::ResetPacketBuffer()
{
	if (lReadCount > lReadNeeded) {
		/* There was too much data read earlier, and only some of it has been
		   used, so: */
		// copy the excess back into the beginning of 'inputbuf'
		ChMemCopy(inputbuf, &inputbuf[lReadNeeded], lReadCount - lReadNeeded);
		lReadCount -= lReadNeeded;			/* Take out the size of what we've
											   already used. */
		lReadNeeded = sizeof(ChMsgPacket);	// Default, we need at least this
	} else {
		// 'inputbuf' has no leftover stuff, just zero these:
		lReadCount = 0;
		lReadNeeded = 0;
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChMsgConn::ProcessBuffer

------------------------------------------------------------------------------

	Processes the contents of the internal buffer and determines whether
	there is enough data to compose a message block.

----------------------------------------------------------------------------*/

chint32 ChMsgConn::ProcessBuffer()
{
											/* Figure out how long 'inputbuf'
												needs to be before we're
												done */
	if (lReadCount)
	{
		int packet_type = inputbuf[0];

		if (1 == packet_type)
		{
			ProcessType1();
		}
		else
		{
			ResetPacketBuffer();
		}
	}

	return 0;
}


/*----------------------------------------------------------------------------

	FUNCTION	||	ChMsgConn::ProcessType1

------------------------------------------------------------------------------

	This function will package up a type 1 packet.  When the packet is
	completely constructed, it will be dispatched.

----------------------------------------------------------------------------*/

chint32 ChMsgConn::ProcessType1()
{
	lReadNeeded = sizeof( ChMsgPacket );	/* The minimum number of bytes
												needed */
	/* Process messages out of 'inputdata' until there isn't enough
	   to form a packet header */
	while (lReadCount && (lReadCount >= lReadNeeded) )
	{										/* We've received at least the
												packet structure */
		ChMsgPacket *pPacket = (ChMsgPacket *)inputbuf;

											/* Check if we have additional
												data */
		if (ntohl(pPacket->data_length))
		{									/* Adjust number of bytes needed
											   so it includes 'data_length' */

			lReadNeeded = sizeof( ChMsgPacket ) + ntohl(pPacket->data_length);
		}

		// If we have enough after including 'data_length', 
		if (lReadCount >= lReadNeeded)
		{									/* We have enough to package
											   up the message. */

			ChModuleID	idModule = ntohl( pPacket->idModule );
			ChMsg		msg( ntohl( pPacket->message_type ),
								(ChVersion)ntohl( pPacket->version ),
								ntohl( pPacket->param1 ),
								ntohl( pPacket->param2 ) );

											// Copy in the packet 'data' field

			msg.Write( pPacket + 1, ntohl(pPacket->data_length) );

											/* Set the message origination
												connection */
			msg.SetOrigin( this );
											// Dispatch the message
			ResetPacketBuffer();
			ChCore::GetCore()->DispatchMsg( idModule, msg );
		}

		// Awww, didn't get enough yet.  Punt.
		if (lReadCount < lReadNeeded)
		{
			#if 0
			#if defined( CH_VERBOSE )
			{
				cerr << "ChMsgConn::ProcessType1: Packet fragment, "
						"continuing to read." 
						<< "lReadCount=" << lReadCount
						<< " lReadNeeded=" << lReadNeeded << endl;
			}
			#endif	// defined( CH_VERBOSE )
			#endif
		}
	}

	return 0;
}

// Local Variables: ***
// tab-width:4 ***
// End: ***
