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

	TinTin alias-related methods.  Originally modified from TinTin++,
	(T)he K(I)cki(N) (T)ickin D(I)kumud Clie(N)t, originally coded by
	Peter Unold 1992.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChText/TinTinAlias.cpp,v 2.1 1996/02/14 01:31:24 coyote Exp $

#include <ChTypes.h>

#include <ctype.h>
#include <signal.h>

#include "TinTin.h"


/*----------------------------------------------------------------------------
	TinTin class
----------------------------------------------------------------------------*/

void TinTin::DoAlias( const string& strArgs )
{
	string		strLeft;
	string		strRight;
	const char*	pstrArgs = strArgs;

	pstrArgs = GetArgInBraces( pstrArgs, strLeft, false );
	pstrArgs = GetArgInBraces( pstrArgs, strRight, true );

	if (strLeft.IsEmpty())
	{
		if (m_pListAliases->GetTop())
		{
			Display( "# Defined aliases:" );

			m_pListAliases->ShowList();
		}
		else
		{
			Display( "# No defined aliases." );
		}
	}
	else if (!strLeft.IsEmpty() && strRight.IsEmpty())
	{
		TinTinListNode*		pNode;

		if (pNode = m_pListAliases->SearchWithWildchars( strLeft ))
		{
			do {
				m_pListAliases->ShowNode( pNode );
				pNode = pNode->GetNext();

			} while (pNode = m_pListAliases->SearchWithWildchars( strLeft,
																	pNode ));
		}
		else if (m_boolDisplayMessages[msgIndexAliases])
		{
			string		strTemp;

			strTemp.Format( "# No match(es) found for {%s}.",
								(const char*)strLeft );
			Display( strTemp );
		}
	}
	else
	{
		TinTinListNode*		pNode;

		if (pNode = m_pListAliases->Search( strLeft ))
		{
			m_pListAliases->DeleteNode( pNode );
		}

		m_pListAliases->InsertNode( strLeft, strRight, "0", ALPHA );

		if (m_boolDisplayMessages[msgIndexAliases])
		{
			string		strTemp;

			strTemp.Format( "# Ok.  {%s} aliases {%s}.",
								(const char*)strLeft, (const char*)strRight );
			Display( strTemp );
		}

		m_iAliasCounter++;
	}
}


void TinTin::DoUnalias( const string& strArgs )
{
	bool			boolFound = false;
	const char*		pstrArgs = strArgs;
	string			strLeft;
	TinTinListNode*	pNode;
	TinTinListNode*	pStart = m_pListAliases->GetTop();

	pstrArgs = GetArgInBraces( pstrArgs, strLeft, true );

	while (pNode = m_pListAliases->SearchWithWildchars( strLeft, pStart ))
	{
		boolFound = true;

		if (m_boolDisplayMessages[msgIndexAliases])
		{
			string		strTemp;

			strTemp.Format( "# Ok.  {%s} is no longer an alias.",
								(const char*)pNode->GetLeft() );
			Display( strTemp );
		}

		pStart = pNode->GetNext();
		m_pListAliases->DeleteNode( pNode );
	}

	if (!boolFound && m_boolDisplayMessages[msgIndexAliases])
	{
		string		strTemp;

		strTemp.Format( "# No match(es) found for {%s}.",
							(const char*)strLeft );
		Display( strTemp );
	}
}

