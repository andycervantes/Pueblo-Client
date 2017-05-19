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

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/ChFdSet.cpp,v 2.3 1995/11/05 19:02:28 glenn Exp $

#include <ChTypes.h>
#include <sockinet.h>
#include <ChFdSet.h>

// Add 'fd' to 'pset', and set 'pmax' to be the maximum of *pmax
// and fd.  This is how we get new file descriptors into the set
// we select() on.
static inline void my_fd_set(int fd, fd_set *pset, int *pmax)
{
	if (fd < 0)
		return;
	FD_SET(fd, pset);
	if (fd > *pmax)
		*pmax = fd;
}

// Remove 'fd' from 'pset'.
static inline void my_fd_unset(int fd, fd_set *pset, int *pmax)
{
	if (fd < 0)
		return;
	FD_CLR(fd, pset);
	// XXX This should figure out the new pmax, maybe
}

// Select on all the file descriptors which AddFd() has been called
// with, calling back those fd's which have data to be read.
int ChFdSet::Select()
{
	fd_set rset_copy;
	int iReady;
	int i;

#if 0 && defined( CH_VERBOSE )
	cerr << "ChFdSet::Select():  ";
	// Print a list of the fds
	for (i = 0; i < fds; i++)
		cerr << fd_arr[i].fd << " ";
	cerr << endl;
#endif // CH_VERBOSE
	
	memcpy(&rset_copy, &rset, sizeof(fd_set));
	iReady = ::select( max_fd + 1, &rset_copy, 0, 0, 0 );

	for (i = 0; i < fds; i++)
	{
		if (FD_ISSET(fd_arr[i].fd, &rset_copy))
		{
			#if 0
			#if defined( CH_VERBOSE )
			{
				cerr << "ChFdSet::Select: calling for fd " <<
						fd_arr[i].fd << endl;
			}
			#endif	// defined( CH_VERBOSE )
			#endif	// 0

			fd_arr[i].cb(*fd_arr[i].m_psi, fd_arr[i].cb_param);
		}
	}
	
	return 0;
}

// Add the specified file descriptor to the set of descriptors we
// select() on.  When there is data to be read on the specified
// file descriptor, we will call 'cb' with 'cb_param' as the 'data'
// parameter.
int ChFdSet::AddFd(sockinetbuf& si, ChFdSetCallback cb, chparam cb_param)
{
#if defined( CH_VERBOSE )
	cerr << "ChFdSet::AddFd" << endl;
#endif
	fd_arr[fds].fd = (int)si;
	fd_arr[fds].m_psi = &si;
	fd_arr[fds].cb = cb;
	fd_arr[fds].cb_param = cb_param;
	fds++;
	my_fd_set((int)si, &rset, &max_fd);
	return 0;
}

// Delete the specified file descriptor from the set we select() on
// and call back.
void ChFdSet::DeleteFd(sockinetbuf& si)
{
	int i, fd = (int) si;

	for (i = 0; i < fds; i++) {
		if (fd_arr[i].fd == fd) {
			// Found the fd.  Delete it
			my_fd_unset(fd, &rset, &max_fd);
			for (int j = i; j < fds; j++) {
				fd_arr[j] = fd_arr[j + 1];
			}
			fds--;
			break;		// XXX assume there's only one callback for the fd
		}
	}
}

// Local Variables: ***
// tab-width:4 ***
// End: ***
