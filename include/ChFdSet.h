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

	This file consists of the interface for the ChFdSet class.

	FdSet's are used for storing sets of file descriptors which can
	be select()ed on in a group.  They are used in the Unix client
	and server.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChFdSet.h,v 2.2 1996/02/27 02:27:33 glenn Exp $

#if !defined(_CHFDSET_H)
#define _CHFDSET_H 1

#if defined( CH_MSW )

//	#include <sys/time.h>

#elif defined (CH_UNIX )

	#include <sys/time.h>

#endif

#include <string.h>

#define CH_DECLARE_FD_CB( name ) \
	CH_EXTERN_CALLBACK ( void ) \
	name(sockinetbuf& si, chparam data)

#define CH_IMPLEMENT_FD_CB( name ) \
	CH_GLOBAL_CALLBACK( void ) \
	name(sockinetbuf& si, chparam data)

typedef void (CALLBACK EXPORT *ChFdSetCallback) (sockinetbuf& si, chparam data);

class ChFdSet
{
  public:
	ChFdSet() { fds = 0; FD_ZERO(&rset); max_fd = 0; };
	int Select();
	int AddFd(sockinetbuf& si, ChFdSetCallback cb, chparam cb_param);
	void DeleteFd(sockinetbuf& si);

  private:
	struct fd_entry {
		sockinetbuf *m_psi;
		int fd;
		ChFdSetCallback cb;
		chparam cb_param;
	} fd_arr[200];
	int fds;
	fd_set rset;
	int max_fd;
};

#endif // _CHFDSET_H

// Local Variables: ***
// tab-width:4 ***
// End: ***
