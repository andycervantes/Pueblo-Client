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

	Implementation for the ChTextOutput class, which is used to display
	output text.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChTxtOut.cpp,v 2.63 1996/02/22 01:45:00 coyote Exp $

#include "headers.h"

#include <ChCore.h>
#include <ChClMod.h>
#include <ChPane.h>
//#include <ChMime.h>
#include <ChUrlMap.h>

#include <ChWorld.h>

#include "ChTextStream.h"
#include "ChTxtOut.h"
#include "ChPrefs.h"

#if defined( CH_UNIX )

	#include <ChTypes.h>
	#include "../../unix/ChText/TextPriv.h"

#endif	// defined( CH_UNIX )

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define ATTR_HREF					TEXT( "href" )
#define ATTR_TARGET					TEXT( "target" )


/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( textOutInitHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutLoadCompleteHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutTextHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutFileHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutLoadFileHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutClearTextHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutResetHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutSetScrollHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutPaneCmdHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutPaneEventHandler )

#if	!defined( CH_UNIX )

CH_DECLARE_MESSAGE_HANDLER( textOutGetPageCountHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutGetPagesHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutGetPageDataHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutReleasePagesHandler )

#endif // !CH_UNIX

CH_DECLARE_MESSAGE_HANDLER( textOutCommandHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutInlineHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutHintHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutInstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutPromoteHookHandler )
CH_DECLARE_MESSAGE_HANDLER( textOutUninstallHookHandler )

static ChMsgHandlerDesc	textOutHandlers[] =
					{	{CH_MSG_INIT, textOutInitHandler},
						{CH_MSG_LOAD_COMPLETE, textOutLoadCompleteHandler},
						{CH_MSG_TEXT, textOutTextHandler},
						{CH_MSG_FILE, textOutFileHandler},
						{CH_MSG_LOAD_FILE, textOutLoadFileHandler},
						{CH_MSG_CLEAR_TEXT, textOutClearTextHandler},
						{CH_MSG_RESET, textOutResetHandler},
						{CH_MSG_SET_SCROLL, textOutSetScrollHandler},
						{CH_MSG_SHOW_MODULE, textOutShowModuleHandler},
						{CH_MSG_PANE_CMD, textOutPaneCmdHandler},
						{CH_MSG_PANE_EVENT, textOutPaneEventHandler},
#if !defined( CH_UNIX )
						{CH_MSG_GET_PAGE_COUNT, textOutGetPageCountHandler},
						{CH_MSG_GET_PAGES, textOutGetPagesHandler},
						{CH_MSG_GET_PAGE_DATA, textOutGetPageDataHandler},
						{CH_MSG_RELEASE_PAGES, textOutReleasePagesHandler},
#endif // !defined( CH_UNIX )
						{CH_MSG_CMD, textOutCommandHandler},
						{CH_MSG_INLINE, textOutInlineHandler},
						{CH_MSG_HINT, textOutHintHandler},
						{CH_MSG_INSTALL_HOOK, textOutInstallHookHandler},
						{CH_MSG_PROMOTE_HOOK, textOutPromoteHookHandler},
						{CH_MSG_UNINSTALL_HOOK, textOutUninstallHookHandler} };

// We want ChTxtOutputWnd on Unix, but we don't want TextOutMainInfo.
#ifndef CH_UNIX

/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( txtOutStdEditMenuHandler )
CH_DECLARE_MESSAGE_HANDLER( OnTxtOutStdEditCopy )
CH_DECLARE_MESSAGE_HANDLER( OnTxtOutStdEditCutPaste )

#endif


/*----------------------------------------------------------------------------
	Inline functions
----------------------------------------------------------------------------*/

inline bool IsTargetSelfOutput( const string& strTarget )
	{
		bool	boolSelf = (strTarget.CompareNoCase( "_self" ) == 0);

		return boolSelf;
	}


/*----------------------------------------------------------------------------
	class ChPaneOutWnd
----------------------------------------------------------------------------*/

class ChPaneOutWnd : public ChTextOutputWnd
{
	public:
		ChPaneOutWnd( const ChModuleID& idWorld );
		virtual ~ChPaneOutWnd();

	protected:
		virtual void OnSubmitForm( const string& strFormData );

	protected:
		ChClientModule	m_worldModule;
};


ChPaneOutWnd::ChPaneOutWnd( const ChModuleID& idWorld ) :
				m_worldModule( idWorld )
{
}


ChPaneOutWnd::~ChPaneOutWnd()
{
}


void ChPaneOutWnd::OnSubmitForm( const string& strFormData )
{
	ChCmdMsg	msg( strFormData );
											// Submit the HTML form
	m_worldModule.Send( msg );
}


/*----------------------------------------------------------------------------
	ChTextOutMainInfo class
----------------------------------------------------------------------------*/

chint16		ChTextOutMainInfo::m_sMinWidth;
chint16		ChTextOutMainInfo::m_sIdealWidth;
chint16		ChTextOutMainInfo::m_sMinHeight;
chint16		ChTextOutMainInfo::m_sIdealHeight;

#ifndef CH_UNIX

ChTextOutMainInfo::ChTextOutMainInfo( ChModuleID idModule,
										ChModuleID idServerModule ) :
					ChMainInfo( idModule ),
					m_textOutDispatcher( idModule, defTextOutHandler ),
					m_stdEditMenu( txtOutStdEditMenuHandler ),
//					m_idTextInModule( 0 ),
//					m_pTextIn( 0 ),
					m_idWorldModule( 0 ),
					m_boolShown( false ),
					m_boolMenus( false ),
					m_boolMenusInstalled( false ),
					m_httpConn( 0 )
{
	ChPane*		pPane = GetPaneMgr()->FindPane( ChPaneMgr::strTextName );
	CClientDC	dc( pPane->GetFrameWnd() );
	TEXTMETRIC	tm;

	dc.GetTextMetrics( &tm );

	m_sMinWidth = tm.tmAveCharWidth * minCharWidth;
	m_sIdealWidth = tm.tmAveCharWidth * idealCharWidth;
	m_sMinHeight = (tm.tmHeight + tm.tmExternalLeading) * minCharHeight;
	m_sIdealHeight = (tm.tmHeight + tm.tmExternalLeading) * idealCharHeight;

	m_pTextStreamMgr = new ChTextStreamManager( idModule );
	ASSERT( m_pTextStreamMgr );
	m_httpConn.SetStreamMgr( m_pTextStreamMgr );
											/* Register this module as a
												handler for HTML text and
												normal text */

	//GetMimeMgr()->AddHandler( GetModuleID(), "text/plain" );
	//GetMimeMgr()->AddHandler( GetModuleID(), "text/html" );

	InstallOutputHooks( GetOutputWnd() );
}


ChTextOutMainInfo::~ChTextOutMainInfo()
{
	InstallOutputHooks( GetOutputWnd(), false );

	m_httpConn.SetStreamMgr( 0 );
	delete m_pTextStreamMgr;

											// Unhook us from the MIME handler

	//GetMimeMgr()->RemoveHandler( GetModuleID(), "text/plain" );
	//GetMimeMgr()->RemoveHandler( GetModuleID(), "text/html" );

											// Unload the text in module
#if 0
	if (m_idTextInModule)
	{
		UnloadClientModule( m_idTextInModule );
		m_idTextInModule = 0;
	}

	if (m_pTextIn)
	{
		delete m_pTextIn;
		m_pTextIn = 0;
	}
#endif
											// Clear all panes

	GetPaneMgr()->ShowAllPanes( GetModuleID(), false );
	GetPaneMgr()->DestroyAllPanes( GetModuleID() );

	DestroyMenus();
											// Destroy the window
	GetOutputWnd()->DestroyWindow();
}


void ChTextOutMainInfo::Initialize()
{
	ChRect			rtChild( -100, -100, -1, -1 );
	bool			boolCreated;
	ChPane*			pPane = GetPaneMgr()->FindPane( ChPaneMgr::strTextName );
	ChModuleMgr*	pModMgr = ChCore::GetCore()->GetModuleMgr();
	string			strDummy;

//	LoadClientModule( CH_MODULE_TEXT_INPUT, CH_MODULE_TEXT_INPUT_BASE,
//						GetModuleID(), 0 );

	pModMgr->FindModule( CH_MODULE_WORLD, m_idWorldModule, strDummy );
	ASSERT( 0 != GetWorldModuleID() );
	ASSERT( 0 != pPane );
											/* Set the main info, this is used
												for menu processing */
	GetOutputWnd()->SetMainInfo( this );
											/* Create the new child using the
												pane frame window as the
												parent */

	boolCreated = GetOutputWnd()->Create( rtChild, pPane->GetFrameWnd() );
	ASSERT( boolCreated );
											// Set the child into the view

	pPane->SetOwner( GetModuleID(), GetOutputWnd() );
	pPane->SetSizePrefs( m_sIdealWidth, m_sIdealHeight, m_sMinWidth,
							m_sMinHeight );
	CreateMenus();
}

#endif // !CH_UNIX

void ChTextOutMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( textOutHandlers ) /
								sizeof( ChMsgHandlerDesc );

	m_textOutDispatcher.AddHandler( textOutHandlers, sHandlerCount );
}


#if 0

void ChTextOutMainInfo::SetTextInID( const ChModuleID& idModule )
{
	m_idTextInModule = idModule;

	if (0 == m_pTextIn)
	{
		m_pTextIn = new ChClientModule( m_idTextInModule );
	}
}

#endif

#if !defined( CH_UNIX )

void ChTextOutMainInfo::ShowModule( bool boolShow )
{
	ChPane*		pPane;
											// Get the correct pane

	pPane = GetPaneMgr()->FindPane( ChPaneMgr::strTextName );
	ASSERT( 0 != pPane );

	if (boolShow && !IsShown())
	{
		pPane->Show();
		InstallMenus();

		m_boolShown = true;
	}
	else if (!boolShow && IsShown())
	{
		pPane->Show( false );
		UninstallMenus();

		m_boolShown = false;
	}
}


void ChTextOutMainInfo::LoadFile( const string& strFilename,
									const string& strURL,
									const string& strHTML,
									const string& strMimeType )
{
	bool					boolPaneAttrs;
	ChPane::ChPaneCmd		paneCmd;
	string					strPaneName;
	string					strPaneTitle;

	if (boolPaneAttrs = !strHTML.IsEmpty())
	{
		boolPaneAttrs = ChPane::GetPaneCmdAttr( strHTML, paneCmd );
	}

	if (boolPaneAttrs)
	{
		ASSERT( ChPane::paneOpen == paneCmd );

		DoPaneOpen( strFilename, strMimeType, strURL, strHTML );
	}
	else
	{
		ChTextOutputWnd*	pWnd = GetOutputWnd();

		pWnd->ShowAppend( false );
		pWnd->DisplayFile( strFilename, strMimeType, ChHtmlWnd::fileReplace, strURL );
	}
}


bool ChTextOutMainInfo::DoPaneCommand( ChPane::ChPaneCmd paneCmd,
										const char* pstrArgs )
{
	switch( paneCmd )
	{
		case ChPane::paneOpen:
		{
			string strURL;
			ChHtmlWnd::GetHTMLHref( pstrArgs, true, strURL );
			if (!strURL.IsEmpty())
			{ 
				string *pstrHTML = new string( pstrArgs );
				m_httpConn.GetURL( strURL, (chparam)pstrHTML );
			}
			else
			{
				TRACE1( "Empty URL passed into ChTextOutMainInfo::LoadURL : %s ", pstrArgs );
			}
			//GetMimeMgr()->LoadURL( "", pstrArgs );
			break;
		}

		case ChPane::paneClose:
		{
			DoPaneClose( pstrArgs );
			break;
		}

		default:
		{
			break;
		}
	}

	return true;
}


void ChTextOutMainInfo::DoPaneOpen( const string& strFilename,
									const string& strMimeType,
									const string& strURL,
									const string& strHTML )
{
	bool				boolPaneAttrs;
	ChPane*				pPane;
	ChPaneOutWnd*		pWnd;
	ChRect				rtChild( 10, 10, 300, 500 );
	ChPane::ChPaneCmd	paneCmd;
	string				strPaneName;
	string				strPaneTitle;
	chflag32			flPaneOptions;
	chint16				sIdealWidth = m_sIdealWidth;
	chint16				sIdealHeight = m_sIdealHeight;
	chint16				sMinWidth = m_sMinWidth;
	chint16				sMinHeight = m_sMinHeight;
	bool				boolCreated = true;

	boolPaneAttrs = ChPane::GetPaneAttrs( strHTML, paneCmd, strPaneName,
											strPaneTitle, flPaneOptions );
	ASSERT( boolPaneAttrs );
	ASSERT( ChPane::paneOpen == paneCmd );

	ChPane::GetPaneSizeAttrs( strHTML, sIdealWidth, sIdealHeight, sMinWidth,
								sMinHeight );

	if (!(pPane = GetPaneMgr()->FindPane( strPaneName )))
	{
		pPane = GetPaneMgr()->CreatePane( strPaneName, 0, sIdealWidth,
											sIdealHeight, flPaneOptions );
		ASSERT( pPane );
		ASSERT( 0 != GetWorldModuleID() );
	}

	if (pPane->GetModuleID() != GetModuleID())
	{
		DWORD		dwPaneStyle;

		pWnd = new ChPaneOutWnd( GetWorldModuleID() );
		ASSERT( pWnd );

		pWnd->SetMainInfo( this );
		InstallOutputHooks( pWnd );
											/* Create the new child using the
												pane frame window as the
												parent */
		#if defined( CH_MSW )

		if (flPaneOptions & paneBanner)
		{									/* Leave the border off of a banner
												pane child, since it shows up
												in a banner */

			dwPaneStyle = WS_VISIBLE | WS_VSCROLL;
		}
		else
		{
			dwPaneStyle = WS_VISIBLE | WS_BORDER | WS_VSCROLL;
		}

		if (boolCreated = pWnd->Create( rtChild, pPane->GetFrameWnd(),
										dwPaneStyle ))
		{
												// Take ownership of the pane
			pPane->SetOwner( GetModuleID(), pWnd );
			pPane->SetTitle( strPaneTitle );
			pPane->SetSizePrefs( sIdealWidth, sIdealHeight, sMinWidth,
									sMinHeight );
		}
		else

		#endif	// defined( CH_MSW )

		{
			delete pWnd;
			TRACE( "ChTextOutMainInfo::DoPaneOpen : Error creating pane." );
		}
	}
	else
	{
		pWnd = (ChPaneOutWnd*)pPane->GetWindow();
	}

	if (boolCreated)
	{										// Display the file

		pWnd->DisplayFile( strFilename, strMimeType, ChHtmlWnd::fileReplace, strURL );

											/* Size the pane if necessary.  The
												pane is sized if it's either
												not sizeable, or if it hasn't
												been automatically sized to
												a previous size. */

		if (!pPane->IsSizeable() || !pPane->IsSized())
		{
			pPane->SetSize( sIdealWidth, sIdealHeight );
		}
											// Turn off scrolling if necessary
		if (pPane->IsNoScroll())
		{
			CRect	rtEdges( 0, 0, 0, 0 );

			pWnd->AllowScroll( false, false );
			pWnd->SetViewIndents( rtEdges );
		}

		if (pPane->IsSizeToFit())
		{
			ChSize		size;

			pWnd->GetDocumentSize( size );

			pPane->SetSize( (chint16)size.cx +
								(2 * GetSystemMetrics( SM_CXBORDER )),
							(chint16)size.cy + 
								(2 * GetSystemMetrics( SM_CXBORDER )) );
		}
												// Finally show the pane
		pPane->Show();
	}
}


void ChTextOutMainInfo::DoPaneClose( const string& strHTML )
{
	bool					boolPaneAttrs;
	string					strPaneName;
	string					strPaneTitle;

	ASSERT( !strHTML.IsEmpty() );

	boolPaneAttrs = ChPane::GetPaneNameAttr( strHTML, strPaneName );

	ASSERT( boolPaneAttrs );

	if (!strPaneName.IsEmpty())
	{
		GetPaneMgr()->DestroyPane( strPaneName );
	}
}


/*----------------------------------------------------------------------------
	ChTextOutMainInfo protected methods
----------------------------------------------------------------------------*/

void ChTextOutMainInfo::InstallOutputHooks( ChTextOutputWnd* pOutWnd,
												bool boolInstall )
{
	if (boolInstall)
	{										// Hook us into pOutWnd

		pOutWnd->InstallHook( CH_MSG_CMD, GetModuleID() );
		pOutWnd->InstallHook( CH_MSG_INLINE, GetModuleID() );
		pOutWnd->InstallHook( CH_MSG_HINT, GetModuleID() );
	}
	else
	{										// Unhook us from pOutWnd

		pOutWnd->UninstallHook( CH_MSG_CMD, GetModuleID() );
		pOutWnd->UninstallHook( CH_MSG_INLINE, GetModuleID() );
		pOutWnd->UninstallHook( CH_MSG_HINT, GetModuleID() );
	}
}


/*----------------------------------------------------------------------------
	ChTextOutMainInfo private methods
----------------------------------------------------------------------------*/

void ChTextOutMainInfo::CreateMenus()
{
	string			strText;
											/* Add our menu hooks to the
												standard edit menu */
	m_stdEditMenu.GetCopyItem()->
					SetHandler( OnTxtOutStdEditCopy )->SetData( (chparam)this );

	m_stdEditMenu.GetCutItem()->
					SetHandler( OnTxtOutStdEditCutPaste )->SetData( (chparam)this );
	m_stdEditMenu.GetPasteItem()->
					SetHandler( OnTxtOutStdEditCutPaste )->SetData( (chparam)this );

	m_boolMenus = true;
}


void ChTextOutMainInfo::InstallMenus()
{
	m_stdEditMenu.Install( CH_MODULE_TEXT_OUTPUT );

	m_boolMenusInstalled = true;
}


void ChTextOutMainInfo::UninstallMenus()
{
	m_stdEditMenu.Uninstall();

	m_boolMenusInstalled = false;
}


void ChTextOutMainInfo::DestroyMenus()
{
	m_boolMenus = false;
	m_boolMenusInstalled = false;
}

#endif	// !defined( CH_UNIX )


/*----------------------------------------------------------------------------
	ChTextOutputWnd class
----------------------------------------------------------------------------*/

ChTextOutputWnd::ChTextOutputWnd() :
					m_pTxtOutInfo( NULL )
{
	SetAnchorTarget( string( TEXT("_webtracker" ) ) );
}


ChTextOutputWnd::~ChTextOutputWnd()
{
}


/*----------------------------------------------------------------------------
	ChTextOutputWnd protected methods
----------------------------------------------------------------------------*/

void ChTextOutputWnd::OnSelectHotSpot( int x, int y, ChPoint& ptRel, chparam userData,
											const string& strDocURL )
{
	const char* pstrArgs = (const char*)userData;

											/* Notification on hotspot
												selection */
	if (pstrArgs)
	{
		ChPane::ChPaneCmd		paneCmd;
											/* Check to see if this is a pane
												anchor.  If it is, send it to
												the pane command handler. */

		if (ChPane::GetPaneCmdAttr( pstrArgs, paneCmd ))
		{
			GetMainInfo()->DoPaneCommand( paneCmd, pstrArgs );
		}
		else
		{									/* Otherwise send the anchor
												through the hook chain */

			ChCmdMsg			msg( pstrArgs, ptRel.x, ptRel.y );
			ChSetFocusMsg		setFocusMsg;
//			ChClientModule*		pTextInModule;

			#if defined( CH_DEBUG )
			{
				string		strDump( pstrArgs );

				if (strDump.GetLength() > 150)
				{
					strDump = strDump.Left( 150 );
					strDump += " [...]";
				}

				TRACE1( "HTML Hot spot: %s\n", (const char*)strDump );
			}
			#endif	// defined( CH_DEBUG )

			DoHook( msg );

			if (msg.IsProcessed())
			{								/* Stop formatting and abort all
												requests generated by this
												page */
				AbortFormatting();
#if 0
											/* Set focus back to the input
												window */

				pTextInModule = GetMainInfo()->GetTextInModule();
				if (0 != pTextInModule)
				{
					pTextInModule->Post( setFocusMsg );
				}
#endif
			}
			else
			{								/* The selection of a hot spot was
												not processed, check if there
												is a HREF, if it does then
												launch the Web browser if we
												have a valid URL */
			   	string		strValue;

				if (ChHtmlWnd::GetHTMLAttribute( pstrArgs, ATTR_HREF,
													strValue ))
				{
					string		strTarget;

					ChHtmlWnd::GetHTMLAttribute( pstrArgs, ATTR_TARGET,
													strTarget );
					if (IsTargetSelfOutput( strTarget ))
					{
						ChHtmlWnd::OnSelectHotSpot( x, y, ptRel, userData,
													strDocURL );
					}
					else
					{
						ChURLParts		urlMap;

						if (urlMap.GetURLParts( strValue, strDocURL ))
						{
							ChClientModule	coreModule( ChClientModule::GetCoreID() );
							ChLoadFileMsg	loadMsg( urlMap.GetURL() );
						
											// Load the web page 

							coreModule.Send( loadMsg );
						}
					}
				}
			}
		}
	}
}

void ChTextOutputWnd::OnSubmitForm( const string& strFormData )
{
	// submit the HTML form
	ChCmdMsg			msg( strFormData, -1, -1 );

	DoHook( msg );
}



void ChTextOutputWnd::OnHotSpot( chparam userData, const string& strDocURL )
{
	char*	pstrCmd;

	if (userData)
	{
		pstrCmd = (char*)userData;
	}
	else
	{
		pstrCmd = "";
	}

	ChHintMsg	msg( pstrCmd );

	DoHook( msg );
}


bool ChTextOutputWnd::OnInline( const char* pstrArgs, const string& strDocURL )
{
	bool	boolProcessed = false;

	if (pstrArgs)
	{
		ChPane::ChPaneCmd		paneCmd;
											/* Check to see if this is a pane
												inline.  If it is, send it to
												the pane command handler. */

		if (ChPane::GetPaneCmdAttr( pstrArgs, paneCmd ))
		{
			boolProcessed = GetMainInfo()->DoPaneCommand( paneCmd, pstrArgs );
		}
		else
		{									/* Otherwise send the inline
												through the hook chain */
			ChInlineMsg	msg( pstrArgs );

			DoHook( msg );
			boolProcessed = msg.IsProcessed();
		}
	}

	return boolProcessed;
}


void ChTextOutputWnd::OnLoadImage( const char* pstrURL, ChObjInline *pImage,
									const string& strDocURL )
{
											/* called when there is a inline
												image to be loaded */

	ChHtmlWnd::OnLoadImage( pstrURL, pImage, strDocURL );
}


#ifndef CH_UNIX

BEGIN_MESSAGE_MAP( ChTextOutputWnd, ChHtmlWnd )
	//{{AFX_MSG_MAP(ChTextOutputWnd)
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTextOutputWnd message handlers
----------------------------------------------------------------------------*/

void ChTextOutputWnd::OnKillFocus( CWnd* pNewWnd )
{
	ChTextOutMainInfo*	pMainInfo = GetMainInfo();

	ChHtmlWnd::OnKillFocus( pNewWnd );

	if (pMainInfo && pMainInfo->IsMenuInstalled())
	{
		ChEditMenu*		pStdEditMenu;
											/* Demote our window (we no longer
												care about the Copy
												menu messages) */

		if (pStdEditMenu = pMainInfo->GetStdEditMenu())
		{
			pStdEditMenu->Promote( false );
		}
	}
}


void ChTextOutputWnd::OnSetFocus( CWnd* pOldWnd )
{
	ChTextOutMainInfo*	pMainInfo = GetMainInfo();

	ChHtmlWnd::OnSetFocus( pOldWnd );

	if (pMainInfo && pMainInfo->IsMenuInstalled())
	{
											/* Promote our window (we want to
												get the Copy menu
												messages first) */
		pMainInfo->GetStdEditMenu()->Promote();
	}
}


void ChTextOutputWnd::OnPaletteChanged(CWnd* pFocusWnd)
{
    // See if the change was caused by us and ignore it if not.
    if (pFocusWnd != this) {
        OnQueryNewPalette();
    }
}

// Note: Windows actually ignores the return value.
BOOL ChTextOutputWnd::OnQueryNewPalette()
{
	CDC* pdc = GetDC();
	UINT u = pdc->RealizePalette();
	ReleaseDC(pdc);
	if (u != 0) 
	{
		// Some colors changed so we need to do a repaint.
		InvalidateRect(NULL, true); // Repaint the lot.
		return true; // Say we did something.
	}
	return false; // Say we did nothing.
}

#endif // !CH_UNIX

/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( defTextOutHandler )
{
	chparam		retVal = 0;

	return retVal;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textOutInitHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutLoadCompleteHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChLoadCompleteMsg*	pMsg = (ChLoadCompleteMsg*)&msg;
	string				strModuleName;
	ChModuleID			idModule;
	string				strFilename;
	chparam				userData;

	pMsg->GetParams( strModuleName, idModule, strFilename, userData );

#if 0
	if (CH_MODULE_TEXT_INPUT == strModuleName)
	{
		pInfo->SetTextInID( idModule );
	}
	else
#endif
	{										// This is a loaded file

		pInfo->LoadFile( strFilename, pMsg->GetURL(), pMsg->GetHTML(),
							pMsg->GetType() );
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutTextHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	string				strText;
	ChTextMsg*			pMsg = (ChTextMsg *)&msg;
	ChTextOutputWnd*	pWnd = pInfo->GetOutputWnd();
	chint32				lLen;

	pMsg->GetParams( strText );
	lLen = strText.GetLength();

	pWnd->AppendText( strText );

	#if defined( CH_VERBOSE )
	{
		TRACE1( "TEXT OUT: %s\n", (const char *)strText );
	}
	#endif	// defined( CH_VERBOSE )

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutFileHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	string				strFilename;
	chflag32			flOptions;
	ChFileMsg::FileCmd	cmd;
	ChFileMsg*			pMsg = (ChFileMsg*)&msg;

	pMsg->GetParams( cmd, strFilename, flOptions );

	if (ChFileMsg::fileOpenWrite == cmd)
	{
		pInfo->GetOutputWnd()->WriteFile( strFilename, flOptions );
	}
	else
	{
		pInfo->GetOutputWnd()->CloseFile();
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutLoadFileHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	string				strURL;
	string				strFilename;
	string				strType;
	ChLoadFileMsg*		pMsg = (ChLoadFileMsg*)&msg;

	pMsg->GetParams( strURL, strFilename, strType );
	pInfo->LoadFile( strFilename, strURL, "", strType );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutClearTextHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChTextOutputWnd*			pWnd = pInfo->GetOutputWnd();

	pWnd->NewPage();
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutResetHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;

	pInfo->GetPaneMgr()->DestroyAllPanes( pInfo->GetModuleID(), false );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutSetScrollHandler )
{
	ChSetScrollMsg*		pMsg = (ChSetScrollMsg*)&msg;
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChTextOutputWnd*	pWnd = pInfo->GetOutputWnd();
	bool				boolAutoScroll;

	pMsg->GetParams( boolAutoScroll );

	pWnd->ShowAppend( boolAutoScroll );
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutShowModuleHandler )
{
	ChShowModuleMsg*	pMsg = (ChShowModuleMsg*)&msg;
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;

	pInfo->ShowModule( pMsg->IsShowing() );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutPaneCmdHandler )
{
	ChPaneCmdMsg*		pMsg = (ChPaneCmdMsg*)&msg;
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	string				strPaneCmd;
	ChPane::ChPaneCmd	paneCmd;

	pMsg->GetParams( strPaneCmd );
											/* Check to see if this is a pane
												message.  If it is, send it to
												the pane command handler. */

	if (ChPane::GetPaneCmdAttr( strPaneCmd, paneCmd ))
	{
		bool	boolProcessed;

		boolProcessed = pInfo->DoPaneCommand( paneCmd, strPaneCmd );
		pMsg->SetProcessed( boolProcessed );
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutPaneEventHandler )
{
	ChPaneEventMsg*	pMsg = (ChPaneEventMsg*)&msg;

	switch( pMsg->GetEvent() )
	{
		case ChPaneEventMsg::paneEventDisconnect:
		{
			const ChPane*	pPane = pMsg->GetPane();
			ChWnd*			pWnd = pPane->GetWindow();

			if (pPane->GetType() == ChPane::paneNormal)
			{
				pWnd->DestroyWindow();
				delete pWnd;
			}
			break;
		}

		case ChPaneEventMsg::paneEventClose:
		{
			pMsg->SetClose();
			break;
		}

		default:
		{
			break;
		}
	}
	return 0;
}


#if !defined( CH_UNIX )

CH_IMPLEMENT_MESSAGE_HANDLER( textOutGetPageCountHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChGetPageCountMsg*	pMsg = (ChGetPageCountMsg*)&msg;
	ChPageType			type;
	int					iPageCount;

	pMsg->GetParams( type );

	if (pInfo->IsShown())
	{
		switch( type )
		{
			case pagePreferences:
			{
				iPageCount = 1;
				break;
			}

			default:
			{
				iPageCount = 0;
				break;
			}
		}
	}
	else
	{
		iPageCount = 0;
	}

	return iPageCount;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutGetPagesHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChGetPagesMsg*		pMsg = (ChGetPagesMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				ChTextOutPrefsPage*	pPage;

				pPage = new ChTextOutPrefsPage;

				pPages[0] = (chparam)pPage;
			}
			#endif
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutGetPageDataHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChGetPageDataMsg*	pMsg = (ChGetPageDataMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				if (pPages[0])
				{
					ChTextOutPrefsPage*	pPage = (ChTextOutPrefsPage*)pPages[0];
					chint32				lLines;

					pPage->OnCommit();

					lLines = pPage->GetLines();
					pInfo->SetBufferLimit( lLines );
				}
			}
			#endif	// defined( CH_MSW )
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutReleasePagesHandler )
{
	ChReleasePagesMsg*	pMsg = (ChReleasePagesMsg*)&msg;
	ChPageType			type;
	chint16				sCount;
	chparam*			pPages;

	pMsg->GetParams( type, sCount, pPages );

	switch( type )
	{
		case pagePreferences:
		{
			ASSERT( 1 == sCount );

			#if defined( CH_MSW )
			{
				if (pPages[0])
				{
					ChTextOutPrefsPage*	pPage = (ChTextOutPrefsPage*)pPages[0];

					delete pPage;
				}
			}
			#endif	// defined( CH_MSW )
			break;
		}

		default:
		{
			break;
		}
	}

	return 0;
}


#endif	// !defined( CH_UNIX )


CH_IMPLEMENT_MESSAGE_HANDLER( textOutCommandHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChCmdMsg*			pMsg = (ChCmdMsg*)&msg;

	pInfo->DoHook( *pMsg );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutInlineHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChInlineMsg*		pMsg = (ChInlineMsg*)&msg;

	pInfo->DoHook( *pMsg );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutHintHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChHintMsg*			pMsg = (ChHintMsg*)&msg;

	pInfo->DoHook( *pMsg );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textOutInstallHookHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChInstallHookMsg*	pMsg = (ChInstallHookMsg*)&msg;
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	pInfo->InstallHook( lMessage, idHookModule );
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textOutPromoteHookHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChPromoteHookMsg*	pMsg = (ChPromoteHookMsg*)&msg;
	ChModuleID			idHookModule;
	bool				boolPromote;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, boolPromote, lMessage );
	pInfo->PromoteHook( lMessage, idHookModule, boolPromote );
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textOutUninstallHookHandler )
{
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMainInfo;
	ChUninstallHookMsg*	pMsg = (ChUninstallHookMsg*)&msg;
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	pInfo->UninstallHook( lMessage, idHookModule );
	return 0;
}


/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( txtOutStdEditMenuHandler )
{
	chparam		retVal = 0;

	return retVal;
}

CH_IMPLEMENT_MESSAGE_HANDLER( OnTxtOutStdEditCopy )
{
	chparam				retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextOutMainInfo*	pInfo = (ChTextOutMainInfo*)pMsg->GetItem()->GetData();
	ChTextOutputWnd*	pOut = pInfo->GetOutputWnd();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SHOW:
		{
			chint32 lStart, lEnd;

			pOut->GetSel( lStart, lEnd );

			if ( lStart != lEnd )
			{
				pMsg->GetItem()->Enable();
			}
			else
			{
				pMsg->GetItem()->Enable( false );
			}
			pMsg->SetProcessed();
			break;
		}

		case CH_MSG_MENU_SELECT:
		{
			pOut->CopyToClipboard();
			pMsg->SetProcessed();
			break;
		}

		default:
		{
			break;
		}
	}
	return retVal;
}

CH_IMPLEMENT_MESSAGE_HANDLER( OnTxtOutStdEditCutPaste )
{
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;

	pMsg->SetProcessed();

	if (CH_MSG_MENU_SHOW == pMsg->GetMessage())
	{
		pMsg->GetItem()->Enable( false );
		pMsg->SetProcessed();
	}

	return false;
}
