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

	This file consists of the interface for the ChTxtView view class.

----------------------------------------------------------------------------*/


#if !defined( _CHHTMLVW_H )
#define _CHHTMLVW_H

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#if defined( CH_MSW )

	#include <afxtempl.h>

#endif	// defined( CH_MSW )

#include <ChTxtVw.h>
#include <ChSplay.h>
#include <ChList.h>
#if !defined( NO_HOOK )
#include <ChMsgTyp.h>
#include <ChHook.h>
#endif

#if defined( CH_MSW )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )

/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

// !!!!!!!!
// These constants are  indexes to pstrHTMLTokens array Do not modify these constants.
//  Add costants to the end and update the 	pstrHTMLTokens to  add new tokens
#define  HTML_UNKNOWN		0
#define	 HTML_H1			1
#define	 HTML_H2			2
#define	 HTML_H3			3
#define	 HTML_H4			4
#define	 HTML_H5			5
#define  HTML_H6			6
#define  HTML_BLKQUOTE		7
#define  HTML_ADDRESS		8
#define  HTML_PARAGRAPH		9
#define  HTML_COMMENT		10
#define  HTML_PREFORMAT		11
#define  HTML_BULLETLINE	12
#define  HTML_LINE			13
#define  HTML_NUMLIST		14
#define  HTML_LINK			15
#define  HTML_IMAGE			16
#define  HTML_QUOTE			17
#define  HTML_STRIKETHROUGH	18
#define  HTML_BOLD			19
#define  HTML_ITALIC		20
#define  HTML_EMBEDLINE		21
#define  HTML_LINEBREAK		22
#define  HTML_UNDERLINE		23
#define  HTML_TYPEWRITER	24
#define  HTML_EMPHASIS		25
#define  HTML_STRONG		26
#define  HTML_CODE			27
#define  HTML_SAMP			28
#define  HTML_CITE			29
#define	 HTML_DIR			30
#define  HTML_DEFNLIST		31
#define	 HTML_DEFNTEXT		32
#define  HTML_DEFNTERM		33
#define  HTML_CENTER		34
#define  HTML_RIGHT			35
#define  HTML_PLAINTEXT		36
#define  HTML_TITLE			37
#define  HTML_FONT			38


/*----------------------------------------------------------------------------
	External classes
----------------------------------------------------------------------------*/

class ChHTMLStyle;

typedef ChPtrList<char>	ChHTMLCmdString;


/*----------------------------------------------------------------------------
	Typedefs 
----------------------------------------------------------------------------*/

// This defines the argument list for htmp tags
typedef struct tagChacoArgList
{
	int			iArgType; 		// type
	chparam		argVal;			// value

} ChArgList, FAR* pChArgList;

// HTML stack data

typedef struct tagChStackData
{
	int			iType;					// tag type
	ChRect		rtIndent;				// indents
	int			iPointSize;				// pointsize
	chuint32	luStyle;				// text view styles
	chuint32	luForeColor;			// fore color
	chuint32	luBackColor;			// back color
	int			iLineWidth;				// line width
	int			iLineHeight;			// line height
	chparam		userData;				// user data
	chuint32	luModified;			 	// fields modified
	int			iLineNumber;			// line number

} ChStackData, FAR* pChStackData;



/*----------------------------------------------------------------------------
	ChStack class
----------------------------------------------------------------------------*/

// This class defines the interface for the HTML stack

class ChStack 
{
	public :
		ChStack( int iSize = 100, int iGrowSize = 25 );
		~ChStack();

		void Push( ChStackData& data );
		ChStackData* Pop();
		ChStackData* Peek( int iIndex );
		int GetTopIndex()			
				{ 
					return m_iTopIndex - 1; 
				}
		ChStackData* Remove( int iIndex );
	private:
		int 	m_iTopIndex;
		int 	m_iSize; 
		int		m_iGrowSize;
		ChStackData* m_pStack;
};


/*----------------------------------------------------------------------------
	ChHTMLView class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChHTMLView : public ChTxtView
{
	friend class   ChHTMLStyle;	   			// To access the HTML tag table

#ifdef CH_MSW
	protected:
											/* protected constructor used
												by dynamic creation */
		ChHTMLView();

		DECLARE_DYNCREATE( ChHTMLView )

		//{{AFX_VIRTUAL(ChHTMLView)
		protected:
		//}}AFX_VIRTUAL
#else
	public:
		ChHTMLView();
#endif // CH_MSW

	public :
		bool NewPage();						/* Clears the contents of the
												HTML view */

		void AppendText( const char* pstrNewText, chint32 lNewCount = -1 )
					{
						ParseText( pstrNewText, lNewCount );
					}
		#if !defined( NO_HOOK )
											// Hook management methods

		inline void InstallHook( const ChModuleID& idModule )
					{
						GetHookMgr()->Install( idModule );
					}
		inline void UninstallHook( const ChModuleID& idModule )
					{
						GetHookMgr()->Uninstall( idModule );
					}
		inline void PromoteHook( const ChModuleID& idModule, bool boolPromote )
					{
						GetHookMgr()->Promote( idModule, boolPromote );
					}
		inline void DoHook( ChCmdMsg& msg )
					{
						bool	boolProcessed;

						GetHookMgr()->Dispatch( msg, boolProcessed );
					}
		#endif

	protected:
		virtual ~ChHTMLView();

		ChSplay< string, ChHTMLStyle*>& GetStyleTbl()
					{
						return m_htmlStyleTbl;
					}
		ChHTMLStyle* GetHTMLStyle( int iTag );

		#if !defined( NO_HOOK )
		inline ChHookManager* GetHookMgr() { return &m_commandHooks; }
		#endif

		inline void AppendChar( char strChar )
		{
			if ( m_iBufIndex >= bufferSize )
			{ // append this to the previous style
				ChTxtView::AppendTextRun( m_pstrLocalBuffer, m_iBufIndex, GetTextStyle() );
			}
			m_pstrLocalBuffer[ m_iBufIndex++ ] = strChar;
		}

		void IncrementFixedFont()			{ m_iFontFixed++; };
		void IncrementUnderline()			{ m_iFontUnderline++; };
		void IncrementStrikethrough()		{ m_iFontStrikethrough++; };
		void IncrementItalic()				{ m_iFontItalic++; };
		void IncrementBold()				{ m_iFontBold++; };

		void DecrementFixedFont()			{ m_iFontFixed--; };
		void DecrementUnderline()			{ m_iFontUnderline--; };
		void DecrementStrikethrough()		{ m_iFontStrikethrough--; };
		void DecrementItalic()				{ m_iFontItalic--;};
		void DecrementBold()				{ m_iFontBold--; };

		//ChHTMLCmdString&	GetCmdList()		{ return m_cmdList; }

#ifdef CH_MSW
		//{{AFX_MSG(ChHTMLView)
		afx_msg void OnMouseMove(UINT nFlags, CPoint point);
		afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
		afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()
#endif // CH_MSW

	private :
		// core methods for HTML view
		chint32	GetBufferSize() { return ChHTMLView::bufferSize; }
		void BuildHTMLStyleTable();
		void FreeHTMLStyleTable();
		void ParseText( const char* pstrNewText, chint32 lCount );
		int  PreProcessTag( const char* pstrBuffer, chint32 lStart, 
									chint32  lCount,  ChHTMLStyle* pStyle );
		int  ProcessTerminationTag( const char* pstrBuffer, chint32& lStart, 
									chint32  lCount,  ChHTMLStyle* pStyle );

		int  GetArguments( const char* pstrBuffer, chint32& lStart, 
									chint32  lCount, pChArgList pArg, int iMax);
		void UpdateAttributes(  int& iIndex, pChArgList pList, 
									string& strAttr, string& strVal );
		int  GetArgType(  string& strArg );
		void RestoreTextStyle( int iType );
		int  LookUpTag( const char* pstrBuffer, chint32& lStart, chint32 lCount);
		void CreateStyle( ChHTMLStyle *pStyle );
		ChFont* GetHTMLFont()				{ return  m_pcurrFont; }

	// Accessor functions
		char* GetBuffer() 					{ return m_pstrLocalBuffer; }
		int	GetBufferIndex() 				{ return m_iBufIndex; }
		ChTextStyle* GetTextStyle() 		{ return m_ptxtStyle; }	
		ChStack& HTMLStack()				{ return m_htmlStack; }
		void  SetBufferIndex( int iIndex )	{ m_iBufIndex = iIndex; }
		

	private:
		enum tagConst { bufferSize = 4092 }; // internal buffer size

		ChHTMLCmdString					m_cmdList;

		ChSplay< string, ChHTMLStyle*>	m_htmlStyleTbl;	 		// HTML tag table
		char*							m_pstrLocalBuffer;		// internal buffer
		int								m_iBufIndex;			// current index 
		HCURSOR							m_hCursor, 				// current cursor
										m_hotCursor;			// hotspot cursor
		#if !defined( NO_HOOK )
		ChHookManager					m_commandHooks;	  		// hooks
		#endif
		ChTextStyle*					m_ptxtStyle;		  	// current text style
		ChFont*							m_pcurrFont; 			// current font
		int								m_iFontFixed;			// use fixed font if > 0
		int								m_iFontItalic;			// use italic if > 0
		int								m_iFontBold;			// use bold if > 0
		int 							m_iFontUnderline;		// use underline if > 0
		int								m_iFontStrikethrough;	// use strikeout if > 0
		ChStack							m_htmlStack;			// HTML state stack
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif // _CHHTMLVW_H
// Local Variables: ***
// tab-width:4 ***
// End: ***
