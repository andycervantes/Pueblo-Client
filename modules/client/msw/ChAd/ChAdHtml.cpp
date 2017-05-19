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

	This file consists of the implementation of the ChAdHtmlBannerWnd class,
	used in the Ad banner, and the ChAdHtmlPageWnd class, used when we need
	to display HTML pages for ads.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChAd/ChAdHtml.cpp,v 1.15 1996/04/16 05:11:07 coyote Exp $

#include "headers.h"
#include "resource.h"

#include <ChCore.h>

#if defined( CH_UNIX )

	#include <ChDispat.h>
	#include <ChMsgTyp.h>
	#include <ChReg.h>
	#include "../../unix/ChTxtMud/UnixRes.h"

#endif	// defined( CH_UNIX )

#include "ChAdHtml.h"


/*----------------------------------------------------------------------------
	ChAdHtmlBannerWnd class
----------------------------------------------------------------------------*/

ChAdHtmlBannerWnd::ChAdHtmlBannerWnd() :
					m_pAdInfo( 0 )
{
}


ChAdHtmlBannerWnd::~ChAdHtmlBannerWnd()
{
}


void ChAdHtmlBannerWnd::GetIdealSize( ChSize& size )
{
}


void ChAdHtmlBannerWnd::OnFrameDisconnect( const ChModuleID& idNewModule )
{
	DestroyWindow();
	delete this;
}


void ChAdHtmlBannerWnd::LoadURL( const string& strURL )
{
	ChHtmlWnd::LoadURL( strURL );
}


#if !defined( CH_UNIX )

BEGIN_MESSAGE_MAP( ChAdHtmlBannerWnd, ChHtmlWnd )
	//{{AFX_MSG_MAP(ChAdHtmlBannerWnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#endif // !CH_UNIX


/*----------------------------------------------------------------------------
	ChAdHtmlBannerWnd protected methods
----------------------------------------------------------------------------*/

void ChAdHtmlBannerWnd::OnHotSpot( chparam userData, const string& strDocURL )
{
	char*	pstrArgs = (char*)userData;
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
	if ( m_pAdInfo )
	{
		ChPersistentFrame*	pFrame = m_pAdInfo->GetCore()->GetFrameWnd();

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


bool ChAdHtmlBannerWnd::OnSelectHotSpot( int x, int y, ChPoint& ptRel,
											chparam userData,
											const string& strDocURL )
{
											/* Notification on hotspot
												selection */
	if (userData)
	{
		char*				pstrCmd = (char*)userData;
		//ChCmdMsg			msg( pstrCmd );
		//ChSetFocusMsg		setFocusMsg;

		#if defined( CH_DEBUG )
		{
			string		strDump( pstrCmd );

			if (strDump.GetLength() > 150)
			{
				strDump = strDump.Left( 150 );
				strDump += " [...]";
			}

			TRACE1( "HTML Hot spot: %s\n", (const char*)strDump );
		}
		#endif
											// Attempt to load the document

		GetMainInfo()->DoAdClick( pstrCmd, ptRel.x, ptRel.y );

	}

	return true;
}


/*----------------------------------------------------------------------------
	ChAdHtmlBannerWnd message handlers
----------------------------------------------------------------------------*/

