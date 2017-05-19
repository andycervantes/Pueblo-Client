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

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTin.h,v 2.6 1996/02/17 02:17:51 coyote Exp $

#if !defined( TINTIN_H )
#define TINTIN_H

#include <ChList.h>


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/
	
#define DEF_TINTIN_CHAR			'#'			// TinTin escape char
#define DEF_VERBATIM_CHAR		'\\'		/* If an input starts with this
												char, it will be sent 'as is'
												to the MUD */

#define DEF_OPEN				'{'			// Char that starts an argument
#define DEF_CLOSE				'}'			// Char that ends an argument

											// Search and insert modes:
#define ALPHA					1
#define PRIORITY				0

#define TINTIN_HELP_PREFIX		"TinTin"


/*----------------------------------------------------------------------------
	Types
----------------------------------------------------------------------------*/

											/* If you change this enumeration,
												you must also change the
												TinTin::m_pstrCommands array
												to correspond with the indices
												in this enumeration */

typedef enum { ttUnknown = -1, ttAction = 0, ttAlias, ttAntisubstitute,
				ttBell, ttBoss, ttChar, ttCr, ttEcho, ttEnd, ttGag, ttHelp,
				ttHighlight, ttHistory, ttIf, ttIgnore, ttInfo, ttKillall,
				ttLog, ttLoop, ttNop, ttMap, ttMath, ttMark, ttMessage,
				ttPath, ttPathdir, ttPresub, ttRedraw, ttRetab, ttReturn,
				ttRead, ttSavepath, ttShowme, ttSpeedwalk, ttStartquotes,
				ttSubstitute, ttTextin, ttTick, ttTickoff, ttTickon,
				ttTickset, ttTicksize, ttTolower, ttTogglesubs,
				ttToupper, ttUnaction, ttUnalias, ttUnantisubstitute,
				ttUnhighlight, ttUnsubstitute, ttUngag, ttUnpath,
				ttUnvariable, ttVariable, ttVersion, ttWizlist, ttWrite,
				ttWritesession, ttZap, ttVerbatim } TTCommand;


/*----------------------------------------------------------------------------
	Forward class declarations
----------------------------------------------------------------------------*/

class TinTin;
class TinTinList;


/*----------------------------------------------------------------------------
	TinTinListNode class
----------------------------------------------------------------------------*/

class TinTinListNode
{
	friend class TinTinList;

	public:
		TinTinListNode();
		TinTinListNode( const string& strLeft, const string& strRight,
						const string& strPriority );
		~TinTinListNode();

		inline TinTinListNode* GetNext() { return m_pNext; }
		inline const string& GetLeft() { return m_strLeft; }
		inline const string& GetRight() { return m_strRight; }
		inline const string& GetPriority() { return m_strPriority; }

	protected:
		TinTinListNode*	m_pNext;

		string			m_strLeft;
		string			m_strRight;
		string			m_strPriority;
};


/*----------------------------------------------------------------------------
	TinTinList class
----------------------------------------------------------------------------*/

class TinTinList
{
	public:
		TinTinList( TinTin* pTinTin );
		~TinTinList();

		inline TinTinListNode* GetTop() { return m_pTop; }

		void AddNode( const string& strLeft, const string& strRight,
						const string& strPriority );
		void InsertNode( const string& strLeft, const string& strRight,
							const string& strPriority, int iMode );
		void DeleteNode( TinTinListNode* pDelete );
		int GetCount();
		void Empty();

		TinTinListNode* Search( const string& strText );
		TinTinListNode* SearchBegin( const string& strText, int iMode );
		TinTinListNode* SearchWithWildchars( const string& strText );
		TinTinListNode* SearchWithWildchars( const string& strText,
												TinTinListNode* pStart );

		void ShowList();
		void ShowNode( TinTinListNode* pNode );

	protected:
		inline void InsertAfter( TinTinListNode* pNode,
									TinTinListNode* pNew )
						{
							TinTinListNode* pNext;

							if (pNode)
							{
								pNext = pNode->GetNext();
								pNode->m_pNext = pNew;
							}
							else
							{				// Insert as first node

								pNext = m_pTop;
								m_pTop = pNew;
							}

							pNew->m_pNext = pNext;
						}

	protected:
		TinTin* 			m_pTinTin;
		TinTinListNode*		m_pTop;
};


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

class ChTextInMainInfo;

class TinTin
{
	public:
		enum { msgIndexAliases, msgIndexActions, msgIndexSubstitutions,
				msgIndexAntiSub, msgIndexHilight, msgIndexVariable,
				msgIndexPathdir, msgIndexLast };

	public:
		TinTin();
		~TinTin();

		inline void ReadInitFile( const string& strFile )
						{
							DoRead( strFile, false );
						}
		inline void Reset() { DoKillAll( true ); }

		virtual void SendToWorld( const string& strOutput );
		virtual void Display( const string& strOutput );

		void ParseInput( const string& strInput );
		void SendToWorld( const string& strCmd, const string& strArgs );

		bool Match( const char* pstrRegex, const char* pstrTest );

	protected:
		inline char GetTinTinChar() { return m_cTinTin; }
		inline void SetTinTinChar( char cNewTinTin )
						{
							m_cTinTin = cNewTinTin;
						}
		inline char GetVerbatimChar() { return m_cVerbatim; }

		inline bool IsOnline() { return m_boolOnline; }
		inline bool IsVerbatim() { return m_boolVerbatim; }
		inline bool IsSpeedwalk() { return m_boolSpeedwalk; }
		inline bool IsUsingActions() { return m_boolDoActions; }
		inline bool IsUsingPresubs() { return m_boolPresub; }
		inline bool IsUsingStartQuotes() { return m_boolStartQuotes; }
		inline bool IsUsingSubs() { return m_boolDoSubs; }

											// In TinTinParse.cpp

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

											// In TinTinAlias.cpp
		void DoAlias( const string& strArgs );
		void DoUnalias( const string& strArgs );

											// In TinTinFiles.cpp

		void DoRead( const string& strFilename, bool boolOnline );

											// In TinTinMisc.cpp
		void DoBell();
		void DoChar( const string& strArg );
		void DoCR();
		void DoHelp( const string& strArgs );
		void DoInfo();
		void DoKillAll( bool boolQuiet );
		void DoWizList();
		void ToggleSpeedwalk();
		void ToggleStartQuotes();
		void ToggleVerbatim( const string& strArg );

											// In TinTinUtils.cpp

		TTCommand ParseTinTinCmd( const char* strCommand );
		bool IsAbrev( const char* pstr1, const char* pstr2 );

											// In TinTinVars.cpp

		void SubstituteVars( const char* pstrArg, string& strOut );
		void SubstituteMyVars( const char* pstrArg, string& strOut );

	protected:
		static const char*	m_pstrCommands[];

		char				m_cTinTin;
		const char			m_cVerbatim;

		bool				m_boolDisplayMessages[msgIndexLast];
		bool				m_boolOnline;

		bool				m_boolDoActions;
		bool				m_boolDoSubs;
		bool				m_boolPresub;
		bool				m_boolSpeedwalk;
		bool				m_boolStartQuotes;
		bool				m_boolVerbatim;

		int					m_iAliasCounter;
		int					m_iActionCounter;
		int					m_iSubCounter;
		int					m_iAntiSubCounter;
		int					m_iVarCounter;
		int					m_iHighlightCounter;

		string				m_strVars[10];	// %0 - %9 variables

		TinTinList*			m_pListAliases;
		TinTinList*			m_pListActions;
		TinTinList*			m_pListVars;
		TinTinList*			m_pListHighlights;
		TinTinList*			m_pListSubs;
		TinTinList*			m_pListAntiSubs;
		TinTinList*			m_pListPath;
		TinTinList*			m_pListPathDirs;
};


#if 0


struct session {
  struct session *next;
  char *name;
  char *address;
  int tickstatus;
  int snoopstatus;
  FILE *logfile;
  int ignore;
  struct listnode *aliases, *actions, *subs, *myvars, *highs, *antisubs;  
  char *history[HISTORY_SIZE];
  struct listnode *path, *pathdirs;
  int path_length, path_list_size;
  int socket, socketbit;
  int old_more_coming,more_coming;
  char last_line[BUFFER_SIZE];
};

/*********************************************************************/
/* file: tintin.h - the include file for tintin++                    */
/*                             TINTIN ++                             */
/*          (T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t             */
/*                    modified by Bill Reiss 1993                    */
/*                     coded by peter unold 1992                     */
/*********************************************************************/

/************************************************************************/
/* Do you want to use help compression or not:  with it, space is saved */
/* but without it the help runs slightly faster.  If so, make sure the  */
/* compression stuff is defined in the default values.                  */
/************************************************************************/

#ifndef COMPRESSED_HELP
#define COMPRESSED_HELP TRUE
#endif

#ifdef HAVE_BCOPY
#define memcpy(s1, s2, n) bcopy(s2, s1, n)
#endif

/***********************************************/
/* Some default values you might wanna change: */
/***********************************************/
#define SCREEN_WIDTH 80
#define CLEAN 0
#define END 1
#define OLD_LOG 0 /* set to one to use old-style logging */
#define DEFAULT_OPEN '{' /*character that starts an argument */
#define DEFAULT_CLOSE '}' /*character that ends an argument */
#define SYSTEM_COMMAND_DEFAULT "system"   /* name of the system command */
#define HISTORY_SIZE 30                   /* history size */
#define MAX_PATH_LENGTH 200               /* max path lenght */

#ifndef DEFAULT_FILE_DIR
#define DEFAULT_FILE_DIR "/usr/local/lib/tintin" /* Path to Tintin files, or HOME */
#endif
#if COMPRESSED_HELP
#define DEFAULT_COMPRESSION_EXT ".Z"     /* for compress: ".Z" */
#define DEFAULT_EXPANSION_STR "uncompress -c "/* for compress: "uncompress -c" */
#endif

#define DEFAULT_ECHO FALSE                /* echo */         
#define DEFAULT_IGNORE FALSE              /* ignore */
#define DEFAULT_SPEEDWALK TRUE           /* speedwalk */
#define DEFAULT_PRESUB TRUE               /* presub before actions */
#define DEFAULT_TOGGLESUBS FALSE          /* turn subs on and off FALSE=ON*/

#define DEFAULT_ALIAS_MESS TRUE           /* messages for responses */
#define DEFAULT_ACTION_MESS TRUE          /* when setting/deleting aliases, */
#define DEFAULT_SUB_MESS TRUE             /* actions, etc. may be set to */
#define DEFAULT_ANTISUB_MESS TRUE         /* default either on or off */
#define DEFAULT_HIGHLIGHT_MESS TRUE       /* TRUE=ON FALSE=OFF */
#define DEFAULT_VARIABLE_MESS TRUE        /* might want to turn off these */
#define DEFAULT_PATHDIR_MESS TRUE
#define DEFAULT_REDRAW FALSE
/**************************************************************************/
/* Whenever TINTIN has written something to the screen, the program sends */
/* a CR/LF to the diku to force a new prompt to appear. You can have      */
/* TINTIN print it's own pseudo prompt instead.                           */
/**************************************************************************/
#define PSEUDO_PROMPT TRUE 
/**************************************************************************/
/* the codes below are used for highlighting text, and is set for the     */
/* codes for VT-100 terminal emulation. If you are using a different      */
/* teminal type, replace the codes below with the correct codes and       */
/* change the codes set up in highlight.c                                 */
/**************************************************************************/
#define DEFAULT_BEGIN_COLOR "["
#define DEFAULT_END_COLOR "[m"
/*************************************************************************/
/* The text below is checked for. If it trickers then echo is turned off */
/* echo is turned back on the next time the user types a return          */
/*************************************************************************/
#define PROMPT_FOR_PW_TEXT "assword:"

/**************************************************************************/ 
/* The stuff below here shouldn't be modified unless you know what you're */
/* doing........                                                          */
/**************************************************************************/ 
#define BUFFER_SIZE 2048
#define VERSION_NUM "v1.5pl6  "
/************************ structures *********************/

struct completenode {
  struct completenode *next;
  char *strng;
};

#endif	// 0

#endif	// !defined( TINTIN_H )
