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

#include "grheader.h"
#if !defined( _CHGRDEP_H )
#define _CHGRDEP_H

#include "ChGrType.h"
#include "ChGrVw.h"   

#include <ChList.h> 

class ChGraphicHTTPReq;
    

#if !defined( NO_TEMPLATES )
											/* Templete definition for request
												queue and connection list */
typedef ChPtrList<ChGraphicHTTPReq>	ChGraphicHTTPReqList;            
typedef ChList<string>		ChStrList;

#else 
#include "TemplCls/ChGrPLst.h"
#include <TemplCls\ChStrLst.h>
typedef ChPtrGraphicHTTPReq			ChGraphicHTTPReqList;            
#endif

//typedef chuint32	ChGraphicPageID;	   // for tracking current page

/* forward declarations */
class ChGraphicMainInfo;
class QvNode;

/* Graphics modules base HTTP and load request classes, along with dependency tracking */


class ChGraphicHTTPReq
{
	public:
	enum type {anchor = 1, background, cast, script, sprite, start, scene, document, texture, wwwInline};

	protected:
		ChGraphicView * m_pView;
		type m_type;
 		//ChPtrList<ChGraphicHTTPReq> m_dependencies;  
 		ChGraphicHTTPReqList        m_dependencies;
		string m_strURL;

		ChGraphicHTTPReq *m_parent;	  // parent depends on me
		virtual void AddParent( ChGraphicHTTPReq *pDependency );
 		bool			m_boolCancelled;
		ChGraphicPageID	m_idPage;

	public:

		ChGraphicHTTPReq( type aType, ChGraphicView * pView, const string& strURL) :
			m_pView(pView), m_type(aType), m_parent(0), m_strURL(strURL),
			m_boolCancelled(false)
				{ 
					//TRACE0("ChAnimHTTPReq()"); 
				}

		virtual ~ChGraphicHTTPReq();

		inline type GetType() {return m_type;}
		inline void *  GetView() {return m_pView;}
		virtual void Add( ChGraphicHTTPReq *pDependency );
		virtual void Delete( ChGraphicHTTPReq *pDependency );
		virtual void OnEmpty();

		inline string& GetURL() { return m_strURL; };
		virtual ChGraphicHTTPReq* Cancel(){m_boolCancelled = true; return this;};
		inline bool IsCancelled() {return m_boolCancelled;};
		inline ChGraphicPageID GetPage() { return m_idPage; }
		inline ChGraphicHTTPReq* SetPage(ChGraphicPageID idPage) { m_idPage = idPage; return this; }

};

class ChGraphicStartHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
		bool m_boolStartAnimating;
		bool m_boolOutstanding;
		 
	public:
		ChGraphicStartHTTPReq(  ChGraphicView * pView, const string& strURL) :
			ChGraphicHTTPReq( start, pView, strURL), m_boolOutstanding(false),
			m_boolStartAnimating(false)
			{ };

		#if 1
		virtual void OnEmpty()
		{
			if(IsOutstanding())
			{
				m_pView->Animate(m_boolStartAnimating);
				ClearAnimating();
			}
		}

		virtual void SetStartAnimating(bool boolPlay)
		{ 
			m_boolStartAnimating = boolPlay;
			m_boolOutstanding = true;
		};
		virtual inline void ClearAnimating()
		{ 
			m_boolOutstanding = false;
		};
		virtual bool GetStartAnimating() const { return m_boolStartAnimating; };
		virtual bool IsOutstanding() const { return m_boolOutstanding; };
		#endif
};

/* request to load background */
class ChGraphicBackgroundHTTPReq : public 	ChGraphicHTTPReq
{
	protected:
 		//ChPtrList<ChGraphicHTTPReq> m_parents;		 // yup, plural; we have many
 		ChGraphicHTTPReqList		  m_parents;
		
		virtual void AddParent( ChGraphicHTTPReq *pDependency );

	public:
		ChGraphicBackgroundHTTPReq(  ChGraphicView * pView, const string& strURL) :
			ChGraphicHTTPReq( background, pView, strURL)
			{ };
		virtual ~ChGraphicBackgroundHTTPReq();

};

/* request to load scene ; base class for viewers' scene classes*/
class ChGraphicSceneHTTPReq : public 	ChGraphicHTTPReq
{
	friend class ChGraphicPaneInfo;

	protected:
		ChGraphicHTTPReqList		m_parents;

		virtual void AddParent( ChGraphicHTTPReq *pDependency );

	public:
		ChGraphicSceneHTTPReq(  ChGraphicView * pView, const string& strURL) :
			ChGraphicHTTPReq( scene, pView, strURL)
			{ };
		virtual ~ChGraphicSceneHTTPReq();

		virtual void OnEmpty();
		virtual bool Load(string& strFilename, ChGraphicMainInfo* pInfo) { return true;};
};

/* request to load document ; used by pane mgr */

class ChGraphicDocumentHTTPReq : public ChGraphicHTTPReq
{
	friend class ChGraphicPaneInfo;

	public:
	enum NotificationOption { noNotification = 0, requested = 0x01, progress = 0x02, 
		received = 0x04, parsed = 0x08, rendered = 0x10 };

	public:
		ChGraphicDocumentHTTPReq(  ChModuleID idModule, const string& strURL) :
			ChGraphicHTTPReq( document, 0, strURL), m_pCommandQ(0), m_notificationOption(noNotification),
			m_idModule( idModule )
			{ };
		virtual ~ChGraphicDocumentHTTPReq();

		virtual void OnEmpty();
		ChGraphicDocumentHTTPReq* AddCommand(string& strCmd);
		ChGraphicDocumentHTTPReq* CancelCommands();
		ChGraphicDocumentHTTPReq* SetFile( string & strURL, string &filename,
											string &mimetype );

		inline ChModuleID GetModuleID() { return m_idModule; };
		inline string &GetFilename() 	{ return m_strFilename; };
		inline string &GetMimeType() 	{ return m_strType; };

		inline NotificationOption GetNotificationOption() { return NotificationOption(m_notificationOption);};
		inline ChGraphicDocumentHTTPReq* SetNotificationOption(NotificationOption option)
			{ 
				m_notificationOption = option;
				return this;
			};
		ChGraphicDocumentHTTPReq* SetNotificationOption(string strOption);
		inline ChStrList *GetCommandQueue() {return m_pCommandQ;};
		inline ChGraphicDocumentHTTPReq *SetCommandQueue(ChStrList *pQ)
			{ m_pCommandQ = pQ; return this;};

	protected:
		virtual void AddParent( ChGraphicHTTPReq *pDependency );

	protected:
		ChModuleID				m_idModule;
		ChGraphicHTTPReqList	m_parents;
		ChStrList*				m_pCommandQ;	// pending commands for this scene
		string					m_strFilename;	// Need to save in case suspended
		string					m_strType;		// mime type - Need to save in case suspended
		int						m_notificationOption;	// flags of NotificationOption's
};

#endif
