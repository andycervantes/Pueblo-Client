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

	This file consists of the Internet implementation for the Sockets++
	classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/api/sockinet.cpp,v 2.3 1995/08/22 00:41:28 glenn Exp $

#include "headers.h"						// Precompiled header directive

#include <ChExcept.h>

#if defined( CH_UNIX )

	#define BSD_COMP

	#include <sys/ioctl.h>
	#include <ChTypes.h>
	#include <sockinet.h>
	#include <ChFdSet.h>

#endif	// defined( CH_UNIX )

#ifdef _AIX
	#define _BSD 43 // define this 44 if BSD 4.4 compat is desired
#endif

#include <SocketXX.h>

#if defined (__alpha) && defined (__DECCXX)
#  define extern extern "C" // fix dec's massive screw up.
#  include <netdb.h>
#  undef extern
#else
#  ifndef WIN32
#    include <netdb.h>
#  endif
#endif

#ifndef _S_NOLIBGXX
#	include <builtin.h>
#endif
#ifdef WIN32
#include <winsock.h>
#else
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#endif /* WIN32 */

#include <stdlib.h>
#include <memory.h>
#include <errno.h>

// <arpa/inet.h> does not have a prototype for inet_addr () and gethostname()
#if !defined(WIN32)
extern "C" unsigned long inet_addr (const char*);

#if !defined (__linux__)
extern "C" int gethostname (char* hostname, int len);
#endif
#endif /* WIN32 */

#ifdef __alpha // alpha/osf2 does not define the following macros/functions
  extern "C" {
    unsigned short ntohs (unsigned short);
    unsigned short htons (unsigned short);
    unsigned long  ntohl (unsigned long);
    unsigned long  htonl (unsigned long);
  }
#endif

/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define _CH_SUPPORTED_ASYNC_EVENTS	(CH_SOCK_EVENT_READ | \
										CH_SOCK_EVENT_OOB_READ | \
										CH_SOCK_EVENT_CONNECT | \
										CH_SOCK_EVENT_CLOSE)


void herror( const char* strErrMessage );

#if defined( WS_ASYNC )

	#if defined( WIN32 )
		#define CH_WSA_NOTIF_CLASS	"Chaco-WSA-Notification-Class"
		#define	CH_MSG_WSA_PACKET_RECEIVED		WM_USER + 500

		chint32 CALLBACK EXPORT SocketsXXWSAproc( HWND hwnd, UINT  uMsg,
													WPARAM wParam, LPARAM lParam );

		HWND					sockinetbuf::hwndWSA = 0;

	#endif	// defined( WIN32 )

	#if defined( CH_UNIX ) && defined( CH_CLIENT )
		void SocketsXXXtproc( XtPointer client_data, int *fid, XtInputId *id);
	#endif  // CH_UNIX

	ChPtrSplay<sockinetbuf>		sockinetbuf::bufTree;

#endif	// defined( WS_ASYNC )

sockinetaddr::sockinetaddr()
{
	sin_family = sockinetbuf::af_inet;
	sin_addr.s_addr = htonl( INADDR_ANY );
	sin_port = 0;
}

sockinetaddr::sockinetaddr( chuint32 luAddr, chint16 sPort )
{
											/* luAddr and sPort are in host
												byte order */
	sin_family = sockinetbuf::af_inet;
	sin_addr.s_addr = htonl( luAddr );
	sin_port = htons( sPort );
}

sockinetaddr::sockinetaddr( chuint32 luAddr, const char *pstrServiceName,
							const char *pstrProtocolName )
{
											// addr is in host byte order
	sin_family = sockinetbuf::af_inet;
	sin_addr.s_addr = htonl( luAddr );		/* Added by cgay@cs.uoregon.edu
												May 29, 1993 */
	SetPort( pstrServiceName, pstrProtocolName );
}

sockinetaddr::sockinetaddr( const char *pstrHostName, chint16 sPort )
{
											// port_no is in host byte order
	SetAddr( pstrHostName );
	sin_port = htons( sPort );
}

sockinetaddr::sockinetaddr( const char *pstrHostName,
							const char *pstrServiceName,
							const char *pstrProtocolName )
{
	SetAddr( pstrHostName );
	SetPort( pstrServiceName, pstrProtocolName );
}

sockinetaddr::sockinetaddr( const sockinetaddr& sockINetAddr )
{
	sin_family = sockinetbuf::af_inet;
	sin_addr.s_addr = sockINetAddr.sin_addr.s_addr;
	sin_port = sockINetAddr.sin_port;
}

void sockinetaddr::SetPort( const char *pstrServiceName,
							const char *pstrProtocolName )
{
	servent *pServiceEntry = getservbyname( pstrServiceName,
											pstrProtocolName );

	if (pServiceEntry == 0)
	{
		perror( pstrServiceName );
		error ( "sockinetaddr: invalid service name" );
		exit( 1 );
	}

	sin_port = pServiceEntry->s_port;
}

int sockinetaddr::GetPort() const
{
	return ntohs( sin_port );
}

void sockinetaddr::SetAddr( const char *pstrHostName )
{
											/* First try to interpret the host
												name as a *.*.*.* address */

	if ( (sin_addr.s_addr = inet_addr( pstrHostName )) == -1)
	{
											/* If that didn't work, then try
												to look up the host by name */

		hostent *pHostEntry = gethostbyname( pstrHostName );

		if (pHostEntry == 0)
		{
			#if defined( WIN32 ) && defined( _DEBUG )
			{
				WSADisplayError( WSAGetLastError(), "sockinetaddr::setaddr" );
			}
			#endif	// defined( WIN32 ) && defined( _DEBUG )

			#if defined( CH_EXCEPTIONS )
			{
				throw ChSocketEx( ChEx::hostNotFound );
			}
			#else
			{
				herror( "sockinetaddr::sockinetaddr -- Bad host name" );
				exit( 1 );
			}
			#endif
		}

		memcpy( &sin_addr, pHostEntry->h_addr, pHostEntry->h_length );
		sin_family = pHostEntry->h_addrtype;
	}
	else
	{
		sin_family = sockinetbuf::af_inet;
	}
}

const char* sockinetaddr::GetHostname() const
{
	if (sin_addr.s_addr == htonl( INADDR_ANY ))
	{
		static char		strHostname[64];

		if (::gethostname( strHostname, 63 ) == -1)
		{
			perror( "in sockinetaddr::gethostname" );
			return "";
		}

		return strHostname;
	}

	hostent *pHostEntry = gethostbyaddr( (const char*)&sin_addr,
											sizeof( sin_addr ),
				    						GetFamily() );
	if (0 == pHostEntry)
	{
		herror( "sockinetaddr::gethostname" );

		return "";
	}

	if (pHostEntry->h_name)
	{
		return pHostEntry->h_name;
	}

	return "";
}


// Copy constructor
sockinetbuf::sockinetbuf( const sockinetbuf& si ) :
				sockbuf( si ), m_pUserData( 0 ),
				m_boolInFinalDestruct( false )
{
	#if defined( WS_ASYNC )
	{
		m_pUserData = si.m_pUserData;
		m_pHandler = si.m_pHandler;
	}
	#endif	// defined( WS_ASYNC )

	#if defined( CH_UNIX ) && defined( CH_CLIENT )
	m_inputId = 0;
	#endif
}


sockinetbuf::sockinetbuf( sockbuf::type ty, int proto ) :
				sockbuf( af_inet, ty, proto ),
				m_pUserData( 0 ),
				m_pHandler( 0 ),
				m_boolInFinalDestruct( false )
{
	#if defined( CH_UNIX ) && defined( CH_CLIENT )
	m_inputId = 0;
	#endif
}

#if defined( WS_ASYNC )

// This constructor returns a copy of the sockbuf already open on the
// socket, if any.
sockinetbuf::sockinetbuf( int soc ) :
				m_pUserData( 0 ), m_boolInFinalDestruct( false )
{
	psockinetbuf	*ppbuf;

	if (ppbuf = (sockinetbuf::bufTree.Find( (chparam) soc)))
	{
		*this = **ppbuf;
	}
	else
	{
	    rep = new sockcnt (soc, 1);
		stmo = -1;
		rtmo = -1;
		m_pHandler = 0;

		#if defined( _S_NOLIBGXX )
		{
	    	xflags( 0 );
		}
		#endif	// defined( _S_NOLIBGXX )

	    xsetflags( _S_LINE_BUF );
	}
	#if defined( CH_UNIX ) && defined( CH_CLIENT )
	m_inputId = 0;
	#endif
}

// Create an async socketbuf. Receives read, oob, and close notifcation in the handler callback

sockinetbuf::sockinetbuf( sockbuf::type ty, ChSocketHandler pHandler,
							chparam userData, chint16 sProto ) :
				sockbuf( af_inet, ty, sProto ),
				m_boolInFinalDestruct( false )
{
#ifdef CH_MSW
	chint16		sError;
#endif
											/* Allocate a new pointer for
												the user data.  A pointer is
												used so that changing the value
												of one socket record changes
												all related socket records */
	m_pUserData = new chparam;

	ASSERT( m_pUserData );

	*m_pUserData = userData;
	m_pHandler = pHandler;

	if (!(sockinetbuf::bufTree.Find( (chparam) rep->sock )))
	{
											/* Register a copy of the new
												sockbuf for this socket in
												the tree */

		sockinetbuf*	pStashedCopy = new sockinetbuf( *this );

		sockinetbuf::bufTree.Insert( (chparam) rep->sock, pStashedCopy );
	}

	#if defined( CH_MSW )
	{
		sError = WSAAsyncSelect( rep->sock, sockinetbuf::hwndWSA,
									CH_MSG_WSA_PACKET_RECEIVED,
									_CH_SUPPORTED_ASYNC_EVENTS );
	}
	#endif	// defined( CH_MSW )

	#if defined( CH_UNIX ) && defined( CH_CLIENT )
	{
		extern XtAppContext app;
	
		// XXX Should save the return value.
		m_inputId = XtAppAddInput( app, (int) *this, (void *)XtInputReadMask,
					   				SocketsXXXtproc, (void *)this);
	}
	#endif

	#if defined( CH_MSW ) && defined( CH_DEBUG )
	{
		if (SOCKET_ERROR == sError)
		{
			WSADisplayError( WSAGetLastError(), "sockinetbuf::sockinetbuf" );
		}
	}
	#endif	// defined( CH_MSW ) && defined( CH_DEBUG )
}

sockinetbuf::~sockinetbuf ()
{
	chint16		sNewCount = rep->cnt - 1;

    overflow( EOF );

	if (!IsFinalDestruct())
	{
		if (1 == sNewCount && this->m_pHandler)
		{
											/* This is really last one, due to
												extra one in tree */
			sockinetbuf		*pSocket;

			if (pSocket = *(sockinetbuf::bufTree.Find( (chparam) rep->sock )))
			{
				sockinetbuf::bufTree.Delete( (chparam) rep->sock );
			}
											/* Set the 'final destruct' flag
												to avoid going through this
												code again */
			pSocket->SetFinalDestruct();
											// Delete the socket in the tree
			delete pSocket;
											// Recalculate sNewCount
			sNewCount = rep->cnt - 1;
		}
	}

    if (0 == sNewCount && !(xflags () & _S_DELETE_DONT_CLOSE))
    {
											// We're about to be destructed
    	close();
#if defined(CH_UNIX) && defined(CH_CLIENT)
	if ( GetInputId() )
		XtRemoveInput( GetInputId() );
#endif
    }

	if (0 == sNewCount)
   	{										// We're about to go away
   		if (m_pUserData)
		{									// Delete the user data storage
			delete m_pUserData;
		}
// XXX Leak 8 bytes.
// We're getting double-frees here on Unix (and probably on non-threaded
// MSW, and maybe on threaded MSW).  It's probably due to the baroque
// and vile reference counting garbage we're doing.
#ifndef CH_UNIX
		delete rep;
#endif
	}

    delete [] base();
}

#endif	// defined( WS_ASYNC )


/*----------------------------------------------------------------------------

	FUNCTION	||	sockinetbuf::SetUserData

------------------------------------------------------------------------------

	This methods sets the user data for the specified socket and for the
	corresponding cached socket, if there is one.

----------------------------------------------------------------------------*/

void sockinetbuf::SetUserData( chparam userData )
{
	if (m_pUserData)
	{										/* Set the user data value for
												all sockets related to this
												one */
		*m_pUserData = userData;
	}
	else
	{										/* This socket doesn't currently
												have user data.  Allocate new
												memory for this socket
												only. */
		m_pUserData = new chparam;
		ASSERT( m_pUserData );
		*m_pUserData = userData;
	}
}


#if defined( WS_ASYNC ) && defined( CH_MSW )

HWND sockinetbuf::CreateWsaWindow( HINSTANCE hInstance )
{
	hwndWSA = CreateWindow( CH_WSA_NOTIF_CLASS, "Chaco WSA Window",
							WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
							CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							0, 0, hInstance, 0 );
	return hwndWSA;
}

#endif	// defined( WS_ASYNC )

sockinetbuf& sockinetbuf::operator =( const sockbuf& socket )
{
	this->sockbuf::operator =( socket );
	return *this;

}

sockinetbuf& sockinetbuf::operator =( const sockinetbuf& inetSocket )
{
	this->sockbuf::operator =( inetSocket );
											// Copy the member variables
	#if defined( WS_ASYNC )
	{
		#if defined( CH_MSW )
		{
			this->hwndWSA = inetSocket.hwndWSA;
		}
		#endif	// defined( CH_MSW )
	}
	#endif	// defined( WS_ASYNC )

	this->m_pUserData = inetSocket.m_pUserData;
	this->m_pHandler = inetSocket.m_pHandler;

	return *this;
}

sockbuf* sockinetbuf::open(sockbuf::type st, int proto)
{
	*this = sockinetbuf(st, proto);
	return this;
}

sockinetaddr sockinetbuf::localaddr() const
{
	sockinetaddr	sin;
	int				len = sin.GetSize();

	if (::getsockname(rep->sock, sin.GetAddr(), &len) == -1)
		perror("sockinetbuf::localaddr()");
	return sin;
}

int sockinetbuf::localport() const
{
	sockinetaddr sin = localaddr();
	if (sin.GetFamily() != af_inet) return -1;
	return sin.GetPort();
}

const char* sockinetbuf::localhost() const
{
	sockinetaddr sin = localaddr();
	if (sin.GetFamily() != af_inet) return "";
	return sin.GetHostname();
}


sockinetaddr sockinetbuf::peeraddr() const
{
	sockinetaddr sin;
	int len = sin.GetSize();
	if (::getpeername(rep->sock, sin.GetAddr(), &len) == -1)
		perror("sockinetbuf::peeraddr()");
	return sin;
}

int sockinetbuf::peerport() const
{
	sockinetaddr sin = peeraddr();
	if (sin.GetFamily() != af_inet) return -1;
	return sin.GetPort();
}

const char* sockinetbuf::peerhost() const
{
	sockinetaddr sin = peeraddr();
	if (sin.GetFamily() != af_inet) return "";
	return sin.GetHostname();
}

int sockinetbuf::bind (sockAddr& sa)
{
    return sockbuf::bind (sa);
}

int sockinetbuf::bind ()
{
    sockinetaddr sa;
    return bind (sa);
}

int sockinetbuf::bind (unsigned long addr, int port_no)
     // address and portno are in host byte order
{
    sockinetaddr sa (addr, port_no);
    return bind (sa);
}

int sockinetbuf::bind (const char* host_name, int port_no)
{
    sockinetaddr sa (host_name, port_no);
    return bind (sa);
}

int sockinetbuf::bind (unsigned long addr,
			const char* service_name,
			const char* protocol_name)
{
    sockinetaddr sa (addr, service_name, protocol_name);
    return bind (sa);
}

int sockinetbuf::bind (const char* host_name,
			const char* service_name,
			const char* protocol_name)
{
    sockinetaddr sa (host_name, service_name, protocol_name);
    return bind (sa);
}

// Note that these are all blocking connects
void sockinetbuf::connect (sockAddr& sa)
{
	#if defined( CH_MSW ) && defined( WS_ASYNC )
	{
		if (m_pHandler)
		{
			chuint32	luBlock = 0;

			WSAAsyncSelect( rep->sock, sockinetbuf::hwndWSA, 0, 0 );
			ioctlsocket( rep->sock, FIONBIO, &luBlock );
		}
	}
	#endif	// defined( CH_MSW ) && defined( WS_ASYNC )

    sockbuf::connect( sa );

	#if defined( CH_MSW ) && defined( WS_ASYNC )
	{
		if (m_pHandler)
		{
			WSAAsyncSelect( rep->sock, sockinetbuf::hwndWSA,
							CH_MSG_WSA_PACKET_RECEIVED,
							_CH_SUPPORTED_ASYNC_EVENTS );
		}
	}
	#endif	// defined( CH_MSW ) && defined( WS_ASYNC )
}

void sockinetbuf::connect (unsigned long addr, int port_no)
     // address and portno are in host byte order
{
    sockinetaddr sa (addr, port_no);

    connect (sa);
}

void sockinetbuf::connect (const char* host_name, int port_no)
{
    sockinetaddr sa (host_name, port_no);

    connect (sa);
}

void sockinetbuf::connect (unsigned long addr,
			const char* service_name,
			const char* protocol_name)
{
    sockinetaddr sa (addr, service_name, protocol_name);

    connect (sa);
}

void sockinetbuf::connect (const char* host_name,
			const char* service_name,
			const char* protocol_name)
{
    sockinetaddr	sa( host_name, service_name, protocol_name );

    connect( sa );
}

int sockinetbuf::is_readready (int wp_sec, int wp_usec)	const
{
	#if defined( WS_ASYNC )

    if (m_pHandler)
    {
		chuint32	luBytes;

		luBytes = GetBytesAvailable();

		return( 0 != luBytes );
    }
    else

	#endif	// defined( WS_ASYNC )

    {
	    fd_set fds;
	    FD_ZERO (&fds);
	    FD_SET (rep->sock, &fds);

	    timeval tv;
	    tv.tv_sec  = wp_sec;
	    tv.tv_usec = wp_usec;

	    int ret = select( rep->sock + 1, &fds, 0, 0, (wp_sec == -1) ? 0 : &tv );
	    if (ret == -1)
	    {
			error( "sockinetbuf::readready" );
			return 0;
	    }

	    return ret;
	}
}


/*----------------------------------------------------------------------------

	FUNCTION	||	sockinetbuf::GetBytesAvailable

	RETURNS		||	Number of bytes available to read on the socket.

------------------------------------------------------------------------------

	This method will return the number of bytes available to be read on
	a socket, -without- doing a select.

----------------------------------------------------------------------------*/

chuint32 sockinetbuf::GetBytesAvailable( void ) const
{
	chuint32	luBytes;

	#if defined( CH_MSW )
	{
		ioctlsocket( rep->sock, FIONREAD, &luBytes );
	}
	#elif defined( CH_UNIX )
		ioctl( rep->sock, FIONREAD, &luBytes );
	#else
		#error Unknown system
	#endif

	return( luBytes );
}

#if defined( WS_ASYNC )
#if defined( CH_MSW )

void sockinetbuf::InitWinsockNotification( HINSTANCE hInstance )
{
	WNDCLASS	wc;

	wc.hInstance = hInstance;
	wc.lpszClassName = CH_WSA_NOTIF_CLASS;
	wc.lpfnWndProc	= SocketsXXWSAproc;
	wc.hCursor = 0;
	wc.hIcon = 0;
	wc.hbrBackground = 0;
	wc.lpszMenuName = 0;
	wc.style = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	RegisterClass( &wc );

	CreateWsaWindow( hInstance );
}

LONG CALLBACK EXPORT
SocketsXXWSAproc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	if (CH_MSG_WSA_PACKET_RECEIVED == uMsg)
	{
		sockinetbuf	sb( (int)wParam );
		chuint16	suEvent = WSAGETSELECTEVENT( lParam );

		(sb.m_pHandler)( sb, (chparam) suEvent );

		return 0;
	}

	return DefWindowProc( hwnd, uMsg, wParam, lParam );
}

#endif	// defined( CH_MSW )

#if defined( CH_UNIX ) && defined( CH_CLIENT )
void SocketsXXXtproc( XtPointer client_data, int *fid, XtInputId *id)
{
    sockinetbuf *sb = (sockinetbuf *)client_data;

    chuint32 luBytesAvailable = sb->GetBytesAvailable();

    // If the socket has been closed, remove the Xt input.
//    if ( !sb->is_readready(0) ) {
    if (luBytesAvailable <= 0) {
	XtInputId inputId = sb->GetInputId(); // Save the id.

	(sb->m_pHandler)( *sb, CH_SOCK_EVENT_CLOSE );
	XtRemoveInput( inputId );
	return;
    }

    (sb->m_pHandler)( *sb, CH_SOCK_EVENT_READ );
}
#endif // CH_UNIX

#endif	// defined( WS_ASYNC )

isockinet::isockinet (sockbuf::type ty, int proto)
: ios (new sockinetbuf (ty, proto))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}

isockinet::isockinet (const sockbuf& sb)
: ios (new sockinetbuf (sb))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}

osockinet::osockinet (sockbuf::type ty, int proto)
: ios (new sockinetbuf (ty, proto))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}

osockinet::osockinet (const sockbuf& sb)
: ios (new sockinetbuf (sb))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}

iosockinet::iosockinet (sockbuf::type ty, int proto)
: ios (new sockinetbuf (ty, proto))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}

iosockinet::iosockinet (const sockbuf& sb)
: ios (new sockinetbuf (sb))
{
    _S_IOS_UNSETF (dont_close); // ios::~ios deletes rdbuf()
}


#ifndef WIN32
extern "C" int h_errno;
#endif

static	char* errmsg[] = {
		": No error\n",
		": Host not found\n",
		": Try again\n",
		": No recovery\n",
		": No address\n"
		": Unknown error\n"
		};

void herror( const char* strErrMessage )
{
	#ifdef WIN32
	{
		#if defined( CH_VERBOSE )
		if (h_errno > 5)
		{
			cerr << strErrMessage << ": unknown error" << endl;
		}
		else
		{
			cerr << strErrMessage << errmsg[h_errno];
		}
		#endif
	}
	#else
	{
		if (h_errno > 5)
		{
			h_errno = 5;
		}

		cerr << strErrMessage << errmsg[h_errno];
	}
	#endif
}
