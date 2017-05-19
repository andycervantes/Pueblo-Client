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

	TinTin class utility methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinUtils.cpp,v 2.3 1996/02/16 23:05:19 coyote Exp $

#include <ChTypes.h>

#include "TinTin.h"


/*----------------------------------------------------------------------------
	TinTin class protected methods
----------------------------------------------------------------------------*/

											/* If you change this array must
												also change the TTCommand
												enumeration to correspond
												with the indices in this
												array */
                      
const char* TinTin::m_pstrCommands[] =
						{	"action",
							"alias",
							"antisubstitute",
							"bell",
							"boss",
							"char",
							"cr",
							"echo",
							"end",
							"gag",
							"help",
							"highlight",
							"history",
							"if",
							"ignore",
							"info",
							"killall",
							"log",
							"loop",
							"nop",
							"map",
							"math",
							"mark",
							"message",
							"path",
							"pathdir",
							"presub",
							"redraw",
							"retab",
							"return",
							"read",
							"savepath",
							"showme",
							"speedwalk",
							"startquotes",
							"substitute",
							"textin",
							"tick",
							"tickoff",
							"tickon",
							"tickset",
							"ticksize",
							"tolower",
							"togglesubs",
							"toupper",
							"unaction",
							"unalias",
							"unantisubstitute",
							"unhighlight",
							"unsubstitute",
							"ungag",
							"unpath",
							"unvariable",
							"variable",
							"version",
							"wizlist",
							"write",
							"writesession",
							"zap",
							"verbatim",		// This is at the end for a reason
							0 };


/*----------------------------------------------------------------------------
	TinTin::ParseTinTinCmd
				Returns the TTCommand value corresponding to the passed
				string.  Abbreviations are matched.
----------------------------------------------------------------------------*/

TTCommand TinTin::ParseTinTinCmd( const char* strCommand )
{
	const char**	ppstrThisCommand = m_pstrCommands;
	TTCommand		foundCommand = ttUnknown;
	int				iLoop = 0;

	while (*ppstrThisCommand && (ttUnknown == foundCommand))
	{
		if (IsAbrev( strCommand, *ppstrThisCommand ))
		{
			foundCommand = (TTCommand)iLoop;
		}

		iLoop++;
		ppstrThisCommand++;
	}

	return foundCommand;
}


/*----------------------------------------------------------------------------
	TinTin::IsAbrev
				Returns true if pstr1 is an abbreviation of pstr2.
----------------------------------------------------------------------------*/

bool TinTin::IsAbrev( const char* pstr1, const char* pstr2 )
{
	return( !strncmp( pstr2, pstr1, strlen( pstr1 ) ) );
}


/*----------------------------------------------------------------------------
	TinTin::Match
				Lightweight regular expression matching.  Only matches '*'
				and understands backslashes for escaping.
----------------------------------------------------------------------------*/

bool TinTin::Match( const char* pstrRegex, const char* pstrTest )
{
	while (*pstrRegex != 0)
	{
		char		cRegex;

		switch (cRegex = *pstrRegex++)
		{
			case '*':
			{
				const char*	pstrSave;
											/* Match empty strTest at end
												of `strTest' */
				if (0 == *pstrTest)
				{							/* ... but only if we're done
													with the pattern */
					return (0 == *pstrRegex);
				}
											/* Greedy algorithm: save starting
												location, then find end of
												strTest */
				pstrSave = pstrTest;
				pstrTest += strlen( pstrTest );

				do
				{
					if (Match( pstrRegex, pstrTest ))
					{
											// Return success if we match here
						return true;
					}
											// Otherwise back up and try again

				} while (--pstrTest >= pstrSave);

											/* Backed up all the way to the
												starting location (i.e. `*'
												matches empty strTest) and
												we _still_ can't match here.
												Give up. */
				return false;
			}

			case '\\':
			{
				if ((cRegex = *pstrRegex++) != '\0')
				{
											/* If not end of pattern, match
												next char explicitly */
					if (cRegex != *pstrTest++)
					{
						return false;
					}
					break;
				}
				
				/* else FALL THROUGH to match a backslash */
			}

			default:
			{								// Normal character
				if (cRegex != *pstrTest++)
				{
					return false;
				}
				break;
			}
		}
	}
											/* OK, we successfully matched the
												pattern if we got here.  Now
												return a match if we also
												reached end of strTest,
												otherwise failure */
	return (0 == *pstrTest);
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: utils.c - some utility-functions                            */
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
#include "tintin.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

void syserr();


/********************************/
/* strdup - duplicates a string */
/* return: address of duplicate */
/********************************/
char *mystrdup(s)
     char *s;
{
  char *dup;

  if((dup=(char *)malloc(strlen(s)+1))==NULL)
    syserr("Not enought memory for strdup.");
  strcpy(dup, s);
  return dup;
}


/*************************************************/
/* print system call error message and terminate */
/*************************************************/
void syserr(msg)
     char *msg;
{
  extern int errno, sys_nerr;
  extern char *sys_errlist[];

  fprintf(stderr,"ERROR: %s (%d",msg, errno);
  if(errno>0 && errno<sys_nerr)
    fprintf(stderr,": %s)\n",sys_errlist[errno]);
  else
    fprintf(stderr,")\n");
  exit(1);
}

#endif	// 0

