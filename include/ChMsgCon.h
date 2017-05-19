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

	This file consists of the interface for the ChMsgConn class, which
	handles message connections.

		sockbuf			(sockinetbuf on the client)
			ChConn
			ChMsgConn

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChMsgCon.h,v 2.3 1995/06/21 17:55:36 glenn Exp $


#include <ChConn.h>

#if !defined( _CHMSGCON_H )
#define _CHMSGCON_H    

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif


#if defined( CH_MSW )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )

class ChMsg;


/*----------------------------------------------------------------------------
	ChMsgPacket structure
----------------------------------------------------------------------------*/

struct ChMsgPacket
{
	chuint8		packet_type;
	chuint8		pad1;
	chuint8		pad2;
	chuint8		pad3;
	ChModuleID	idModule;
	chuint32	message_type;
	chparam		param1;
	chparam		param2;
	chuint32	version;
	chuint32	data_length;
				// Data often follows the packet in memory and on the network
};


/*----------------------------------------------------------------------------
	ChMsgConn class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChMsgConn : public ChConn
{
	public:
		ChMsgConn( sockinetbuf s ) : ChConn( s ), lReadCount( 0 ), lReadNeeded( 0 ), m_lModuleID( 2 ) {}
		ChMsgConn( sockbuf s ) : ChConn( s ), lReadCount( 0 ), lReadNeeded( 0 ), m_lModuleID( 2 ) {}

		ChMsgConn( ChSocketHandler pHandler, chparam userData = 0 ) :
			ChConn( pHandler, userData ), lReadCount( 0),
			lReadNeeded( 0 ), m_lModuleID( 2 )
			{ ResetPacketBuffer(); }

		ChMsgConn( const char *pstrHost, chuint16 suPort,
					ChSocketHandler pHandler, chparam userData = 0 );

		ChMsgConn( const char *pstrHost, chuint16 suPort );

		ChMsgConn() : ChConn(), lReadCount( 0 ), lReadNeeded( 0 ), m_lModuleID( 2 )
				{ ResetPacketBuffer(); }

		void Post( ChMsg& msg, chflag16 fPriority = 0 ) const;
		void Post( chint32 lMessage, chparam param1 = 0,
					chparam param2 = 0, chflag16 fPriority = 0 ) const;

		chint32 ProcessInput();
		chint32 ProcessInput( void *pBuf, chint32 lLen );

	protected:
		chint32 ProcessBuffer();

	private:
		chint32		ProcessType1();
		void		ResetPacketBuffer();

		chint32		lReadCount;
		chint32		lReadNeeded;
		char		inputbuf[2048]; // XXX re-do to grow
		ChMsgPacket	packet;
		chint32		m_lModuleID;
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// _CHCONN_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
