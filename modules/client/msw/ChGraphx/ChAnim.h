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

	Interface for the ChAnimView class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAnim.h,v 2.11 1996/07/02 19:41:13 pritham Exp $

#include "grheader.h"
#if !defined( _CHANIM_H )
#define _CHANIM_H

#include <ChHook.h>
#include <ChGraphx.h>
#include "ChGrVw.h"
#include <ChSplay.h>
#include "ChSpritN.h"
#include "ChSprite.h"
#include "ChSpLstN.h"
#include "ChSprLst.h"
#include "ChPhSprt.h"
#include <fstream.h>
//#include <ChDibImage.h>
#include <ChDibBmp.h>

#define CH_ANIM_SCRIPT_GO_TO  -2
#define CH_ANIM_SCRIPT_STOP  -1

/*----------------------------------------------------------------------------
	ChAnimView class	-- enhanced graphic view for graphic module
----------------------------------------------------------------------------*/

class ChAnimView;
class ChAnimAnchor;
class ChAnimCastMember;
								// make it a class and it can serialize itself ??
								// ought to be able to do loops in a character's
								// script, maybe by using a union or special
								// value.
#if 0
typedef struct _ChCell {
    int x;
    int y;
    int z;
	int	sprite;	// sprite id ??
    int row;
    int col;
    //CWave* pSnd;   // needs to be id ?
} ChCell;

Moved ChCell class to ChGraphx.h - needed by messages

#endif
 
								 // ChAnimAnchor is a hotspot which initiates
								 // character action, some sort of 
								 // message to callback. (Module can then 
								 // do as it wishes. It also posts a CH_MSG_ANCHOR
								 // to m_moduleId
class ChAnimAnchor
{
	CH_FRIEND_MESSAGE_HANDLER( animatorLoadAnchorHandler );
	CH_FRIEND_MESSAGE_HANDLER( graphicPaletteChangeHandler );

	friend class ChAnimCastMember;
	friend class ChAnimView;

	public:
		typedef enum { rect = 1, cast } type;

	public:
		ChAnimAnchor();
		ChAnimAnchor( chuint32 id, CRect& rcHot );
		ChAnimAnchor( chuint32 id, chuint32 hotCastId );
	
		virtual ~ChAnimAnchor();

	public:
	    inline void SetId( chuint32 id ) { m_id = id; }
	    inline void SetRect(CRect& rcHot) { m_type = rect; m_rcHot = rcHot; }
		chuint32 GetId( ) { return m_id; }; 
	    CRect& GetRect() {return m_rcHot; };
		string& GetHint() { return m_strHint; };
		inline chuint32 GetCursorId() { return m_cursor; };

		void SetHint( string & strHint ) {m_strHint = strHint;};
		void SetCmd( string & strCmdArg ) {m_strCmdArg = strCmdArg;};
		void SetCast( chuint32 castId ) {m_pCast = 0; m_castId = castId;};
		void SetStartFrame( chint32 lStartCell ) {m_lStartCell = lStartCell;};
		inline void SetCursorId( chuint32 cursor ) {m_cursor = cursor;};
		void SetCursor( string& cursorName );
		inline type GetType() { return m_type; };
		inline chuint32 GetHotCastId() { return m_hotCastId; }
		inline void SetHotCastId(chuint32 hotCastId) { m_type = cast; m_pHotCast = 0; m_hotCastId = hotCastId; }
		inline ChAnimCastMember * GetHotCast() { return m_pHotCast; }
		inline chuint32 GetCastId() const { return m_castId; }
		inline ChAnimCastMember * GetCast();

		inline ChAnimView * GetView() const { return m_pView; }

		// called by view; pt is in image coordinates
		bool HitTest(const CPoint & pt ) const
			{
				return m_rcHot.PtInRect(*LPPOINT(&pt));	// Test point for containment
			};

		//  called if Anchored
		virtual bool Notify(CPoint &point);	// derive to get this notification
		virtual bool Post(CPoint &point);

		#if 0
		void Serialize(ChArchive& archive)
			{
				if( archive.GetMode() == modeRead )
				{
					archive >> m_id;
					archive >> (chint32)m_rcHot.TopLeft().x;
					archive >> (chint32)m_rcHot.TopLeft().y;
					archive >> (chint32)m_rcHot.BottomRight().x;
					archive >> (chint32)m_rcHot.BottomRight().y;
					archive >> m_moduleId;
					archive >> m_strHint;
				}
				else
				{
					// oughta do something for versions??????
					archive << m_id;
					archive << (chint32)m_rcHot.TopLeft().x;
					archive << (chint32)m_rcHot.TopLeft().y;
					archive << (chint32)m_rcHot.BottomRight().x;
					archive << (chint32)m_rcHot.BottomRight().y;
					archive << m_moduleId;
	 				archive << m_strHint;
				}
			}
		#endif

    protected:
		void SetView( ChAnimView *const pView )
				{
					m_pView = pView;
				}

    protected:
											// Anchoring objects
		type				m_type;
		chuint32			m_id;
	    CRect 				m_rcHot;	  	//  a 'union' class of ChAnimCastMember and rect
	    ChAnimCastMember*	m_pHotCast;
		chuint32			m_hotCastId;	// for as-yet unloaded

											// resultant objects
	    ChAnimCastMember*	m_pCast;		// only fill in if used
		chuint32			m_castId;	  	// for as-yet unloaded; null means none
	    chint32				m_lStartCell;	// mandatory if cast supplied

											//  messaging
		//ChModuleID		m_moduleId;
		string				m_strCmdArg;
											// user feedback
		string				m_strHint;
		chuint32			m_cursor;
											/* Set the view when added to a
												view, so it's available to
												notifyees */
		ChAnimView*			m_pView;
};

typedef ChAnimAnchor *pChAnimAnchor;




class ChCharacter						 // thought we needed this, but whatever . . .
{
	public:
		//ChCharacter();
		//virtual ~ChCharacter();
		virtual bool Tick(chuint32 luCurrMsec) = 0; 			// Move one step
		virtual void GetBounds(CRect* pRect) = 0;	// return bounding rect
		virtual void Draw(CDC * pDC ) = 0;	// draw yourself to DC
		virtual bool HitTest(const CPoint & pt ) = 0;	// Test point for containment

};

class ChAnimParser;
class ChAnimCastMember : public ChCharacter
{

	friend class ChAnimParser;

	public:
		ChAnimCastMember(chuint32 luId = 1);
		virtual ~ChAnimCastMember();
		virtual bool Tick(chuint32 luCurrMsec); 			// Move one step
		virtual void GetBounds(CRect* pRect);	// return bounding rect
		virtual void Draw(CDC * pDC );	// draw yourself to DC
		virtual bool HitTest(const CPoint & pt );	// Test point for containment
		void	Show( bool boolVisible = true );
		bool	IsVisible() { return m_boolVisible; }
		chuint32 GetId() { return m_id; };			// tag for external reference
		void Animate( bool boolRun = true );
		bool IsAnimating( ) {return !m_boolFrozen; };
		void SetDraggable( bool boolDraggable = true ) { m_boolDraggable = boolDraggable;};
		bool IsDraggable( ) {return m_boolDraggable; };

		void SetCell( chint32 iCell );
		//virtual void Serialize( ChArchive& ar ) const;
		virtual void Read( istream& strm );
		void SetSprite(CPhasedSprite* pSprite);		  
		void SetScript(int numCells, int iCurCell, chint32 lFrameRate, ChCell *pScript, bool boolCopy = false);
		void SetScript(ChAnimScript *pScript, bool boolCopy = false);

		inline ChCell* GetScriptCells() { return m_pScript; };
		inline string& GetScriptURL() { return m_strScriptURL; };
		inline ChAnimCastMember*  SetScriptURL(string& strURL)
				{ m_strScriptURL = strURL; return this; };
		inline string& GetName() { return m_strName; };									 
		inline CPhasedSprite* GetSprite( ) { return m_pSprite; }
		inline string& GetSpriteURL()  { return m_strSpriteURL; }
		inline ChAnimCastMember* SetSpriteURL(const string& strURL)
				{m_strSpriteURL = strURL; return this; }
		void InitFromMsg( ChCastMsg *pMsg );
		void OnAddition(ChAnimView *pView);
		void InitializeScript();
	 	inline ChAnimAnchor *GetAnchor() { return m_pAnchor; };
		inline void SetAnchor(ChAnimAnchor *pAnchor)
		{ 
			if(m_pAnchor && m_pAnchor != pAnchor)
			{
				pAnchor->m_pHotCast = 0;
				delete pAnchor;
			}
			m_pAnchor = pAnchor;
			pAnchor->m_pHotCast = this;
		};

	protected:
	    CPhasedSprite* m_pSprite;		// just one for now; array in future ?
									// or could change CPhasedSprite to handle
									// multiple dibs (but then it's 3d...maybe not
									// a good idea
		string		m_strSpriteURL;	// where to find sprite data
		string		m_strScriptURL;	// where to find sprite data
    	chint32 	m_iCurCell;
	    ChCell* 	m_pScript;
		chint32		m_numCells;
		chint32		m_lFrameRate;
		chint32		m_lTicksPerFrame; // hundredths of a millisec
		chint32		m_lLastTick;
		bool		m_boolFrozen;
		bool		m_boolVisible;
		bool		m_boolDraggable;
		int			m_version;   // for serializing
		chint32		m_iNumSpriteRows, m_iNumSpriteCols;	// stash while loading
		chuint32	m_id;
		ChAnimAnchor *m_pAnchor;
		ChAnimView *m_pView;
		string 		m_strName;
		void SetId(chuint32 luId) { m_id = luId; };
		inline void SetName(string& strName) {  m_strName = strName; };
};


inline void ChPtrSplayDestruct( ChAnimAnchor* pAnchor )
{
	delete pAnchor;
}


class ChAnimView : public ChGraphicView
{
	CH_FRIEND_MESSAGE_HANDLER( animatorLoadCompleteHandler );
	protected: 


	public:
	    ChAnimView( ChGraphicMainInfo *pInfo );
	    virtual ~ChAnimView();

	public:
		bool Create( const CRect& rtView, CWnd* pParent,
						DWORD dwStyle = WS_VISIBLE | WS_VSCROLL | WS_BORDER,
						UINT uiID = 0 );

		ChDibBmp* GetDIB() {return m_pDIB;}
		BOOL Create(ChDibBmp* pDIB);            // Create a new buffer.
		virtual void OnInitialUpdate(); // First time after construction.
 		virtual void Draw(CDC* pDC = NULL, 
              RECT* pClipRect = NULL);  // Draw off-screen buffer to screen.

		virtual void Render(CRect* pClipRect=0);

		bool LoadBackground( const string & strURL ); 
		bool LoadBackgroundJPEG( const string & strURL ); 
		bool LoadBackgroundGIF( const string & strURL );
		bool LoadBackground( chuint16 suResId );      

		ChDibBmp* GetBackground() {return m_pDibBkgnd;}
		inline CSpriteList* GetSpriteList() {return &m_spriteList;}
		bool LoadCharacter( ChArchive& ar );	// module should expose
		bool LoadAnchor( ChArchive& ar );	// module should expose
		bool LoadCharacterScript( chuint32 luId, ChArchive& ar );	// module should expose
		ChAnimView* DeleteCharacter( chuint32 luId );	// module should expose
		bool AddAnchor( ChAnimAnchor* pAnchor, bool boolPutInPending = true );	// module should expose
		bool DeleteAnchor( const chuint32 luId );	// module should expose
		bool DeleteAnchors( void );	// module should expose
		ChAnimView* AnimateCharacter( chuint32 luId, bool boolRun = true );	// module should expose
		ChAnimView* ShowCharacter( chuint32 luId, bool boolShow = true);	// module should expose
		virtual void Animate( bool boolRun );			// module should expose
		bool IsAnimating() const;
		void OnTick();							// called by system timer mgr (to be defined)
		void AddCharacter(ChAnimCastMember * pChar);	 // prob internal only for now
		ChAnimCastMember * FindChar(chuint32 luId);
		void ChAnimView::NewSprite(CSprite* pSprite);
    	inline BOOL Insert(CSprite* pSprite) { return m_spriteList.Insert( pSprite ); };
    	inline CSprite *Remove(CSprite* pSprite) { return m_spriteList.Remove( pSprite ); };
		inline void SetCmdHookMgr( ChHookManager *pHookMgr ) {m_pHookMgr = pHookMgr;};
		inline ChHookManager *GetCmdHookMgr( ) { return m_pHookMgr; };
	    void AddDirtyRegion(CRect* pRect);
	    void RenderAndDrawDirtyList();

											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChMazeWnd)
		protected:
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		//}}AFX_VIRTUAL
	public:

	protected: 
	    ChDibBmp* m_pDIB;           // The DIB buffer.

	    BITMAPINFO* m_pOneToOneClrTab;  // Pointer to 1-to-1 color table
	    BOOL m_bUseCreateDIBSection;    // Flag
	    CDSPROC* m_pCDSProc;            // Pointer to CreateDIBSection
	    HBITMAP m_hbmSection;           // Bitmap from section
	    CObList m_DirtyList;            // Dirty regions

		bool	m_boolBackgroundDirty;
	    void EmptyDirtyList();

		bool	m_boolCenterIt;
	    ChDibBmp *m_pDibBkgnd;
		bool NewBackground(ChDibBmp* pDIB);
		bool DeferredNewBackground();
		ChHookManager	*m_pHookMgr;

		ChPtrList<ChAnimCastMember> m_characters;


		// m_Anchors has to be fast on walks, but also ought to be a list
		// or tree (by id). Splay trees will work because walk is done
		// usually on OnSetCursor; last anchor hit is highly probable this
		// time.
		
		ChPtrSplay<ChAnimAnchor> m_Anchors;
		chuint32	m_anchorId;		// last anchor with hint displayed

		// Anchors waiting for characters
		ChPtrList<ChAnimAnchor>	*m_pCastAnchors;

		//class ChAnchorHitTest - tests for hits in rectangular anchors
		class ChAnchorHitTest : public ChPtrSplayVisitor2<ChAnimAnchor>
		{
			protected:
				CPoint 	m_pt;
				ChAnimAnchor *m_pHit;

			public:
				ChAnchorHitTest( const CPoint & pt ) :  m_pt(pt), m_pHit(0) { };
				ChAnchorHitTest( ) :  m_pt(0), m_pHit(0) { };

				bool Visit( chuint32 key, const  ChAnimAnchor* pAnchor )
						{
							if (pAnchor->HitTest(m_pt))
							{	
								m_pHit = (ChAnimAnchor*)pAnchor;
								return false;
							} 
							return true;
						}
				inline ChAnimAnchor * GetHit() { return m_pHit; }
				void Initialize( const CPoint & pt )
					{
						m_pt = pt;
						m_pHit = 0;
					}
		};

		ChAnchorHitTest m_HitFinder;
		ChAnimAnchor *FindAnchor( const CPoint & pt );

		CSpriteList m_spriteList;			  // currently active sprites
	    UINT m_uiTimer;                 // timer id
		#define MAX_CURSOR_COUNT	10
		HCURSOR m_cursors[MAX_CURSOR_COUNT];	   // temporary; make it work first !!!!
		chuint m_cursorId;

		inline HCURSOR GetCursor(chuint32 lCursor) { return m_cursors[lCursor]; };
		BOOL SetCursor( POINT& pointInClient );
	    void LoadAnchors(const string& strFilename);
		void UpdateAnchorList();

// Generated message map functions
protected:
    //{{AFX_MSG(ChAnimView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

	#if 0
	// these are used for moving the background dib
	protected: 
	    BOOL m_bInPlace;
	public:
		BOOL IsInPlace() {return m_bInPlace;}
	    int m_iBkgndPos;
		int GetBkgndPos() {return m_iBkgndPos;}
		void SetBkgndPos(int iPos)
		    {m_iBkgndPos = iPos;}

	#endif
};

#endif  //( _CHANIM_H )
