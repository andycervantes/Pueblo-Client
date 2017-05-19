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

	Defines the ChText module for the Pueblo system.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChText.cpp,v 2.5 1996/02/22 01:44:58 coyote Exp $

#include "headers.h"

#include <ChMsgTyp.h>
#include <ChText.h>

#include "ChTxtIn.h"
#include "ChTxtOut.h"


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
CH_EXTERN_LIBRARY( void )
InitChTextDLL();
#endif

/*----------------------------------------------------------------------------
	Chaco module library entry point
----------------------------------------------------------------------------*/

ChMain
{
	chparam		retVal = 0;

	switch( msg.GetMessage() )
	{
		case CH_MSG_INIT:
		{
			ChInitMsg	*pMsg = (ChInitMsg *)&msg;
			string		strLoadParam;
			ChModuleID	idServerModule;

			#if defined( CH_MSW ) && defined( CH_ARCH_16 )
			// initialize MFC
			InitChTextDLL();
			#endif

			pMsg->GetParams( idModule, strLoadParam, idServerModule );

#if 0
			if (*pstrModule == CH_MODULE_TEXT_INPUT)
			{
				ChTextInMainInfo	*pMainInfo;

				pMainInfo = new ChTextInMainInfo( idModule, idServerModule );
				pMainInfo->RegisterDispatchers();

				retVal = (chparam)pMainInfo;
			}
			else
			if (*pstrModule == CH_MODULE_TEXT_OUTPUT)
			{
				ChTextOutMainInfo	*pMainInfo;

				pMainInfo = new ChTextOutMainInfo( idModule, idServerModule );
				pMainInfo->RegisterDispatchers();

				retVal = (chparam)pMainInfo;
			}

#endif	// 0

			break;
		}

		case CH_MSG_TERM:
		{
			delete pMainInfo;
			break;
		}
	}

	return retVal;
}
