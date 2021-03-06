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

	This file consists of the interfaces for various classes derived
	from ChMsg.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChMsgTyp.h,v 2.51 1996/09/04 18:22:29 coyote Exp $

#if (!defined( _CHMSGTYP_H ))
#define _CHMSGTYP_H

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA
#endif

#include <ChTypes.h>
#include <ChMData.h>
#include <ChMsg.h>
#include <ChArch.h>
#include <ChTime.h>
#include <ChAcct.h>
#include <ChClInfo.h>


/*----------------------------------------------------------------------------
----Login management messages-------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChGreetingMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_GREETING		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChGreetingMsg : public ChMsg
{
	public:
		enum tagEvents { initialGreeting = 1, clientInfo, clientValid,
							clientInvalid, clientOutOfDate };

	public:
											/* Initial greeting
												(server -> client) */

		ChGreetingMsg( chint16 sEvent, chint32 lProtocolVersion ) :
			ChMsg( CH_MSG_GREETING, CH_VERS_GREETING, sEvent,
					lProtocolVersion )
				{
					ASSERT( initialGreeting == sEvent );
				}
											/* Client information greeting
												(client -> server) */
		ChGreetingMsg( chint16 sEvent ) :
			ChMsg( CH_MSG_GREETING, CH_VERS_GREETING, sEvent )
				{
					ASSERT( clientInfo == sEvent );

					ChArchive		archive( this, modeWrite );
					ChClientInfo	info( ChClientInfo::thisMachine );

					archive << info;
				}
											/* Client invalid greeting
												(server -> client) */

		ChGreetingMsg( chint16 sEvent, const char* pstrError ) :
			ChMsg( CH_MSG_GREETING, CH_VERS_GREETING, sEvent )
				{
					ASSERT( clientInvalid == sEvent );

					ChArchive		archive( this, modeWrite );
					string			strError( pstrError );

					if (pstrError)
					{
						strError = pstrError;
					}

					archive << strError;
				}
											/* Client out of date greeting
												(server -> client) */

		ChGreetingMsg( chint16 sEvent, bool boolCritical,
						const char* pstrDescription,
						const char* pstrURL, const string& strErrorMsg ) :
			ChMsg( CH_MSG_GREETING, CH_VERS_GREETING, sEvent, boolCritical )
				{
					ASSERT( clientOutOfDate == sEvent );
					ASSERT( 0 != pstrDescription );
					ASSERT( 0 != pstrURL );

					string			strDesc( pstrDescription );
					string			strURL( pstrURL );
					ChArchive		archive( this, modeWrite );

					archive << strURL << strDesc << strErrorMsg;
				}

		inline void GetParams( chint16& sEvent )
				{
					sEvent = (chint16)GetParam1();
				}

		inline void GetInfo( ChClientInfo& info )
				{
					ASSERT( clientInfo == (chint16)GetParam1() );

					ChArchive	archive( this, modeRead );

					archive >> info;
				}

		inline void GetError( string& strError )
				{
					ASSERT( clientInvalid == (chint16)GetParam1() );

					ChArchive	archive( this, modeRead );

					archive >> strError;
				}

		inline void GetProtocol( chint32& lVersion )
				{
					ASSERT( initialGreeting == (chint16)GetParam1() );

					lVersion = GetParam2();
				}

		inline void GetOutOfDateInfo( bool& boolCritical,
										string& strDescription,
										string& strURL, string& strErrorMsg )
				{
					ASSERT( clientOutOfDate == (chint16)GetParam1() );

					ChArchive	archive( this, modeRead );

					boolCritical = (bool)GetParam2();
					archive >> strURL >> strDescription >> strErrorMsg;
				}
};


/*----------------------------------------------------------------------------
	ChLoginMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_LOGIN		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLoginMsg : public ChMsg
{
	public:
		ChLoginMsg( string strUsername, string strPassword ) :
			ChMsg( CH_MSG_LOGIN, CH_VERS_LOGIN )
				{
					ChArchive	archive( this, modeWrite );
					archive << CH_PLATFORM;
					archive << strUsername << strPassword;
				}

		inline void GetParams( string& strPlatform, string &strUsername,
								string &strPassword )
				{
					ChArchive	archive( this, modeRead );

					archive >> strPlatform >> strUsername >> strPassword;
				}
};

/*----------------------------------------------------------------------------
	ChSproingMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_SPROING		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChSproingMsg : public ChMsg
{
	public:
		enum tagEvents { sproingEchoRequest, sproingEchoReply };
	
		ChSproingMsg( chint16 sEvent, chuint32 luSequence = 0 ) :
			ChMsg( CH_MSG_SPROING, CH_VERS_SPROING, sEvent, luSequence )
				{
					ChArchive	archive( this, modeWrite );
					ChTime		time = ChTime::GetCurrentTime();

					archive << time;
				}

		inline void GetParams( chint16& sEvent, ChTime& time, chuint32& luSequence )
				{
					ChArchive	archive( this, modeRead );

					archive >> time;
					sEvent = (chint16)GetParam1();
					luSequence = (chuint32)GetParam2();
				}
};

/*----------------------------------------------------------------------------
	ChRedirectMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_REDIRECT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChRedirectMsg : public ChMsg
{
	public:
	
		ChRedirectMsg( string strServer, chuint32 luPort ) :
			ChMsg( CH_MSG_REDIRECT, CH_VERS_REDIRECT )
				{
					ChArchive	archive( this, modeWrite );

					archive << strServer << luPort;
				}

		inline void GetParams( string& strServer, chuint32& luPort )
				{
					ChArchive	archive( this, modeRead );

					archive >> strServer;
					archive >> luPort;
				}
};


/*----------------------------------------------------------------------------
	ChNewAccountMsg class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChNewAccountMsg : public ChLoginMsg
{
	public:
		ChNewAccountMsg( string strUsername, string strPassword ) :
			ChLoginMsg( strUsername, strPassword )
				{
											// Override the message value

					SetMessage( CH_MSG_NEW_ACCOUNT );
				}
};


/*----------------------------------------------------------------------------
	ChAccountInfoMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_ACCOUNT_INFO		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChAccountInfoMsg : public ChMsg
{
	public:
		enum tagEvents { cancel, infoSupplied };

	public:
		ChAccountInfoMsg( chint16 sEvent ) :
			ChMsg( CH_MSG_ACCOUNT_INFO, CH_VERS_ACCOUNT_INFO, sEvent ) {}

		ChAccountInfoMsg( ChAccountInfo& info ) :
			ChMsg( CH_MSG_ACCOUNT_INFO, CH_VERS_ACCOUNT_INFO, infoSupplied )
				{
					ChArchive	archive( this, modeWrite );

					archive << info;
				}

		inline void GetParams( chint16& sEvent )
				{
					sEvent = (chint16)GetParam1();
				}

		inline void GetInfo( ChAccountInfo& info )
				{
					ASSERT( infoSupplied == (chint16)GetParam1() );

					ChArchive	archive( this, modeRead );

					archive >> info;
				}
};


/*----------------------------------------------------------------------------
	ChValidationMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_VALIDATION		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChValidationMsg : public ChMsg
{
	public:
		enum tagEvents { accountInvalid, accountValid, passwordInvalid,
							accountInUse, getInfo, unknownError };

	public:
		ChValidationMsg( chint16 sEvent, string *pstrError = 0 ) :
			ChMsg( CH_MSG_VALIDATION, CH_VERS_VALIDATION, sEvent )
				{
					string		strEmpty;
					ChArchive	archive( this, modeWrite );

					if (0 == pstrError)
					{
						pstrError = &strEmpty;
					}

					archive << *pstrError;
				}

		inline void GetParams( chint16& sEvent, string *pstrError = 0 )
				{
					sEvent = (chint16)GetParam1();

					if (pstrError)
					{
						ChArchive	archive( this, modeRead );

						archive >> *pstrError;
					}
				}
};


/*----------------------------------------------------------------------------
	ChUsageStatisticMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_USAGE_STATISTIC	((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChUsageStatisticMsg : public ChMsg
{
	public:
		enum tagEvents { worldConnect, worldEnhanced, worldDisconnect,
							adSelected, otherStatistic };

	public:
		ChUsageStatisticMsg( chint16 sEvent, ChTime time,
								string strHost, chint16 sPort ) :
			ChMsg( CH_MSG_USAGE_STATISTIC, CH_VERS_USAGE_STATISTIC, sEvent )
				{
					ChArchive	archive( this, modeWrite );

					archive << time << strHost << sPort;
				}

		ChUsageStatisticMsg( chint16 sEvent, ChTime time,
								string strParam ) :
			ChMsg( CH_MSG_USAGE_STATISTIC, CH_VERS_USAGE_STATISTIC, sEvent )
				{
					ChArchive	archive( this, modeWrite );
					chint16		sParam = 0;

					archive << time << strParam << sParam;
				}

		inline chint16 GetEvent()
				{
					return (chint16)GetParam1();
				}

		inline void GetParams( ChTime& time, string& strHost, chint16& sPort )
				{
					ChArchive	archive( this, modeRead );

					archive >> time >> strHost >> sPort;
				}

		inline void GetParams( ChTime& time, string& strParam )
				{
					ChArchive	archive( this, modeRead );

					archive >> time >> strParam;
				}
};


/*----------------------------------------------------------------------------
	ChInvalidWorldMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_INVALID_WORLD	((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChInvalidWorldMsg : public ChMsg
{
	public:
		ChInvalidWorldMsg( const string& strReason ) :
			ChMsg( CH_MSG_INVALID_WORLD, CH_VERS_INVALID_WORLD )
				{
					ChArchive	archive( this, modeWrite );

					archive << strReason;
				}

		inline void GetParams( string& strReason )
				{
					ChArchive	archive( this, modeRead );

					archive >> strReason;
				}
};


/*----------------------------------------------------------------------------
----Module management messages------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChInitMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_INIT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChInitMsg : public ChMsg
{
	public:
		ChInitMsg( const ChModuleID idModule,
					const string& strLoadParam,
					const ChModuleID idServerModule = 0 ) :
			ChMsg( CH_MSG_INIT, CH_VERS_INIT, idModule,
					idServerModule )
				{
					m_strLoadParam = strLoadParam;
				}

		inline void GetParams( ChModuleID& idModule,
								string& strLoadParam,
								ChModuleID& idServerModule )
				{
					GetParams( idModule, strLoadParam );
					idServerModule = GetParam2();
				}

		inline void GetParams( ChModuleID& idModule,
								string& strLoadParam )
				{
					idModule = GetParam1();
					strLoadParam = m_strLoadParam;
				}

	protected:
		string		m_strLoadParam;
};


/*----------------------------------------------------------------------------
	ChTermMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_TERM		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChTermMsg : public ChMsg
{
	public:
		ChTermMsg() : ChMsg( CH_MSG_TERM, CH_VERS_TERM ) {}
};


/*----------------------------------------------------------------------------
	ChLoadModuleMsg class -- Used to load a client module
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChLoadModuleMsg : public ChMsg
{
	public:
		enum tagType { requestToServer, requestToClient };

	public:
											/* GetParam1() is always the
												subtype of message... either a
												request to the server or a
												request to the client */
		#if defined( CH_CLIENT )
											/* This first constructor should
												only be used for messages to
												the server */

		ChLoadModuleMsg( const string& strModuleName,
							const string& strModuleBase,
							bool boolOptional,
							bool boolUseExisting,
							const string& strLoadParam = "" ) :
			ChMsg( CH_MSG_LOAD_MODULE, (ChVersion)0x00000000, requestToServer,
					MAKELONG( boolUseExisting, boolOptional ) )
				{
					string		strCombinedName( strModuleName );
					ChArchive	archive( this, modeWrite );

					strCombinedName += '\n';
					strCombinedName += strModuleBase;

					archive << strCombinedName;
					archive << strLoadParam;
				}

		#elif defined( CH_SERVER )
											/* These next constructors are for
												messages to the client (from
												the server) */

		ChLoadModuleMsg( ChModuleID idModule, const string& strModuleName,
							const string& strLibraryName,
							ChModuleID idServerModule,
							bool boolOptional,
							bool boolUseExisting = true,
							const string& strLoadParam = "" ) :
			ChMsg( CH_MSG_LOAD_MODULE, (ChVersion)0x00000000, requestToClient,
					MAKELONG( boolUseExisting, boolOptional ) )
				{
					ChArchive	archive( this, modeWrite );

					archive << idModule << strModuleName << strLibraryName <<
								idServerModule << strLoadParam;
				}

		ChLoadModuleMsg( ChModuleID idModule, const string& strModuleName,
							const string& strLibraryName,
							const string& strLoadParam = "",
							bool boolOptional = false,
							bool boolUseExisting = true ) :
			ChMsg( CH_MSG_LOAD_MODULE, (ChVersion)0x00000000, requestToClient,
					MAKELONG( boolUseExisting, boolOptional ) )
				{
					ChArchive	archive( this, modeWrite );
					ChModuleID	idServerModule = 0;

					archive << idModule << strModuleName << strLibraryName <<
								idServerModule << strLoadParam;
				}
		#endif
											/* This first method is used to
												read parameters for messages
												sent to the server to request
												that a module be loaded */

		inline void GetParams( string& strModuleName, string& strModuleBase,
								bool& boolOptional, bool& boolUseExisting )
				{
					ASSERT( GetParam1() == requestToServer );

					ChArchive	archive( this, modeRead );
					int			iDelimiter;

					archive >> strModuleName;

											// Disassemble string

					iDelimiter = strModuleName.Find( '\n' );
					if (-1 == iDelimiter)
					{
						strModuleBase = "";
					}
					else
					{
						strModuleBase = strModuleName.Mid( iDelimiter + 1 );
						strModuleName = strModuleName.Left( iDelimiter );
					}

					boolUseExisting = (bool)LOWORD( GetParam2() );
					boolOptional = (bool)HIWORD( GetParam2() );
				}
											/* These next methods are used to
												read parameters for messages
												sent to the client (from the
												server) to indicate that the
												client should start a module
												load process */

		inline void GetParams( ChModuleID& idModule, string& strModuleName,
								string& strLibraryName, string& strLoadParam,
								ChModuleID& idServerModule, bool& boolOptional,
								bool& boolUseExisting )
				{
					ASSERT( GetParam1() == requestToClient );

					GetParams( idModule, strModuleName, strLibraryName,
								strLoadParam, idServerModule, boolOptional );
					boolUseExisting = (bool)LOWORD( GetParam2() );
				}

		inline void GetParams( ChModuleID& idModule, string& strModuleName,
								string& strLibraryName, string& strLoadParam,
								bool& boolOptional, bool& boolUseExisting )
				{
					ASSERT( GetParam1() == requestToClient );

					GetParams( idModule, strModuleName, strLibraryName,
								strLoadParam, boolOptional );

					boolUseExisting = (bool)LOWORD( GetParam2() );
				}

		inline void GetParams( ChModuleID& idModule, string& strModuleName,
								string& strLibraryName,
								string& strLoadParam,
								ChModuleID& idServerModule,
								bool& boolOptional )
				{
					ASSERT( GetParam1() == requestToClient );

					ChArchive	archive( this, modeRead );

					archive >> idModule >> strModuleName >> strLibraryName >>
								idServerModule >> strLoadParam;

					boolOptional = (bool)HIWORD( GetParam2() );
				}

		inline void GetParams( ChModuleID& idModule, string& strModuleName,
								string& strLibraryName, string& strLoadParam,
								bool& boolOptional )
				{
					ASSERT( GetParam1() == requestToClient );

					ChArchive	archive( this, modeRead );
					ChModuleID	idServerModule;

					archive >> idModule >> strModuleName >> strLibraryName >>
								idServerModule >> strLoadParam;

					boolOptional = (bool)HIWORD( GetParam2() );
				}
};


/*----------------------------------------------------------------------------
	ChLogoutMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_LOGOUT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLogoutMsg : public ChMsg
{
	public:
		ChLogoutMsg() : ChMsg( CH_MSG_LOGOUT, CH_VERS_LOGOUT ) {}
};


/*----------------------------------------------------------------------------
	ChResetMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_RESET		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChResetMsg : public ChMsg
{
	public:
		ChResetMsg() :
				ChMsg( CH_MSG_RESET, CH_VERS_RESET )
			{
			}
};


/*----------------------------------------------------------------------------
	ChShowModuleMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_SHOW_MODULE		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChShowModuleMsg : public ChMsg
{
	public:
		ChShowModuleMsg( bool boolShow = true ) :
				ChMsg( CH_MSG_SHOW_MODULE, CH_VERS_SHOW_MODULE, boolShow )
			{
			}

		inline bool IsShowing() { return (bool)GetParam1(); }
};


/*----------------------------------------------------------------------------
	ChSetFocusMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_SET_FOCUS		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChSetFocusMsg : public ChMsg
{
	public:
		ChSetFocusMsg() : ChMsg( CH_MSG_SET_FOCUS, CH_VERS_SET_FOCUS ) {}
};


/*----------------------------------------------------------------------------
	ChCheckpointModuleMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_CHECKPOINT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChCheckpointModuleMsg : public ChMsg
{
	public:
		ChCheckpointModuleMsg() :
			ChMsg( CH_MSG_CHECKPT_MODULE, CH_VERS_CHECKPOINT )
				{
				}
};


/*----------------------------------------------------------------------------
	ChLoadFileMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_LOAD_FILE		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLoadFileMsg : public ChMsg
{
	public:
		ChLoadFileMsg( const string& strURL, const string& strFilename = "",
						const string& strType = "" ) :
			ChMsg( CH_MSG_LOAD_FILE )
				{
					ChArchive	archive( this, modeWrite );

					archive << strURL;
					archive << strFilename;
					archive << strType;
				}

		inline void GetParams( string& strURL )
				{
					ChArchive	archive( this, modeRead );

					archive >> strURL;
				}

		inline void GetParams( string& strURL, string &strFilename, string& strType )
				{
					ChArchive	archive( this, modeRead );

					archive >> strURL;
					archive >> strFilename;
					archive >> strType;
				}
};


/*----------------------------------------------------------------------------
	ChStatusMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_STATUS		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChStatusMsg : public ChMsg
{
	public:
		ChStatusMsg( const string& strStatus ) :
			ChMsg( CH_MSG_STATUS, CH_VERS_STATUS )
				{
					ChArchive	archive( this, modeWrite );

					archive << strStatus;
				}

		ChStatusMsg( const char* pstrStatus ) :
			ChMsg( CH_MSG_STATUS, CH_VERS_STATUS )
				{
					ChArchive	archive( this, modeWrite );
					string		strStatus( pstrStatus );

					archive << strStatus;
				}

		inline void GetParams( string &strStatus )
				{
					ChArchive	archive( this, modeRead );

					archive >> strStatus;
				}
};


/*----------------------------------------------------------------------------
----Page Management messages--------------------------------------------------
		These message manage the display of about and preferences pages.
----------------------------------------------------------------------------*/

typedef enum { pageAbout, pagePreferences } ChPageType;


/*----------------------------------------------------------------------------
	ChGetPageCountMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_GET_PAGE_COUNT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChGetPageCountMsg : public ChMsg
{
	public:
		ChGetPageCountMsg( ChPageType type ) :
				ChMsg( CH_MSG_GET_PAGE_COUNT, CH_VERS_GET_PAGE_COUNT,
						(chparam)type )
			{
			}

		inline void GetParams( ChPageType& type )
			{
				type = (ChPageType)GetParam1();
			}
};


/*----------------------------------------------------------------------------
	ChGetPagesMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_GET_PAGES		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChGetPagesMsg : public ChMsg
{
	public:
		ChGetPagesMsg( ChPageType type, chint16 sCount, chparam* pPages ) :
				ChMsg( CH_MSG_GET_PAGES, CH_VERS_GET_PAGES,
						(chparam)pPages )
			{
				SetParam2( MAKELONG( (chuint16)type, sCount ) );
			}

		inline void GetParams( ChPageType& type, chint16& sCount,
								chparam*& pPages )
			{
				chparam		param2 = GetParam2();

				pPages = (chparam*)GetParam1();
				type = (ChPageType)LOWORD( param2 );
				sCount = HIWORD( param2 );
			}
};


/*----------------------------------------------------------------------------
	ChGetPageDataMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_GET_PAGE_DATA		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChGetPageDataMsg : public ChMsg
{
	public:
		ChGetPageDataMsg( ChPageType type, chint16 sCount,
							chparam* pPages ) :
				ChMsg( CH_MSG_GET_PAGE_DATA, CH_VERS_GET_PAGE_DATA,
						(chparam)pPages )
			{
				SetParam2( MAKELONG( (chuint16)type, sCount ) );
			}

		inline void GetParams( ChPageType& type, chint16& sCount,
								chparam*& pPages )
			{
				chparam		param2 = GetParam2();

				pPages = (chparam*)GetParam1();
				type = (ChPageType)LOWORD( param2 );
				sCount = HIWORD( param2 );
			}
};


/*----------------------------------------------------------------------------
	ChReleasePagesMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_RELEASE_PAGES		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChReleasePagesMsg : public ChMsg
{
	public:
		ChReleasePagesMsg( ChPageType type, chint16 sCount,
							chparam* pPages ) :
				ChMsg( CH_MSG_RELEASE_PAGES, CH_VERS_RELEASE_PAGES,
						(chparam)pPages )
			{
				SetParam2( MAKELONG( (chuint16)type, sCount ) );
			}

		inline void GetParams( ChPageType& type, chint16& sCount,
								chparam*& pPages )
			{
				chparam		param2 = GetParam2();

				pPages = (chparam*)GetParam1();
				type = (ChPageType)LOWORD( param2 );
				sCount = HIWORD( param2 );
			}
};


/*----------------------------------------------------------------------------
----HTTP messages-------------------------------------------------------------
		The HTTP messages won't work when sent over the wire.  They are
		designed to only work when sent directly through a dispatcher.
----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
	ChLoadCompleteMsg class -- Used by HTTP to the client core, and also
								used to notify when a LoadClientModule
								operation completes.  In this case, the
								second constructor and GetParams method is
								used.
----------------------------------------------------------------------------*/

#define CH_VERS_LOAD_COMPLETE		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLoadCompleteMsg : public ChMsg
{
	public:
		ChLoadCompleteMsg( const string& strModuleName,
							const ChModuleID& idModule,
							const string& strFilename, chparam userData ) :
				ChMsg( CH_MSG_LOAD_COMPLETE, CH_VERS_LOAD_COMPLETE,
						(chparam)idModule, userData )
				{
					ChArchive	archive( this, modeWrite );

					archive << strModuleName << strFilename;
				}

		inline void GetParams( string& strModuleName, ChModuleID& idModule,
								string& strFilename, chparam& userData )
				{
					ChArchive	archive( this, modeRead );

					archive >> strModuleName >> strFilename;

					idModule = (ChModuleID)GetParam1();
					userData = GetParam2();
				}

	#if defined( CH_CLIENT )
											// Client-side only code
	public:
		ChLoadCompleteMsg( const string& strURL, const string& strFilename,
							const string& strType,
							chparam userData ) :
				ChMsg( CH_MSG_LOAD_COMPLETE, CH_VERS_LOAD_COMPLETE,
						0, userData ),
				m_strURL( strURL ),
				m_strType( strType ),
				m_pData(0 )
				{
					ChArchive	archive( this, modeWrite );
					string		strModuleName;

					archive << strModuleName << strFilename;
				}

		inline void GetParams( string& strURL, string& strFilename,
								chparam& userData )
				{
					ChArchive	archive( this, modeRead );
					string		strModuleName;

					archive >> strModuleName >> strFilename;

					strURL = m_strURL;
					userData = GetParam2();
				}

		inline const string& GetURL() const { return m_strURL; }
		inline const string& GetType() const { return m_strType; }
		inline const string& GetHTML() const { return m_strHTML; }
		inline void* GetNotifyData() const   { return m_pData; }

		inline void SetHTML( const string& strHTML ) { m_strHTML = strHTML; }
		inline void SetNotifyData( void* pData ) { m_pData = pData; }

	#endif	// defined( CH_CLIENT )

	protected:
		string		m_strURL;
		string		m_strHTML;
		string  	m_strType;
		void*		m_pData;
};


/*----------------------------------------------------------------------------
	ChLoadErrorMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_LOAD_ERROR		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLoadErrorMsg : public ChMsg
{
	public:
											/* These are load errors caused by
												results other than HTTP
												problems */

		enum tagErrors { errOptionalNotCached = 10 };

	public:
		ChLoadErrorMsg( const string& strModuleName,
						const ChModuleID& idModule,
						const string& strURL,
						chint32 lError, chparam userData ) :
				ChMsg( CH_MSG_LOAD_ERROR, CH_VERS_LOAD_ERROR,
						(chparam)lError, userData )
				{
					ChArchive	archive( this, modeWrite );

					archive << strModuleName << idModule << strURL << string("");
				}

		inline void GetParams( string& strModuleName, ChModuleID& idModule,
								string& strURL, chint32& lError,
								chparam& userData )
				{
					ChArchive	archive( this, modeRead );

					archive >> strModuleName >> idModule >> strURL;

					lError = (chint32)GetParam1();
					userData = GetParam2();
				}
		ChLoadErrorMsg( const string& strModuleName,
						const ChModuleID& idModule,
						const string& strURL,
						chint32 lError, chparam userData,
						const string& strErrorMsg  ) :
				ChMsg( CH_MSG_LOAD_ERROR, CH_VERS_LOAD_ERROR,
						(chparam)lError, userData )
				{
					ChArchive	archive( this, modeWrite );

					archive << strModuleName << idModule << strURL << strErrorMsg;
				}

		inline void GetParams( string& strModuleName, ChModuleID& idModule,
								string& strURL, chint32& lError,
								chparam& userData, string& strErrorMsg )
				{
					ChArchive	archive( this, modeRead );

					archive >> strModuleName >> idModule >> strURL >> strErrorMsg;

					lError = (chint32)GetParam1();
					userData = GetParam2();
				}
};


/*----------------------------------------------------------------------------
	ChLoadDataMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_LOAD_DATA		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChLoadDataMsg : public ChMsg
{
	public:
		ChLoadDataMsg( const string& strURL, ptr pData, chuint32 luSize,
						chuint32 luTotalSize, chparam userData ) :
				ChMsg( CH_MSG_LOAD_DATA, CH_VERS_LOAD_DATA,
						(chparam)pData, userData ),
				m_strURL( strURL ), m_luSize( luSize ),
				m_luTotalSize( luTotalSize ) {}

		inline void GetParams( string& strURL, ptr& pData, chuint32& luSize,
								chuint32& luTotalSize, chparam& userData )
				{
					strURL = m_strURL;
					luSize = GetDataSize();
					luTotalSize = GetTotalDataSize();
					pData = (ptr)GetParam1();
					userData = GetParam2();
				}

	protected:
		chuint32 GetDataSize() 		{ return m_luSize; }
		chuint32 GetTotalDataSize() { return m_luTotalSize; }
	private:
		string		m_strURL;
		chuint32	m_luSize;
		chuint32	m_luTotalSize;
};


#if defined( CH_MSW )

// make it unix -after- we define portabel rect and point types

/*----------------------------------------------------------------------------
	ChAnchorEventMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_ANCHOR_EVENT		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChAnchorEventMsg : public ChMsg
{
	public:
		ChAnchorEventMsg( chuint32 luId, const CPoint &point ) :
			ChMsg( CH_MSG_ANCHOR_EVENT, CH_VERS_ANCHOR_EVENT )
				{
					ChArchive	archive( this, modeWrite );

					SetParam1( luId );

					archive << chint32( point.x );
					archive << chint32( point.y );
				}

		ChAnchorEventMsg( chuint32 luId ) :
			ChMsg( CH_MSG_ANCHOR_EVENT, CH_VERS_ANCHOR_EVENT )
				{
					ChArchive	archive( this, modeWrite );

					SetParam1( luId );

					archive << chint32( 0 );
					archive << chint32( 0 );
				}

		inline void GetParams( chuint32& luId, CPoint &point )
				{
					ChArchive	archive( this, modeRead );
					chint32 	x, y;

					luId = (bool)GetParam1();

					archive >> x;
					archive >> y;

					point.x = (int)x;
					point.y = (int)y;
				}

		inline void GetParams( chuint32& luId )
				{
					luId = (bool)GetParam1();
				}
};

#endif


/*----------------------------------------------------------------------------
----Hook messages-------------------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChInstallHookMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_INSTALL_HOOK		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChInstallHookMsg : public ChMsg
{
	public:
		ChInstallHookMsg( const ChModuleID& idModule, chint32 lMessage ) :
				ChMsg( CH_MSG_INSTALL_HOOK, CH_VERS_INSTALL_HOOK, lMessage )
				{
					SetOriginModule( idModule );
				}

		inline void GetParams( ChModuleID& idModule, chint32& lMessage )
				{
					idModule = GetOriginModule();
					lMessage = GetParam1();
				}
};


/*----------------------------------------------------------------------------
	ChPromoteHookMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_PROMOTE_HOOK		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChPromoteHookMsg : public ChMsg
{
	public:
		ChPromoteHookMsg( const ChModuleID& idModule, bool boolPromote = true,
							chint32 lMessage = 0 ) :
				ChMsg( CH_MSG_PROMOTE_HOOK, CH_VERS_PROMOTE_HOOK, lMessage,
						boolPromote )
				{
					SetOriginModule( idModule );
				}

		inline void GetParams( ChModuleID& idModule, bool& boolPromote,
								chint32& lMessage )
				{
					idModule = GetOriginModule();
					boolPromote = (bool)GetParam2();
					lMessage = GetParam1();
				}
};


/*----------------------------------------------------------------------------
	ChUninstallHookMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_UNINSTALL_HOOK		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChUninstallHookMsg : public ChMsg
{
	public:
		ChUninstallHookMsg( const ChModuleID& idModule,
							chint32 lMessage = 0 ) :
				ChMsg( CH_MSG_UNINSTALL_HOOK, CH_VERS_UNINSTALL_HOOK,
						lMessage )
			{
				SetOriginModule( idModule );
			}

		inline void GetParams( ChModuleID& idModule, chint32& lMessage )
			{
				idModule = GetOriginModule();
				lMessage = GetParam1();
			}
};


/*----------------------------------------------------------------------------
----Media Control messages----------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChMediaPlayMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_MEDIA_PLAY		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChMediaPlayMsg : public ChMsg
{
	public:
											// Plays a URL file

		ChMediaPlayMsg( string strURL, bool boolLooping = false ) :
			ChMsg( CH_MSG_MEDIA_PLAY, CH_VERS_MEDIA_PLAY, boolLooping,
					false )
				{
					ChArchive	archive( this, modeWrite );

					archive << strURL;
				}

		inline void GetParams( string& strURL, bool& boolLooping )
				{
					ChArchive	archive( this, modeRead );

					boolLooping = (bool)GetParam1();

					archive >> strURL;
				}
};


/*----------------------------------------------------------------------------
	ChMediaStopMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_MEDIA_STOP		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChMediaStopMsg : public ChMsg
{
	public:
		ChMediaStopMsg() :
			ChMsg( CH_MSG_MEDIA_STOP, CH_VERS_MEDIA_STOP ) {}
};


/*----------------------------------------------------------------------------
----Ad Control messages------------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChAdMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_AD				((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChAdMsg : public ChMsg
{
	public:
		ChAdMsg( const string& strAdURL, const string& strParam,
					const string& strUserParam ) :
			ChMsg( CH_MSG_AD, CH_VERS_AD )
				{
					ChArchive	archive( this, modeWrite );

					archive << strAdURL << strParam << strUserParam;
				}

		inline void GetParams( string& strAdURL, string& strParam,
								string& strUserParam )
				{
					ChArchive	archive( this, modeRead );

					archive >> strAdURL >> strParam >> strUserParam;
				}
};


/*----------------------------------------------------------------------------
----HTML event messages-------------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChCmdMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_CMD		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChCmdMsg : public ChMsg
{
	public:
		ChCmdMsg( const string& strCmd, chint32 lXCoord = -1,
					chint32 lYCoord = -1 ) :
				ChMsg( CH_MSG_CMD, CH_VERS_CMD ),
				m_strCmd( strCmd ),
				m_lXCoord( lXCoord ),
				m_lYCoord( lYCoord )
				{
				}
		ChCmdMsg( const char* pstrCmd, chint32 lXCoord = -1,
					chint32 lYCoord = -1 ) :
				ChMsg( CH_MSG_CMD, CH_VERS_CMD ),
				m_strCmd( pstrCmd ),
				m_lXCoord( lXCoord ),
				m_lYCoord( lYCoord )
				{
				}

		inline void GetParams( string& strCmd )
				{
					strCmd = m_strCmd;
				}

		inline void GetParams( string& strCmd, chint32& lXCoord,
								chint32& lYCoord )
				{
					strCmd = m_strCmd;
					lXCoord = m_lXCoord;
					lYCoord = m_lYCoord;
				}

	protected:
		string		m_strCmd;
		chint32		m_lXCoord;
		chint32		m_lYCoord;
};


/*----------------------------------------------------------------------------
	ChInlineMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_INLINE	((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChInlineMsg : public ChMsg
{
	public:
		ChInlineMsg( const string& strArgs ) :
					ChMsg( CH_MSG_INLINE, CH_VERS_INLINE ),
					m_strArgs( strArgs )
				{
				}
		ChInlineMsg( const char* pstrArgs ) :
					ChMsg( CH_MSG_INLINE, CH_VERS_INLINE ),
					m_strArgs( pstrArgs )
				{
				}

		inline void GetParams( string& strArgs )
				{
					strArgs = m_strArgs;
				}

	protected:
		string		m_strArgs;
};


/*----------------------------------------------------------------------------
	ChHintMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_HINT	((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChHintMsg : public ChMsg
{
	public:
		ChHintMsg( const string& strHint ) :
					ChMsg( CH_MSG_HINT, CH_VERS_HINT ),
					m_strHint( strHint )
				{
				}
		ChHintMsg( const char* pstrHint ) :
					ChMsg( CH_MSG_HINT, CH_VERS_HINT ),
					m_strHint( pstrHint )
				{
				}

		inline void GetParams( string& strHint )
				{
					strHint = m_strHint;
				}

	protected:
		string		m_strHint;
};




/*----------------------------------------------------------------------------
----Misc. messages------------------------------------------------------------
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	ChSendWorldCmdMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_SEND_WORLD_CMD		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChSendWorldCmdMsg : public ChMsg
{
	public:
		ChSendWorldCmdMsg( const string& strDefaultCmd,
							const string& strMD5,
							const string& strOverrideCmd,
							const string& strParams,
							bool boolEcho = false ) :
			ChMsg( CH_MSG_SEND_WORLD_CMD, CH_VERS_SEND_WORLD_CMD ),
			m_strDefaultCmd( strDefaultCmd ),
			m_strMD5( strMD5 ),
			m_strOverrideCmd( strOverrideCmd ),
			m_strParams( strParams ),
			m_boolEcho( boolEcho )
				{
				}

		inline const string& GetDefaultCmd() { return m_strDefaultCmd; }
		inline const string& GetMD5() { return m_strMD5; }
		inline const string& GetOverrideCmd() { return m_strOverrideCmd; }
		inline const string& GetParams() { return m_strParams; }
		inline bool GetEcho() { return m_boolEcho; }

	protected:
		string		m_strDefaultCmd;
		string		m_strMD5;
		string		m_strOverrideCmd;
		string		m_strParams;
		bool		m_boolEcho;
};


/*----------------------------------------------------------------------------
	ChConnectedMsg class
----------------------------------------------------------------------------*/

#define CH_VERS_CONNECTED		((ChVersion)0x00000000)

class CH_EXPORT_CLASS ChConnectedMsg : public ChMsg
{
	public:
		ChConnectedMsg() :
			ChMsg( CH_MSG_CONNECTED, CH_VERS_CONNECTED )
				{
				}

		inline const string& GetPuebloClientParams() const
				{
					return m_strParams;
				}

		inline void ClearPuebloClientParams()
				{
					m_strParams = "";
				}
		inline void SetPuebloClientParam( const string& strParam,
											const string& strValue )
				{
					m_strParams = strParam + "=" + strValue;
				}
		inline void AppendPuebloClientParam( const string& strParam,
												const string& strValue )
				{
					m_strParams += strParam + "=" + strValue;
				}

	protected:
		string		m_strParams;
};


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR
#endif

#endif	// !defined( _CHMSGTYP_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
