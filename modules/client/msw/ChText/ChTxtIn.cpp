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

	Implementation for the ChTextInputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/ChTxtIn.cpp,v 2.36 1996/02/17 01:46:42 coyote Exp $

#include "headers.h"

#include <ChCore.h>
#include <ChSplit.h>
#include <ChUtil.h>
#include <ChWorld.h>

#include "ChTxtIn.h"
#include "ChPrefs.h"
#include "ChKeyMapType.h"
#include "resource.h"

#if defined( CH_MSW )
	#include <ctl3d.h>
#endif	// defined( CH_MSW )

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	Handler declarations
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( textInInitHandler )
CH_DECLARE_MESSAGE_HANDLER( textInShowModuleHandler )
CH_DECLARE_MESSAGE_HANDLER( textInGetPageCountHandler )
CH_DECLARE_MESSAGE_HANDLER( TextInGetPagesHandler )
CH_DECLARE_MESSAGE_HANDLER( TextInGetPageDataHandler )
CH_DECLARE_MESSAGE_HANDLER( TextInReleasePagesHandler )
CH_DECLARE_MESSAGE_HANDLER( textInSetFocusHandler )
CH_DECLARE_MESSAGE_HANDLER( textInTextHandler )
CH_DECLARE_MESSAGE_HANDLER( textInClearTextHandler )
CH_DECLARE_MESSAGE_HANDLER( textInInstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( textInPromoteHookHandler )
CH_DECLARE_MESSAGE_HANDLER( textInUninstallHookHandler )
CH_DECLARE_MESSAGE_HANDLER( textInSetPasswordHandler )

static ChMsgHandlerDesc	textInHandlers[] =
					{	{CH_MSG_INIT, textInInitHandler},
						{CH_MSG_SHOW_MODULE, textInShowModuleHandler},
						{CH_MSG_GET_PAGE_COUNT, textInGetPageCountHandler},
						{CH_MSG_GET_PAGES, TextInGetPagesHandler},
						{CH_MSG_GET_PAGE_DATA, TextInGetPageDataHandler},
						{CH_MSG_RELEASE_PAGES, TextInReleasePagesHandler},
						{CH_MSG_SET_FOCUS, textInSetFocusHandler},
						{CH_MSG_TEXT, textInTextHandler},
						{CH_MSG_CLEAR_TEXT, textInClearTextHandler},
						{CH_MSG_INSTALL_HOOK, textInInstallHookHandler},
						{CH_MSG_PROMOTE_HOOK, textInPromoteHookHandler},
						{CH_MSG_UNINSTALL_HOOK, textInUninstallHookHandler},
						{CH_TXT_MSG_SET_PASSWORD, textInSetPasswordHandler} };


/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_DECLARE_MESSAGE_HANDLER( stdEditMenuHandler )
CH_DECLARE_MESSAGE_HANDLER( OnStdEditCopy )
CH_DECLARE_MESSAGE_HANDLER( OnStdEditCut )
CH_DECLARE_MESSAGE_HANDLER( OnStdEditPaste )
CH_DECLARE_MESSAGE_HANDLER( OnStdEditClear )
CH_DECLARE_MESSAGE_HANDLER( stdWindowMenuHandler )
CH_DECLARE_MESSAGE_HANDLER( OnStdWindowCommand )


/*----------------------------------------------------------------------------
	ChTextInTinTin class
----------------------------------------------------------------------------*/

ChTextInTinTin::ChTextInTinTin( ChTextInMainInfo* pMainInfo ) :
				m_pMainInfo( pMainInfo )
{
}


void ChTextInTinTin::SendToWorld( const string& strOutput )
{
	if (IsOnline())
	{										/* This function doesn't apply
												any tintin processing to the
												string that it is sending */
		GetMainInfo()->Send( strOutput );
	}
}


void ChTextInTinTin::Display( const string& strOutput )
{
	if (IsOnline())
	{										/* This function doesn't apply
												any tintin processing to the
												string that it is sending */
		GetMainInfo()->Display( strOutput );
	}
}


/*----------------------------------------------------------------------------
	ChTextInMainInfo class
----------------------------------------------------------------------------*/

ChTextInMainInfo::ChTextInMainInfo( const ChModuleID& idModule,
									const ChModuleID& idServerModule ) :
					ChMainInfo( idModule ),
					m_idServerModule( idServerModule ),
					m_textInDispatcher( idModule, defTextInHandler ),
					m_pBanner( 0 ),
					m_pEdit( 0 ),
					m_stdEditMenu( stdEditMenuHandler ),
					m_stdWindowMenu( stdWindowMenuHandler ),
					m_boolShown( false ),
					m_boolMenus( false ),
					m_boolMenusInstalled( false ),
					m_sEditLines( 2 ),
					m_pTinTinProcessor( 0 )
{
											// Init registry values
	UpdatePreferences();
											/* Create the tintin processor
												object */

	m_pTinTinProcessor = new ChTextInTinTin( this );
	ASSERT( m_pTinTinProcessor );
}


ChTextInMainInfo::~ChTextInMainInfo()
{
	if (IsShown())
	{
		ShowModule( false );
	}

	if (m_pTinTinProcessor)
	{										/* Delete the tintin processor
												object */
		delete m_pTinTinProcessor;
		m_pTinTinProcessor = 0;
	}

	if (m_pBanner)
	{
		ChSplitter*		pSplitter = ChSplitter::GetSplitter();

											/* Disassociate and destroy the
												edit field */
		m_pBanner->SetChild( 0 );
		if (m_pEdit)
		{
			delete m_pEdit;
			m_pEdit = 0;
		}
											// Destroy the banner

		pSplitter->DestroyBanner( INPUT_BANNER_TITLE );
		m_pBanner = 0;
	}

	DestroyMenus();
}


void ChTextInMainInfo::RegisterDispatchers()
{
	chint16		sHandlerCount = sizeof( textInHandlers ) /
								sizeof( ChMsgHandlerDesc );

	m_textInDispatcher.AddHandler( textInHandlers, sHandlerCount );
}


void ChTextInMainInfo::ShowModule( bool boolShow )
{
	if (boolShow && !IsShown())
	{										// Show the banner
		if (m_pBanner)
		{
			m_pBanner->ShowWindow( SW_SHOW );
		}

		m_pTinTinProcessor->Reset();
		if (!m_strTinTinFile.IsEmpty())
		{
			m_pTinTinProcessor->ReadInitFile( "{" + m_strTinTinFile + "}" );
		}

		InstallMenus();
		m_boolShown = true;
	}
	else if (!boolShow && IsShown())
	{										// Hide the banner
		if (m_pBanner)
		{
			m_pBanner->ShowWindow( SW_HIDE );
		}

		UninstallMenus();
		m_boolShown = false;
	}
}


void ChTextInMainInfo::Send( const string& strText )
{
											/* This function doesn't apply
												any tintin processing to the
												string that it is sending */

	ChHookManager*		pHookMgr = GetHookMgr();
	bool				boolProcessed;

	ChTextMsg			msg( strText, TEXT_SEND_TO_WORLD );

	pHookMgr->Dispatch( msg, boolProcessed );

	if (!boolProcessed)
	{										// If not processed, ignore it...
	}
}


void ChTextInMainInfo::Display( const string& strText )
{
											/* This function doesn't apply
												any tintin processing to the
												string that it is sending */

	ChHookManager*		pHookMgr = GetHookMgr();
	bool				boolProcessed;

	ChTextMsg			msg( strText, TEXT_DISPLAY_ONLY );

	pHookMgr->Dispatch( msg, boolProcessed );

	if (!boolProcessed)
	{										// If not processed, ignore it...
	}
}


void ChTextInMainInfo::UpdatePreferences()
{
	ChRegistry	reg( TEXT_IN_PREFS_GROUP );
	chint16		sOldEditLines = GetEditLines();

											// Read in the number of edit lines

	reg.Read( TEXT_IN_EDIT_LINES, m_sEditLines, TEXT_IN_EDIT_LINES_DEF );

	if (GetEdit())
	{										/* Tell the edit field to update
												itself as well */
		GetEdit()->UpdatePreferences();
	}

	if (m_pBanner && (sOldEditLines != GetEditLines()))
	{
		ChSize	editSize;
											// Size the banner pane

		ChTextInputEdit::GetSize( GetEditLines(), editSize );
		m_pBanner->SetChildSize( (chint16)editSize.cx, (chint16)editSize.cy );
	}

	reg.Read( TEXT_IN_TINTIN_FILE, m_strTinTinFile, TEXT_IN_TINTIN_FILE_DEF );
}


/*----------------------------------------------------------------------------
	ChTextInMainInfo protected methods
----------------------------------------------------------------------------*/

void ChTextInMainInfo::Initialize()
{
	ChSplitter*	pSplitter = ChSplitter::GetSplitter();
	chint16		sClientHeight = 30;
	CSize		editSize;
											/* Get the edit size for the number
												of lines desired */

	ChTextInputEdit::GetSize( GetEditLines(), editSize );

											/* Create the banner and the edit
												field */

	m_pEdit = new ChTextInputEdit( GetServerModule() );
	m_pBanner = pSplitter->CreateBanner( 0, INPUT_BANNER_TITLE, false, true,
											(chint16)editSize.cx,
											(chint16)editSize.cy );
	m_pEdit->Create( m_pBanner, this );
											// Set the banner information
	m_pBanner->SetChild( m_pEdit );
											// Create menus for this module
	CreateMenus();
}


/*----------------------------------------------------------------------------
	ChTextInMainInfo private methods
----------------------------------------------------------------------------*/

void ChTextInMainInfo::CreateMenus()
{
	ChMenuItem*		pItem;
	string			strText;
											/* Add our menu hooks to the
												standard Edit menu */
	m_stdEditMenu.GetCutItem()->
					SetHandler( OnStdEditCut )->SetData( (chparam)this );
	m_stdEditMenu.GetCopyItem()->
					SetHandler( OnStdEditCopy )->SetData( (chparam)this );
	m_stdEditMenu.GetPasteItem()->
					SetHandler( OnStdEditPaste )->SetData( (chparam)this );

											/* Add our item to the standard
												Window menu */

	ChUtil::Load( (chparam)hTextDLL, IDS_WND_MENU_INPUT, strText );
	pItem = m_stdWindowMenu.InsertItem( strText, OnStdWindowCommand );
	ChUtil::Load( (chparam)hTextDLL, IDS_WND_MENU_INPUT_TXT,
					strText );
	pItem->SetHelpText( strText );
	ChUtil::Load( (chparam)hTextDLL, IDS_WND_MENU_INPUT_ACC,
					strText );
	pItem->SetAccelerator( strText[0], CH_ACC_CONTROL | CH_ACC_VIRTKEY );
	pItem->SetData( (chparam)this );

	m_boolMenus = true;
}


void ChTextInMainInfo::InstallMenus()
{
	m_stdEditMenu.Install( CH_MODULE_TEXT_INPUT );
	m_stdWindowMenu.Install( CH_MODULE_TEXT_INPUT );

	m_boolMenusInstalled = true;
}


void ChTextInMainInfo::UninstallMenus()
{
	m_stdEditMenu.Uninstall();
	m_stdWindowMenu.Uninstall();

	m_boolMenusInstalled = false;
}


void ChTextInMainInfo::DestroyMenus()
{
	m_boolMenus = false;
	m_boolMenusInstalled = false;
}


/*----------------------------------------------------------------------------
	ChTextInputBar constants
----------------------------------------------------------------------------*/

#define NUM_EDIT_CHARS_PER_LINE		80

#define INPUT_EDIT_STYLE			(WS_CHILD | WS_VISIBLE | WS_BORDER | \
										ES_AUTOVSCROLL | ES_MULTILINE | \
										ES_LEFT)


/*----------------------------------------------------------------------------
	ChTextInputEdit class
----------------------------------------------------------------------------*/

ChTextInputEdit::ChTextInputEdit( const ChModuleID& idServerModule ) :
					m_serverCore( idServerModule ),
					m_boolPassword( false ),
					m_h3dLib( 0 ),
					m_pprocSubclassCtl3d( 0 ),
					m_boolBrowsingHistory( false ),
					m_tabCompletionMode( tabModeReset ),
					m_posTabCompletion( 0 )
{
	ChCore*				pCore = ChCore::GetCore();
	const ChClientInfo*	pClientInfo = pCore->GetClientInfo();
	OSType				osType = pClientInfo->GetPlatform();

	m_boolWindows95 = (osWin95 == osType);

	if (!m_boolWindows95 && (m_h3dLib = LoadLibrary( "Ctl3d32.dll" )))
	{
		m_pprocSubclassCtl3d =
			(SubclassCtl3dProc)GetProcAddress( m_h3dLib, "Ctl3dSubclassCtl" );
	}
											// Init registry values
	UpdatePreferences();
}


ChTextInputEdit::~ChTextInputEdit()
{
	if (m_h3dLib)
	{
		FreeLibrary( m_h3dLib );
		m_h3dLib = 0;
		m_pprocSubclassCtl3d = 0;
	}
}


bool ChTextInputEdit::Create( ChWnd* pParent, ChTextInMainInfo* pMainInfo )
{
	CRect		rtEdit( 0, 0, 100, 100 );
											// Cache the pMainInfo
	m_pMainInfo = pMainInfo;
											// Create the window

	return CEdit::CreateEx( WS_EX_CLIENTEDGE, "edit", "_Text_In_Module_Edit_",
							INPUT_EDIT_STYLE, rtEdit.left, rtEdit.top,
							rtEdit.Width(), rtEdit.Height(),
							pParent->GetSafeHwnd(), 0 );
}


void ChTextInputEdit::GetSize( int iLines, CSize& size )
{
	CWindowDC	dc( CWnd::GetDesktopWindow() );
	TEXTMETRIC	tm;

	dc.GetTextMetrics( &tm );

	size.cy = (chint16)(tm.tmHeight + tm.tmExternalLeading) * iLines;
	size.cx = (chint16)(tm.tmAveCharWidth * NUM_EDIT_CHARS_PER_LINE);

	size.cx += (3 * GetSystemMetrics( SM_CXFRAME ));
	size.cy += (3 * GetSystemMetrics( SM_CYFRAME ));

	if (INPUT_EDIT_STYLE & WS_VSCROLL)
	{
		size.cx += GetSystemMetrics( SM_CXVSCROLL );
	}

	if (INPUT_EDIT_STYLE & WS_HSCROLL)
	{
		size.cy += GetSystemMetrics( SM_CYHSCROLL );
	}
}


void ChTextInputEdit::Send()
{											/* This function doesn't apply
												any tintin processing to the
												string that it is sending */
	string		strText;

	GetWindowText( strText );
	GetMainInfo()->Send( strText );
}


void ChTextInputEdit::EraseText()
{
	SetWindowText( "" );
}


void ChTextInputEdit::UpdatePreferences()
{
	ChRegistry	reg( TEXT_IN_PREFS_GROUP );
	string		strKeyMap;

	reg.Read( TEXT_IN_PREFS_KEYMAP, strKeyMap, TEXT_IN_PREFS_KEYMAP_DEF );
	m_keyMapType.Set( strKeyMap );
	m_keyMapType.CreateMap( m_keyMap );

	reg.ReadBool( TEXT_IN_PREFS_CLEAR, m_boolClearOnSend,
					TEXT_IN_PREFS_CLEAR_DEF );
}


BEGIN_MESSAGE_MAP( ChTextInputEdit, CEdit )
	//{{AFX_MSG_MAP(ChTextInputEdit)
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChTextInputEdit protected methods
----------------------------------------------------------------------------*/

void ChTextInputEdit::OnSendKey()
{
	string		strText;

	GetWindowText( strText );

											/* Don't add blank lines or passwords
												to the history */

	if (!IsPassword() && (strText.GetLength() > 0))
	{
		m_history.Add( strText );			// Add to the history
	}

	if (m_boolClearOnSend || IsPassword())
	{
		EraseText();
	}
	else
	{
		SetSel( 0, -1 );					// Select all text
	}
											/* We're no longer browsing the
												history, if we were before... */
	SetBrowsingHistory( false );

	GetMainInfo()->GetTinTin()->ParseInput( strText );
}


void ChTextInputEdit::MoveInHistory( bool boolUp )
{
	string		strLine;

	if (boolUp)
	{
		if (!IsBrowsingHistory())
		{									/* When we start browsing the
												history, we save the current
												text and use it as the 'end'
												text for browsing */
			GetWindowText( m_strEndText );
			SetBrowsingHistory( true );
		}

		if (m_history.GetPrevious( strLine ))
		{
			bool	boolNewText;
			string	strCurrent;

			GetWindowText( strCurrent );
											/* We haven't modified since
												we sent the text -- skip the
												last stored line */
			if (strLine == strCurrent)
			{
				boolNewText = m_history.GetPrevious( strLine );
			}
			else
			{
				boolNewText = true;
			}

			if (boolNewText)
			{
				SetHistoryText( strLine );
			}
		}
	}
	else
	{
		if (m_history.GetNext( strLine ))
		{
			SetHistoryText( strLine );
		}
		else
		{									/* We're at the end of the history
												again... */
			SetHistoryText( m_strEndText );
			SetBrowsingHistory( false );
		}
	}
}


void ChTextInputEdit::SetBrowsingHistory( bool boolBrowsing )
{
	if (m_boolBrowsingHistory != boolBrowsing)
	{
		m_boolBrowsingHistory = boolBrowsing;

		if (!m_boolBrowsingHistory)
		{									// Reset the history to the end
			m_history.Reset();
		}
	}
}


void ChTextInputEdit::DoTabCompletion()
{
	string		strText;

	if (tabModeReset == m_tabCompletionMode)
	{										// Reset the expansion string
		GetWindowText( m_strTabCompletion );
	}

	if ((tabModeReset == m_tabCompletionMode) ||
		(tabModeStart == m_tabCompletionMode))
	{										// Start from the beginning
		m_posTabCompletion = 0;
		m_tabCompletionMode = tabModeHistory;
	}

	strText = m_strTabCompletion;

	switch( m_tabCompletionMode )
	{
		case tabModeHistory:
		{
			if (m_history.GetExpansion( strText, m_posTabCompletion ))
			{
				int		iPos = m_strTabCompletion.GetLength();

				SetWindowText( strText );
				SetSel( iPos, iPos );

				if (0 == m_posTabCompletion)
				{							// We're at the end of the list

					m_tabCompletionMode = tabModeEnd;
				}
			}
			else
			{								// We've hit the end of the list
				MessageBeep( MB_ICONASTERISK );
				m_tabCompletionMode = tabModeStart;
			}
			break;
		}

		case tabModeEnd:
		{
			MessageBeep( MB_ICONASTERISK );
			m_tabCompletionMode = tabModeStart;
			break;
		}

		case tabModeReset:
		default:
		{
			break;
		}
	}
}


void ChTextInputEdit::DoRightButtonMenu( CPoint ptMouse )
{
	CMenu	popupMenu;

	popupMenu.CreatePopupMenu();
	ConstructRightButtonMenu( popupMenu );

	popupMenu.TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, ptMouse.x,
								ptMouse.y, this, 0 );
}


void ChTextInputEdit::ConstructRightButtonMenu( CMenu& menu )
{
	int		iHistoryCount = m_history.GetCount();
	string	strText;
											// Add history items
	if (iHistoryCount > 0)
	{
		int		iItem = 0;
		int		iItemsInMenu;

		menu.AppendMenu( MF_SEPARATOR );

		iItemsInMenu = min( maxMenuHistory, iHistoryCount );

		for (iItem = iHistoryCount - iItemsInMenu; iItem < iHistoryCount; iItem++)
		{
			string		strMenu;

			strMenu = m_history.GetString( iItem );
			TruncateMenuString( strMenu );
			menu.AppendMenu( MF_STRING, popupMenuHistoryBase + iItem,
								strMenu );
		}
	}
}


int ChTextInputEdit::GetEndOfLineIndex( int iLine ) const
{
	int		iChar;

	if (iLine == GetLineCount() - 1)
	{
		iChar = GetWindowTextLength();
	}
	else
	{
		iChar = LineIndex( iLine + 1 ) - 1;
	}

	return iChar;
}


void ChTextInputEdit::SendKeyDown( UINT uiKey, LPARAM lParam,
									bool boolStripCtrl )
{
											/* This function will send a key to
												the edit control, first
												stripping off the control key
												if it is pressed */
	static BYTE	bKeyStateArray[256];

	bool		boolControlWasPressed;
	BYTE		bControlBack;

	if (boolStripCtrl)
	{
		GetKeyboardState( bKeyStateArray );

		bControlBack = bKeyStateArray[VK_CONTROL];

		if (boolControlWasPressed = !!(bControlBack & 0x80))
		{
											// Turn off the control key

			bKeyStateArray[VK_CONTROL] &= ~0x80;
			SetKeyboardState( bKeyStateArray );
		}
	}
											// Send the key
	SendMessage( WM_KEYDOWN, uiKey, lParam );

	if (boolStripCtrl && boolControlWasPressed)
	{										// Restore the control key
		
		bKeyStateArray[VK_CONTROL] = bControlBack;
		SetKeyboardState( bKeyStateArray );
	}
}


bool ChTextInputEdit::ProcessKey( UINT& uiChar, LPARAM lParam )
{
	bool		boolContinue = false;
	bool		boolInTabCompletion = false;
	ChPosition	pos;
	chflag32	flMods = 0;
	bool		boolStripControl;

	#if 0
											/* We ignore the state of the
												shift key */
	if (GetKeyState( VK_SHIFT ) & 0x8000)
	{
		flMods |= ACTION_MOD_SHIFT;
	}

	#endif	// 0

	if (GetKeyState( VK_CONTROL ) & 0x8000)
	{
		boolStripControl = true;
		flMods |= ACTION_MOD_CONTROL;
	}
	else
	{
		boolStripControl = false;
	}

	pos = m_keyMap.FindItem( uiChar, flMods );
	if (pos)
	{
		ChKeyMapItem*	pItem = m_keyMap.GetItem( pos );

		ASSERT( pItem );

		switch( (KeyAction)pItem->GetUserData() )
		{
			case actSend:
			{
				OnSendKey();
				break;
			}

			case actTranspose:
			{
				int		iStart;
				int		iEnd;
				bool	boolLegal = false;

				GetSel( iStart, iEnd );

				if (iStart == iEnd)
				{
					int		iLen = GetWindowTextLength();

					if ((iEnd > 0) && (iEnd < iLen))
					{
						string		strText;
						string		strNewText;

						GetWindowText( strText );
						strNewText = strText.Left( iEnd - 1 );
						strNewText += strText[iEnd];
						strNewText += strText[iEnd - 1];
						strNewText += strText.Mid( iEnd + 1 );

						SetWindowText( strNewText );
						SetSel( iEnd, iEnd );

						boolLegal = true;
					}
				}

				if (!boolLegal)
				{							/* Transpose doesn't work here...
												beep */
					MessageBeep( MB_OK );
				}
				break;
			}

			case actHistoryPrev:
			{
				MoveInHistory( true );
				break;
			}

			case actHistoryNext:
			{
				MoveInHistory( false );
				break;
			}

			case actCursorLeft:
			{
				SendKeyDown( VK_LEFT, lParam, boolStripControl );
				break;
			}

			case actCursorRight:
			{
				SendKeyDown( VK_RIGHT, lParam, boolStripControl );
				break;
			}

			case actCursorHome:
			{
				SetSel( 0, 0 );
				break;
			}

			case actCursorEnd:
			{
				int		iChar = GetWindowTextLength();

				SetSel( iChar, iChar );
				break;
			}

			case actCursorStartLine:
			{
				SendKeyDown( VK_HOME, lParam, boolStripControl );
				break;
			}

			case actCursorEndLine:
			{
				SendKeyDown( VK_END, lParam, boolStripControl );
				break;
			}

			case actCursorUp:
			{
				if (0 == LineFromChar())
				{
					MoveInHistory( true );
				}
				else
				{
					SendKeyDown( VK_UP, lParam, boolStripControl );
				}
				break;
			}

			case actCursorDown:
			{
				int		iLastLineIndex = GetLineCount() - 1;

				if (iLastLineIndex == LineFromChar())
				{
					MoveInHistory( false );
				}
				else
				{
					SendKeyDown( VK_DOWN, lParam, boolStripControl );
				}
				break;
			}

			case actTabCompletion:
			{
				DoTabCompletion();
				boolInTabCompletion = true;
				break;
			}

			case actDeleteText:
			{
				EraseText();
				break;
			}

			case actDeleteToEndOfBuffer:
			{
				int		iStart;
				int		iEnd;

				GetSel( iStart, iEnd );

				if (iStart == iEnd)
				{							// No selection

					SetSel( iStart, GetWindowTextLength() );
				}
											// Clear the selection
				Clear();
				break;
			}

			case actDeleteNextChar:
			{
				int		iStart;
				int		iEnd;
				int		iLen = GetWindowTextLength();
				bool	boolLegal = true;

				GetSel( iStart, iEnd );

				if (iStart == iEnd)
				{							// No selection
					if (iEnd < iLen)
					{
						iEnd++;
						SetSel( iStart, iEnd );
					}
					else
					{
						MessageBeep( MB_OK );
						boolLegal = false;
					}
				}

				if (boolLegal)
				{							// Clear the selection
					Clear();
				}
				break;
			}

			default:
			{
				boolContinue = true;
				break;
			}
		}
	}
	else
	{
		boolContinue = true;
	}

	if (!boolInTabCompletion)
	{
		m_tabCompletionMode = tabModeReset;
	}

	return boolContinue;
}


/*----------------------------------------------------------------------------
	ChTextInputEdit message handlers
----------------------------------------------------------------------------*/

bool ChTextInputEdit::PreTranslateMessage( MSG* pMsg )
{
	bool boolCancel;

	if (WM_KEYDOWN == pMsg->message)
	{
		if (ProcessKey( pMsg->wParam, pMsg->lParam ))
		{
			boolCancel = CEdit::PreTranslateMessage( pMsg );
		}
		else
		{
			boolCancel = true;
		}
	}
	else if (WM_KEYUP == pMsg->message)
	{
		if (VK_RETURN == pMsg->wParam)
		{
			boolCancel = true;
		}
	}
	else
	{
		boolCancel = CEdit::PreTranslateMessage( pMsg );
	}

	return boolCancel;
}


int ChTextInputEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}

	if (m_pprocSubclassCtl3d)
	{
		m_pprocSubclassCtl3d( GetSafeHwnd() );
	}

	return 0;
}

bool ChTextInputEdit::OnCommand( WPARAM wParam, LPARAM lParam )
{
	bool	boolProcessed = true;
	string	strText;

	if ((wParam >= popupMenuHistoryBase) &&
				(wParam <= popupMenuHistoryBase + maxHistory))
	{
		int		iIndex = wParam - popupMenuHistoryBase;

		strText = m_history.GetString( iIndex );
	}
	else
	{
		boolProcessed = false;
	}

	if (boolProcessed && !strText.IsEmpty())
	{
		SetWindowText( strText );
		OnSendKey();
	}

	return boolProcessed;
}


void ChTextInputEdit::OnChar( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	CEdit::OnChar( nChar, nRepCnt, nFlags );
}


void ChTextInputEdit::OnKillFocus( CWnd* pNewWnd )
{
	CEdit::OnKillFocus( pNewWnd );

	if (GetMainInfo() && GetMainInfo()->IsMenuInstalled())
	{
		ChEditMenu*		pStdEditMenu;
											/* Demote our window (we no longer
												care about the Cut/Copy/Paste
												menu messages) */

		if (pStdEditMenu = GetMainInfo()->GetStdEditMenu())
		{
			pStdEditMenu->Promote( false );
		}
	}
}


void ChTextInputEdit::OnSetFocus( CWnd* pOldWnd )
{
	CEdit::OnSetFocus( pOldWnd );

	if (GetMainInfo() && GetMainInfo()->IsMenuInstalled())
	{
											/* Promote our window (we want to
												get the Cut/Copy/Paste menu
												messages first) */
		GetMainInfo()->GetStdEditMenu()->Promote();
	}
}


void ChTextInputEdit::OnRButtonDown( UINT nFlags, CPoint ptMouse )
{
	ClientToScreen( &ptMouse );
	DoRightButtonMenu( ptMouse );
}


/*----------------------------------------------------------------------------
	Chaco message handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( defTextInHandler )
{
	chparam		retVal = 0;

	return retVal;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textInInitHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;

	pInfo->Initialize();
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textInShowModuleHandler )
{
	ChShowModuleMsg*	pMsg = (ChShowModuleMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;

	pInfo->ShowModule( pMsg->IsShowing() );
	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textInGetPageCountHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
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


CH_IMPLEMENT_MESSAGE_HANDLER( TextInGetPagesHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
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
				ChTextInPrefsPage*	pPage;

				pPage = new ChTextInPrefsPage;

//				pPage->SetEditLines( pInfo->GetEditLines() );

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


CH_IMPLEMENT_MESSAGE_HANDLER( TextInGetPageDataHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
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
					ChTextInPrefsPage*	pPage = (ChTextInPrefsPage*)pPages[0];

					pPage->OnCommit();
					pInfo->UpdatePreferences();
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


CH_IMPLEMENT_MESSAGE_HANDLER( TextInReleasePagesHandler )
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
					ChTextInPrefsPage*	pPage = (ChTextInPrefsPage*)pPages[0];

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


CH_IMPLEMENT_MESSAGE_HANDLER( textInSetFocusHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;

	if (pInfo->IsShown())
	{
		pInfo->GetEdit()->SetFocus();
	}
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textInTextHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
	ChTextMsg*			pMsg = (ChTextMsg*)&msg;
	string				strText;

	pMsg->GetParams( strText );
	pInfo->GetEdit()->SetWindowText( strText );
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textInClearTextHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;

	pInfo->GetEdit()->EraseText();
	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textInInstallHookHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
	ChInstallHookMsg*	pMsg = (ChInstallHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetHookMgr();
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_TEXT == lMessage );

	pHookMgr->Install( idHookModule );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textInPromoteHookHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
	ChPromoteHookMsg*	pMsg = (ChPromoteHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetHookMgr();
	ChModuleID			idHookModule;
	bool				boolPromote;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, boolPromote, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_TEXT == lMessage );

	pHookMgr->Promote( idHookModule, boolPromote );

	return 0;
}

CH_IMPLEMENT_MESSAGE_HANDLER( textInUninstallHookHandler )
{
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMainInfo;
	ChUninstallHookMsg*	pMsg = (ChUninstallHookMsg*)&msg;
	ChHookManager*		pHookMgr = pInfo->GetHookMgr();
	ChModuleID			idHookModule;
	chint32				lMessage;

	pMsg->GetParams( idHookModule, lMessage );
	ASSERT( 0 == lMessage || CH_MSG_TEXT == lMessage );

	pHookMgr->Uninstall( idHookModule );

	return 0;
}


CH_IMPLEMENT_MESSAGE_HANDLER( textInSetPasswordHandler )
{
	ChTextInMainInfo*		pInfo = (ChTextInMainInfo*)pMainInfo;
	ChTextSetPasswordMsg*	pMsg = (ChTextSetPasswordMsg*)&msg;
	bool					boolPassword;

	pMsg->GetParams( boolPassword );
	pInfo->SetPassword( boolPassword );

	return 0;
}


/*----------------------------------------------------------------------------
	Chaco menu handlers
----------------------------------------------------------------------------*/

CH_IMPLEMENT_MESSAGE_HANDLER( stdEditMenuHandler )
{
	chparam		retVal = 0;

	return retVal;
}


CH_IMPLEMENT_MESSAGE_HANDLER( OnStdEditCut )
{
	chparam				retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMsg->GetItem()->GetData();
	ChTextInputEdit*	pEdit = pInfo->GetEdit();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SHOW:
		{
			int		iStart;
			int		iEnd;

			pEdit->GetSel( iStart, iEnd );

			if (iStart == iEnd)
			{
				pMsg->GetItem()->Enable( false );
			}
			else
			{
				pMsg->GetItem()->Enable();
			}
			pMsg->SetProcessed();
			break;
		}

		case CH_MSG_MENU_SELECT:
		{
			pEdit->Cut();
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

CH_IMPLEMENT_MESSAGE_HANDLER( OnStdEditCopy )
{
	chparam		retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMsg->GetItem()->GetData();
	ChTextInputEdit*	pEdit = pInfo->GetEdit();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SHOW:
		{
			int		iStart;
			int		iEnd;

			pEdit->GetSel( iStart, iEnd );

			if (iStart == iEnd)
			{
				pMsg->GetItem()->Enable( false );
			}
			else
			{
				pMsg->GetItem()->Enable();
			}
			pMsg->SetProcessed();
			break;
		}

		case CH_MSG_MENU_SELECT:
		{
			pEdit->Copy();
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


CH_IMPLEMENT_MESSAGE_HANDLER( OnStdEditPaste )
{
	chparam				retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMsg->GetItem()->GetData();
	ChTextInputEdit*	pEdit = pInfo->GetEdit();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SHOW:
		{
			if (pEdit->OpenClipboard())
			{
				if (::GetClipboardData( CF_TEXT ))
				{
					pMsg->GetItem()->Enable();
				}
				else
				{
					pMsg->GetItem()->Enable( false );
				}

				::CloseClipboard();
			}
			pMsg->SetProcessed();
			break;
		}

		case CH_MSG_MENU_SELECT:
		{
			pEdit->Paste();
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


CH_IMPLEMENT_MESSAGE_HANDLER( OnStdEditClear )
{
	chparam				retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMsg->GetItem()->GetData();
	ChTextInputEdit*	pEdit = pInfo->GetEdit();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SHOW:
		{
			int		iStart;
			int		iEnd;

			pEdit->GetSel( iStart, iEnd );

			if (iStart == iEnd)
			{
				pMsg->GetItem()->Enable( false );
			}
			else
			{
				pMsg->GetItem()->Enable();
			}
			pMsg->SetProcessed();
			break;
		}

		case CH_MSG_MENU_SELECT:
		{
			pEdit->Clear();
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


CH_IMPLEMENT_MESSAGE_HANDLER( stdWindowMenuHandler )
{
	chparam		retVal = 0;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	pMsg->SetProcessed();

	return retVal;
}


CH_IMPLEMENT_MESSAGE_HANDLER( OnStdWindowCommand )
{
	chparam				retVal = false;
	ChMenuMsg*			pMsg = (ChMenuMsg*)&msg;
	ChTextInMainInfo*	pInfo = (ChTextInMainInfo*)pMsg->GetItem()->GetData();
	ChTextInputEdit*	pEdit = pInfo->GetEdit();

	pMsg->SetProcessed();

	switch( pMsg->GetMessage() )
	{
		case CH_MSG_MENU_SELECT:
		{
			pEdit->SetFocus();
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


/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

CH_GLOBAL_FUNC( void )
TruncateMenuString( string& strText )
{
	if (strText.GetLength() > MAX_MENU_STRING_LEN)
	{
									/* Truncate the string to make a
										happy menu, and add ellipses */

		strText = strText.Left( MAX_MENU_STRING_LEN );
		strText += "...";
	}
}
