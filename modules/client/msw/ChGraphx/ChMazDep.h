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

	Interface for the Animation HTTP and load request classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChMazDep.h,v 2.24 1996/09/26 02:07:01 pritham Exp $

#include "grheader.h"
#if !defined( _CHMAZDEP_H )
#define _CHMAZDEP_H

#include "ChGrDep.h"
#include "ChMaze.h"                            

#if !defined( NO_TEMPLATES ) 


#else
#include <TemplCls\ChStrLst.h>
#include <TemplCls\ChStrLst.inl>

#endif

/* Graphics modules base HTTP and load request classes, along with dependency tracking */

class ChMazeHTTPReq : public ChGraphicHTTPReq
{

	public:

		ChMazeHTTPReq( type aType, ChMazeWnd * pView, const string& strURL) :
			 ChGraphicHTTPReq(aType, pView, strURL)
				{ 
					//TRACE0("ChAnimHTTPReq()"); 
				}

		virtual ~ChMazeHTTPReq();

	public:

	protected:
};

class ChMazeStartHTTPReq : public 	ChGraphicStartHTTPReq
{
		 
	public:
		ChMazeStartHTTPReq(  ChMazeWnd * pView, const string& strURL) :
			ChGraphicStartHTTPReq( pView, strURL )
			{ };

};
											// Request to load scene

class ChMazeSceneHTTPReq : public 	ChGraphicSceneHTTPReq
{
	protected:
		//ChList<string> *m_pCommandQ;	// pending commands for this scene
		ChMazeMainInfo* m_pInfo;
		QvNode *m_pRoot;
	public:
		ChMazeSceneHTTPReq( ChGraphicView * pView, const string& strURL );
		virtual ~ChMazeSceneHTTPReq();

		//ChMazeSceneHTTPReq* Spawn(ChMazeMainInfo* pMainInfo);
		inline ChMazeMainInfo *GetInfo() { return m_pInfo;};
		inline ChMazeWnd *  GetView() {return (ChMazeWnd *)m_pView;}

};

class QvTexture2;

/* request to load texture */
class ChMazeTextureHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		ChMazeMainInfo		*m_pInfo;
		QvNode 				*m_pTextureNode;		   // who to fill in when loaded - could be texture2 or bginfo
		int					m_iMimeType;		// Type of texture
		chuint 				m_uOption;
		void*				m_hTexture;


	public:

		enum tagOptions { textureShrink = 0x01, textureExpand = 0x02,
						  textureCrop = 0x04, textureChromaKey = 0x08,
						  textureAutoSize = 0x10, textureKeepSize = 0x20 };

		ChMazeTextureHTTPReq(  ChGraphicView * pView, const string& strURL, QvNode *pTextureNode, chuint uOption = 0) :
			ChGraphicHTTPReq(texture, pView, strURL), m_pInfo(0), m_pTextureNode(pTextureNode), m_uOption(uOption)
			{ 
				// Use the node so that I am around till the request
				// is handled
				m_pTextureNode ? m_pTextureNode->Use() : 0;
			};
		virtual ~ChMazeTextureHTTPReq() 
				{
					// Done with the node
					m_pTextureNode ? m_pTextureNode->Release() : 0;
				};

		//bool Load( const string& strFilename, void* pData );
		

		int	 GetTextureType()				{ return  m_iMimeType; }
		void SetTextureType( int iType )	{ m_iMimeType = iType; }
		inline void* GetTextureHandle()			{ return  m_hTexture; }
		inline void SetTextureHandle( void*  hTexture ) { m_hTexture = hTexture; }
		inline ChMazeWnd *  GetView() {return (ChMazeWnd *)m_pView;}
		inline chuint  GetOption() {return m_uOption;}
		inline QvNode* GetTextureNode() {return m_pTextureNode;}


};

class QvWWWInline;
/* request to load inline */
class ChMazeInlineHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		ChMazeMainInfo		*m_pInfo;
		QvWWWInline 		*m_pInlineNode;			// who to fill in when loaded
		int					m_iMimeType;				// Type of file - oughta be wrl

	public:


		ChMazeInlineHTTPReq(  ChGraphicView * pView, const string& strURL, QvWWWInline *pInlineNode) :
			ChGraphicHTTPReq(wwwInline, pView, strURL), m_pInfo(0), m_pInlineNode(pInlineNode)
			{ };
		virtual ~ChMazeInlineHTTPReq() {};

		//bool Load(string& strFilename, string& strURL, ChMazeMainInfo* pInfo);
		


		int	 GetFileType()				{ return  m_iMimeType; }
		void SetFileType( int iType )	{ m_iMimeType = iType; }
 		inline ChMazeWnd *  GetView() {return (ChMazeWnd *)m_pView;}
		inline QvWWWInline * GetInlineNode() { return m_pInlineNode; }
		inline void SetInlineNode(QvWWWInline * pNode) { m_pInlineNode = pNode; }

};


#endif
