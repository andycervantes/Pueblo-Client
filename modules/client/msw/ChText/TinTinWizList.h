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

	TinTin class linked list methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinWizList.h,v 2.2 1996/02/16 22:36:36 coyote Exp $

#if !defined( _TINTINWIZLIST_H )
#define _TINTINWIZLIST_H

#include "resource.h"


/*----------------------------------------------------------------------------
	TinTinWizList class
----------------------------------------------------------------------------*/

class TinTinWizList : public ChDialog
{
	public:
		TinTinWizList( CWnd* pParent = 0 );

											// Dialog Data
		//{{AFX_DATA(TinTinWizList)
		enum { IDD = IDD_TINTIN_WIZLIST };
		// NOTE: the ClassWizard will add data members here
		//}}AFX_DATA


											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(TinTinWizList)
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(TinTinWizList)
			// NOTE: the ClassWizard will add member functions here
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()
};


#endif	// !defined( _TINTINWIZLIST_H )
