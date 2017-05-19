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

	TinTin class linked list methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinAction.cpp,v 2.1 1996/02/14 01:31:24 coyote Exp $

#include <ChTypes.h>

#include "TinTin.h"


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	TinTin::PrepareActionAlias
				Run throught each of the commands on the right side of an
				alias/action expression, call substitute_text() for all
				commands but #alias/#action.
----------------------------------------------------------------------------*/

void TinTin::PrepareActionAlias( const string& strText, string& strResult )
{
	SubstituteVars( strText, strResult );
	SubstituteMyVars( strResult, strResult );
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: action.c - funtions related to the action command           */
/*                             TINTIN III                            */
/*          (T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t             */
/*                     coded by peter unold 1992                     */
/*********************************************************************/
#include <ctype.h>
#ifdef HAVE_STRING_H
#include <string.h>
#else
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#endif
#include "tintin.h"

extern struct session *activesession;
extern struct listnode *common_actions;
extern char vars[10][BUFFER_SIZE]; /* the &0, %1, %2,....%9 variables */
extern int term_echoing;
extern int echo;
extern char tintin_char;
extern int acnum;
extern int mesvar[6];
extern char *get_arg_in_braces();
extern struct listnode *search_node_with_wild();
extern struct listnode *searchnode_list();
void substitute_vars();
int var_len[10];
char *var_ptr[10];

/***********************/
/* the #action command */
/***********************/

/*  Priority code added by Joann Ellsworth 2/2/94 */

void action_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE], right[BUFFER_SIZE], result[BUFFER_SIZE];
  char pr[BUFFER_SIZE];
  struct listnode *myactions, *ln;

  myactions=(ses) ? ses->actions : common_actions;
  arg=get_arg_in_braces(arg, left, 0);
  arg=get_arg_in_braces(arg, right, 1);
  arg=get_arg_in_braces(arg, pr, 1);
  if (!*pr) strcpy(pr, "5"); /* defaults priority to 5 if no value given */
  if(!*left) {
    tintin_puts2("#Defined actions:", ses);
    show_list_action(myactions);
    prompt(ses);
  }

  else if(*left && !*right) {
    if ((ln=search_node_with_wild(myactions,left))!=NULL) {
      while((myactions=search_node_with_wild(myactions, left))!=NULL) {
        shownode_list_action(myactions);
      }
      prompt(ses);
    }
    else
      if (mesvar[1])
        tintin_puts("#That action is not defined.", ses);
  }

  else {
    if((ln=searchnode_list(myactions, left))!=NULL)
      deletenode_list(myactions, ln);
    insertnode_list(myactions, left, right, pr, PRIORITY);
    if (mesvar[1]) {
      sprintf(result,"#Ok. {%s} now triggers {%s} @ {%s}",left,right,pr);
      tintin_puts2(result, ses);
    }
    acnum++;
  }
}

/*************************/
/* the #unaction command */
/*************************/
void unaction_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE] ,result[BUFFER_SIZE];
  struct listnode *myactions, *ln, *temp;
  int flag;
  flag=FALSE;
  myactions=(ses) ? ses->actions : common_actions;
  temp=myactions;
  arg=get_arg_in_braces(arg,left,1);
  while ((ln=search_node_with_wild(temp, left))!=NULL) {
    if (mesvar[1]) {
      sprintf(result,"#Ok. {%s} is no longer a trigger.",ln->left);
      tintin_puts2(result, ses);
    }
    deletenode_list(myactions, ln);
    flag=TRUE;
    temp=ln;
  }
  if (!flag && mesvar[1]) {
    sprintf(result, "#No match(es) found for {%s}", left);
    tintin_puts2(result, ses);
  }
}


/**********************************************/
/* check actions from a sessions against line */
/**********************************************/
void check_all_actions(line, ses)
     char *line;
     struct session *ses;
{

  struct listnode *ln;
 static char temp[BUFFER_SIZE]=PROMPT_FOR_PW_TEXT;
 char strng[BUFFER_SIZE];
 if(check_one_action(line, temp, ses) && ses==activesession) {
    term_noecho();
    term_echoing=FALSE;
  } 
  ln=(ses) ? ses->actions : common_actions;

  while(( ln=ln->next )) {
    if(check_one_action(line, ln->left,ses)) {
      char buffer[BUFFER_SIZE];
      prepare_actionalias(ln->right, buffer,ses);
      if(echo && activesession==ses) { 
        sprintf(strng, "[ACTION: %s]", buffer);
        tintin_puts2(strng, activesession);
      }
      parse_input(buffer, ses);
      return;
    }
  }
}

int match_a_string(line, mask)
     char *line;
     char *mask;
{
  char *lptr, *mptr;
  lptr=line;
  mptr=mask;
  while (*lptr && *mptr && !(*mptr=='%' && isdigit(*(mptr+1)))) {
    if (*lptr++!=*mptr++)
      return -1;
  }
  if (!*mptr || (*mptr=='%' && isdigit(*(mptr+1)))) {
    return (int)(lptr-line);
  }
  return -1;
}

int check_one_action(line, action, ses)
     char *line;
     char *action;
     struct session *ses;
{
  int i; 
  if (check_a_action(line,action,ses)) {
    for(i=0; i<10; i++) {
      if (var_len[i]!=-1) {
        strncpy(vars[i], var_ptr[i], var_len[i]);
        *(vars[i]+var_len[i])='\0'; 
      }
    }
    return TRUE;
  }       
  else
    return FALSE;
}
/******************************************************************/
/* check if a text triggers an action and fill into the variables */
/* return TRUE if triggered                                       */
/******************************************************************/
int check_a_action(line, action, ses)
     char *line;
     char *action;
     struct session *ses;
{   
  char result[BUFFER_SIZE];
  char *temp2, *tptr, *lptr, *lptr2;
  int  i,flag_anchor, count, len, flag;
  for (i=0; i<10; i++) var_len[i]=-1;
  flag_anchor=FALSE;
  lptr=line;
  substitute_myvars(action,result,ses);
  tptr=result;
  if(*tptr=='^') {
    tptr++;
    flag_anchor=TRUE;
    /* CHANGED to fix a bug with #action {^%0 foo}
     * Thanks to Spencer Sun for the bug report (AND fix!)
    if (*tptr!=*line)
      return FALSE;
    */
  }
  if (flag_anchor) {
    if ((len=match_a_string(lptr, tptr))==-1)
      return FALSE;
    lptr+=len;
    tptr+=len;
  }
  else {
    flag=TRUE;
    len=-1;
    while(*lptr && flag) {
      if((len=match_a_string(lptr, tptr))!=-1) {
        flag=FALSE;
      }
      else
        lptr++;
    }
    if (len!=-1) {
      lptr+=len;
      tptr+=len;
    }
    else
      return FALSE;
  }
  while(*lptr && *tptr) {
    temp2=tptr+2;
    if (!*temp2) {
      var_len[*(tptr+1)-48]=strlen(lptr);
      var_ptr[*(tptr+1)-48]=lptr;
      return TRUE;
    }
    lptr2=lptr;
    flag=TRUE;
    len=-1;
    while(*lptr2 && flag) {
      if ((len=match_a_string(lptr2, temp2))!=-1) {
        flag=FALSE;
      }
      else 
        lptr2++;
    }
    if (len!=-1) {
      var_len[*(tptr+1)-48]=lptr2-lptr;
      var_ptr[*(tptr+1)-48]=lptr;
      lptr=lptr2+len;
      tptr=temp2+len;
    }
    else {
      return FALSE;
    }
  }
  if (*tptr)
    return FALSE;
  else
    return TRUE;
}       
    


#endif
