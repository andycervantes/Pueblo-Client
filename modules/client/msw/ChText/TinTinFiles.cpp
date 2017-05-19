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

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinFiles.cpp,v 2.1 1996/02/14 01:31:25 coyote Exp $

#include <ChTypes.h>
#include <ChUtil.h>

#include <fstream.h>

#include "TinTin.h"

/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define BUF_SIZE		2048


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	TinTin::DoRead
				Read a file of tintin commands.
----------------------------------------------------------------------------*/

void TinTin::DoRead( const string& strFilename, bool boolOnline )
{
	string		strFilePath( strFilename );
	char		buffer[BUF_SIZE];
	ifstream	file;
	bool		boolFlag = true;
	bool		boolSaveOnline = IsOnline();

											// Set the 'online' state
	if (IsOnline() && !boolOnline)
	{										/* Only turn 'online' in 'off'
												direction */
		m_boolOnline = boolOnline;
	}

	GetArgInBraces( strFilePath, strFilePath, true );

	if (-1 == strFilePath.Find( '\\' ))
	{										/* Get the file from the Pueblo
												directory by default */
		string		strAppDir;

		ChUtil::GetAppDirectory( strAppDir );
		strFilePath = strAppDir + strFilePath;
	}

	file.open( strFilePath, ios::in | ios::nocreate );
	if (!file.is_open())
	{
		if (boolOnline)
		{
			string		strTemp;

			strTemp.Format( "# Error - The file '%s' couldn't be opened.",
							(const char*)strFilePath );
			Display( strTemp );
		}
	}
	else
	{
		m_iAliasCounter = 0;
		m_iActionCounter = 0;
		m_iSubCounter = 0;
		m_iAntiSubCounter = 0;
		m_iVarCounter = 0;
		m_iHighlightCounter = 0;

		do {
			file.getline( buffer, BUF_SIZE );
			ParseInput( buffer );

		} while (!file.eof());

		if (boolOnline)
		{
			string		strTemp;

			if (m_iAliasCounter)
			{
				strTemp.Format( "# OK.  %d aliases loaded.", m_iAliasCounter );
				Display( strTemp );
			}

			if (m_iActionCounter)
			{
				strTemp.Format( "# OK.  %d actions loaded.",
									m_iActionCounter );
				Display( strTemp );
			}

			if (m_iAntiSubCounter)
			{
				strTemp.Format( "# OK.  %d antisubs loaded.",
									m_iAntiSubCounter );
				Display( strTemp );
			}

			if (m_iSubCounter)
			{
				strTemp.Format( "# OK.  %d substitutes loaded.",
									m_iSubCounter );
				Display( strTemp );
			}

			if (m_iVarCounter)
			{
				strTemp.Format( "# OK.  %d variables loaded.", m_iVarCounter );
				Display( strTemp );
			}

			if (m_iHighlightCounter)
			{
				strTemp.Format( "# OK.  %d highlights loaded.",
									m_iHighlightCounter );
				Display( strTemp );
			}
		}

		file.close();
	}
											// Reset the 'online' state
	m_boolOnline = boolSaveOnline;
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: files.c - funtions for logfile and reading/writing comfiles */
/*                             TINTIN + +                            */
/*          (T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t             */
/*                     coded by peter unold 1992                     */
/*                    New code by Bill Reiss 1993                    */
/*********************************************************************/
#ifdef HAVE_STRING_H
#include <string.h>
#else
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#endif
#include "tintin.h"

struct listnode *common_aliases, *common_actions, *common_subs,
                *common_myvars, *common_highs, *common_antisubs, 
		*common_pathdirs;
struct completenode *complete_head;
void prepare_for_write();

extern struct session *parse_input();

extern int puts_echoing;
extern int alnum,acnum,subnum,hinum,varnum,antisubnum;
extern int verbose;
extern char tintin_char;
/**********************************/
/* load a completion file         */
/**********************************/
void read_complete()
{
  FILE *myfile;
  char buffer[BUFFER_SIZE], *cptr;
  char message[80];
  int flag;
  struct completenode *tcomplete, *tcomp2;
  flag=TRUE;
  if ((complete_head=(struct completenode *)(malloc(sizeof(struct completenode))))==NULL) {
    fprintf(stderr, "couldn't alloc completehead\n");
    exit(1);
  }
  tcomplete=complete_head;

  if((myfile=fopen("tab.txt", "r"))==NULL) {
    if((cptr=(char *) getenv("HOME"))) {
      strcpy(buffer,cptr);
      strcat(buffer,"/.tab.txt");
      myfile=fopen(buffer, "r");
    }
  }
  if(myfile==NULL) {
    tintin_puts("no tab.txt file, no completion list\n", (struct session *)NULL);
    return;
  }

  while(fgets(buffer, sizeof(buffer), myfile)) {
    for(cptr=buffer; *cptr && *cptr!='\n'; cptr++);
    *cptr='\0';
    if ((tcomp2=(struct completenode *)(malloc(sizeof(struct completenode))))==NULL) {
      fprintf(stderr, "couldn't alloc comletehead\n");
      exit(1);
    }
    
    if ((cptr=(char *)(malloc(strlen(buffer)+1)))==NULL) {
      fprintf(stderr, "couldn't alloc memory for string in complete\n");
      exit(1);
    }
    strcpy(cptr, buffer);
    tcomp2->strng=cptr;
    tcomplete->next=tcomp2;      
    tcomplete=tcomp2;
  }
  tcomplete->next=NULL;
  fclose(myfile);
  tintin_puts("tab.txt file loaded.\n", (struct session *)NULL);
  prompt(NULL);
  tintin_puts("\n", (struct session *)NULL);
  
}

  
/********************/
/* the #log command */
/********************/
void log_command(arg, ses)
     char *arg;
     struct session *ses;
{
  if(ses) {
    if(!ses->logfile) {
      if(*arg) { 
        if((ses->logfile=fopen(arg, "w")))
          tintin_puts("#OK. LOGGING.....", ses);
        else
         tintin_puts("#COULDN'T OPEN FILE.", ses);
      }
      else
        tintin_puts("#SPECIFY A FILENAME.", ses);
    }
    else {
      fclose(ses->logfile);
      ses->logfile=NULL;
      tintin_puts("#OK. LOGGING TURNED OFF.", ses);
    }
  }
  else
   tintin_puts("#THERE'S NO SESSION TO LOG.", ses);
  prompt(NULL);
}


/************************/
/* write a command file */
/************************/
struct session *write_command(filename, ses)
     char *filename;
     struct session *ses;
{
  FILE *myfile;
  char buffer[BUFFER_SIZE];
  struct listnode *nodeptr;
  get_arg_in_braces(filename,filename, 1);
  if (*filename=='\0') {
    tintin_puts("#ERROR - COULDN'T OPEN THAT FILE.", ses);
    prompt(NULL);
    return(0); /* added zero return */
  }    
  if((myfile=fopen(filename, "w"))==NULL) {
    tintin_puts("#ERROR - COULDN'T OPEN THAT FILE.", ses);
    prompt(NULL);
    return(0); /* added zero return */
  }

  nodeptr=(ses) ? ses->aliases : common_aliases;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("alias", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->actions : common_actions;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("action", nodeptr->left, nodeptr->right, nodeptr->pr,
    buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->antisubs : common_antisubs;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("antisubstitute", nodeptr->left,
    nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  } 
  
  nodeptr=(ses) ? ses->subs : common_subs;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("substitute", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->myvars : common_myvars;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("variable", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }
  nodeptr=(ses) ? ses->highs : common_highs;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("highlight", nodeptr->right, nodeptr->left, "\0", buffer);
    fputs(buffer, myfile);
  }
  nodeptr=(ses) ? ses->pathdirs : common_pathdirs;
  while((nodeptr=nodeptr->next)) {
    prepare_for_write("pathdir", nodeptr->right, nodeptr->left, "\0", buffer);
    fputs(buffer, myfile);
  }
  fclose(myfile);
  tintin_puts("#COMMANDO-FILE WRITTEN.", ses);
  return ses;
}

/************************/
/* write a command file */
/************************/
struct session *writesession_command(filename, ses)
     char *filename;
     struct session *ses;
{
  FILE *myfile;
  char buffer[BUFFER_SIZE], fn[BUFFER_SIZE];
  struct listnode *nodeptr;
  get_arg_in_braces(filename,filename,1);
  if(*filename=='\0') {
    tintin_puts("#ERROR - COULDN'T OPEN THAT FILE.", ses);
    prompt(NULL);
    return(0); /* added zero return */
  }
  if((myfile=fopen(filename, "w"))==NULL) {
    tintin_puts("#ERROR - COULDN'T OPEN THAT FILE.", ses);
    prompt(NULL);
    return(0); /* added zero return */
  }

  nodeptr=(ses) ? ses->aliases : common_aliases;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_aliases, nodeptr->left))
      continue;
    prepare_for_write("alias", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->actions : common_actions;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_actions, nodeptr->left))
      continue;
    prepare_for_write("action", nodeptr->left, nodeptr->right, nodeptr->pr,
    buffer);
    fputs(buffer, myfile);
  }
  
  nodeptr=(ses) ? ses->antisubs : common_antisubs;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_antisubs, nodeptr->left))
      continue;
    prepare_for_write("antisubstitute", nodeptr->left, "", "\0", buffer);
    fputs(buffer,myfile);
  }
  
  nodeptr=(ses) ? ses->subs : common_subs;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_subs, nodeptr->left))
      continue;
    prepare_for_write("substitute", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->myvars : common_myvars;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_myvars, nodeptr->left))
      continue;
    prepare_for_write("variable", nodeptr->left, nodeptr->right, "\0", buffer);
    fputs(buffer, myfile);
  }

  nodeptr=(ses) ? ses->highs : common_highs;
  while((nodeptr=nodeptr->next)) {
    if(ses && searchnode_list(common_highs, nodeptr->left))
      continue;
    prepare_for_write("highlight", nodeptr->right, nodeptr->left, "\0", buffer);
    fputs(buffer, myfile);
  }

  fclose(myfile);
  tintin_puts("#COMMANDO-FILE WRITTEN.", ses);
  return ses;
}


void prepare_for_write(command, left, right, pr, result)
     char *command;
     char *left;
     char *right;
     char *pr;
     char *result;
{
  /* char tmpbuf[BUFFER_SIZE]; */
  *result=tintin_char;
  *(result+1)='\0';
  strcat(result, command);
  strcat(result, " {");
  strcat(result, left);
  strcat(result, "}");
  if (strlen(right)!=0) {
    strcat(result, " {");
    strcat(result, right);
    strcat(result, "}");
  }
  if (strlen(pr)!=0) {
    strcat(result, " {");
    strcat(result, pr);
    strcat(result, "}");
  }
  strcat(result,"\n");
}

void prepare_quotes(string)
     char *string;
{
  char s[BUFFER_SIZE], *cpsource, *cpdest;
  int nest=FALSE;
  strcpy(s, string);

  cpsource=s;
  cpdest=string;

 while(*cpsource) {
    if(*cpsource=='\\') {
      *cpdest++=*cpsource++;
      if(*cpsource)
        *cpdest++=*cpsource++;
    }
    else if(*cpsource=='\"' && nest==FALSE) {
      *cpdest++='\\';
      *cpdest++=*cpsource++;
    }
    else if(*cpsource=='{') {
      nest=TRUE;
      *cpdest++=*cpsource++;
    }
    else if(*cpsource=='}') {
      nest=FALSE;
      *cpdest++=*cpsource++;
    }
    else
      *cpdest++=*cpsource++; 
  }
  *cpdest='\0';
}


#endif
