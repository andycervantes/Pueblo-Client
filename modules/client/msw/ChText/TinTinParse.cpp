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

	TinTin class main & parsing methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinParse.cpp,v 2.7 1996/02/17 02:17:53 coyote Exp $

#include <ChTypes.h>

#include <ctype.h>
#include <signal.h>

#include "TinTin.h"


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

TinTin::TinTin() :
			m_cTinTin( DEF_TINTIN_CHAR ),
			m_cVerbatim( DEF_VERBATIM_CHAR ),
			m_boolOnline( true ),
			m_boolDoActions( true ),
			m_boolDoSubs( true ),
			m_boolPresub( true ),
			m_boolSpeedwalk( false ),
			m_boolStartQuotes( false ),
			m_boolVerbatim( true ),
			m_iAliasCounter( 0 ),
			m_iActionCounter( 0 ),
			m_iSubCounter( 0 ),
			m_iAntiSubCounter( 0 ),
			m_iVarCounter( 0 ),
			m_iHighlightCounter( 0 )
{
	m_pListActions = new TinTinList( this );
	m_pListAliases = new TinTinList( this );
	m_pListHighlights = new TinTinList( this );
	m_pListPath = new TinTinList( this );
	m_pListPathDirs = new TinTinList( this );
	m_pListSubs = new TinTinList( this );
	m_pListAntiSubs = new TinTinList( this );
	m_pListVars = new TinTinList( this );

	m_boolDisplayMessages[msgIndexAliases] = true;
	m_boolDisplayMessages[msgIndexActions] = true;
	m_boolDisplayMessages[msgIndexSubstitutions] = true;
	m_boolDisplayMessages[msgIndexAntiSub] = true;
	m_boolDisplayMessages[msgIndexHilight] = true;
	m_boolDisplayMessages[msgIndexVariable] = true;
	m_boolDisplayMessages[msgIndexPathdir] = true;
}


TinTin::~TinTin()
{
	if (m_pListActions)
	{
		delete m_pListActions;
		m_pListActions = 0;
	}

	if (m_pListAliases)
	{
		delete m_pListAliases;
		m_pListAliases = 0;
	}

	if (m_pListHighlights)
	{
		delete m_pListHighlights;
		m_pListHighlights = 0;
	}

	if (m_pListPath)
	{
		delete m_pListPath;
		m_pListPath = 0;
	}

	if (m_pListPathDirs)
	{
		delete m_pListPathDirs;
		m_pListPathDirs = 0;
	}

	if (m_pListSubs)
	{
		delete m_pListSubs;
		m_pListSubs = 0;
	}

	if (m_pListAntiSubs)
	{
		delete m_pListAntiSubs;
		m_pListAntiSubs = 0;
	}

	if (m_pListVars)
	{
		delete m_pListVars;
		m_pListVars = 0;
	}
}


void TinTin::SendToWorld( const string& strOutput )
{
}


void TinTin::Display( const string& strOutput )
{
}


/*----------------------------------------------------------------------------
	TinTin::ParseInput
				Checks for TinTin commands and aliases.
----------------------------------------------------------------------------*/

void TinTin::ParseInput( const string& strInput )
{
	string			strWorking( strInput );
	const char*		pstrTemp;
	const char*		pstrStart;
	const char*		pstrWorking = strWorking;
	TinTinListNode*	pNode;
	string			strCommand;
	const char*		pstrCommand;
	string			strArgs;

	if (strWorking.IsEmpty())
	{										// Empty line
		SendToWorld( strWorking );
	}

	pstrTemp = GetArgStopAtSpaces( strWorking, strCommand );
	pstrStart = strCommand;

	if ((*pstrStart == GetTinTinChar()) &&
			IsAbrev( pstrStart + 1, "verbatim" ))
	{
											// Toggle verbatim status

		pstrTemp = GetArgAll( pstrTemp, strArgs );

		ToggleVerbatim( strArgs );
	}
	else if (IsVerbatim())
	{
		SendToWorld( strWorking );
	}
	else if (*pstrWorking == GetVerbatimChar())
	{										/* Line starts with verbatim
												escape, so send it 'as is'
												to the world */
		strWorking = pstrWorking++;
		SendToWorld( strWorking );
	}
	else
	{
		SubstituteMyVars( strWorking, strWorking );

		pstrWorking = strWorking;
		while (*pstrWorking)
		{
			bool		boolQuote;

			if (*pstrWorking == ';')
			{
				pstrWorking++;
			}

			if (boolQuote = (!IsUsingStartQuotes() && ('"' == *pstrWorking)))
			{
											/* We're not processing quotes
												at the start of a command, so
												don't include the quote in
												processing */
				pstrWorking++;
			}

			pstrWorking = GetArgStopAtSpaces( pstrWorking, strCommand );
			pstrWorking = GetArgAll( pstrWorking, strArgs );

			if (boolQuote)
			{								/* If we preserved a quote, add it
												back to the beginning of the
												string */
				strCommand = '"' + strCommand;
			}

			pstrCommand = strCommand;

			if (*pstrCommand == GetTinTinChar())
			{
				ParseTinTinCommand( pstrCommand + 1, strArgs );
			}
			else if (pNode = m_pListAliases->SearchBegin( strCommand, ALPHA ))
			{
											// Alias found
				int			iLoop;
				const char*	pstrBeginArg;
				const char*	pstrEndArg;
				char		cEnd;
				string		strNewCommand;
											// Strip out the arguments
				m_strVars[0] = strArgs;
				for (iLoop = 1, pstrBeginArg = strArgs; iLoop < 10; iLoop++)
				{
					string		strTemp;
											// Find the beginning of the arg
					while (*pstrBeginArg == ' ')
					{
						pstrBeginArg++;
					}
											// Find the end of the argument

					cEnd = (*pstrBeginArg == '{') ? '}' : ' ';
					pstrBeginArg = (*pstrBeginArg == '{') ?
										pstrBeginArg + 1 : pstrBeginArg;
					for (pstrEndArg = pstrBeginArg;
							*pstrEndArg && (*pstrEndArg != cEnd); pstrEndArg++)
						;
											// Chop out the argument
					strTemp = pstrBeginArg;
					m_strVars[iLoop] = strTemp.Left( pstrEndArg - pstrBeginArg );

											// Move to the next argument

					pstrBeginArg = (*pstrEndArg) ? pstrEndArg + 1 : pstrEndArg;
				}

				PrepareActionAlias( pNode->GetRight(), strNewCommand );

				if(!strcmp( pNode->GetRight(), strNewCommand ) &&
					!strArgs.IsEmpty())
				{							// Append arguments
					strNewCommand += " ";
					strNewCommand += strArgs;
				}

				ParseInput( strNewCommand );
			}
			else if (IsSpeedwalk() && strArgs.IsEmpty() &&
						IsSpeedwalkDirective( strCommand ))
			{
				DoSpeedwalk( strCommand );
			}
			else
			{
				GetArgWithSpaces( strArgs, strArgs );
				SendToWorld( strCommand, strArgs );
			}
		}
	}
}


void TinTin::SendToWorld( const string& strCmd, const string& strArgs )
{
	string	strTemp( strCmd );

	strTemp += ' ' + strArgs;
	SendToWorld( strTemp );
}


/*----------------------------------------------------------------------------
	TinTin::ParseTinTinCommand
				Parses and processes most of the TinTin commands.
----------------------------------------------------------------------------*/

void TinTin::ParseTinTinCommand( const string& strCommand, string& strArgs )
{
	const char*		pstrCommand = strCommand;

	if (isdigit( *pstrCommand ))
	{
		int		iCount = atoi( pstrCommand );

		if (iCount > 0)
		{
			GetArgInBraces( strArgs, strArgs );

			while (iCount-- > 0)
			{								// Recurse to process the strCommand
				ParseInput( strArgs );
			}
		}
		else
		{
			Display( "# Yeah right!  Go repeat that yourself dude." );
		}
	}
	else
	{
		TTCommand	cmd;

		cmd = ParseTinTinCmd( strCommand );

		switch( cmd )
		{
			case ttAlias:
			{
				DoAlias( strArgs );
				break;
			}

			case ttBell:
			{
				DoBell();
				break;
			}

			case ttChar:
			{
				DoChar( strArgs );
				break;
			}

			case ttCr:
			{
				DoCR();
				break;
			}

			case ttHelp:
			{
				DoHelp( strArgs );
				break;
			}

			case ttInfo:
			{
				DoInfo();
				break;
			}

			case ttKillall:
			{
				DoKillAll( false );
				break;
			}

			case ttNop:
			{
				break;
			}

			case ttRead:
			{
				DoRead( strArgs, true );
				break;
			}

			case ttSpeedwalk:
			{
				ToggleSpeedwalk();
				break;
			}

			case ttStartquotes:
			{
				ToggleStartQuotes();
				break;
			}

			case ttUnalias:
			{
				DoUnalias( strArgs );
				break;
			}

			case ttWizlist:
			{
				DoWizList();
				break;
			}

			default:
			{
				string		strFormat( "# Unknown command!  ('%s')" );
				string		strStatus;

				strStatus.Format( strFormat, (const char*)strCommand );
				Display( strStatus );
				break;
			}
		}
	}

	#if 0

//	else if (IsAbrev( strCommand, "action" ))
//	{
//		action_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "antisubstitute" ))
//	{
//		parse_antisub( strArgs );
//	}
//	else if (IsAbrev( strCommand, "boss" ))
//	{
//		boss_strCommand();
//	}
//	else if (IsAbrev( strCommand, "echo" ))
//	{
//		echo_strCommand();
//	}
//	else if (IsAbrev( strCommand, "end" ))
//	{
//		end_strCommand( strCommand );
//	}
//	else if (IsAbrev( strCommand, "highlight" ))
//	{
//		parse_high( strArgs );
//	}
//	else if (IsAbrev( strCommand, "history" ))
//	{
//		history_strCommand();
//	}
//	else if (IsAbrev( strCommand, "if" ))
//	{
//		if_strCommand(strArgs, ses);
//	}
//	else if (IsAbrev( strCommand, "ignore" ))
//	{
//		ignore_strCommand();
//	}
//	else if (IsAbrev( strCommand, "log" ))
//	{
//		log_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "loop" ))
//	{
//		loop_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "map" ))
//	{
//		map_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "math" ))
//	{
//		math_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "mark" ))
//	{
//		mark_strCommand();
//	}
//	else if (IsAbrev( strCommand, "message" ))
//	{
//		message_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "path" ))
//	{
//		path_strCommand();
//	}
//	else if (IsAbrev( strCommand, "pathdir" ))
//	{
//		pathdir_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "presub" ))
//	{
//		presub_strCommand();
//	}
//	else if (IsAbrev( strCommand, "redraw" ))
//	{
//		redraw_strCommand();
//	}
//	else if (IsAbrev( strCommand, "retab" ))
//	{
//		read_complete();
//	}
//	else if (IsAbrev( strCommand, "return" ))
//	{
//		return_strCommand();
//	}
//	else if (IsAbrev( strCommand, "savepath" ))
//	{
//		savepath_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "session" ))
//	{
//		session_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "showme" ))
//	{
//		showme_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "snoop" ))
//	{
//		snoop_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "split" ))
//	{
//		split_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "suspend" ))
//	{
//		tstphandler(SIGTSTP,0,NULL,NULL);
//	}
//	else if (IsAbrev( strCommand, "tablist" ))
//	{
//		tablist( complete_head );
//	}
//	else if (IsAbrev( strCommand, "tabadd" ))
//	{
//		tab_add( strArgs );
//	}
//	else if (IsAbrev( strCommand, "tabdelete" ))
//	{
//		tab_delete(strArgs);
//	}
//	else if (IsAbrev( strCommand, "textin" ))
//	{
//		read_file( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unsplit" ))
//	{
//		unsplit_strCommand();
//	}
//	else if (IsAbrev( strCommand, "substitute" ))
//	{
//		parse_sub( strArgs );
//	}
//	else if (IsAbrev( strCommand, "gag" ))
//	{
//		if (*strArgs != '{')
//		{
//			strcpy( strCommand, strArgs );
//			strcpy( strArgs, "{" );
//			strcat( strArgs, strCommand );
//			strcat( strArgs, "} " );
//		}
//		strcat( strArgs, " ." );
//
//		parse_sub( strArgs );
//	}
//	else if (IsAbrev( strCommand, system_com ))
//	{
//		system_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "tick" ))
//	{
//		tick_strCommand();
//	}
//	else if (IsAbrev( strCommand, "tickoff" ))
//	{
//		tickoff_strCommand();
//	}
//	else if (IsAbrev( strCommand, "tickon" ))
//	{
//		tickon_strCommand();
//	}
//	else if (IsAbrev( strCommand, "tickset" ))
//	{
//		tickset_strCommand();
//	}
//	else if (IsAbrev( strCommand, "ticksize" ))
//	{
//		ticksize_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "tolower" ))
//	{
//		tolower_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "togglesubs" ))
//	{
//		togglesubs_strCommand();
//	}
//	else if (IsAbrev( strCommand, "toupper" ))
//	{
//		toupper_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unaction" ))
//	{
//		unaction_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unantisubstitute" ))
//	{
//		unantisubstitute_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unhighlight" ))
//	{
//		unhighlight_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unsubstitute" ))
//	{
//		unsubstitute_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "ungag" ))
//	{
//		unsubstitute_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "unpath" ))
//	{
//		unpath_strCommand();
//	}
//	else if (IsAbrev( strCommand, "variable" ))
//	{
//		var_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "version" ))
//	{
//		version_strCommand();
//	}
//	else if (IsAbrev( strCommand, "unvariable" ))
//	{
//		unvar_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "write" ))
//	{
//		write_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "writesession" ))
//	{
//		writesession_strCommand( strArgs );
//	}
//	else if (IsAbrev( strCommand, "zap" ))
//	{
//		zap_strCommand();
//	}

	#endif
}


/*----------------------------------------------------------------------------
	TinTin::IsSpeedwalkDirective
				Returns true if command consists only of the letters
				[n,s,e,w,u,d] or digits followed by those letters.
----------------------------------------------------------------------------*/

bool TinTin::IsSpeedwalkDirective( const char* pstrCmd )
{
	bool	boolSpeedWalk = false;

	while (*pstrCmd)
	{
		if ((*pstrCmd != 'n') && (*pstrCmd != 'e') && (*pstrCmd != 's') &&
			(*pstrCmd != 'w') && (*pstrCmd != 'u') && (*pstrCmd != 'd') &&
			!isdigit( *pstrCmd ))
		{
			return false;
		}

		if (!isdigit( *pstrCmd ))
		{
			boolSpeedWalk = TRUE;
		}

		pstrCmd++;
	}

	return boolSpeedWalk;
}


/*----------------------------------------------------------------------------
	TinTin::DoSpeedwalk
				This function will interpret and perform a speedwalk
				command.
----------------------------------------------------------------------------*/

void TinTin::DoSpeedwalk( const char* pstrCmd )
{
	while (*pstrCmd)
	{
		const char*	pstrStart = pstrCmd;
		bool		boolMultiple = false;
		char		cDirection;
		int			iCount;

		while (isdigit( *pstrCmd ))
		{
			pstrCmd++;
			boolMultiple = true;
		}

		if (boolMultiple && *pstrCmd)
		{
			if (2 == sscanf( pstrStart, "%d%c", &iCount, cDirection ))
			{
				for (int iLoop = 0; iLoop < iCount; iLoop++)
				{
					SendToWorld( cDirection );
				}
			}
		}
		else if (*pstrCmd)
		{
			SendToWorld( cDirection );
		}

		if (*pstrCmd)
		{
			pstrCmd++;
		}
	}
}


/*----------------------------------------------------------------------------
	TinTin::GetArgStopAtSpaces
				Get all arguments - don't remove double-quotes or
				back-slashes.
----------------------------------------------------------------------------*/

const char* TinTin::GetArgAll( const char* pstrText, string& strArg )
{
	int		iNestLevel = 0;

	strArg = "";
	pstrText = SpaceOut( pstrText );

	while (*pstrText)
	{
		if (*pstrText == '\\')
		{									/* Next character is quoted,
												so leave it in to be
												processed later */
			strArg += *pstrText++;
			if (*pstrText)
			{
				strArg += *pstrText++;
			}
		}
		else if ((*pstrText == ';') && (0 == iNestLevel))
		{
											// Semicolon ends the command...
			break;
		}
		else if (*pstrText == DEF_OPEN)
		{									// Open argument
			iNestLevel++;
			strArg += *pstrText++;
		}
		else if (*pstrText == DEF_CLOSE)
		{									// Close argument
			if (0 > --iNestLevel)
			{
				iNestLevel = 0;
			}
			strArg += *pstrText++;
		}
		else
		{									// Copy the character
			strArg += *pstrText++;
		}
	}

	return pstrText;
}


/*----------------------------------------------------------------------------
	TinTin::GetArgInBraces
				Get the argument.  If the argument is bracketed with
				curly braces, just get that part.
----------------------------------------------------------------------------*/

const char* TinTin::GetArgInBraces( const char* pstrText, string& strArg,
									bool boolIncludeSpaces )
{
	int			iNestLevel = 0;
	const char*	pstrTemp;
	string		strResult;

	pstrText = SpaceOut( pstrText );

	pstrTemp = pstrText;

	if (*pstrText != DEF_OPEN)
	{										// This isn't bracketed in braces
		if (boolIncludeSpaces)
		{
			pstrText = GetArgWithSpaces( pstrText, strArg );
		}
		else
		{
			pstrText = GetArgStopAtSpaces( pstrText, strArg );
		}

		return pstrText;
	}

	pstrText++;

	while (*pstrText && !((*pstrText == DEF_CLOSE) && (iNestLevel == 0)))
	{
		if (*pstrText == DEF_OPEN)
		{
			iNestLevel++;
		}
		else if (*pstrText == DEF_CLOSE)
		{
			iNestLevel--;
		}

		strResult += *pstrText++;
	}

	strArg = strResult;

	if (!*pstrText)
	{										/* There should be a '}' still
												in the buffer */

		Display( "# Unmatched braces error!" );
	}
	else
	{										// Skip the close brace
		pstrText++;
	}

	return pstrText;
}


/*----------------------------------------------------------------------------
	TinTin::GetArgStopAtSpaces
				Gets a single argument, stopping at spaces and removing
				quotes.
----------------------------------------------------------------------------*/

const char* TinTin::GetArgStopAtSpaces( const char* pstrText, string& strArg )
{
	bool	boolInside = false;

	strArg = "";
	pstrText = SpaceOut( pstrText );

	while (*pstrText)
	{
		if (*pstrText == '\\')
		{									// Next character is quoted
			if (*++pstrText)
			{
				strArg += *pstrText++;
			}
		}
		else if (*pstrText == '"')
		{									// We're inside a double-quote
			pstrText++;
			boolInside = !boolInside;
		}
		else if (*pstrText == ';')
		{
			if (boolInside)
			{								/* Semicolon inside a double-quote.
												Copy it verbatim. */
				strArg += *pstrText++;
			}
			else
			{								// Semicolon ends the command...
				break;
			}
		}
		else if (!boolInside && (*pstrText == ' '))
		{
											// End at a space...
			break;
		}
		else
		{									// Copy the character
			strArg += *pstrText++;
		}
	}

	return pstrText;
}


/*----------------------------------------------------------------------------
	TinTin::GetArgWithSpaces
				Gets the entire argument, including spaces,
				removing quotes.

				For example:
					In:		"this is it" way way hmmm;
					Out:	this is it way way hmmm
----------------------------------------------------------------------------*/

const char* TinTin::GetArgWithSpaces( const char* pstrText, string& strArg )
{
	int			iNestLevel = 0;
	string		strTemp;

	pstrText = SpaceOut( pstrText );

	while (*pstrText)
	{
		if (*pstrText == '\\')
		{
			if (*++pstrText)
			{
				strTemp += *pstrText++;
			}
		}
		else if ((*pstrText == ';') && (0 == iNestLevel))
		{
			break;
		}
		else if (*pstrText == DEF_OPEN)
		{
			iNestLevel++;
			strTemp += *pstrText++;
		}
		else if(*pstrText == DEF_CLOSE)
		{
			strTemp += *pstrText++;
			iNestLevel--;
		}
		else
		{
			strTemp += *pstrText++;
		}
	}

	strArg = strTemp;
	return pstrText;
}


/*----------------------------------------------------------------------------
	TinTin::SpaceOut
				Advances point to next non-space.
----------------------------------------------------------------------------*/

const char* TinTin::SpaceOut( const char* pstrText )
{
	while (isspace( *pstrText ))
	{
		pstrText++;
	}

	return pstrText;
}


#if 0

/*********************************************************************/
/* file: parse.c - some utility-functions                            */
/*                             TINTIN III                            */
/*          (T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t             */
/*                     coded by peter unold 1992                     */
/*********************************************************************/
#ifdef HAVE_STRING_H
#include <string.h>
#else
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#endif


#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

struct session *parse_tintin_command();
void do_speedwalk();
char *get_arg_with_spaces();

extern struct listnode *searchnode_list_begin();
extern struct session *all_command();
extern struct session *read_command();
extern struct session *session_command();
extern struct session *write_command();
extern struct session *writesession_command();
extern struct session *zap_command();
extern struct completenode *complete_head;
extern char *space_out();
extern char *get_arg_in_braces();
void write_com_arg_mud();
void prompt();

extern char k_input[240];
extern struct session *sessionlist, *activesession;
extern struct listnode *common_aliases, *common_actions, *common_subs;
extern struct listnode *common_myvars, *common_antisubs;
extern char vars[10][BUFFER_SIZE]; /* the %0, %1, %2,....%9 variables */
extern char tintin_char, verbatim_char;
extern int term_echoing, verbatim;
extern int speedwalk, is_split, display_row, display_col, input_row, input_col;
extern char system_com[80];
extern void action_command();
extern void unhighlight_command();
extern char *get_arg_stop_spaces();
extern char *cryptkey;
extern char *get_arg_all();
extern void tstphandler();




/**********************************************/
/* get all arguments - don't remove "s and \s */
/**********************************************/
char *get_arg_all(s, arg)
     char *s;
     char *arg;
{
  /* int inside=FALSE; */
  int nest=0;
  s=space_out(s);
  while(*s) {

    if(*s=='\\') {
      *arg++=*s++;
      if(*s)
	*arg++=*s++;
    }


    else if(*s==';' && nest<1) {
	break;
    }

    else if(*s==DEFAULT_OPEN) {
      nest++;
      *arg++=*s++;
    }

    else if(*s==DEFAULT_CLOSE) {
      nest--;
      *arg++=*s++;
    }

    else
      *arg++=*s++;
  }

  *arg='\0';
  return s;
}

#endif	// 0
