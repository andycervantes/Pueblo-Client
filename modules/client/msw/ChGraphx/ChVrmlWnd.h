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

	Interface for the ChPuebloVrmlWnd class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlWnd.h,v 2.6 1996/09/26 02:07:03 pritham Exp $

#if !defined( _CHVRMLWND_H )
#define _CHVRMLWND_H

#include "ChMaze.h"



/*----------------------------------------------------------------------------
	ChPuebloVrmlWnd class
----------------------------------------------------------------------------*/

class ChPuebloVrmlWnd : public ChMazeWnd
{
	protected:

 	public:

		#ifndef CH_UNIX
		inline bool IsValid() { return (0 != m_hWnd); }
		#endif
		
	#if 0
		virtual  void OnHotSpot( chparam userData,
								const string& strDocURL  );
		virtual  void  OnUpdateProgress( UINT uMsgID  );
	#endif
											// Implementation
	public:
		ChPuebloVrmlWnd(ChMazeMainInfo *pInfo, ChVrmlSettings *pSettings );

		virtual ~ChPuebloVrmlWnd();

		virtual bool OnCameraChange(ChCameraChange efChanged);
		virtual void OnError( chuint32 luErrorCode, const string& strMsg, int iType  );

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChPuebloVrmlWnd)
		afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
		
		afx_msg BOOL OnEraseBkgnd(CDC* pDC);
		afx_msg void OnKillFocus(CWnd* pNewWnd);
		afx_msg void OnSetFocus(CWnd* pOldWnd);
		afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

		DECLARE_MESSAGE_MAP()

};



#endif	// !defined( _CHVRMLWND_H )
