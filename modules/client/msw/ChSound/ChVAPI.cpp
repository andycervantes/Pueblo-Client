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

	Implementation of the ChVAPI object, which manages the interface between
	VAPI and the Sound Module.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChSound/ChVAPI.cpp,v 1.1 1996/09/26 17:32:05 coyote Exp $

#include "headers.h"

#if defined( CH_USE_VAPI )

#include <ChReg.h>

#include "ChVAPI.h"


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define DEF_VAPI_PORT	12370
											/* This should be set to zero
												if Voxware ever fixes the
												problem of returning the
												correct port number */
#define VAPI_PORT		DEF_VAPI_PORT


/*----------------------------------------------------------------------------
	ChVAPI static member variables
----------------------------------------------------------------------------*/

ChVAPI*				ChVAPI::m_this = 0;
int					ChVAPI::m_iUsage = 0;
VAPI_HANDLE			ChVAPI::m_hVAPI = 0;

ChVAPISessionMgr	ChVAPI::m_vapiSessions;
chuint16			ChVAPI::m_suVAPIPort = 0;
string				ChVAPI::m_strVAPILocalHost;

VAPI_USER_INFO		ChVAPI::m_userInfo;

chuint32			ChVAPI::m_luMikeVolume;
chuint32			ChVAPI::m_luMikeSensitivity;
bool				ChVAPI::m_boolRejectCalls;


/*----------------------------------------------------------------------------
	ChVAPI public methods
----------------------------------------------------------------------------*/

ChVAPI::ChVAPI()
{
	if (0 == m_iUsage)
	{
		VAPI_INITIALIZE			vapiInit;
		VAPI_TRANSACTION_HANDLE	hTransaction;
		VAPI_RETCODE			retCode;

		m_this = this;

		ChMemClearStruct( &m_userInfo );
		m_userInfo.wSizeOfUserInfo = sizeof( VAPI_USER_INFO );

		ChMemClearStruct( &vapiInit );
		vapiInit.wSizeOfInitialize = sizeof( VAPI_INITIALIZE );
		vapiInit.usListenPort = VAPI_PORT;
		vapiInit.lpNotifyProc = NotifyProc;

		retCode = vapiInitialize( &m_hVAPI, &hTransaction, 0,
									&vapiInit );
		if (VAPI_NO_ERROR != retCode)
		{
			#if defined( CH_DEBUG )
			{
				char		cBuffer[160];

				sprintf( cBuffer, "VAPI: Error calling vapiInitialize (%hu)\n",
										retCode );
				TRACE( cBuffer );
			}
			#endif	// defined( CH_DEBUG )

			m_hVAPI = 0;
		}
		else
		{
			UpdatePrefs();
		}
	}

	m_iUsage++;
}


ChVAPI::~ChVAPI()
{
	if (0 == --m_iUsage)
	{
		if (GetVAPIHandle())
		{
			VAPI_RETCODE			retCode;

			retCode = vapiCleanup( GetVAPIHandle() );
			if (VAPI_NO_ERROR != retCode)
			{
				#if defined( CH_DEBUG )
				{
					char		cBuffer[160];

					sprintf( cBuffer, "VAPI: Error calling vapiCleanup (%hu)\n",
										retCode );
					TRACE( cBuffer );
				}
				#endif	// defined( CH_DEBUG )
			}
		}

		m_hVAPI = 0;
	}
}


/*----------------------------------------------------------------------------
	ChVAPI public methods
----------------------------------------------------------------------------*/

bool ChVAPI::MakeCall( const string& strCallId, const string& strHost,
						chuint16 suPort, chflag32 flOptions,
						chflag32 flRemoteOptions )
{
	VAPI_RETCODE			retCode;
	VAPI_TRANSACTION_HANDLE	hTransaction;
	bool					boolSuccess;
	chuint16				suFullDuplex;
	bool					boolFullDuplex;
											// Copy information to be shared

	ASSERT( VAPI_MAX_LASTNAME_LENGTH > sizeof( chflag32 ) );

	sprintf( m_userInfo.szLastName, "%d", flRemoteOptions );
	strncpy( m_userInfo.szFirstName, (const char*)strCallId, VAPI_MAX_LASTNAME_LENGTH );
	m_userInfo.szLocale2[VAPI_MAX_LASTNAME_LENGTH - 1] = '\0';

	vapiSetUserInfo( GetVAPIHandle(), &m_userInfo );

	retCode = vapiQuerySoundDevices( GetVAPIHandle(), 0, 0, &suFullDuplex );
	boolFullDuplex = !!suFullDuplex;
	retCode = vapiSetSoundDevices( GetVAPIHandle(), 0, 0, boolFullDuplex );
	if (VAPI_NO_ERROR != retCode)
	{
		#if defined( CH_DEBUG )
		{
			char		cBuffer[160];

			sprintf( cBuffer, "VAPI: Error calling vapiSetSoundDevices (%hu)\n",
								retCode );
			TRACE( cBuffer );
		}
		#endif	// defined( CH_DEBUG )

		boolSuccess = false;
	}
	else
	{
		VAPI_USER_INFO		destUserInfo;

		ChMemClearStruct( &destUserInfo );
		destUserInfo.wSizeOfUserInfo = sizeof( VAPI_USER_INFO );
		strcpy( destUserInfo.szNetAddress, (const char*)strHost );
		destUserInfo.usPort = suPort;

		retCode = vapiEstablishSession(	GetVAPIHandle(), &hTransaction,
											0, &destUserInfo, USE_UDP );
		if (VAPI_NO_ERROR != retCode)
		{
			#if defined( CH_DEBUG )
			{
				char		cBuffer[160];

				sprintf( cBuffer,
							"VAPI: Error calling vapiEstablishSession (%hu)\n",
							retCode );
				TRACE( cBuffer );
			}
			#endif	// defined( CH_DEBUG )

			boolSuccess = false;
		}
	}

	return boolSuccess;
}


bool ChVAPI::Hangup( const string& strCallId )
{
	return m_vapiSessions.Hangup( GetVAPIHandle(), strCallId );
}


void ChVAPI::UpdatePrefs()
{
	ChRegistry	reg( SOUND_PREFS_GROUP );
	chint32		lVolume;

	reg.ReadBool( SOUND_PREFS_REJECT_CALLS, m_boolRejectCalls,
					SOUND_PREFS_REJECT_CALLS_DEF );

	reg.Read( SOUND_PREFS_MIKE_VOLUME, m_luMikeVolume,
				SOUND_PREFS_MIKE_VOLUME_DEF );
	reg.Read( SOUND_PREFS_MIKE_SENSITIVITY, m_luMikeSensitivity,
				SOUND_PREFS_MIKE_SENSITIVITY_DEF );

	vapiSetRecordLevel( GetVAPIHandle(), GetMikeVolume() );

	if (0 == GetMikeVolume())
	{
		vapiMuteMike( GetVAPIHandle(), VAPI_MUTE_MIKE );
	}
	else
	{
		vapiMuteMike( GetVAPIHandle(), VAPI_UNMUTE_MIKE );
	}

	vapiSetVoiceActivationLevel( GetVAPIHandle(),
									(chuint16)GetMikeSensitivity() );

	reg.Read( SOUND_PREFS_SPEECH_VOLUME, lVolume, VOLUME_MAX_RANGE );
	if (lVolume < 0)
	{
		lVolume = 0;
	}
	else if (lVolume > VOLUME_MAX_RANGE)
	{
		lVolume = VOLUME_MAX_RANGE;
	}
	vapiSetSpeakerVolume( GetVAPIHandle(), lVolume );
}


/*----------------------------------------------------------------------------
	ChVAPI notification callback
----------------------------------------------------------------------------*/

VAPI_RETCODE ChVAPI::NotifyProc( unsigned short wMessage,
									unsigned long hTransaction,
				    				unsigned long dwVapiParamOne,
				    				unsigned long dwVapiParamTwo,
				    				unsigned long dwUserParam )
{
	VAPI_HANDLE			hVAPI;

	#if defined( CH_DEBUG )
	char				cBuffer[160];
	#endif	// defined( CH_DEBUG )

	hVAPI = GetVAPIHandle();

	switch (wMessage)
	{
		case VAPI_NOTIFY_MIC_VOLUME_CHANGE:
		{
			//UpdateRecordSlider(dwVapiParamOne);
			return VAPI_NO_ERROR;
		}

		case VAPI_NOTIFY_BUFFER_LEVEL_CHANGE:
		{
			//UpdateBufferScale(dwVapiParamOne);
			return VAPI_NO_ERROR;
		}

		case VAPI_NOTIFY_MIC_GAINMETER_CHANGE:
		{
			//UpdateXmitSpeechScale(dwVapiParamOne, 0);
			return VAPI_NO_ERROR;
		}

		case VAPI_NOTIFY_NEW_SESSION_STATUS:
		{
			switch( dwVapiParamOne )
			{
				case VAPI_NOTIFY_STATUS_ESTABLISHED:
				{
					VAPI_SESSION_INFO*	pSessionInfo;
					VAPI_RETCODE		retCode;
					VAPI_SESSION_HANDLE	hSession;
					string				strCallId;
					chflag32			flOptions;

					pSessionInfo = (VAPI_SESSION_INFO*)dwVapiParamTwo;
					hSession = pSessionInfo->hSession;

					strCallId = pSessionInfo->RemoteUserInfo.szFirstName;
					flOptions =
						atol( pSessionInfo->RemoteUserInfo.szLastName );

					TRACE( "VAPI: Call is established.\n" );

					m_vapiSessions.Set( strCallId, hSession, flOptions );

					retCode = vapiHandsOffMode( hVAPI, VAPI_HANDS_OFF_MODE );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiHandsOffMode (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}

					retCode = vapiSetInitialDelay( hVAPI, hSession, 100 );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSetInitialDelay (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}

					retCode = vapiSetSilentWindow( hVAPI, 0 );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSetSilentWindow (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}

					retCode = vapiSetSpeakerVolume( hVAPI, 50 );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSetSpeakerVolume (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}

					retCode = vapiSetRecordLevel( hVAPI, GetMikeVolume() );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSetRecordLevel (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}

					retCode = vapiSetVoiceActivationLevel( GetVAPIHandle(),
															(chuint16)GetMikeSensitivity() );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSetSpeechActivationLevel (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}
					break;
				}

				case VAPI_NOTIFY_STATUS_RINGING:
				{
					TRACE( "VAPI: Ring!\n" );
					break;
				}

				case VAPI_NOTIFY_STATUS_INCOMING_CALL:
				{
					VAPI_TRANSACTION_HANDLE	hTransaction;
					LPVAPI_SESSION_INFO		pSessionInfo;
					VAPI_RETCODE			retCode;
					VAPI_SESSION_HANDLE		hSession;
					unsigned long			dwResponse;

					TRACE( "VAPI: Incoming call.\n" );

					pSessionInfo = (VAPI_SESSION_INFO*)dwVapiParamTwo;
					hSession = pSessionInfo->hSession;

					if (m_vapiSessions.AllSessionsInUse())
					{
						dwResponse = VAPI_SESSION_RESPONSE_BUSY;
					}
					else
					{
						dwResponse = VAPI_SESSION_RESPONSE_ACCEPT;
					}

					retCode =
						vapiSessionResponse( hVAPI, &hTransaction,
												0, hSession, dwResponse );
					if (VAPI_NO_ERROR != retCode)
					{
						#if defined( CH_DEBUG )
						{
							sprintf( cBuffer,
										"VAPI: Error calling "
										"vapiSessionResponse (%hu)\n",
										retCode );
							TRACE( cBuffer );
						}
						#endif	// defined( CH_DEBUG )
					}
					break;
				}

				case VAPI_NOTIFY_STATUS_HANGUP:
				{
					VAPI_SESSION_INFO*	pSessionInfo;

					pSessionInfo = (VAPI_SESSION_INFO*)dwVapiParamTwo;

											// Clear the active session handle

					m_vapiSessions.ClearSessionHdl( pSessionInfo->hSession );

					TRACE( "VAPI: Hung up!\n" );
					break;
				}

				case VAPI_NOTIFY_STATUS_XMIT:
				{
					//SetDlgItemText(hNotifyDlg, IDC_SENDRECV, "TRANSMIT");
					return VAPI_NO_ERROR;
				}

				case VAPI_NOTIFY_STATUS_RECV:
				{
					//SetDlgItemText(hNotifyDlg, IDC_SENDRECV, "RECEIVE");
					return VAPI_NO_ERROR;
				}

				case VAPI_NOTIFY_STATUS_UNKNOWN:
				{
					//SendMessage(GetDlgItem(hNotifyDlg, IDC_NOTIFY_LIST), LB_INSERTSTRING, (WPARAM)-1, (long)"Unknown rejection from remote.");
					break;
				}

				default:
				{
					#if defined( CH_DEBUG )
					{
						//wsprintf(cBuffer, "Unknown response from remote user (%ld).", dwVapiParamOne);
						//SendMessage(GetDlgItem(hNotifyDlg, IDC_NOTIFY_LIST), LB_INSERTSTRING, (WPARAM)-1, (long)cBuffer);
					}
					#endif	// defined( CH_DEBUG )
					break;
				}
			}
			break;
		}	

		case VAPI_NOTIFY_LOCAL_MODE:
		{
			switch( dwVapiParamOne )
			{
				case VAPI_NOTIFY_LOCALMODE_LISTEN:
				{
					//SetDlgItemText(hNotifyDlg, IDC_TALKLSTN, "LISTEN");
					break;
				}

				case VAPI_NOTIFY_LOCALMODE_TALK:
				{
					//SetDlgItemText(hNotifyDlg, IDC_TALKLSTN, "TALK");
					break;
				}
			}
			break;
		}

		case VAPI_NOTIFY_INIT_STATUS:
		{
			if (!dwVapiParamOne)
			{
				VAPI_NET_INIT_INFO*		pInitInfo;

				pInitInfo = (VAPI_NET_INIT_INFO*)dwVapiParamTwo;

				SetVAPIPort( pInitInfo->usLocalPort );
				SetVAPILocalHost( pInitInfo->szLocalNetAddress );

				strcpy( m_userInfo.szNetAddress,
						pInitInfo->szLocalNetAddress );
				m_userInfo.usPort = pInitInfo->usLocalPort;

				vapiSetUserInfo( GetVAPIHandle(), &m_userInfo );

				#if defined( CH_DEBUG )
				{
					sprintf( cBuffer, "VAPI: Initialized for %s:%d\n",
										pInitInfo->szLocalNetAddress,
										(int)pInitInfo->usLocalPort );
					TRACE( cBuffer );
				}
				#endif	// defined( CH_DEBUG )
			}
			break;
		}

		case VAPI_NOTIFY_SESSION_RESPONSE:
		{
			if (VAPI_SESSION_RESPONSE_ACCEPT == dwVapiParamTwo)
			{
				#if defined( CH_DEBUG )
				{
											// Call accepted!

					strcpy( cBuffer, "VAPI: Call has been accepted." );
				}
				#endif	// defined( CH_DEBUG )
			}
			else
			{
				switch (dwVapiParamTwo)
				{
					case VAPI_SESSION_RESPONSE_REJECT:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: Call has not been accepted." );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}

					case VAPI_SESSION_RESPONSE_BUSY:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: Caller is busy." );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}

					case VAPI_SESSION_RESPONSE_NOANSWER:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: Caller did not answer." );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}

					case VAPI_SESSION_RESPONSE_BLOCK:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: Caller is blocking calls." );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}

					case VAPI_SESSION_RESPONSE_VOICEMAIL:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: Speech mail system." );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}

					default:
					{
						#if defined( CH_DEBUG )
						{
							strcpy( cBuffer, "VAPI: UNKNOWN CALL RESPONSE\n" );
						}
						#endif	// defined( CH_DEBUG )
						break;
					}
				}
			}

			#if defined( CH_DEBUG )
			{
				TRACE( cBuffer );
			}
			#endif	// defined( CH_DEBUG )
			break;
		}

		default:
		{
			#if defined( CH_DEBUG )
			{
				sprintf( cBuffer, "VAPI: Unknown notification message (%ld).",
									wMessage );
				TRACE( cBuffer );
			}
			#endif	// defined( CH_DEBUG )
			break;
		}
	}

	return VAPI_NO_ERROR;
}


/*----------------------------------------------------------------------------
	ChVAPISessionMgr public methods
----------------------------------------------------------------------------*/

ChVAPISessionMgr::ChVAPISessionMgr() :
						m_iSessions( 0 )
{
	for (int iLoop = 0; iLoop < SESSION_LIMIT; iLoop++)
	{
		SetInUse( iLoop, false );
	}
}


ChVAPISessionMgr::~ChVAPISessionMgr()
{
}


bool ChVAPISessionMgr::Set( const string& strCallId,
							VAPI_SESSION_HANDLE hSession,
							chflag32 flOptions )
{
	bool			boolSuccess = false;
	ChVAPISession*	pFoundSession = 0;
	int				iLoc;

	if (0 == (pFoundSession = Find( strCallId, &iLoc )))
	{
		if (SESSION_LIMIT > GetSessionCount())
		{
			iLoc = 0;

			while ((0 == pFoundSession) && (iLoc < SESSION_LIMIT))
			{
				if (!IsInUse( iLoc ))
				{
					pFoundSession = GetSession( iLoc );
				}
				else
				{
					iLoc++;
				}
			}
		}
	}

	if (pFoundSession)
	{
		SetInUse( iLoc );

		pFoundSession->Set( hSession, strCallId, flOptions );

		boolSuccess = true;
	}

	return boolSuccess;
}


VAPI_SESSION_HANDLE ChVAPISessionMgr::
						GetSessionHandle( const string& strCallId,
											chflag32* pflOptions )
{
	VAPI_SESSION_HANDLE		hSession = 0;
	ChVAPISession*			pSession;

	if (pSession = Find( strCallId ))
	{
		hSession = pSession->GetSessionHdl();

		if (pflOptions)
		{
			*pflOptions = pSession->GetOptions();
		}
	}

	return hSession;
}


bool ChVAPISessionMgr::Hangup( VAPI_HANDLE hVAPI, const string& strCallId )
{
	VAPI_SESSION_HANDLE		hSession = 0;
	bool					boolSuccess = true;

	if (!strCallId.IsEmpty())
	{										// Look up the session by call id

		hSession = GetSessionHandle( strCallId );
	}

	if (hSession)
	{
		boolSuccess = Hangup( hVAPI, hSession );
	}
	else
	{
		for (int iLoop = 0; iLoop < SESSION_LIMIT; iLoop++)
		{
			if (IsInUse( iLoop ))
			{
				boolSuccess = boolSuccess &&
								Hangup( hVAPI,
										GetSession( iLoop )->GetSessionHdl() );
			}
		}
	}

	return boolSuccess;
}


bool ChVAPISessionMgr::ClearSession( const string& strCallId )
{
	int		iLoc;
	bool	boolFound;

	if (boolFound = (0 != Find( strCallId, &iLoc )))
	{
		SetInUse( iLoc, false );
	}

	return boolFound;
}


bool ChVAPISessionMgr::ClearSessionHdl( VAPI_SESSION_HANDLE hSession )
{
	bool		boolFound = false;
	int			iLoop;

	for (iLoop = 0; iLoop < SESSION_LIMIT; iLoop++)
	{
		if (IsInUse( iLoop ) &&
			(GetSession( iLoop )->GetSessionHdl() == hSession))
		{
			SetInUse( iLoop, false );

			boolFound = true;
		}
	}

	return boolFound;
}


/*----------------------------------------------------------------------------
	ChVAPISessionMgr protected methods
----------------------------------------------------------------------------*/

ChVAPISession* ChVAPISessionMgr::Find( const string& strCallId, int* piLoc )
{
	ChVAPISession*	pFoundSession = 0;

	if (0 != GetSessionCount())
	{
		int		iLoop = 0;

		while ((0 == pFoundSession) && (iLoop < SESSION_LIMIT))
		{
			if (IsInUse( iLoop ))
			{
				if (GetSession( iLoop )->GetId() == strCallId)
				{
					pFoundSession = GetSession( iLoop );

					if (piLoc)
					{
						*piLoc = iLoop;
					}
				}
			}

			iLoop++;
		}
	}

	return pFoundSession;
}


ChVAPISession* ChVAPISessionMgr::Find( VAPI_SESSION_HANDLE hSession,
										int* piLoc )
{
	ChVAPISession*	pFoundSession = 0;

	if (0 != GetSessionCount())
	{
		int		iLoop = 0;

		while ((0 == pFoundSession) && (iLoop < SESSION_LIMIT))
		{
			if (IsInUse( iLoop ))
			{
				if (GetSession( iLoop )->GetSessionHdl() == hSession)
				{
					pFoundSession = GetSession( iLoop );

					if (piLoc)
					{
						*piLoc = iLoop;
					}
				}
			}

			iLoop++;
		}
	}

	return pFoundSession;
}


bool ChVAPISessionMgr::Hangup( VAPI_HANDLE hVAPI, VAPI_SESSION_HANDLE hSession )
{
	VAPI_RETCODE			retCode;
	VAPI_TRANSACTION_HANDLE	hTransaction;
	bool					boolSuccess = true;

	retCode = vapiHangupSession( hVAPI, &hTransaction, 0, hSession );
	if (VAPI_NO_ERROR != retCode)
	{
		#if defined( CH_DEBUG )
		{
			char		cBuffer[160];

			sprintf( cBuffer, "VAPI: Error calling vapiHangupSession (%hu)\n",
								retCode );
			TRACE( cBuffer );
		}
		#endif	// defined( CH_DEBUG )

		boolSuccess = false;
	}

	return boolSuccess;
}


/*----------------------------------------------------------------------------
	ChVAPISession public methods
----------------------------------------------------------------------------*/

ChVAPISession::ChVAPISession()
{
}


ChVAPISession::~ChVAPISession()
{
}


#endif	// defined( CH_USE_VAPI )


// Local Variables: ***
// tab-width:4 ***
// End: ***
