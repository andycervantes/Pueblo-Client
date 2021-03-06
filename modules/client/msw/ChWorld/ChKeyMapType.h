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

	Contains the interface for the ChWorldInfo class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/ChKeyMapType.h,v 2.3 1996/04/10 21:22:23 coyote Exp $

#if !defined( _CHKEYMAPTYPE_H )
#define _CHKEYMAPTYPE_H

#include <ChStrmbl.h>
#include <ChKeyMap.h>


/*----------------------------------------------------------------------------
	Key map constants
----------------------------------------------------------------------------*/

#define ACTION_CURSOR_UP			"cursor up"
#define ACTION_CURSOR_UP_2			"cursor up 2"
#define ACTION_CURSOR_DOWN			"cursor down"
#define ACTION_CURSOR_DOWN_2		"cursor down 2"
#define ACTION_CURSOR_LEFT			"cursor left"
#define ACTION_CURSOR_RIGHT			"cursor right"
#define ACTION_CURSOR_HOME			"cursor home"
#define ACTION_CURSOR_END			"cursor end"
#define ACTION_CURSOR_START_LINE	"cursor start line"
#define ACTION_CURSOR_END_LINE		"cursor end line"

#define ACTION_SEND					"send"
#define ACTION_TAB_COMPLETION		"tab completion"
#define ACTION_HISTORY_PREV			"history previous"
#define ACTION_HISTORY_NEXT			"history next"

#define ACTION_DELETE_TEXT			"delete text"
#define ACTION_DELETE_NEXT_CHAR		"delete next char"
#define ACTION_DELETE_TO_END_BUFF	"delete to end of buffer"

#define ACTION_LOG_PAGE_UP			"log page up"
#define ACTION_LOG_PAGE_DOWN		"log page down"
#define ACTION_LOG_HOME				"log home"
#define ACTION_LOG_END				"log end"

#define ACTION_TRANSPOSE			"transpose"

#define ACTION_MOD_SHIFT			(1L << 0)
#define ACTION_MOD_CONTROL			(1L << 1)


/*----------------------------------------------------------------------------
	Action enum
----------------------------------------------------------------------------*/

typedef enum { actCursorUp, actCursorDown, actCursorLeft, actCursorRight,
				actCursorHome, actCursorEnd, actCursorStartLine,
				actCursorEndLine, actSend, actTabCompletion, actTranspose,
				actDeleteText, actDeleteNextChar, actDeleteToEndOfBuffer,
				actHistoryPrev, actHistoryNext, actLogPageUp, actLogPageDown,
				actLogHome, actLogEnd } KeyAction;


/*----------------------------------------------------------------------------
	Types
----------------------------------------------------------------------------*/

typedef enum { keymapUndefined = -1, keymapEndList = -1, keymapWindows,
				keymapEmacs } KeymapType;

typedef struct
{
	KeymapType	type;
	char*		pstrName;

} KeyMapName;

typedef struct
{
	chuint32		luKey;
	chflag32		flModifiers;
	const char*		pstrName;
	chparam			userData;

} KeyMapEntry;


/*----------------------------------------------------------------------------
	ChKeyMapType class
----------------------------------------------------------------------------*/

class ChKeyMapType
{
	public:
		enum { constVersion = 1 };

	public:
		ChKeyMapType() : m_map( keymapWindows ) {}
		ChKeyMapType( const string& strType );
		ChKeyMapType( const ChKeyMapType& type );
		ChKeyMapType( KeymapType type );
		virtual ~ChKeyMapType() {}

		inline operator KeymapType() const { return m_map; }
		inline void Set( KeymapType type )
				{
					m_map = type;
				}

		string GetName() const;
		void Set( const string& strType );
		void CreateMap( ChKeyMap& keyMap );

	private:
		static KeyMapName		m_mapNames[];
		static KeyMapEntry		m_windowsKeyMap[];
		static KeyMapEntry		m_emacsKeyMap[];

		KeymapType				m_map;
};


#endif	// !defined( _CHKEYMAPTYPE_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
