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

	TinTin class miscellaneous methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinMisc.cpp,v 2.6 1996/02/17 02:17:52 coyote Exp $

#include <ChTypes.h>
#include <ChDlg.h>

#include "TinTin.h"
#include "TinTinInfo.h"
#include "TinTinWizList.h"


/*----------------------------------------------------------------------------
	TinTin class protected methods
----------------------------------------------------------------------------*/

void TinTin::DoBell()
{
	MessageBeep( MB_OK );
}


/*----------------------------------------------------------------------------
	TinTin::DoChar
				Changes the TinTin escape character (start of commands.)
----------------------------------------------------------------------------*/

void TinTin::DoChar( const string& strArg )
{
	string	strWorking( strArg );

	GetArgInBraces( strWorking, strWorking, true );

	if (ispunct( strWorking[0] ))
	{
		string		strTemp;

		SetTinTinChar( strWorking[0] );

		strTemp.Format( "# OK.  The TinTin command character is now {%c}",
							GetTinTinChar() );
		Display( strTemp );
	}
	else
	{
		Display( "# Error - Please specify a punctuation character, "
					"like # or /" );
	}
}


void TinTin::DoCR()
{
	SendToWorld( "\n" );
}


void TinTin::DoHelp( const string& strArgs )
{
	string		strTopic;
	DWORD		dwKey = 0;

	GetArgStopAtSpaces( strArgs, strTopic );

	if (strTopic.IsEmpty())
	{
		strTopic = TINTIN_HELP_PREFIX ",overview";
		dwKey = (DWORD)(const char*)strTopic;
	}
	else
	{
		TTCommand	cmd;

		cmd = ParseTinTinCmd( strTopic );

		if (ttUnknown == cmd)
		{
			string		strFormat( "# Unknown command!  ('%s')" );
			string		strStatus;

			strStatus.Format( strFormat, (const char*)strTopic );
			Display( strStatus );
		}
		else
		{
			strTopic = m_pstrCommands[(int)cmd];

			strTopic = TINTIN_HELP_PREFIX ",#" + strTopic;
			dwKey = (DWORD)(const char*)strTopic;
		}
	}

	if (dwKey)
	{
		AfxGetApp()->WinHelp( dwKey, HELP_KEY );
	}
}


void TinTin::DoInfo()
{
	TinTinInfo		info;

	info.SetCounts( m_pListActions->GetCount(),
					m_pListAliases->GetCount(),
					m_pListSubs->GetCount(),
					m_pListAntiSubs->GetCount(),
					m_pListVars->GetCount(),
					m_pListHighlights->GetCount() );
	info.SetFlags( IsUsingActions(), IsUsingStartQuotes(), IsSpeedwalk(),
					IsUsingSubs(), IsUsingPresubs() );

	info.DoModal();
}


/*----------------------------------------------------------------------------
	TinTin::DoKillAll
				Empties the lists.
----------------------------------------------------------------------------*/

void TinTin::DoKillAll( bool boolQuiet )
{
	m_pListAliases->Empty();
	m_pListActions->Empty();
	m_pListVars->Empty();
	m_pListHighlights->Empty();
	m_pListSubs->Empty();
	m_pListAntiSubs->Empty();
	m_pListPath->Empty();
	m_pListPathDirs->Empty();

	if (!boolQuiet)
	{
		Display( "# Lists cleared." );
	}
}


void TinTin::DoWizList()
{
	TinTinWizList	wizList;

	wizList.DoModal();
}


/*----------------------------------------------------------------------------
	TinTin::ToggleQuotes
				Toggles the 'quotes' state.  If 'quotes' is true, then
				tintin treats double-quotes at the beginning of
				a line as the start of a quoted string.  Otherwise, these
				quotes are sent to the world as-is.
----------------------------------------------------------------------------*/

void TinTin::ToggleSpeedwalk()
{
	m_boolSpeedwalk = !IsSpeedwalk();

	if (IsSpeedwalk())
	{
		Display( "# Speedwalk is now on." );
	}
	else 
	{
		Display( "# Speedwalk is now off." );
	}
}


/*----------------------------------------------------------------------------
	TinTin::ToggleStartQuotes
				Toggles the 'quotes' state.  If 'quotes' is true, then
				tintin treats double-quotes at the beginning of
				a line as the start of a quoted string.  Otherwise, these
				quotes are sent to the world as-is.
----------------------------------------------------------------------------*/

void TinTin::ToggleStartQuotes()
{
	m_boolStartQuotes = !IsUsingStartQuotes();

	if (IsUsingStartQuotes())
	{
		Display( "# Initial double-quotes are now processed." );
	}
	else 
	{
		Display( "# Initial double-quotes are sent to the world." );
	}
}


/*----------------------------------------------------------------------------
	TinTin::ToggleVerbatim
				Toggles the verbatim state.  If 'verbatim' is true, then
				all text is sent 'as is' to the world.

				strArg may be 'on' or 'off' to set the mode explicitly.
----------------------------------------------------------------------------*/

void TinTin::ToggleVerbatim( const string& strArg )
{
	string		strMode( strArg );
	bool		boolError = false;

	strMode.MakeLower();

	if (strMode.IsEmpty())
	{
		m_boolVerbatim = !IsVerbatim();
	}
	else if ("on" == strMode)
	{
		m_boolVerbatim = true;
	}
	else if ("off" == strMode)
	{
		m_boolVerbatim = false;
	}
	else
	{
		Display( "# Error - Parameter to #verbatim must be 'on' or 'off'." );
		boolError = true;
	}

	if (!boolError)
	{
		if (IsVerbatim())
		{
			Display( "# All text is now sent 'as is'." );
		}
		else 
		{
			Display( "# Text is no longer sent 'as is'." );
		}
	}
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: misc.c - misc commands                                      */
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
#include <ctype.h>
#include "tintin.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

/* externs */
extern struct session *newactive_session();
extern struct listnode *common_aliases, *common_actions, *common_subs, *common_myvars;
extern struct listnode *common_highs, *common_antisubs, *common_pathdirs;
extern char *get_arg_in_braces();
extern void term_echo();
extern int redraw, is_split;
extern struct session *sessionlist;
extern struct completenode *complete_head;
extern char tintin_char;
extern int echo;
extern int speedwalk;
extern int presub;
extern int togglesubs;
extern char vars[10][BUFFER_SIZE]; /* the %0, %1, %2,....%9 variables */
extern int mesvar[7];
extern int verbatim;

/****************************/
/* the version command      */
/****************************/
void version_command()
{ 
  char temp[80];
  sprintf(temp,"#You are using TINTIN++ %s\n\r", VERSION_NUM);
  tintin_puts2(temp, NULL);
  prompt(NULL);
} 
/****************************/
/* the verbatim command,    */
/* used as a toggle         */
/****************************/
void verbatim_command()
{
  verbatim=!verbatim;
  if (verbatim) 
    tintin_puts2("#All text is now sent 'as is'.", (struct sesssion *)NULL);
  else 
    tintin_puts2("#Text is no longer sent 'as is'.", (struct session *)NULL); 
  prompt(NULL);
}

void redraw_command()
{
  redraw=!redraw;
  if (redraw) 
    tintin_puts2("#Ok. I now redraw input line when text arrives.", (struct session *)NULL);
  else
    tintin_puts2("#Ok. I no longer redraw the input line.", (struct session *)NULL);
  prompt(NULL);
}


/*********************/
/* the #boss command */
/*********************/
void boss_command(ses)
     struct session *ses;
{
  char temp[80];
  int i;
  for(i=0; i<50; i++) {
    sprintf(temp, "in-order traverse of tree starting from node %d resulted in %d red nodes\n", i, 50-i);
    tintin_puts2(temp, (struct session *)NULL);
  }
  getchar(); /* stop screen from scrolling stuff */
}

/*********************/
/* the #echo command */
/*********************/
void echo_command(ses)
     struct session *ses;
{
  echo=!echo;
  if(echo)
    tintin_puts("#ECHO IS NOW ON.", ses);
  else
    tintin_puts("#ECHO IS NOW OFF.", ses);
}

/*********************/
/* the #end command */
/*********************/
void end_command(command, ses)
     char *command;
     struct session *ses;
{
  if(strcmp(command, "end"))
    tintin_puts("#YOU HAVE TO WRITE #end - NO LESS, TO END!", ses);
  else {
    struct session *sesptr;
    for(sesptr=sessionlist; sesptr; sesptr=sesptr->next) 
      cleanup_session(sesptr);
    ses=NULL;  
    if (is_split) 
      write(1, "c", 3);
    tintin_puts2("TINTIN suffers from bloodlack, and the lack of a beating heart...", ses);
    tintin_puts2("TINTIN is dead! R.I.P.", ses);
    tintin_puts2("Your blood freezes as you hear TINTIN's death cry.", ses);
    term_echo();
    exit(0);
  }
}

/***********************/
/* the #ignore command */
/***********************/
void ignore_command(ses)
     struct session *ses;
{
  if (ses) {
    if(ses->ignore=!ses->ignore)
      tintin_puts("#ACTIONS ARE IGNORED FROM NOW ON.", ses);
    else
      tintin_puts("#ACTIONS ARE NO LONGER IGNORED.", ses);
  } else tintin_puts("#No session active => Nothing to ignore!", ses);     
}

/**********************/
/* the #presub command*/
/**********************/
void presub_command(ses)
     struct session *ses;
{
  presub=!presub;
  if(presub)
    tintin_puts("#ACTIONS ARE NOW PROCESSED ON SUBSTITUTED BUFFER.",ses);
  else
    tintin_puts("#ACTIONS ARE NO LONGER DONE ON SUBSTITUTED BUFFER.",ses);
}

/**************************/
/* the #togglesubs command*/
/**************************/
void togglesubs_command(ses)
     struct session *ses;
{
  togglesubs=!togglesubs;
  if(togglesubs)
    tintin_puts("#SUBSTITUTES ARE NOW IGNORED.",ses);
  else 
    tintin_puts("#SUBSTITUTES ARE NO LONGER IGNORED.", ses);
}

/***********************/
/* the #showme command */
/***********************/
void showme_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char result[BUFFER_SIZE], strng[BUFFER_SIZE];
  get_arg_in_braces(arg,arg,1);
  prepare_actionalias(arg,result,ses);
  sprintf(strng,"%s",result);
  tintin_puts(strng, ses);
}
/***********************/
/* the #loop command   */
/***********************/
void loop_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char left[BUFFER_SIZE],right[BUFFER_SIZE];
  char result[BUFFER_SIZE];
  int flag, bound1, bound2, counter;
  arg=get_arg_in_braces(arg,left,0);
  arg=get_arg_in_braces(arg,right,1);
  flag =1;
  if (sscanf(left,"%d,%d",&bound1,&bound2)!=2) 
    tintin_puts2("#Wrong number of arguments in #loop",ses);
  else {
    flag=1;
    counter=bound1;
    while(flag==1) {
      sprintf(vars[0], "%d", counter);
      substitute_vars(right,result);
      parse_input(result,ses);
      if (bound1<bound2) {
        counter++;
        if (counter>bound2)
          flag=0;
      }
      else {
        counter--;
        if (counter<bound2)
          flag=0;
      }
    } 
  }  
}
/************************/
/* the #message command */
/************************/
void message_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char offon[2][20];
  int mestype;
  char ms[6][20], tpstr[80];
  sscanf("aliases actions substitutes antisubstitutes highlights variables",
    "%s %s %s %s %s %s",ms[0],ms[1],ms[2],ms[3],ms[4],ms[5]);
  strcpy(offon[0],"OFF.");
  strcpy(offon[1],"ON.");
  get_arg_in_braces(arg,arg,1);
  mestype=0;
  while (!is_abrev(arg,ms[mestype]) && mestype<6)
    mestype++;
  if (mestype==6)
    tintin_puts2("#Invalid message type to toggle.", ses);
  else {
    mesvar[mestype]=!mesvar[mestype];
    sprintf(tpstr,"#Ok. messages concerning %s are now %s",
      ms[mestype],offon[mesvar[mestype]]);
    tintin_puts2(tpstr,ses);
  }
}

/**********************/
/* the #snoop command */
/**********************/
void snoop_command(arg, ses)
     char *arg;
     struct session *ses;
{
  char buf[100];
  struct session *sesptr=ses;

  if(ses) {
    get_arg_in_braces(arg, arg,1);
    if(*arg) {
      for(sesptr=sessionlist; sesptr && strcmp(sesptr->name, arg); sesptr=sesptr->next);
      if(!sesptr) {
        tintin_puts("#NO SESSION WITH THAT NAME!", ses);
        return;
      }
    }
    if(sesptr->snoopstatus) {
      sesptr->snoopstatus=FALSE;
      sprintf(buf, "#UNSNOOPING SESSION '%s'", sesptr->name);
      tintin_puts(buf, ses);
    }
    else {
      sesptr->snoopstatus=TRUE;
      sprintf(buf, "#SNOOPING SESSION '%s'", sesptr->name);
      tintin_puts(buf, ses);
    }
  }
  else
    tintin_puts("#NO SESSION ACTIVE => NO SNOOPING", ses);
}


/***********************/
/* the #system command */
/***********************/
void system_command(arg, ses)
     char *arg;
     struct session *ses;
{
  get_arg_in_braces(arg, arg, 1);
  if(*arg) {
    tintin_puts3("^#OK EXECUTING SHELL COMMAND.", ses);
    term_echo();
#if defined(DEBUG)
    system(arg);
#else
    alarm(0);
    system(arg);
#endif
#if defined(DEBUG)
    alarm(0);
#else
    alarm(1);
#endif
    term_noecho();
    tintin_puts3("!#OK COMMAND EXECUTED.", ses);
  }
  else
    tintin_puts2("#EXECUTE WHAT COMMAND?", ses);
  prompt(NULL);

}


/********************/
/* the #zap command */
/********************/
struct session *zap_command(ses)
     struct session *ses;
{
  tintin_puts("#ZZZZZZZAAAAAAAAPPPP!!!!!!!!! LET'S GET OUTTA HERE!!!!!!!!", ses);
  if(ses) {  
    cleanup_session(ses);
    return newactive_session();
  }
  else {
    end_command("end", (struct session *) NULL);
  }
}




/*********************************************************************/
/*   tablist will display the all items in the tab completion file   */
/*********************************************************************/
void tablist(tcomplete)
     struct completenode *tcomplete;
{
   int count, done;
   char tbuf[BUFFER_SIZE];
   struct completenode *tmp;

done=0;
if (tcomplete==NULL)
  {
   tintin_puts2("Sorry.. But you have no words in your tab completion file",NULL);
   return;
  }
count=1;
*tbuf='\0';

/* 
   I'll search through the entire list, printing thre names to a line then
   outputing the line.  Creates a nice 3 column effect.  To increase the # 
   if columns, just increase the mod #.  Also.. decrease the # in the %s's
*/

for(tmp=tcomplete->next;tmp!=NULL;tmp=tmp->next) 
  {
  if ((count % 3))
     {
     if (count == 1)
        sprintf(tbuf,"%25s", tmp->strng); 
     else
        sprintf(tbuf,"%s%25s",tbuf,tmp->strng);
     done=0;
     ++count;
     }
  else
     {
     sprintf(tbuf,"%s%25s",tbuf,tmp->strng);
     tintin_puts2(tbuf, NULL);
     done=1;
     *tbuf='\0';
     ++count;
     }
  }
  if (!done)
     tintin_puts2(tbuf, NULL);
  prompt(NULL);
}

void tab_add(arg)
   char *arg;
{
   struct completenode *tmp, *tmpold, *tcomplete;
   struct completenode *newt;
   char *newcomp, buff[BUFFER_SIZE];

   tcomplete=complete_head;
  
   if ((arg == NULL) || (strlen(arg)<=0)) {
     tintin_puts("Sorry, you must have some word to add.", NULL);
     prompt(NULL);
     return;
   }
   get_arg_in_braces(arg, buff, 1);

   if ((newcomp=(char *)(malloc(strlen(buff)+1)))==NULL) {
       fprintf(stderr, "Could not allocate enough memory for that Completion word.\n");
       exit(1);
   }
   strcpy(newcomp, buff);
   tmp=tcomplete;
   while (tmp->next != NULL) {
      tmpold=tmp;
      tmp=tmp->next;
   } 

   if ((newt=(struct completenode *)(malloc(sizeof(struct completenode))))==NULL) {
       fprintf(stderr, "Could not allocate enough memory for that Completion word.\n");
       exit(1);
   }
       
   newt->strng=newcomp;
   newt->next=NULL;
   tmp->next=newt;
   tmp=newt;
   sprintf(buff,"#New word %s added to tab completion list.", arg);
   tintin_puts(buff, NULL);
   prompt(NULL);
}
   
void tab_delete(arg)
   char *arg;
{
   struct completenode *tmp, *tmpold, *tmpnext, *tcomplete;
   struct completenode *newt;
   char *oldcomp, s_buff[BUFFER_SIZE], c_buff[BUFFER_SIZE];

   tcomplete=complete_head;

   if ((arg == NULL) || (strlen(arg)<=0)) {
     tintin_puts("#Sorry, you must have some word to delete.", NULL);
     prompt(NULL);
     return;
   }
   get_arg_in_braces(arg, s_buff, 1);
   tmp=tcomplete->next;
   tmpold=tcomplete;
   if (tmpold->strng == NULL) {   /* (no list if the second node is null) */
     tintin_puts("#There are no words for you to delete!", NULL);
     prompt(NULL);
     return;
   } 
   strcpy(c_buff, tmp->strng); 
   while ((tmp->next != NULL) && (strcmp(c_buff, s_buff) != 0)) {
      tmpold=tmp;
      tmp=tmp->next;
      strcpy(c_buff, tmp->strng); 
   }
   if (tmp->next != NULL) {
      tmpnext=tmp->next;
      tmpold->next=tmpnext;
      free(tmp);
      tintin_puts("#Tab word deleted.", NULL);
      prompt(NULL);
    } else {
      if (strcmp(c_buff, s_buff) == 0) { /* for the last node to delete */
        tmpold->next=NULL;
        free(tmp);
        tintin_puts("#Tab word deleted.", NULL);
        prompt(NULL);
        return;
      }
      tintin_puts("Word not found in list.", NULL);
      prompt(NULL);
    }
}    
 
#endif	// 0
