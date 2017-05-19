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

	This file contains the implementation of the ChPrConn preferences page,
	which manages connection preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChPrConn.h,v 2.4 1996/02/24 05:35:41 coyote Exp $

#include <ChReg.h>
#include <ChPage.h>


/*----------------------------------------------------------------------------
	ChPrefsConnPage class
----------------------------------------------------------------------------*/

class ChPrefsConnPage : public ChPropertyPage
{
	DECLARE_DYNCREATE( ChPrefsConnPage )

	public:
		ChPrefsConnPage();
		~ChPrefsConnPage();
											// Overrides
		virtual bool OnSetActive();
		virtual void OnCommit();
											// Dialog Data
		//{{AFX_DATA(ChPrefsConnPage)
		enum { IDD = IDD_PREF_SERVER };
		//}}AFX_DATA
											/* ClassWizard generate virtual
												function overrides */
		//{{AFX_VIRTUAL(ChPrefsConnPage)
		//}}AFX_VIRTUAL

	protected:
											// Generated message map functions
		//{{AFX_MSG(ChPrefsConnPage)
		// NOTE: the ClassWizard will add member functions here
		//}}AFX_MSG

	protected:
		bool		m_boolInitialized;
		string		m_strHost;
		chint16		m_sPort;
		ChRegistry	m_reg;
	
	DECLARE_MESSAGE_MAP()
};
