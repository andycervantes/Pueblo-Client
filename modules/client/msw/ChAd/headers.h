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

	Source file that includes just the standard includes.  This file may
	be used for precompiled headers.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChAd/headers.h,v 1.10 1996/03/07 21:24:45 pritham Exp $

#if !defined( _HEADERS_H )
#define _HEADERS_H

#if defined( CH_MSW )

	#include <afxwin.h>						// MFC core and std components
	#include <afxext.h>						// MFC extensions
	#include <afxdisp.h>					// MFC dispatchers

	#if defined( WIN32 ) && defined( USE_CNM_CTL )

		#include <afxcmn.h>					// MFC new control classes

	#endif	// defined( WIN32 )

	#include <ctype.h>

#endif	// CH_MSW

#include <ChTypes.h>
#include <ChModule.h>
#include <ChDispat.h>
#include <ChMsg.h>
#include <ChMsgTyp.h>
#include <ChUtil.h>

#if defined( CH_MSW )

	#if !defined( NO_TEMPLATES )
	#include <afxtempl.h>					// MFC template classes
	#endif

#endif	// CH_MSW

#include "ChAdHtml.h"


class ChArgumentList;


/*----------------------------------------------------------------------------
	Global variables
----------------------------------------------------------------------------*/

#if defined( CH_MSW )

	CH_EXTERN_VAR AFX_EXTENSION_MODULE ChAdDLL;

#elif defined( CH_UNIX )

	extern string_resource	ad_resources[];

#endif	// defined( CH_UNIX )


/*----------------------------------------------------------------------------
	Macros
----------------------------------------------------------------------------*/

#if defined( CH_MSW )

	#define LOADSTRING( lKey, strValue ) \
				(ChUtil::Load( (chparam)ChAdDLL.hModule, lKey, strValue ))

#elif defined( CH_UNIX )

	#define LOADSTRING( lKey, strValue ) \
				(ChUtil::Load( (chparam)ad_resources, lKey, strValue ))

#else

	#error "OS not defined"

#endif


/*----------------------------------------------------------------------------
	ChAdMainInfo class
----------------------------------------------------------------------------*/

class ChAdMainInfo : public ChMainInfo
{
	CH_FRIEND_MESSAGE_HANDLER( adLoadCompleteHandler )
	CH_FRIEND_MESSAGE_HANDLER( adGetPagesHandler )
	CH_FRIEND_MESSAGE_HANDLER( adGetPageDataHandler )

	public:
		ChAdMainInfo( const ChModuleID& idModule,
							 ChCore* pCore,
							 ChArgumentList* pList );
		virtual ~ChAdMainInfo();

		inline bool AllModulesLoaded()
						{
							return true;
						}
		inline bool IsShown() { return m_boolShown; }

		inline ChAdHtmlBannerWnd* GetAdBannerWnd() { return &m_adBannerWnd; }

		void Initialize();
		void ShowModule( bool boolShow );

		void DisplayAdBanner( const string& strAdURL,
								const string& strParam = "",
								const string& strUserParam = "" );
		bool DoAdClick( const string& strArgs, chint32 lX, chint32 lY );

	protected:
		inline chint16 GetAdWidth() { return m_sAdWidth; }
		inline chint16 GetAdHeight() { return m_sAdHeight; }
		inline void SetShown( bool boolShown ) { m_boolShown = boolShown; }

	private:
		void RegisterDispatchers();

		void CreateMenus();
		void InstallMenus();
		void UninstallMenus();
		void DestroyMenus();

	private:
//		ChClientModule		m_clientCore;
//		ChServerModule		m_serverModule;
		ChDispatcher		m_adDispatcher;

		ChAdHtmlBannerWnd	m_adBannerWnd;

		bool				m_boolShown;
		bool				m_boolMenus;

		string				m_strCurrAdURL;
		string				m_strCurrAdParam;
		string				m_strCurrAdUserParam;

		chint16				m_sAdWidth;
		chint16				m_sAdHeight;
};


#endif	// !defined( _HEADERS_H )
