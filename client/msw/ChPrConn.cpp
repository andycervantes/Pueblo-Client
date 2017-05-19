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

	This file contains the implementation of the ChPrefsConnPage class,
	which manages connection preferences.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/client/msw/ChPrConn.cpp,v 2.9 1996/04/19 00:33:25 coyote Exp $

#include "headers.h"

#include <ChReg.h>

#include "ChClCore.h"
#include "ChPrConn.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


/*----------------------------------------------------------------------------
	ChPrefsConnPage class
----------------------------------------------------------------------------*/

IMPLEMENT_DYNCREATE( ChPrefsConnPage, ChPropertyPage )


ChPrefsConnPage::ChPrefsConnPage() :
					ChPropertyPage( ChPrefsConnPage::IDD, 0, hInstApp ),
					m_reg( CH_CONNECTION_GROUP ),
					m_boolInitialized( false )
{
	//{{AFX_DATA_INIT(ChPrefsConnPage)
	//}}AFX_DATA_INIT
}


ChPrefsConnPage::~ChPrefsConnPage()
{
}


bool ChPrefsConnPage::OnSetActive()
{
	bool	boolResult;

	boolResult = ChPropertyPage::OnSetActive();

	if (!m_boolInitialized)
	{
		CEdit		*pEdit;
		char		strPort[10];

		m_reg.Read( CH_CONNECTION_HOST, m_strHost, CH_CONNECTION_HOST_DEF );
		m_reg.Read( CH_CONNECTION_PORT, m_sPort, CH_CONNECTION_PORT_DEF );

												// Set the host name

		pEdit = (CEdit *)GetDlgItem( IDC_CONN_EDIT_ADDRESS );
		pEdit->SetWindowText( m_strHost );
												// Set the port

		pEdit = (CEdit *)GetDlgItem( IDC_CONN_EDIT_PORT );

		sprintf( strPort, "%hd", m_sPort );
		pEdit->SetWindowText( strPort );
											/* Set the initialized flag so
												that we don't do this again */
		m_boolInitialized = true;
	}

	return boolResult;
}


void ChPrefsConnPage::OnCommit()
{
	if (m_boolInitialized)
	{
		CEdit		*pEdit;
		string		strNewHost;
		string		strPort;
		chint16		sNewPort;
		bool		boolChanged = false;
											// Get the host name

		pEdit = (CEdit *)GetDlgItem( IDC_CONN_EDIT_ADDRESS );
		pEdit->GetWindowText( strNewHost );

		if (strNewHost != m_strHost)
		{
			m_reg.Write( CH_CONNECTION_HOST, strNewHost );
			boolChanged = true;
		}
											// Get the port

		pEdit = (CEdit *)GetDlgItem( IDC_CONN_EDIT_PORT );

		pEdit->GetWindowText( strPort );
		sNewPort = atoi( strPort );

		if (sNewPort != m_sPort)
		{
			m_reg.Write( CH_CONNECTION_PORT, sNewPort );
			boolChanged = true;
		}

		if (boolChanged)
		{
//			ChClientCore::GetCore()->ResetServerInfo();
		}
	}     
}


BEGIN_MESSAGE_MAP( ChPrefsConnPage, ChPropertyPage )
	//{{AFX_MSG_MAP(ChPrefsConnPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/*----------------------------------------------------------------------------
	ChPrefsConnPage message handlers
----------------------------------------------------------------------------*/

