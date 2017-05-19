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

	This file consists of the implementation of the ChGraphicHTTPReq class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChGrDep.cpp,v 2.16 1996/05/15 23:55:56 pritham Exp $

#include "grheader.h"
////#include <QvDB.h>
//#include <QvInput.h>
//#include <QvNode.h>
//#include <QvState.h>

//#include <fstream.h>
//#include "ChGrMod.h"
#include "ChGrDep.h"
//#include "ChMaze.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif


ChGraphicHTTPReq::~ChGraphicHTTPReq()
{
//TRACE0("~ChGraphicHTTPReq()");
	if (m_parent) m_parent->Delete(this);
}

void ChGraphicHTTPReq::Add( ChGraphicHTTPReq *pDependency )
{
	m_dependencies.AddTail(pDependency);
	pDependency->AddParent(this);
}

void ChGraphicHTTPReq::Delete( ChGraphicHTTPReq *pDependency )
{
	ChPosition pos = m_dependencies.Find(pDependency);
	m_dependencies.Remove(pos);

	if (pos && m_dependencies.IsEmpty())
	{
		OnEmpty();
	}
}

void ChGraphicHTTPReq::OnEmpty()
{
	if(m_parent)
	{
		m_parent->Delete(this);
		m_parent = 0;
	}

	delete this;
};

void ChGraphicHTTPReq::AddParent( ChGraphicHTTPReq *pDependency )
{
	m_parent = pDependency;
}

// ChGraphicBackgroundHTTPReq

ChGraphicBackgroundHTTPReq::~ChGraphicBackgroundHTTPReq()
{
	m_parent = 0;
	while(!m_parents.IsEmpty())
	{
		ChGraphicHTTPReq *pParent = m_parents.RemoveHead();
		pParent->Delete(this);
	}
}

void ChGraphicBackgroundHTTPReq::AddParent( ChGraphicHTTPReq *pDependency )
{
	m_parent = pDependency;	// last one added - not really used
	m_parents.AddTail(pDependency);
}

// ChGraphicSceneHTTPReq

ChGraphicSceneHTTPReq::~ChGraphicSceneHTTPReq()
{
	m_parent = 0;
	while(!m_parents.IsEmpty())
	{
		ChGraphicHTTPReq *pParent = m_parents.RemoveHead();
		pParent->Delete(this);
	}
}

void ChGraphicSceneHTTPReq::AddParent( ChGraphicHTTPReq *pDependency )
{
	m_parent = pDependency;	// last one added - not really used
	m_parents.AddTail(pDependency);
}


void ChGraphicSceneHTTPReq::OnEmpty()
{

	if(m_parent)
	{
		m_parent->Delete(this);
	}
	m_parent = 0;
	delete this;
}

// ChGraphicDocumentHTTPReq

ChGraphicDocumentHTTPReq::~ChGraphicDocumentHTTPReq()
{
	m_parent = 0;
	while(!m_parents.IsEmpty())
	{
		ChGraphicHTTPReq *pParent = m_parents.RemoveHead();
		pParent->Delete(this);
	}
	CancelCommands();
}

void ChGraphicDocumentHTTPReq::AddParent( ChGraphicHTTPReq *pDependency )
{
	m_parent = pDependency;	// last one added - not really used
	m_parents.AddTail(pDependency);
}


void ChGraphicDocumentHTTPReq::OnEmpty()
{

	if(m_parent)
	{
		m_parent->Delete(this);
	}
	m_parent = 0;
	delete this;
}

ChGraphicDocumentHTTPReq* ChGraphicDocumentHTTPReq::AddCommand(string& strCmd)
{
	// MFC uses a static buffer of 512 bytes, commands can be > 512 bytes sometimes
	
//	TRACE1("AddCommand: %s\n", strCmd);

	if (!m_pCommandQ)
	{
		//m_pCommandQ = new ChList<string>;
		m_pCommandQ = new ChStrList;
	}

	if (m_pCommandQ)
	{
		m_pCommandQ->AddTail( strCmd );
	}

	return this;
}

ChGraphicDocumentHTTPReq* ChGraphicDocumentHTTPReq::CancelCommands()
{
	if(m_pCommandQ)
	{
		string strCmd;

		while (!m_pCommandQ->IsEmpty())
		{
			strCmd = m_pCommandQ->RemoveHead();
		}

		delete m_pCommandQ;
		m_pCommandQ = 0;
	}
	return this;
}


ChGraphicDocumentHTTPReq*
ChGraphicDocumentHTTPReq::SetFile( string & strURL, string &filename,
									string &mimetype )
{
	if (strURL != "")
	{
		m_strURL = strURL;		// fix it in case it changed
	}
	m_strFilename = filename;
	m_strType = mimetype;

	return this;
}

ChGraphicDocumentHTTPReq* ChGraphicDocumentHTTPReq::SetNotificationOption(string strOption)
{
	m_notificationOption = noNotification;
	if(strOption.IsEmpty()) 
	{
		return this;
	}
	string arg;
	char * pA = arg.GetBuffer(200);
	int n = 0;
	if(sscanf(LPCTSTR(strOption) + n, "%s%n", pA, &n) > 0)
	{
		if(arg.IsEmpty()) 
		{
			return this;
		}
		if(!(arg.CompareNoCase("requested"))) m_notificationOption = m_notificationOption | requested;
		else if(!(arg.CompareNoCase("parsed"))) m_notificationOption |= parsed;
		else if(!(arg.CompareNoCase("progress"))) m_notificationOption |= progress;
		else if(!(arg.CompareNoCase("received"))) m_notificationOption |= received;
		else if(!(arg.CompareNoCase("rendered"))) m_notificationOption |= rendered;
	}
	return this;
}
