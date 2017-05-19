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

	TinTin class definitions.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/TinTin.h,v 2.34 1996/05/01 18:48:52 coyote Exp $

#if !defined( TINTIN_H )
#define TINTIN_H


#include "TinTinSettings.h"


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define TINTIN_VERSION			"1.6"

#define DEF_TINTIN_CHAR			'#'			// TinTin escape char
#define DEF_VERBATIM_CHAR		'\\'		/* If an input starts with this
												char, it will be sent 'as is'
												to the MUD */
#define DEF_TICK_SIZE			75
#define DEF_TICK_KEY			"TinTin"

#define DEF_OPEN				'{'			// Char that starts an argument
#define DEF_CLOSE				'}'			// Char that ends an argument
#define TINTIN_DEF_GAG_STRING	"."

#define TINTIN_HELP_PREFIX		"TinTin"

#define MAX_PATH_LENGTH			200			// Maximum path length
#define MAX_RECURSE				100			// Maximum recursion depth


/*----------------------------------------------------------------------------
	Types
----------------------------------------------------------------------------*/

											/* If you change this enumeration,
												you must also change the
												TinTin::m_pstrCommands array
												to correspond with the indices
												in this enumeration */

typedef enum { ttUnknown = -1, ttAction = 0, ttAlert, ttAlias, ttAll,
				ttAntisubstitute, ttBell, ttBoss, ttChar, ttCr, ttEcho,
				ttEnd, ttGag, ttHelp, ttHighlight, ttHistory, ttIf,
				ttIgnore, ttInfo, ttKillall, ttLog, ttLoop, ttMap, ttMath,
				ttMark, ttMbox, ttMessage, ttName, ttNop, ttPath,
				ttPathdir, ttPlaySound, ttPresub, ttRandom, ttRedraw,
				ttRetab, ttReturn, ttRead, ttSavepath, ttSession, ttShowme,
				ttSpeedwalk, ttSplit, ttSubstitute, ttTextin,
				ttTick, ttTickkey, ttTickoff, ttTickon, ttTickset, ttTicksize,
				ttTolower, ttTogglesub, ttToupper, ttUnaction, ttUnalias,
				ttUnantisubstitute, ttUnhighlight, ttUnsubstitute,
				ttUngag, ttUnpath, ttUnvariable, ttVariable, ttVersion,
				ttWizlist, ttWrite, ttWritesession, ttZap, ttVerbatim,
				ttEnhancements, ttExpressions } TTCommand;

typedef int		VarLenType[10];
typedef string	VarType[10];


typedef enum { opInvalid = -1, opOpenParen = 0, opCloseParen, opBooleanNot,
				opLowercase, opMult, opDiv, opAdd, opSubtract, opCompGreater,
				opCompGreaterEqual, opCompLess, opCompLessEqual, opCompEqual,
				opCompNotEqual, opBoolAnd, opBoolOr, opInt, opString,
				opMaximum } TTOperator;


/*----------------------------------------------------------------------------
	Utility functions
----------------------------------------------------------------------------*/

CH_EXTERN_FUNC( bool )
Match( const char* pstrRegex, const char* pstrTest );


/*----------------------------------------------------------------------------
	MathOp class
----------------------------------------------------------------------------*/

class MathOps
{
	public:
		MathOps() : m_iNext( 0 ),
					m_op( opInvalid ),
					m_iValue( 0 ),
					m_pstrValue( 0 )
			{
			}

		~MathOps()
			{
				if (m_pstrValue)
				{
					delete m_pstrValue;
				}
			}

		inline int GetNext() const { return m_iNext; }
		inline TTOperator GetOp() const { return m_op; }
		inline int GetInt() const
						{
							ASSERT( IsInt() );

							return m_iValue;
						}
		inline int& GetInt()
						{
							ASSERT( IsInt() );

							return m_iValue;
						}
		inline string* GetString() const
						{
							ASSERT( 0 != m_pstrValue );
							ASSERT( IsString() );

							return m_pstrValue;
						}

		inline bool IsInt() const
						{
							return (GetOp() == opInt);
						}
		inline bool IsString() const
						{
							return (GetOp() == opString);
						}
		inline bool IsValue() const
						{
							return (IsInt() || IsString());
						}

		inline void SetNext( int iNext ) { m_iNext = iNext; }
		inline void SetOp( TTOperator op ) { m_op = op; }
		inline void Set( int iValue ) { m_iValue = iValue; }
		inline void Set( const string& strValue )
						{
							if (m_pstrValue)
							{
								*m_pstrValue = strValue;
							}
							else
							{
								m_pstrValue = new string( strValue );
							}
						}

		inline void Set( const string* pstrValue )
						{
							Set( *pstrValue );
						}

		inline void Reset()
						{
							if (m_pstrValue)
							{
								delete m_pstrValue;
								m_pstrValue = 0;
							}
						}

	protected:
		int			m_iNext;
		TTOperator	m_op;
		int			m_iValue;
		string*		m_pstrValue;
};


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

class ChWorldMainInfo;

class TinTin
{
	public:
		TinTin( ChWorldMainInfo* pMainInfo );
		~TinTin();

		inline void ReadInitFile( const string& strFile )
						{
							DoRead( strFile, false );
						}

		inline void Message( const string& strMessage,
								bool boolPreformatted = false ) const
						{
							if (IsMessages())
							{
								Display( strMessage, boolPreformatted );
							}
						}
		inline void ActMessage( const string& strMessage )
						{
							if (IsMessages())
							{
								Display( strMessage, false );
							}
							CheckActions( strMessage );
						}
		inline void ErrMessage( const string& strMessage ) const
						{
							Display( strMessage, false );
						}

		inline bool IsIgnore() { return GetSettings()->IsIgnore(); }
		inline bool IsActionsDefined()
						{
							return (0 != GetListActions()->GetTop());
						}

		virtual void SendToWorld( const string& strOutput );
		virtual void Display( const string& strOutput,
								bool boolPreformatted ) const;
		void Reset();

		void ParseInput( const string& strInput );

		void CheckActions( const string& strLine );
		void CheckInsertPath( const string& strCommand );

		void OnSecondTick( time_t timeCurr );

	protected:
		inline ChWorldMainInfo* GetMainInfo() const { return m_pMainInfo; }
		inline TinTinSettings* GetSettings() const
						{
							return m_pActiveSettings;
						}

		inline TinTinList* GetListAliases() const
						{
							return GetSettings()->GetListAliases();
						}
		inline TinTinList* GetListActions() const
						{
							return GetSettings()->GetListActions();
						}
		inline TinTinList* GetListVars() const
						{
							return GetSettings()->GetListVars();
						}
		inline TinTinList* GetListHighlights() const
						{
							return GetSettings()->GetListHighlights();
						}
		inline TinTinList* GetListSubs() const
						{
							return GetSettings()->GetListSubs();
						}
		inline TinTinList* GetListAntiSubs() const
						{
							return GetSettings()->GetListAntiSubs();
						}
		inline TinTinList* GetListPath() const { return m_pListPath; }
		inline TinTinList* GetListPathDirs() const
						{
							return GetSettings()->GetListPathDirs();
						}
		inline int GetSecondsToTick() const { return m_iSecsToTick; }
		inline const string& GetTickKey() const
						{
							return GetSettings()->GetTickKey();
						}
		inline int GetTickSize() const
						{
							return GetSettings()->GetTickSize();
						}
		inline time_t GetTimeStart() const { return m_timeStart; }
		inline char GetTinTinChar() const
						{
							return GetSettings()->GetTinTinChar();
						}
		inline char GetVerbatimChar() const { return m_cVerbatim; }

		inline bool IsDisplayingMsg( int iClass ) const
						{
							return GetSettings()->IsDisplayingMsg( iClass );
						}
		inline bool IsEcho() const { return GetSettings()->IsEcho(); }
		inline bool IsIgnore() const { return GetSettings()->IsIgnore(); }
		inline bool IsMessages() const { return m_boolMessages; }
		inline bool IsOnline() const { return m_boolOnline; }
		inline bool IsSpeedwalk() const
						{
							return GetSettings()->IsSpeedwalk();
						}
		inline bool IsTicking() const { return GetSettings()->IsTicking(); }
		inline bool IsUsingPresubs() const
						{
							return GetSettings()->IsUsingPresubs();
						}
		inline bool IsUsingSubs() const
						{
							return GetSettings()->IsUsingSubs();
						}
		inline bool IsVerbatim() const { return GetSettings()->IsVerbatim(); }

		inline void SetDisplayingMsg( int iClass, bool boolDisplay )
						{
							GetSettings()->SetDisplayingMsg( iClass,
																boolDisplay );
						}
		inline void SetEcho( bool boolEcho )
						{
							GetSettings()->SetEcho( boolEcho );
						}
		inline void SetIgnore( bool boolIgnore )
						{
							GetSettings()->SetIgnore( boolIgnore );
						}
		inline void SetLocalSettings( bool boolLocal )
						{
							m_pActiveSettings = boolLocal ? m_pSettings :
															m_pGlobalSettings;
						}
		inline void SetMessages( bool boolOn )
						{
							m_boolMessages = boolOn;
						}
		inline void SetPresub( bool boolPresub )
						{
							GetSettings()->SetPresub( boolPresub );
						}
		inline void SetSecondsToTick( int iSecondsToTick )
						{
							m_iSecsToTick = iSecondsToTick;
						}
		inline void SetSpeedwalk( bool boolSpeedwalk )
						{
							GetSettings()->SetSpeedwalk( boolSpeedwalk );
						}
		inline void SetTicking( bool boolTicking )
						{
							GetSettings()->SetTicking( boolTicking );
						}
		inline void SetTickKey( const string& strKey )
						{
							GetSettings()->SetTickKey( strKey );
						}
		inline void SetTickSize( int iSize )
						{
							GetSettings()->SetTickSize( iSize );
						}
		inline void SetTimeStart( time_t start ) { m_timeStart = start; }
		inline void SetTinTinChar( char cNewTinTin )
						{
							GetSettings()->SetTinTinChar( cNewTinTin );
						}
		inline void SetUsingSubs( bool boolUsingSubs )
						{
							GetSettings()->SetUsingSubs( boolUsingSubs );
						}
		inline void SetVerbatim( bool boolVerbatim )
						{
							GetSettings()->SetVerbatim( boolVerbatim );
						}
											// In TinTinMain.cpp
		void ReadGlobalFile();
											// In TinTinParse.cpp

		void Send( const string& strCmd );
		void Send( const string& strCmd, const string& strArgs );
		void ParseTinTinCommand( const string& strCommand, string& strArgs );

		bool IsSpeedwalkDirective( const char* pstrCmd );
		void DoSpeedwalk( const char* pstrCmd );

		const char* GetArgAll( const char* pstrText, string& strArg );
		const char* GetArgInBraces( const char* pstrText, string& strArg,
									bool boolIncludeSpaces = true );
		const char* GetArgStopAtSpaces( const char* pstrText, string& strArg );
		const char* GetArgWithSpaces( const char* pstrText, string& strArg );
		const char* SpaceOut( const char* pstrText );

											// In TinTinAction.cpp

		void PrepareActionAlias( const string& strText, string& strResult );
		void DoAction( const string& strArgs );
		void DoUnaction( const string& strArgs );
	
		bool CheckOneAction( const string& strLine, const string& strAction );
		bool CompareAction( const string& strLine, const string& strAction,
							VarLenType& iVarLen, VarType& strVar );

											// In TinTinAlias.cpp
		void DoAlias( const string& strArgs );
		void DoUnalias( const string& strArgs );

											// In TinTinFiles.cpp

		void DoRead( const string& strFilename, bool boolOnline );
		void DoWrite( const string& strFilename );

		void CompleteFilePath( string& strFilePath );
		void FormatCommand( const string& strCommand, const string& strLeft,
							const string& strRight, const string& strPriority,
							string& strResult );

											// In TinTinIf.cpp
		void DoIf( const string& strArgs );
		void DoMath( const string& strArgs );

		void EvalExpression( const char* pstrArgs, string& strResult );
		bool CompileExpression( const char* pstrArg );
		void ResetExpression();
		bool DoOneInside( int iBegin, int iEnd );
		bool CompareValues( const MathOps& left, const MathOps& right,
							TTOperator op );
		void MakeString( const MathOps& val, string& strVal );

											// In TinTinMisc.cpp
		void DoAlert();
		void DoBell();
		void DoChar( const string& strArg );
		void DoCR();
		void DoEnd( const string& strCommand );
		void DoHelp( const string& strArgs );
		void DoInfo();
		void DoKillAll( bool boolQuiet );
		void DoLog( const string& strArgs );
		void DoLoop( const string& strArgs );
		void DoMbox( const string& strArgs );
		void DoMessage( const string& strArgs );
		void DoPlaySound( const string& strArgs );
		void DoRandom( const string& strArgs );
		void DoShowMe( const string& strArgs );
		void DoSplit( const string& strArgs );
		void DoVersion();
		void DoWizList();
		void DoZap();
		void ToggleEcho();
		void ToggleIgnore();
		void ToggleSpeedwalk();
		void ToggleSub();
		void ToggleVerbatim( const string& strArg );

											// In TinTinPath.cpp
		void DoMap( const string& strArgs );
		void DoMark();
		void DoPath();
		void DoPathdir( const string& strArgs );
		void DoReturn();
		void DoSavepath( const string& strArgs );
		void DoUnpath();
											// In TinTinSession.cpp

		void DoAll( const string& strArgs );
		void DoName( const string& strArgs );
		void DoSession( const string& strArgs );
		void CreateSession( const string& strLabel,
							const string& strConnInfo );

											// In TinTinSubs.cpp

		void DoSubstitute( const string& strArgs );
		void DoUnsubstitute( const string& strArgs, bool boolUngag );

											// In TinTinTicks.cpp
		void DoTick();
		void DoTickKey( const string& strArgs );
		void DoTickOff();
		void DoTickOn();
		void DoTickSet();
		void DoTickSize( const string& strArgs );

											// In TinTinUtils.cpp

		TTCommand ParseTinTinCmd( const char* strCommand );
		bool IsAbrev( const char* pstr1, const char* pstr2 );

											// In TinTinVars.cpp

		void DoChangeCase( const string& strArgs, bool boolToUpper );
		void DoVariable( const string& strArgs );
		void DoUnvariable( const string& strArgs );

		void SubstituteVars( const char* pstrArg, string& strOut,
								bool boolQuoted = false );
		void SubstituteMyVars( const char* pstrArg, string& strOut,
								bool boolQuoted = false );
		
		bool IsVarNameValid( const string& strName );

	protected:
		static const char		m_cVerbatim;
		static const char*		m_pstrCommands[];
		static TinTinSettings*	m_pGlobalSettings;
		static int				m_iObjectCount;
		static string			m_strFalse;

		ChWorldMainInfo*		m_pMainInfo;

		TinTinSettings*			m_pSettings;
		TinTinSettings*			m_pActiveSettings;

		int						m_iRecurseLevel;

		bool					m_boolUseGlobal;
		bool					m_boolMessages;	// Overrides the following array

		bool					m_boolOnline;

		bool					m_boolTrackPaths;
		int						m_iPathLen;
		TinTinList*				m_pListPath;

		time_t					m_timeStart;
		int						m_iSecsToTick;

		VarType					m_strVars;	// %0 - %9 variables

		int						m_iAliasCounter;
		int						m_iActionCounter;
		int						m_iSubCounter;
		int						m_iAntiSubCounter;
		int						m_iVarCounter;
		int						m_iHighlightCounter;
		int						m_iPathdirCounter;
};

#endif	// !defined( TINTIN_H )
