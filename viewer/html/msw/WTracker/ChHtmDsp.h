/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##'##,     ,####""   .##'    `##.
        ###        ###########    ,##' `##,   ###       ####      ####
        ###..      ###'    ###  ,###########, ####..    `###,    ,##'
          `######  ###     ###  `##'     `##'   `######   `########'


	Copyright 1995, Chaco Communications, Inc. All rights reserved.
	Unpublished -- Rights reserved under the copyright laws of the United
	States.  Use of a copyright notice is precautionary only and does no
	imply publication or disclosure.

	This software contains confidential information and trade secrets of
	Chaco Communications, Inc.  Use, disclosure, or reproduction is
	prohibited without the prior express written permission of Chaco
	Communications, Inc.

	RESTRICTED RIGHTS LEGEND

	Use, duplication, or disclosure by the Government is subject to
	restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
	Technical Data and Computer Software clause at DFARS 252.227-7013.

	Chaco Communications, Inc.
	10164 Parkwood Drive, Suite 8, Cupertino, CA, 95014-1533

------------------------------------------------------------------------------

	Interface for the ChTextOutputBar class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/viewer/html/msw/WTracker/ChHtmDsp.h,v 1.2 1996/04/04 08:11:26 pritham Exp $

#if !defined( _CHTXTOUT_H )
#define _CHTXTOUT_H

#include <ChHtmWnd.h>

#define HTML_OUT_PANE		0




/*----------------------------------------------------------------------------
	HTML history list
----------------------------------------------------------------------------*/
class ChHTMLHistory
{
	public :
		ChHTMLHistory( const string& strURL, const string& strFile, 
								const string& strMimeType, bool bbTmpFile = false ) :
								m_strURL( strURL ), m_strFile( strFile ), 
								m_strMimeType( strMimeType ),
								m_boolTmpFile( bbTmpFile )
		{																				 
		}
		~ChHTMLHistory()
		{
			if ( m_boolTmpFile )
			{
				::DeleteFile( m_strFile );
			}
		}

		void GetHistory( string& strURL, string& strFile, string& strMimeType )
			{
				strURL = m_strURL;
				strFile = m_strFile;
				strMimeType = m_strMimeType;
			}
		const string& GetURL( ) { return m_strURL; }

	private :
		string m_strFile;
		string m_strURL;
		string m_strMimeType;
		bool   m_boolTmpFile;
};




/*----------------------------------------------------------------------------
	ChBrowserWnd class
----------------------------------------------------------------------------*/

class ChBrowserWnd : public ChHtmlWnd
{

	public:
		ChBrowserWnd( ChHTTPConn *pConn );

		#ifndef CH_UNIX
		inline bool IsValid() { return (0 != m_hWnd); }
		#endif
		void	LoadURL( const string& strURL, chuint32 flOptions = 0  );
		const string& 	GetHomePage()	{ return m_strHomePage; } 
		void    AbortRequests( );

		const string& GetFilename()		{ return m_strFile; }

		int		GetHistoryCount()	
						{ 
							return m_urlList.GetCount(); 
						}
		ChParamList* GetHistoryList()	
						{ 
							return &m_urlList;
						}
		void    GoForward();
		bool    CanGoForward()		
					{ 
							return ( m_listPos && 	
										m_listPos != m_urlList.GetTailPosition() );
					}
		void    GoBackward();
		bool    CanGoBackward()		
					{ 
							return ( m_listPos && 	
										m_listPos != m_urlList.GetHeadPosition() );
					}
		inline const string& GetPendingRequest()		{ return m_strPendingRequest; }

	protected:
											/* ClassWizard generated virtual
												function overrides */
	//{{AFX_VIRTUAL(ChBrowserWnd)
	//}}AFX_VIRTUAL
		virtual  void OnHotSpot( chparam userData,
								const string& strDocURL  );

		virtual void OnLoadComplete( const string& strFile, const string& strURL, 
											const string& strMimeType,
											chparam userData );
		virtual void OnLoadError( chint32 lError, const string& strErrMsg, 
								const string& strURL,	chparam userData );

											// Implementation
	public:
		virtual ~ChBrowserWnd();

	private :
	void UpdateFrameOnLoad( const string& strURL, const string& strFile );



	private :
		string		m_strFile;
		ChParamList m_urlList;
		ChPosition	m_listPos;
		string 		m_strHomePage;
		string 		m_strPendingRequest;
	protected:

#ifndef CH_UNIX    
	protected:
		//{{AFX_MSG(ChBrowserWnd)
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
#endif
};


#endif	// !defined( _CHTXTOUT_H )
