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

	This file consists of implementation of the ChClientModule class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChClMod.cpp,v 2.6 1995/10/14 19:49:41 coyote Exp $

#include "headers.h"
#include <ChArch.h>
#include <ChVers.h>
#include <ChClMod.h>
#include <ChCore.h>

#ifdef CH_SERVER
#include <ChMsgTyp.h>
#include "../server/ChSerUsr.h"
#endif


/*----------------------------------------------------------------------------
	ChClientModule class
----------------------------------------------------------------------------*/

string	ChClientModule::m_strCoreName = "_Chaco Client Core_";

#if defined( CH_SERVER )

ChClientModule::ChClientModule( const ChUser &user, const string& strModule,
								const string& strLibraryName,
								const string& strLoadParam,
								ChModuleID idServerModule,
								bool boolOptional, bool boolUseExisting ) :
		ChModule( strModule ), m_user( user )
{
	static int	iNextModuleId = 10;
											/* XXX Somewhat of a hack.  Assumes
												that 'user' is really a
												ChServerUser */

	ChServerUser*	pUser = (ChServerUser *)&user;

	m_pConn = pUser->GetMsgConn();

	if (strModule == ChClientModule::GetCoreName())
	{
											// for core modules
		m_idModule = CH_CORE_MODULE_ID;
	}
	else
	{										/* For non-core modules, tell the
												client to load the module */

		ChLoadModuleMsg		replyLoad( iNextModuleId, strModule,
										strLibraryName, idServerModule,
										boolOptional, true, strLoadParam );
		m_idModule = iNextModuleId;
		iNextModuleId++;

		pUser->GetClientCore()->Post( replyLoad );
	}
}

#endif // CH_SERVER


#if defined( CH_CLIENT )
											/* This version of the constructor
												is for the client only, since
												the user is not specified */

ChClientModule::ChClientModule( const ChModuleID& idModule ) :
					m_idModule( idModule ),
					ChModule( idModule )
{
}

#endif	// defined( CH_CLIENT )


ChClientModule::~ChClientModule()
{
	#if defined( CH_VERBOSE )
	{
		cerr << "destroying ChClientModule" << endl;
	}
	#endif	// defined( CH_VERBOSE )
}


/*----------------------------------------------------------------------------
	ChClientModule public methods
----------------------------------------------------------------------------*/


void ChClientModule::Serialize( ChArchive& ar )
{
											/* First call the parents'
												Serialize method */
	ChModule::Serialize( ar );
											// Now serialize ourself
}

void ChClientModule::Post( ChMsg& msg, chflag16 fPriority ) const
{
	msg.SetDestinationModule( m_idModule );

	#if defined( CH_SERVER )
	{
		m_pConn->Post( msg, fPriority );
	}
	#else
	{										/* For the client, dispatch
												directly, since client modules
												cannot post to a client on
												another machine */

		ChCore::GetCore()->DispatchMsg( m_idModule, msg );
	}
	#endif
}

#if defined( CH_CLIENT )

chparam ChClientModule::Send( ChMsg& msg ) const
{
	msg.SetDestinationModule( m_idModule );

											/* For the client, dispatch
												directly, since client modules
												cannot post to a client on
												another machine */

	return ChCore::GetCore()->DispatchMsg( m_idModule, msg );
}

#endif	// defined( CH_CLIENT )


void ChClientModule::Post( chint32 lMessage, chparam param1, chparam param2,
		chflag16 fPriority ) const
{
	ChMsg   msg( lMessage, param1, param2 );

	msg.SetDestinationModule( m_idModule );
	m_pConn->Post( msg, fPriority );
}


// Local Variables: ***
// tab-width:4 ***
// End: ***
