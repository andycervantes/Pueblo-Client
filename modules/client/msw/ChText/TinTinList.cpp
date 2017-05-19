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

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinList.cpp,v 2.2 1996/02/16 22:36:33 coyote Exp $

#include <ChTypes.h>

#include <ctype.h>
#include <signal.h>

#include "TinTin.h"



/*----------------------------------------------------------------------------
	TinTinListNode class
----------------------------------------------------------------------------*/

TinTinListNode::TinTinListNode() :
					m_pNext( 0 )
{
}


TinTinListNode::TinTinListNode( const string& strLeft, const string& strRight,
								const string& strPriority ) :
					m_pNext( 0 ),
					m_strLeft( strLeft ),
					m_strRight( strRight ),
					m_strPriority( strPriority )
{
}


TinTinListNode::~TinTinListNode()
{
}


/*----------------------------------------------------------------------------
	TinTinList class
----------------------------------------------------------------------------*/

TinTinList::TinTinList( TinTin* pTinTin ) :
				m_pTinTin( pTinTin ),
				m_pTop( 0 )
{
}

	
TinTinList::~TinTinList()
{
	Empty();
}

	
void TinTinList::AddNode( const string& strLeft, const string& strRight,
							const string& strPriority )
{
	TinTinListNode* 	pNew;
	TinTinListNode* 	pTop = GetTop();

	pNew = new TinTinListNode( strLeft, strRight, strPriority );

	if (0 == pTop)
	{										// First node in list
		m_pTop = pNew;
	}
	else
	{
		while (0 != pTop->GetNext())
		{
			pTop = pTop->GetNext();
		}

		pTop->m_pNext = pNew;
	}
}


/*----------------------------------------------------------------------------
	TinTinList::InsertNode
					Create a node containing the strLeft, strRight, and
					strPriority fields and stuff it into the list - in
					lexicographical order, or by numerical priority
					(dependent on mode)
----------------------------------------------------------------------------*/

void TinTinList::InsertNode( const string& strLeft, const string& strRight,
								const string& strPriority, int iMode )
{
	TinTinListNode* 	pNew;
	TinTinListNode* 	pTop = GetTop();
	TinTinListNode* 	pLast = 0;

	pNew = new TinTinListNode( strLeft, strRight, strPriority );

	if (0 == pTop)
	{										/* List was empty -- make the new
												node the top node */
		m_pTop = pNew;
	}
	else
	{
		switch (iMode)
		{
			case PRIORITY:
			{
				while (pTop)
				{
					if (strcmp( strPriority, pTop->GetPriority() ) < 0)
					{
						InsertAfter( pLast, pNew );
						return;
					}
					else if (strcmp( strPriority, pTop->GetPriority() ) == 0)
					{
											/* Priorities being equal, insert
												the string in alphabetical
												order */

						while (pTop &&
								(strcmp( strPriority, pTop->GetPriority() ) == 0))
						{
							if (strcmp( strLeft, pTop->GetLeft() ) <= 0)
							{
								InsertAfter( pLast, pNew );
								return;
							}

							pLast = pTop;
							pTop = pTop->GetNext();
						}

						InsertAfter( pLast, pNew );
						return;
					}

					pLast = pTop;
					pTop = pTop->GetNext();
				}

				InsertAfter( pLast, pNew );
				break;
			}

			case ALPHA:
			{
				while (pTop)
				{
					if (strcmp( strLeft, pTop->GetLeft() ) <= 0)
					{
						InsertAfter( pLast, pNew );
						return;
					}

					pLast = pTop;
					pTop = pTop->GetNext();
				}

				InsertAfter( pLast, pNew );
				break;
			}
		}
	}
}


void TinTinList::DeleteNode( TinTinListNode* pDelete )
{
	TinTinListNode* 	pTop = GetTop();

	if (pTop)
	{
		if (pTop == pDelete)
		{									// First node in list
			m_pTop = pTop->GetNext();
			delete pDelete;
		}
		else
		{
			TinTinListNode*	pLast = pTop;

			while (pTop = pTop->GetNext())
			{
				if (pTop == pDelete)
				{
					pLast->m_pNext = pTop->GetNext();
					delete pTop;
					return;
				}
	
				pLast = pTop;
			}
		}
	}
}


int TinTinList::GetCount()
{ 
	int				iCount = 0;
	TinTinListNode*	pTop = GetTop();

	while (pTop)
	{
		iCount++;
		pTop = pTop->GetNext();
	}

	return iCount;
}


/*----------------------------------------------------------------------------
	TinTinList::Empty
					Deletes every node in the list.
----------------------------------------------------------------------------*/

void TinTinList::Empty()
{
	TinTinListNode* 	pTop = GetTop();

	while (pTop)
	{
		TinTinListNode* 	pNext = pTop->GetNext();

		delete pTop;
		pTop = pNext;
	}

	m_pTop = 0;
}


/*----------------------------------------------------------------------------
	TinTinList::Search
					Search for a node that has strText in the left value.
					Return: ptr to node on success / 0 on failure.
----------------------------------------------------------------------------*/

TinTinListNode* TinTinList::Search( const string& strText )
{
	TinTinListNode*	pTop = GetTop();

	while (pTop)
	{
		if (strcmp( pTop->GetLeft(), strText ) == 0)
		{
			return pTop;
		}

		pTop = pTop->GetNext();
	}

	return 0;
}

	
/*----------------------------------------------------------------------------
	TinTinList::SearchBegin
					Search for a node that has strText as a beginning.
					Return: ptr to node on success / 0 on failure.
----------------------------------------------------------------------------*/

TinTinListNode* TinTinList::SearchBegin( const string& strText, int iMode )
{
	const char*		pstrText = strText;
	int				iTextLen = strText.GetLength();
	int				iCmp;
	TinTinListNode*	pTop = GetTop();

	if (0 == pTop)
	{
		return 0;
	}

	switch (iMode)
	{
		case PRIORITY:
		{
			while (pTop)
			{
				iCmp = strncmp( pTop->GetLeft(), pstrText, iTextLen );

				if ((iCmp == 0) &&
					((*((const char*)pTop->GetLeft() + iTextLen) == ' ') ||
						(*((const char*)pTop->GetLeft() + iTextLen) == '\0')))
				{
					return pTop;
				}

				pTop = pTop->GetNext();
			}
			return 0;
			break;
		}

		case ALPHA:
		{
			while (pTop)
			{
				iCmp = strncmp( pTop->GetLeft(), pstrText, iTextLen );

				if ((iCmp == 0) &&
					((*((const char*)pTop->GetLeft() + iTextLen) == ' ') ||
						(*((const char*)pTop->GetLeft() + iTextLen) == '\0')))
				{
					return pTop;
				}
				else if (iCmp > 0)
				{
					return 0;
				}

				pTop = pTop->GetNext();
			}
			return 0;
			break;
		}

		default:
		{
			return 0;
		}
	}
}


TinTinListNode* TinTinList::SearchWithWildchars( const string& strText )
{
	if (0 != GetTop())
	{
		return SearchWithWildchars( strText, GetTop() );
	}
	else
	{
		return 0;
	}
}


TinTinListNode* TinTinList::SearchWithWildchars( const string& strText,
													TinTinListNode* pStart )
{
	while (pStart)
	{
		if (m_pTinTin->Match( strText, pStart->GetLeft() ))
		{
			return pStart;
		}

		pStart = pStart->GetNext();
	}

	return 0;
}


void TinTinList::ShowList()
{
	TinTinListNode*	pTop = GetTop();

	if (pTop)
	{
		while (pTop)
		{
			ShowNode( pTop );
			pTop = pTop->GetNext();
		}
	}
}


void TinTinList::ShowNode( TinTinListNode* pNode )
{
	string		strTemp;

	strTemp.Format( "#    {%s} = {%s}", (const char*)pNode->GetLeft(),
										(const char*)pNode->GetRight() );
	m_pTinTin->Display( strTemp );
}


#if 0

/* Autoconf patching by David Hedbor, neotron@lysator.liu.se */
/*********************************************************************/
/* file: llist.c - linked-list datastructure                         */
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

void insertnode_list();
int match();

/***********************************************/
/* make a copy of a list - return: ptr to copy */
/***********************************************/
struct listnode *copy_list(sourcelist, mode)
     struct listnode *sourcelist;
{
  struct listnode *resultlist;

  resultlist=init_list();
  while((sourcelist=sourcelist->next))
    insertnode_list(resultlist, sourcelist->left, sourcelist->right, 
    sourcelist->pr, mode);
  
  return(resultlist);
} 

/*****************************/
/* delete a node from a list */
/*****************************/


/************************************/
/* show contens of a node on screen */
/************************************/

void shownode_list_action(nptr)
     struct listnode *nptr;
{
  char temp[BUFFER_SIZE];
  sprintf(temp, "{%s}={%s} @ {%s}", nptr->left, nptr->right, nptr->pr);
  tintin_puts2(temp, (struct session *)NULL);
}
/************************************/
/* list contens of a list on screen */
/************************************/

void show_list_action(listhead)
     struct listnode *listhead;
{
  while((listhead=listhead->next))
    shownode_list_action(listhead);
}


int check_one_node(text, action)
     char *text;
     char *action;
{
  char *temp, temp2[BUFFER_SIZE], *tptr;
  while (*text && *action) {
    if (*action=='*') {
      action++;
      temp=action;
      tptr=temp2;
      while(*temp && *temp !='*')
        *tptr++= *temp++;
      *tptr='\0';
      if (strlen(temp2)==0) 
        return TRUE;
      while(strncmp(temp2,text,strlen(temp2))!=0 && *text)
        text++;
    }
    else {
      temp=action;
      tptr=temp2;
      while (*temp && *temp !='*')
        *tptr++= *temp++;
      *tptr='\0';
      if(strncmp(temp2,text,strlen(temp2))!=0)
        return FALSE;
      else {
        text+=strlen(temp2);
        action+=strlen(temp2);
      }
    }
  }
  if (*text)
    return FALSE;
  else if ((*action=='*' && !*(action+1)) || !*action)
    return TRUE;
  return FALSE;
}


#endif
