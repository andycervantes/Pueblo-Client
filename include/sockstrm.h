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

	This file consists of the core streaming interfaces for the Sockets++
	classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/sockstrm.h,v 2.3 1995/11/09 10:23:40 pritham Exp $

#ifndef _SOCKSTREAM_H
#define	_SOCKSTREAM_H

#if defined( CH_SERVER ) || defined( CH_UNIX )

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif

#include <iostream.h>
#include <stddef.h>
#include <sys/types.h>

#include <ChTypes.h>

#ifdef CH_MSW
#include <winsock.h>
#else
#include <sys/uio.h>
#include <sys/socket.h>
#endif /* CH_MSW */


#ifndef _G_config_h
	// non libg++ or g++ compilation
#       define _S_NOLIBGXX

#       define _S_USER_BUF		0x0001
#       define _S_UNBUFFERED		0x0002
#       define _S_NO_READS		0x0004
#       define _S_NO_WRITES		0x0008
#       define _S_EOF_SEEN		0x0010
#       define _S_ERR_SEEN		0x0020
#       define _S_DELETE_DONT_CLOSE	0x0040
#       define _S_LINKED		0x0080
#       define _S_LINE_BUF		0x0200

#       define _G_ssize_t size_t

#       define _S_IOS_SETF(x) (x = 1)
#       define _S_IOS_UNSETF(x) (x=0)

#else
#       ifndef _S_USER_BUF
		// libg++ 2.5.x
#               define _S_USER_BUF		_IO_USER_BUF
#		define _S_UNBUFFERED		_IO_UNBUFFERED
#		define _S_NO_READS		_IO_NO_READS
#		define _S_NO_WRITES		_IO_NO_WRITES
#		define _S_EOF_SEEN		_IO_EOF_SEEN
#		define _S_ERR_SEEN		_IO_ERR_SEEN
#		define _S_DELETE_DONT_CLOSE	_IO_DELETE_DONT_CLOSE
#		define _S_LINKED		_IO_LINKED
#		define _S_LINE_BUF		_IO_LINE_BUF
#	endif //  !_S_USER_BUF

#	define _S_IOS_SETF(x) ios::setf (ios::dont_close)
#	define _S_IOS_UNSETF(x) ios::unsetf (ios::dont_close)

#endif //  !_G_config_h

#ifdef __linux__
// linux leaves these thing out. We define it for compatitbility
// not for their use.
#	define SO_ACCEPTCONN	0x0002
#	define SO_USELOOPBACK	0x0040
#	define SO_SNDLOWAT	0x1003
#	define SO_RCVLOWAT	0x1004
#	define SO_SNDTIMEO	0x1005
#	define SO_RCVTIMEO	0x1006

#	define MSG_MAXIOVLEN	16
#	define SOMAXCONN	5
#endif // __linux__

extern void sock_error (const char* classname, const char* error_message);


/*----------------------------------------------------------------------------
	sockaddr class
----------------------------------------------------------------------------*/

struct sockaddr;

class CH_EXPORT_CLASS sockAddr
{
	public:
		virtual ~sockAddr() {}

		virtual	operator void*() const = 0;
		operator sockaddr*() const { return GetAddr(); }

		virtual int GetSize() const = 0;
		virtual int GetFamily() const = 0;
		virtual sockaddr* GetAddr() const = 0;

		void error( const char *pstrErr ) const;
};


/*----------------------------------------------------------------------------
	sockbuf class
----------------------------------------------------------------------------*/

struct msghdr;

class sockbuf;

class CH_EXPORT_CLASS sockbuf: public streambuf
{
public:
    enum type {
	sock_stream	= SOCK_STREAM,
	sock_dgram	= SOCK_DGRAM,
	sock_raw	= SOCK_RAW,
	sock_rdm	= SOCK_RDM,
	sock_seqpacket  = SOCK_SEQPACKET
    };
    enum option {
	so_debug	= SO_DEBUG,
	so_acceptconn	= SO_ACCEPTCONN,
	so_reuseaddr	= SO_REUSEADDR,
	so_keepalive	= SO_KEEPALIVE,
	so_dontroute	= SO_DONTROUTE,
	so_broadcast	= SO_BROADCAST,
	so_useloopback	= SO_USELOOPBACK,
	so_linger	= SO_LINGER,
	so_oobinline	= SO_OOBINLINE,
	so_sndbuf	= SO_SNDBUF,
	so_rcvbuf	= SO_RCVBUF,
	so_sndlowat	= SO_SNDLOWAT,
	so_rcvlowat	= SO_RCVLOWAT,
	so_sndtimeo	= SO_SNDTIMEO,
	so_rcvtimeo	= SO_RCVTIMEO,
	so_error	= SO_ERROR,
	so_type		= SO_TYPE
    };
	#if !defined( CH_ARCH_16 )
    enum level { sol_socket = SOL_SOCKET };
	#else
    enum level { sol_socket = 32767/*SOL_SOCKET*/ };
	#endif
    enum msgflag {
	msg_oob		= MSG_OOB,
	msg_peek	= MSG_PEEK,
	msg_dontroute	= MSG_DONTROUTE,

	msg_maxiovlen	= MSG_MAXIOVLEN
    };
    enum shuthow {
	shut_read,
	shut_write,
	shut_readwrite
    };
    enum { somaxconn	= SOMAXCONN };
    struct socklinger {
	int	l_onoff;	// option on/off
	int	l_linger;	// linger time

	socklinger (int a, int b): l_onoff (a), l_linger (b) {}
    };

protected:
    struct sockcnt {
	int	sock;
	int	cnt;

	sockcnt(int s, int c): sock(s), cnt(c) {}
    };

    sockcnt*	rep;  // counts the # refs to sock
    int		stmo; // -1==block, 0==poll, >0 == waiting time in secs
    int		rtmo; // -1==block, 0==poll, >0 == waiting time in secs

    virtual int		underflow ();
    virtual int		overflow (int c = EOF);
    virtual int		doallocate ();
    int			flush_output ();

#ifdef _S_NOLIBGXX
    int         x_flags; // port to USL iostream
    int                 xflags () const { return x_flags; }
    int                 xsetflags (int f) { return x_flags |= f; }
    int                 xflags (int f)
	                { int ret = x_flags; x_flags = f; return ret; }
    void                xput_char (char c) { *pptr() = c; pbump (1); }
    int                 linebuffered () const { return x_flags & _S_LINE_BUF; }
#endif // _S_NOLIBGXX

public:
				sockbuf (int soc = -1);
    			sockbuf (int, type, int proto=0);
    			sockbuf (const sockbuf&);
    sockbuf&		operator = (const sockbuf&);
    virtual 		~sockbuf ();
    			operator int () const { return rep->sock; }


    virtual sockbuf*	open	(type, int proto=0);
    virtual sockbuf*	close	();
    virtual int		sync	();
    virtual _G_ssize_t	sys_read (char* buf, _G_ssize_t len);
    virtual _G_ssize_t	sys_write (const void* buf, long len);
    virtual int		xsputn (const char* s, int n);
    int			is_open () const { return rep->sock >= 0; }
    int			is_eof  ()       { return xflags() & _S_EOF_SEEN; }


    virtual int		bind	(sockAddr&);
    virtual void	connect	(sockAddr&);

    void		listen	(int num=somaxconn);
    virtual sockbuf	accept	();
    virtual sockbuf	accept	(sockAddr& sa);

    int			read	(void* buf, int len);
    int			recv	(void* buf, int len, int msgf=0);
    int			recvfrom(sockAddr& sa,
				 void* buf, int len, int msgf=0);

#ifndef __linux__
    int			recvmsg (msghdr* msg, int msgf=0);
    int			sendmsg	(msghdr* msg, int msgf=0);
#endif

    int			write	(const void* buf, int len) const;
    int			send	(const void* buf, int len, int msgf=0);
    int			sendto	(sockAddr& sa,
				 const void* buf, int len, int msgf=0);

    int			sendtimeout (int wp=-1);
    int			recvtimeout (int wp=-1);
    int			is_readready (int wp_sec, int wp_usec=0) const;
    int			is_writeready (int wp_sec, int wp_usec=0) const;
    int			is_exceptionpending (int wp_sec, int wp_usec=0) const;

    void		shutdown (shuthow sh);

    int			getopt(option op, void* buf,int len,
			       level l=sol_socket) const;
    void		setopt(option op, void* buf,int len,
			       level l=sol_socket) const;

    type		gettype () const;
    int			clearerror () const;
    int			debug	  (int opt= -1) const;
    int			reuseaddr (int opt= -1) const;
    int			keepalive (int opt= -1) const;
    int			dontroute (int opt= -1) const;
    int			broadcast (int opt= -1) const;
    int			oobinline (int opt= -1) const;
    int			linger    (int tim= -1) const;
    int			sendbufsz (int sz=-1)   const;
    int			recvbufsz (int sz=-1)   const;
	void		cancelblocking() {}

    void		error (const char* errmsg) const;
};


/*----------------------------------------------------------------------------
	isockstream class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS isockstream: public istream {
#ifdef _S_NOLIBGXX
protected:
    int                 dont_close;
public:
	                ~isockstream () { if (!dont_close) delete rdbuf (); }
#endif
public:
    			isockstream(sockbuf& sb)
    			: ios (&sb) { _S_IOS_SETF(dont_close); }
    			isockstream(sockbuf* sb=0)
			: ios (sb) { _S_IOS_SETF(dont_close); }


    sockbuf*		rdbuf () { return (sockbuf*)ios::rdbuf(); }
    sockbuf*		operator -> () { return rdbuf(); }

    void		error (const char* errmsg) const;
};


/*----------------------------------------------------------------------------
	osockstream class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS osockstream: public ostream {
#ifdef _S_NOLIBGXX
protected:
    int                 dont_close;
public:
	                ~osockstream () { if (!dont_close) delete rdbuf (); }
#endif
public:
    			osockstream(sockbuf& sb)
			: ios (&sb) { _S_IOS_SETF(dont_close); }
    			osockstream(sockbuf* sb=0)
			: ios (sb) { _S_IOS_SETF(dont_close); }

    sockbuf*		rdbuf () { return (sockbuf*)ios::rdbuf(); }
    sockbuf*		operator -> () { return rdbuf(); }

    void		error (const char* errmsg) const;
};


/*----------------------------------------------------------------------------
	iosockstream class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS iosockstream: public iostream {
#ifdef _S_NOLIBGXX
protected:
    int             dont_close;
public:
	                ~iosockstream () { if (!dont_close) delete rdbuf(); }
#endif
public:
    			iosockstream(sockbuf& sb)
			: ios (&sb) { _S_IOS_SETF(dont_close); }
    			iosockstream(sockbuf* sb=0)
			: ios (sb) { _S_IOS_SETF(dont_close); }

    sockbuf*		rdbuf () { return (sockbuf*)ios::rdbuf(); }
    sockbuf*		operator -> () { return rdbuf(); }

    void		error (const char* errmsg) const;
};

#if defined( CH_MSW )

void WSADisplayError( chint16 sError, char *pstrContext );

#endif	// defined( WIN32 )

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR    
#endif

#endif	// defined( CH_SERVER ) || defined( CH_UNIX )
#endif	// _SOCKSTREAM_H
