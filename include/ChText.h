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

	Main header file for the ChTxtIn and ChTxtOut modules of the Pueblo
	system.  These handle simple text input and output, respectively.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChText.h,v 2.2 1995/07/26 08:35:10 coyote Exp $

#if !defined( _CHTEXT_H_ )
#define _CHTEXT_H_

#include <ChMsg.h>


/*----------------------------------------------------------------------------
	Constants:
----------------------------------------------------------------------------*/

#define CH_MODULE_TEXT_INPUT		"Chaco Text Input module"
#define CH_MODULE_TEXT_INPUT_BASE	"ChText"
#define CH_MODULE_TEXT_OUTPUT		"Chaco Text Output module"
#define CH_MODULE_TEXT_OUTPUT_BASE	"ChText"

#define CH_MODULE_TEXT				"Chaco Text module"


/*----------------------------------------------------------------------------
	Message Constants:
----------------------------------------------------------------------------*/

#define CH_TXT_MSG_SET_PASSWORD		(CH_MSG_USER + 1)


/*----------------------------------------------------------------------------
	ChTextSetPasswordMsg class -- Tells the text input window to use
									password mode (or not.)
----------------------------------------------------------------------------*/

class ChTextSetPasswordMsg : public ChMsg
{
	public:
		ChTextSetPasswordMsg( bool boolPassword ) :
			ChMsg( CH_TXT_MSG_SET_PASSWORD, boolPassword )
				{
				}

		inline bool GetPassword() { return (bool)GetParam1(); }
		inline void GetParams( bool& boolPassword )
				{
					boolPassword = (bool)GetParam1();
				}
};


#endif	// !defined( _CHTEXT_H_ )
