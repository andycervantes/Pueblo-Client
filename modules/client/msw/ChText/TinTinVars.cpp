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

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinVars.cpp,v 2.1 1996/02/14 01:31:27 coyote Exp $

#include <ChTypes.h>

#include "TinTin.h"


/*----------------------------------------------------------------------------
	TinTin class protected methods
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	TinTin::SubstituteVars
					Copy 'pstrArg' into 'strOut', but substitute
					the variables %0..%9 with the real variables.
----------------------------------------------------------------------------*/

void TinTin::SubstituteVars( const char* pstrArg, string& strOut )
{
	string			strResult;
	int				iPercentCount;
	int				iDollarCount;
	int				iNestLevel = 0;
	int				iArgNumber;

	while (*pstrArg)
	{
		if (*pstrArg == '%')
		{									// Substitute variable
			iPercentCount = 0;

			while (*(pstrArg + iPercentCount) == '%') 
			{
				iPercentCount++;
			}

			if (isdigit( *(pstrArg + iPercentCount) ) &&
				(iPercentCount == (iNestLevel + 1)))
			{
				iArgNumber = *(pstrArg + iPercentCount) - '0';
				strResult += m_strVars[iArgNumber];
				pstrArg += iPercentCount + 1;
			}
			else
			{
				string		strTemp( pstrArg );

				strResult += strTemp.Left( iPercentCount + 1 );
				pstrArg += iPercentCount + 1;
			}
		}

		if (*pstrArg=='$')
		{									// Substitute variable
			iDollarCount = 0;

			while (*(pstrArg + iDollarCount) == '$')
			{
				iDollarCount++;
			}

			if (isdigit( *(pstrArg + iDollarCount) ) &&
				(iDollarCount == (iNestLevel + 1)))
			{
				const char*		pstrText;

				iArgNumber = *(pstrArg + iDollarCount) - '0';

				pstrText = m_strVars[iArgNumber];
				while (*pstrText)
				{
					if (*pstrText == ';')
					{
						pstrText++;
					}
					else
					{
						strResult += *pstrText++;
					}
				}

				pstrArg += iDollarCount + 1;
			}
			else
			{
				string		strTemp( pstrArg );

				strResult += strTemp.Left( iPercentCount + 1 );
				pstrArg += iPercentCount + 1;
			}
		}
		else if (*pstrArg == DEF_OPEN)
		{
			iNestLevel++;
			strResult += *pstrArg++;
		}
		else if (*pstrArg==DEF_CLOSE)
		{
			iNestLevel--;
			strResult += *pstrArg++;
		}
		else if ((*pstrArg == '\\') && (iNestLevel == 0))
		{
			while (*pstrArg == '\\')
			{
				strResult += *pstrArg++;
			}

			if (*pstrArg == '%')
			{
				strResult += '\\';
				strResult += *pstrArg++;
			}
		}
		else
		{
			strResult += *pstrArg++;
		}
	}

	strOut = strResult;
}


/*----------------------------------------------------------------------------
	TinTin::SubstituteMyVars
					Substitute the variables $<string> with the values
					they stand for.
----------------------------------------------------------------------------*/

void TinTin::SubstituteMyVars( const char* pstrArg, string& strOut )
{
	string			strResult;
	int				iNestLevel = 0;

	while (*pstrArg)
	{
		if (*pstrArg == '$')
		{									// Substitute variable
			int		iCounter = 0;
			int		iVarLen = 0;
			string	strVarName;

			while (*(pstrArg + iCounter) == '$')
			{
				iCounter++;
			}

			while (isalpha( *(pstrArg + iVarLen + iCounter) )) 
			{
				iVarLen++;
			}

			if (iVarLen > 0)
			{
				strVarName = (const char*)(pstrArg + iCounter);
				strVarName = strVarName.Left( iVarLen );
			}

			if ((iCounter == iNestLevel + 1) &&
				!isdigit( *(pstrArg + iCounter + 1) ))
			{
				TinTinListNode*		pNode;

				pNode = m_pListVars->Search( strVarName );

				if (pNode)
				{
					strResult += pNode->GetRight();
					pstrArg += iCounter + iVarLen;
				}
				else
				{
					string		strTemp( pstrArg );

					strResult += strTemp.Left( iCounter + iVarLen );
					pstrArg += iCounter + iVarLen;
				}
			}
			else
			{
				string		strTemp( pstrArg );

				strResult += strTemp.Left( iCounter + iVarLen );
				pstrArg += iVarLen + iCounter;
			}
		}
		else if (*pstrArg == DEF_OPEN)
		{
			iNestLevel++;
			strResult += *pstrArg++;
		}
		else if (*pstrArg == DEF_CLOSE)
		{
			iNestLevel--;
			strResult += *pstrArg++;
		}
		else if ((*pstrArg == '\\') && (*(pstrArg + 1) == '$') &&
					(iNestLevel == 0))
		{
			pstrArg++;
			strResult += *pstrArg++;
		}
		else
		{
			strResult += *pstrArg++;
		}
	}

	strOut = strResult;
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: variables.c - functions related the the variables           */
/*                             TINTIN ++                             */
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
#include <ctype.h>
#include "tintin.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

extern char *get_arg_in_braces();
extern struct listnode *search_node_with_wild();
extern struct listnode *searchnode_list();

extern struct listnode *common_myvars;
extern char vars[10][BUFFER_SIZE]; /* the %0, %1, %2,....%9 variables */
extern int varnum;
extern int mesvar[5];
/*************************/
/* the #variable command */
/*************************/
void var_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE], right[BUFFER_SIZE], arg2[BUFFER_SIZE];
  struct listnode *tempvars, *ln;
  /* char right2[BUFFER_SIZE]; */
  tempvars=(ses) ? ses->myvars : common_myvars;
  arg=get_arg_in_braces(arg, left,0);
  arg=get_arg_in_braces(arg, right,1);
  if(!*left) {
    tintin_puts2("#THESE VARIABLES HAVE BEEN SET:", ses);
    show_list(tempvars);
    prompt(ses);
  }

  else if(*left && !*right) {
    if ((ln=search_node_with_wild(tempvars,left))!=NULL) {
      while((tempvars=search_node_with_wild(tempvars, left))!=NULL) {
        shownode_list(tempvars);
      }
      prompt(ses);
    }
    else
      if (mesvar[5])
        tintin_puts2("#THAT VARIABLE IS NOT DEFINED.", ses);
  }

  else {
    if((ln=searchnode_list(tempvars, left))!=NULL)
      deletenode_list(tempvars, ln);
    insertnode_list(tempvars, left, right, "0", ALPHA);
    varnum++;
    if (mesvar[5]) {
      sprintf(arg2, "#Ok. $%s is now set to {%s}.",left, right);
      tintin_puts2(arg2, ses);
    }
  }
}
/************************/
/* the #unvar   command */
/************************/
void unvar_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE] ,result[BUFFER_SIZE];
  struct listnode *tempvars, *ln, *temp;
  int flag;
  flag=FALSE;
  tempvars=(ses) ? ses->myvars : common_myvars;
  temp=tempvars;
  arg=get_arg_in_braces(arg,left,1);
  while ((ln=search_node_with_wild(temp, left))!=NULL) {
    if (mesvar[5]) {
      sprintf(result, "#Ok. $%s is no longer a variable.", ln->left);
      tintin_puts2(result, ses);
    }
    deletenode_list(tempvars, ln);
    flag=TRUE;
    temp=ln;
  }
  if (!flag && mesvar[5])
    tintin_puts2("#THAT VARIABLE IS NOT DEFINED.", ses);
}

/*************************/
/* the #tolower command */
/*************************/
void tolower_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE], right[BUFFER_SIZE], arg2[BUFFER_SIZE], *p;
  struct listnode *tempvars, *ln;

  tempvars = (ses) ? ses->myvars : common_myvars;
  arg = get_arg_in_braces(arg, left,0);
  arg = get_arg_in_braces(arg, right,1);
  if (!*left || !*right) {
    tintin_puts2("#Syntax: #tolower <var> <text>", ses);
  } else {
    if ((ln=searchnode_list(tempvars, left)) != NULL)
      deletenode_list(tempvars, ln);
    for (p=right; *p; p++)
      *p = tolower(*p);
    insertnode_list(tempvars, left, right, "0", ALPHA);
    varnum++;
    if (mesvar[5]) {
      sprintf(arg2, "#Ok. $%s is now set to {%s}.",left, right);
      tintin_puts2(arg2, ses);
    }
  }
}

/*************************/
/* the #toupper command */
/*************************/
void toupper_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE], right[BUFFER_SIZE], arg2[BUFFER_SIZE], *p;
  struct listnode *tempvars, *ln;

  tempvars = (ses) ? ses->myvars : common_myvars;
  arg = get_arg_in_braces(arg, left,0);
  arg = get_arg_in_braces(arg, right,1);
  if (!*left || !*right) {
    tintin_puts2("#Syntax: #toupper <var> <text>", ses);
  } else {
    if ((ln=searchnode_list(tempvars, left)) != NULL)
      deletenode_list(tempvars, ln);
    for (p=right; *p; p++)
      *p = toupper(*p);
    insertnode_list(tempvars, left, right, "0", ALPHA);
    varnum++;
    if (mesvar[5]) {
      sprintf(arg2, "#Ok. $%s is now set to {%s}.",left, right);
      tintin_puts2(arg2, ses);
    }
  }
}

#endif	// 0
