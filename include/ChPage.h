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

	This file consists of the interface for the ChPropertyPage class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChPage.h,v 2.3 1996/09/12 18:16:52 pritham Exp $

#if (!defined( _CHPAGE_H ))
#define _CHPAGE_H

#include <ChTypes.h>


#if defined( CH_MSW )

#if !defined( CH_PUEBLO_PLUGIN )

#pragma warning( disable:4275 )

/*----------------------------------------------------------------------------
	ChPropertyPage class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC( ChPropertyPage )

	public:
		ChPropertyPage( unsigned int idTemplate, unsigned int idCaption = 0,
						HINSTANCE hModule = 0 );
		virtual ~ChPropertyPage();

		virtual bool OnSetActive();			// called when this page gets the focus
		virtual bool OnKillActive();	    // perform validation here

		virtual void OnCommit() {}			/* called to commit data (this is
												a good time to save data to the
												registry */

	protected:
		HINSTANCE		m_hModule;
		HINSTANCE		m_hOldModule;
};

#endif  // !defined( CH_PUEBLO_PLUGIN )
#endif	// !defined( CH_MSW )
#endif	// !defined( _CHPAGE_H )
