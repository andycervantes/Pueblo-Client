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

	This file consists of the interface for the ChHtmlPageWnd class,
	used when we need to display HTML pages.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChHtmlPg.h,v 2.4 1996/02/22 01:44:36 coyote Exp $

#if !defined( _CHHTMLPG_H )
#define _CHHTMLPG_H

#if defined( CH_MSW )

	#include <afxwin.h>                                             // MFC core and std components
	#include <afxext.h>                                             // MFC extensions
	#include <afxdisp.h>                                    // MFC dispatchers

#endif  // CH_MSW

#include <ChHtmWnd.h>


/*----------------------------------------------------------------------------
	ChHtmlPageWnd class
----------------------------------------------------------------------------*/

class ChHtmlPageWnd : public ChHtmlWnd
{
	public:
		ChHtmlPageWnd();
		virtual ~ChHtmlPageWnd();

	protected:
		virtual void OnHotSpot( chparam userData, const string& strDocURL );

	protected:
											/* ClassWizard generated virtual
												function overrides */
		//{{AFX_VIRTUAL(ChHtmlPageWnd)
		//}}AFX_VIRTUAL

	#if !defined( CH_UNIX )

	protected:
		//{{AFX_MSG(ChHtmlPageWnd)
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()

	#endif  // !defined( CH_UNIX )
};


#endif  // !defined( _CHHTMLPG_H )
