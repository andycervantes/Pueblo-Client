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

	This file consists of the implementation of the ChHtmlPageWnd class,
	used when we need to display HTML pages.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChHtmlPg.cpp,v 2.3 1996/01/11 02:49:58 coyote Exp $

#include "headers.h"
#include "resource.h"

#include <ChCore.h>
#include <ChMsgTyp.h>

#if defined( CH_UNIX )

	#include <ChDispat.h>
	#include <ChMsgTyp.h>
	#include <ChReg.h>
	#include "../../unix/ChTxtMud/UnixRes.h"

#endif	// defined( CH_UNIX )

#include "ChHtmlPg.h"


/*----------------------------------------------------------------------------
	Forward declarations
----------------------------------------------------------------------------*/

CH_INTERN_FUNC( void )
DoAnchorHint( char* pstrArgs );


/*----------------------------------------------------------------------------
	ChHtmlPageWnd class
----------------------------------------------------------------------------*/

ChHtmlPageWnd::ChHtmlPageWnd()
{
}


ChHtmlPageWnd::~ChHtmlPageWnd()
{
}


#if !defined( CH_UNIX )

BEGIN_MESSAGE_MAP( ChHtmlPageWnd, ChHtmlWnd )
	//{{AFX_MSG_MAP(ChHtmlPageWnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#endif // !CH_UNIX


/*----------------------------------------------------------------------------
	ChHtmlPageWnd protected methods
----------------------------------------------------------------------------*/

void ChHtmlPageWnd::OnHotSpot( chparam userData, const string& strDocURL )
{
	DoAnchorHint( (char*)userData );
}


/*----------------------------------------------------------------------------
	ChHtmlPageWnd message handlers
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	Shared utility functions
----------------------------------------------------------------------------*/

CH_INTERN_FUNC( void )
DoAnchorHint( char* pstrArgs )
{
	string	strURL;
	string	strHint;

	if (pstrArgs && ChHtmlWnd::GetHTMLHref( pstrArgs, false, strURL ))
	{
		if (!strURL.IsEmpty())
		{
			strHint = strURL;
		}
	}

	#if defined( CH_MSW )
	{
		ChCore*				pCore = ChCore::GetCore();
		ChPersistentFrame*	pFrame = pCore->GetFrameWnd();

		ASSERT( pFrame );
		pFrame->SetMessageText( strHint );
	}
	#elif defined( CH_UNIX )
	{
		TRACE1( "Need code to display URL hint: %s",
					(const char*)strHint );
	}
	#else
	{
		#error Platform not defined!
	}
	#endif
}
