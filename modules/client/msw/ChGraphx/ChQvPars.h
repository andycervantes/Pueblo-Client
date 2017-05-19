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

	Implementation for the ChParseInfo class, which is used to display VRML.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChQvPars.h,v 1.4 1996/04/15 20:27:52 pritham Exp $
#if !defined( _CH_QVPARS_H )
#define  _CH_QVPARS_H

#include <QvDB.h>
#include <QvNode.h>

class ChMazeWnd;

class ChParseInfo
{
	public :
		enum tagSize{ minFileSize = 0x7FFF };
		enum tagFileType { typeUnknown = 0, typeScene, typeWWWInline };
		enum tagState { stateInit = 1, stateInQVParse, stateDone, stateAbort };

		ChParseInfo( ChMazeWnd* pWnd, const string strURL, const string& strFileName );
		~ChParseInfo( );


		void	Abort( )		
					{ 
						m_boolCancel = true;
						m_in.Abort();
				 	} 
		// Attributes
		int  	 GetType()		{ return m_iType; }
		int		 GetState()		{ return m_iState; }
		string&  GetURL()		{ return m_strURL; }
		QvNode*& GetQVNode()	{ return m_pRoot; }
		QvInput* GetStream()	{ return &m_in; }
		ChMazeWnd* GetWnd()		{ return m_pWnd; }
		bool GetParseResult()	{ return m_boolParseResult; }
		bool IsCanceled()		{ return m_boolCancel; }	
		  
		void SetState( int iState )			 { m_iState = iState; }
		void SetParseResult( bool boolResult ) { m_boolParseResult = boolResult; }
		
		void* GetUserData()					{ return m_pUserData; }
		void  SetUserData( void * pData )	{ m_pUserData = pData; }
		void* GetUserData2()					{ return m_pUserData2; }
		void  SetUserData2( void * pData )	{ m_pUserData2 = pData; }

		// Methods
		bool ParseVrmlFile( int iType );

	private :
		int					m_iType;
		int					m_iState;
		ChQvFileMapInput	m_in;
		bool				m_boolCancel;
		bool				m_boolParseResult;
		QvNode*				m_pRoot;
		ChMazeWnd* 			m_pWnd;
		string				m_strURL;
		string				m_strFile;
		void*				m_pUserData;
		void*				m_pUserData2;
};

#endif //#if !defined( _CH_QVPARS_H )
