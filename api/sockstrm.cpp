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

	Portions copyright (C) 1992,1993,1994 Gnanasekaran Swaminathan
											<gs4t@virginia.edu>

	Permission is granted to use at your own risk and distribute this software
	in source and binary forms provided the above copyright notice and this
	paragraph are preserved on all copies.  This software is provided "as is"
	with no express or implied warranty.

	Version: 21May94 1.7

------------------------------------------------------------------------------

	This file consists of the core streaming implementation for the Sockets++
	classes.

	You can simultaneously read and write into a sockbuf just like you can
	listen and talk through a telephone. Hence, the read and the write
	buffers are different. That is, they do not share the same memory.

	Read:
		gptr() points to the start of the get area.  The unread chars are
		gptr() - egptr().  base() points to the read buffer.  eback() is
		set to base() so that pbackfail() is called only when there is no
		place to putback a char.  And pbackfail() always returns EOF.

	Write:
		pptr() points to the start of the put area.  The unflushed chars
		are pbase() - pptr().  pbase() points to the write buffer.  epptr()
		points to the end of the write buffer.

	Output is flushed whenever one of the following conditions holds:

		(1) pptr() == epptr()
		(2) EOF is written
		(3) linebuffered and '\n' is written

	Unbuffered:
		Input buffer size is assumed to be of size 1 and output buffer is
		of size 0. That is, egptr() <= base()+1 and epptr() == pbase().

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/sockstrm.cpp,v 2.2 1996/04/26 17:04:16 coyote Exp $

#include "headers.h"						// Precompiled header directive

#ifdef _AIX
	#define _BSD 43 // define this 44 if BSD 4.4 compat is desired
#endif

//extern "C" int shutdown (int, int); // they have forgotten this

#include <SocketXX.h>
#include <ChExcept.h>

#ifndef _S_NOLIBGXX
#     	include <builtin.h>
#endif
#ifdef WIN32
#include <winsock.h>
#include <io.h>
#else
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <memory.h>
#include <errno.h>

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif

#ifdef FD_ZERO
// bzero causes so much trouble to us
#undef FD_ZERO
#define FD_ZERO(p) (memset ((p), 0, sizeof *(p)))
#endif

#ifdef __osf__
  extern "C" int select (int, fd_set*, fd_set*, fd_set*, timeval*);
#endif

#if !defined TRACE1
#define TRACE1(a,b)	  // jwd; hack to compile !!!!!!!!!!!!!
#define TRACE2(a,b,c)
#endif

void sock_error (const char* classname, const char* msg)
{
	#if defined( CH_VERBOSE )
    if (errno)
	perror (msg);
    cerr << classname << ' ' << msg << endl;
	#endif
    errno = 0;
}

void sockAddr::error( const char *pstrErr ) const
{
    sock_error( "class sockAddr ", pstrErr );
}

sockbuf::sockbuf (int soc)
: rep (new sockcnt (soc, 1)),
  stmo (-1), rtmo (-1)
{
#ifdef _S_NOLIBGXX
    xflags (0);
#endif
    xsetflags (_S_LINE_BUF);
}

sockbuf::sockbuf (int domain, sockbuf::type st, int proto)
: rep (0), stmo (-1), rtmo (-1)
{
#ifdef WIN32
	static int winsock_inited = 0;
	WORD wVersion = MAKEWORD(2, 0);
	WSADATA wsData;
	int retval;

	if (!winsock_inited) {
		retval = WSAStartup(wVersion, &wsData);

		if (retval != 0) {
			perror("sockbuf::sockbuf initializing WinSock");
		}
		else
			winsock_inited = 1;
	}
#endif /* WIN32 */

    int soc = ::socket (domain, st, proto);
    rep = new sockcnt (soc, 1);
#ifdef _S_NOLIBGXX
    xflags (0);
#endif
    if (rep->sock == -1) perror ("sockbuf::sockbuf");
    xsetflags (_S_LINE_BUF);
}

sockbuf::sockbuf (const sockbuf& sb)
: rep (sb.rep), stmo (sb.stmo), rtmo (sb.rtmo)
{
#ifdef _S_NOLIBGXX
    xflags (0);
#endif
    rep->cnt++;
    xsetflags (_S_LINE_BUF);
}

sockbuf& sockbuf::operator =( const sockbuf& sb )
{
	if (this != &sb && rep != sb.rep && rep->sock != sb.rep->sock)
	{
		this->sockbuf::~sockbuf();

		rep = sb.rep;
		stmo = sb.stmo;
		rtmo = sb.rtmo;

		rep->cnt++;
	
		#if defined( _S_NOLIBGXX )
		{
			xflags (sb.xflags ());
		}
		#else
		{									/* xflags () is a non-const member
												function in libg++ */
			xflags (((sockbuf&)sb).xflags ());
		}
		#endif
	}
	
	return *this;
}

sockbuf::~sockbuf ()
{
    overflow (EOF);
    if (rep->cnt == 1 && !(xflags () & _S_DELETE_DONT_CLOSE))
    {
    	close ();
	}

    delete [] base ();
    if (--rep->cnt == 0)
    {
// XXX Leak 8 bytes.
// We're getting double-frees here on Unix (and probably on non-threaded
// MSW, and maybe on threaded MSW).  It's probably due to the baroque
// and vile reference counting garbage we're doing.
// There's another one of these in sockinet.cpp
#ifndef CH_UNIX
    	delete rep;
#endif
    }
}

sockbuf* sockbuf::open (type, int)
{
    return 0;
}

sockbuf* sockbuf::close()
{
	if (rep->sock >= 0)
	{
		#if defined( WIN32 )
		if (::closesocket( rep->sock ) == -1)
		#else
		if (::close( rep->sock ) == -1)
		#endif
		{
			return this;
		}

		rep->sock = -1;
	}

	return 0;
}

_G_ssize_t sockbuf::sys_read (char* buf, _G_ssize_t len)
     // return EOF on eof, 0 on timeout, and # of chars read on success
{
    return read (buf, len);
}

_G_ssize_t sockbuf::sys_write (const void* buf, long len)
     // return written_length; < len indicates error
{
    return write (buf, (int) len);
}

int sockbuf::flush_output()
     // return 0 when there is nothing to flush or when the flush is a success
     // return EOF when it could not flush
{
    if (pptr () <= pbase ()) return 0;
    if (!(xflags () & _S_NO_WRITES)) {
	int wlen   = pptr () - pbase ();
	int wval   = sys_write (pbase (), wlen);
	int status = (wval == wlen)? 0: EOF;
	if (unbuffered()) setp (pbase (), pbase ());
	else setp (pbase (), pbase () + BUFSIZ);
	return status;
    }
    return EOF;
}

int sockbuf::sync ()
{
    return flush_output ();
}

int sockbuf::doallocate ()
     // return 1 on allocation and 0 if there is no need
{
    if (!base ()) {
	char*	buf = new char[2*BUFSIZ];
	setb (buf, buf+BUFSIZ, 0);
	setg (buf, buf, buf);

	buf += BUFSIZ;
	setp (buf, buf+BUFSIZ);
	return 1;
    }
    return 0;
}

int sockbuf::underflow ()
{
    if (xflags () & _S_NO_READS) return EOF;

    if (gptr () < egptr ()) return *(unsigned char*)gptr ();

    if (base () == 0 && doallocate () == 0) return EOF;

    int bufsz = unbuffered () ? 1: BUFSIZ;
    int rval = sys_read (base (), bufsz);
    if (rval == EOF) {
	xsetflags (_S_EOF_SEEN);
	return EOF;
    }else if (rval == 0)
	return EOF;
    setg (eback (), base (), base () + rval);
    return *(unsigned char*)gptr ();
}

int sockbuf::overflow (int c)
     // if c == EOF, return flush_output();
     // if c == '\n' and linebuffered, insert c and
     // return (flush_output()==EOF)? EOF: c;
     // otherwise insert c into the buffer and return c
{
    if (c == EOF) return flush_output ();

    if (xflags () & _S_NO_WRITES) return EOF;

    if (pbase () == 0 && doallocate () == 0) return EOF;

    xput_char (c);
    if ((unbuffered () || linebuffered () && c == '\n' || pptr () >= epptr ())
	&& flush_output () == EOF)
	return EOF;

    return c;
}

int sockbuf::xsputn (const char* s, int n)
{
    if (n <= 0) return 0;
    const unsigned char* p = (const unsigned char*)s;

    for (int i=0; i<n; i++, p++) {
	if (*p == '\n') {
	    if (overflow (*p) == EOF) return i;
	} else
	    if (sputc (*p) == EOF) return i;
    }
    return n;
}

int sockbuf::bind (sockAddr& sa)
{
	int ret;

	ret = ::bind (rep->sock, sa.GetAddr(), sa.GetSize());
	if (ret == -1)
		error ("sockbuf::bind");
	return ret;
}

void sockbuf::connect( sockAddr& sa )
{
    if (::connect( rep->sock, sa.GetAddr(), sa.GetSize()) == -1)
	{
		#if defined( WIN32 ) && defined( _DEBUG )
			WSADisplayError( WSAGetLastError(), "sockbuf::connect" );
		#endif	// defined( WIN32 ) && defined( _DEBUG )

		error ( "sockbuf::connect" );

		#if defined( CH_EXCEPTIONS )
		{
			switch( WSAGetLastError() )
			{
				case WSAETIMEDOUT:
				{							// Throw a timed-out exception

					throw ChSocketEx( ChEx::socketTimedOut );
					break;
				}

				default:
				{							// Throw a misc. failure exception

					throw ChSocketEx( ChEx::connectFailed );
					break;
				}
			}
		}
		#endif
	}
}

void sockbuf::listen (int num)
{
    if (::listen (rep->sock, num) == -1)
	error ("sockbuf::listen");
}

sockbuf	sockbuf::accept (sockAddr& sa)
{
    int len = sa.GetSize();
    int soc = -1;
    while ((soc = ::accept (rep->sock, sa.GetAddr(), &len)) == -1
	   && errno == EINTR)
	errno = 0;
    if (soc == -1)
	error ("sockbuf::accept");
    return soc;
}

sockbuf	sockbuf::accept ()
{
    int soc = -1;
    while ((soc = ::accept (rep->sock, 0, 0)) == -1
	   && errno == EINTR)
	{
//	  cout << "sockbuf::accept: errno == " << errno << endl;
      errno = 0;
	}
    if (soc == -1 && errno != EAGAIN)
	error ("sockbuf::accept");
    return soc;
}

int sockbuf::read (void* buf, int len)
{
    if (rtmo != -1 && is_readready (rtmo)==0) return 0;

    int	rval;
#ifdef WIN32
	if ((rval = ::recv(rep->sock, (char *)buf, len, 0)) < 0)
		error("sockbuf::read");
#else
    if ((rval = ::read (rep->sock, (char*) buf, len)) == -1)
	error("sockbuf::read");
#endif
    return ((rval==0) ? EOF: rval);
}

int sockbuf::recv (void* buf, int len, int msgf)
{
    if (rtmo != -1 && is_readready (rtmo)==0) return 0;

    int	rval;
    if ((rval = ::recv (rep->sock, (char*) buf, len, msgf)) == -1)
	error ("sockbuf::recv");
    return (rval==0) ? EOF: rval;
}

int sockbuf::recvfrom (sockAddr& sa, void* buf, int len, int msgf)
{
    if (rtmo != -1 && is_readready (rtmo)==0) return 0;

    int	rval;
    int	sa_len = sa.GetSize();

    if ((rval = ::recvfrom (rep->sock, (char*) buf, len,
	                    msgf, sa.GetAddr(), &sa_len)) == -1)
	error ("sockbuf::recvfrom");
    return (rval==0) ? EOF: rval;
}

int sockbuf::write(const void* buf, int len) const
{
    if (stmo != -1 && is_writeready (stmo)==0) return 0;

    int	wlen=0;
    while(len>0) {
	int	wval;

#ifdef WIN32
//cout << "sending: '" << (char *)buf << "' len=" << len << endl;
	wval = ::send(rep->sock, (char *) buf, len, 0);
	if (wval < 0) {
		int error_val = WSAGetLastError();
		error ("sockbuf::write");
		#if defined( CH_VERBOSE )
		cerr << "WSAGetLastError() == " << error_val << endl;
		#endif
		return wval;
	}
#else
	if ((wval = ::write (rep->sock, (char*) buf, len)) == -1) {
	    error ("sockbuf::write");
	    return wval;
	}
#endif /* WIN32 */
	len -= wval;
	wlen += wval;
    }
    return wlen; // == len if every thing is all right
}

int sockbuf::send (const void* buf, int len, int msgf)
{
    if (stmo != -1 && is_writeready (stmo)==0) return 0;

    int	wlen=0;
    while(len>0) {
	int	wval;
	if ((wval = ::send (rep->sock, (char*) buf, len, msgf)) == -1) {
	    error ("sockbuf::send");
	    return wval;
	}
	len -= wval;
	wlen += wval;
    }
    return wlen;
}

int sockbuf::sendto (sockAddr& sa, const void* buf, int len, int msgf)
{
    if (stmo != -1 && is_writeready (stmo)==0) return 0;

    int	wlen=0;
    while(len>0) {
	int	wval;
	if ((wval = ::sendto (rep->sock, (char*) buf, len,
			      msgf, sa.GetAddr(), sa.GetSize())) == -1) {
	    error ("sockbuf::sendto");
	    return wval;
	}
	len -= wval;
	wlen += wval;
    }
    return wlen;
}

#if !defined(__linux__) && !defined(WIN32)
// linux does not have sendmsg or recvmsg

  int sockbuf::recvmsg (msghdr* msg, int msgf)
  {
    if (rtmo != -1 && is_readready (rtmo)==0) return 0;

    int	rval;
    if ((rval = ::recvmsg(rep->sock, msg, msgf)) == -1)
	error ("sockbuf::recvmsg");
    return (rval==0)? EOF: rval;
  }

  int sockbuf::sendmsg (msghdr* msg, int msgf)
  {
    if (stmo != -1 && is_writeready (stmo)==0) return 0;

    int	wval;
    if ((wval = ::sendmsg (rep->sock, msg, msgf)) == -1)
	error("sockbuf::sendmsg");
    return wval;
  }
#endif //!__linux__

int sockbuf::sendtimeout (int wp)
{
    int oldstmo = stmo;
    stmo = (wp < 0) ? -1: wp;
    return oldstmo;
}

int sockbuf::recvtimeout (int wp)
{
    int oldrtmo = rtmo;
    rtmo = (wp < 0) ? -1: wp;
    return oldrtmo;
}

int sockbuf::is_readready (int wp_sec, int wp_usec) const
{
    fd_set fds;
    FD_ZERO (&fds);
    FD_SET (rep->sock, &fds);

    timeval tv;
    tv.tv_sec  = wp_sec;
    tv.tv_usec = wp_usec;

    int ret = select (rep->sock+1, &fds, 0, 0, (wp_sec == -1) ? 0: &tv);
    if (ret == -1) {
	error ("sockbuf::readready");
	return 0;
    }
    return ret;
}

int sockbuf::is_writeready (int wp_sec, int wp_usec) const
{
    fd_set fds;
    FD_ZERO (&fds);
    FD_SET (rep->sock, &fds);

    timeval tv;
    tv.tv_sec  = wp_sec;
    tv.tv_usec = wp_usec;

    int ret = select (rep->sock+1, 0, &fds, 0, (wp_sec == -1) ? 0: &tv);
    if (ret == -1) {
	error ("Select::operator ()");
	return 0;
    }
    return ret;
}

int sockbuf::is_exceptionpending (int wp_sec, int wp_usec) const
{
    fd_set fds;
    FD_ZERO (&fds);
    FD_SET  (rep->sock, &fds);

    timeval tv;
    tv.tv_sec = wp_sec;
    tv.tv_usec = wp_usec;

    int ret = select (rep->sock+1, 0, 0, &fds, (wp_sec == -1) ? 0: &tv);
    if (ret == -1) {
	error ("Select::operator ()");
	return 0;
    }
    return ret;
}

void sockbuf::shutdown (shuthow sh)
{
    switch (sh) {
    case shut_read:
	xsetflags(_S_NO_READS);
	break;
    case shut_write:
	xsetflags(_S_NO_WRITES);
	break;
    case shut_readwrite:
	xsetflags(_S_NO_READS|_S_NO_WRITES);
	break;
    }
#ifndef WIN32
    if (::shutdown(rep->sock, sh) == -1)
	error("sockbuf::shutdown");
#endif
}

int sockbuf::getopt (option op, void* buf, int len, level l) const
{
    int	rlen = len;
    if (::getsockopt (rep->sock, l, op, (char*) buf, &rlen) == -1)
	perror ("sockbuf::getopt");
    return rlen;
}

void sockbuf::setopt (option op, void* buf, int len, level l) const
{
    if (::setsockopt (rep->sock, l, op, (char*) buf, len) == -1)
	perror ("sockbuf::setopt");
}

sockbuf::type sockbuf::gettype () const
{
    int	ty=0;
    getopt (so_type, &ty, sizeof (ty));
    return sockbuf::type(ty);
}

int sockbuf::clearerror () const
{
    int 	err=0;
    getopt (so_error, &err, sizeof (err));
    return err;
}

int sockbuf::debug (int opt) const
{
    int old=0;
    getopt (so_debug, &old, sizeof (old));
    if (opt != -1)
	setopt (so_debug, &opt, sizeof (opt));
    return old;
}

int sockbuf::reuseaddr (int opt) const
{
    int old=0;
    getopt (so_reuseaddr, &old, sizeof (old));
    if (opt != -1)
	setopt (so_reuseaddr, &opt, sizeof (opt));
    return old;
}

int sockbuf::keepalive (int opt) const
{
    int old=0;
    getopt (so_keepalive, &old, sizeof (old));
    if (opt != -1)
	setopt (so_keepalive, &opt, sizeof (opt));
    return old;
}

int sockbuf::dontroute (int opt) const
{
    int old=0;
    getopt (so_dontroute, &old, sizeof (old));
    if (opt != -1)
	setopt (so_dontroute, &opt, sizeof (opt));
    return old;
}

int sockbuf::broadcast (int opt) const
{
    int old=0;
    getopt (so_broadcast, &old, sizeof (old));
    if (opt != -1)
	setopt (so_broadcast, &opt, sizeof (opt));
    return old;
}

int sockbuf::oobinline (int opt) const
{
    int old=0;
    getopt (so_oobinline, &old, sizeof (old));
    if (opt != -1)
	setopt (so_oobinline, &opt, sizeof (opt));
    return old;
}

int sockbuf::linger (int opt) const
{
    socklinger	old (0, 0);
    getopt (so_linger, &old, sizeof (old));
    if (opt > 0) {
	socklinger nw (1, opt);
	setopt (so_linger, &nw, sizeof (nw));
    }else if (opt == 0) {
	socklinger nw (0, old.l_linger);
	setopt (so_linger, &nw, sizeof (nw));
    }
    return old.l_onoff ? old.l_linger: -1;
}

int sockbuf::sendbufsz (int  sz) const
{
    int old=0;
    getopt (so_sndbuf, &old, sizeof (old));
    if (sz >= 0)
	setopt (so_sndbuf, &sz, sizeof (sz));
    return old;
}

int sockbuf::recvbufsz (int sz) const
{
    int old=0;
    getopt (so_rcvbuf, &old, sizeof (old));
    if (sz >= 0)
	setopt (so_rcvbuf, &sz, sizeof (sz));
    return old;
}

void sockbuf::error (const char* msg) const
{
    sock_error ("class sockbuf: ", msg);
}

void isockstream::error (const char* msg) const
{
    sock_error ("class isockstream: ", msg);
}

void osockstream::error (const char* msg) const
{
    sock_error ("class osockstream: ", msg);
}

void iosockstream::error( const char* msg ) const
{
    sock_error ("class iosockstream: ", msg);
}
