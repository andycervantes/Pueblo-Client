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

	This file consists of the interface for the Internet Sockets++ classes.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/sockinet.h,v 2.4 1995/10/14 16:57:12 coyote Exp $

#ifndef _SOCKINET_H
#define	_SOCKINET_H

#if defined( CH_SERVER ) || defined( CH_UNIX )

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA    
#endif

#if defined( CH_UNIX ) && defined( CH_CLIENT )
	#define String XtString
	#include <X11/Intrinsic.h>
	#undef String
#endif // CH_UNIX && CH_CLIENT

#include <ChTypes.h>
#include <ChSplay.h>

#include "sockstrm.h"

#if !defined( CH_MSW )
	#include <netinet/in.h>
#endif

#if defined( CH_UNIX )
// Experimental, as of 2/27/95 -GAC
#define WS_ASYNC
#endif

#if defined( CH_MSW  ) && !defined( WS_ASYNC )
	#define WS_ASYNC	1
#endif

#if defined( CH_MSW ) && defined( CH_ARCH_32 )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )


/*----------------------------------------------------------------------------
	Event constants
----------------------------------------------------------------------------*/

#ifdef CH_UNIX
#define FD_READ		0
#define FD_OOB		1
#define FD_CONNECT	2
#define FD_CLOSE	3
#endif // CH_UNIX

#define CH_SOCK_EVENT_READ		FD_READ		// Socket is ready for reading
#define CH_SOCK_EVENT_OOB_READ	FD_OOB		/* Socket is ready for reading
												out-of-band data */
#define CH_SOCK_EVENT_CONNECT	FD_CONNECT	// Socket connection is complete
#define CH_SOCK_EVENT_CLOSE		FD_CLOSE	// Socket has been closed


/*----------------------------------------------------------------------------
	sockinetaddr class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS sockinetaddr: public sockAddr, public sockaddr_in
{
	public:
											// Lots of constructors...
		sockinetaddr();
		sockinetaddr( chuint32 luAddr, chint16 sPort = 0 );
		sockinetaddr( const char *pstrHostName, chint16 sPort = 0 );
		sockinetaddr( chuint32 luAddr, const char *pstrServiceName,
						const char *pstrProtocolName = "tcp" );
		sockinetaddr( const char *pstrHostName, const char *pstrServiceName,
						const char *pstrProtocolName = "tcp" );
		sockinetaddr( const sockinetaddr& sockINetAddr );

											// (void *) cast operator

		operator void*() const { return (sockaddr_in *)this; }

											// Public methods

		int GetSize() const { return sizeof( sockaddr_in ); }
		int GetFamily() const { return sin_family; }
		sockaddr *GetAddr() const { return (sockaddr *)((sockaddr_in *)this); }

		int	GetPort() const;
		const char *GetHostname() const;

	protected:
		void SetPort( const char *pstrServiceName,
						const char *pstrProtocolName = "tcp" );
		void SetAddr( const char *pstrHostName );
};


/*----------------------------------------------------------------------------
	sockinetbuf class
----------------------------------------------------------------------------*/

class sockinetbuf;

typedef sockinetbuf	*psockinetbuf;
typedef void (CALLBACK EXPORT *ChSocketHandler)( sockinetbuf& si, chparam luEvent );   

#if defined( NO_TEMPLATES )
#include <TemplCls\ChSockBf.h>   
#endif

class CH_EXPORT_CLASS sockinetbuf: public sockbuf
{
	#if defined( CH_MSW )
		friend chint32 CALLBACK EXPORT SocketsXXWSAproc( HWND hwnd, UINT uMsg,
															WPARAM wParam,
															LPARAM lParam );
	#endif	// defined( CH_MSW )
#if defined( CH_UNIX ) && defined( CH_CLIENT )
		friend void SocketsXXXtproc( XtPointer client_data, int *fid, XtInputId *id);
#endif

	public:
		enum domain { af_inet = AF_INET };

		sockinetbuf( const sockbuf& si ) : sockbuf( si ), m_pUserData( 0 ), m_pHandler( 0 ), m_boolInFinalDestruct( false )
		{
			#if defined( CH_UNIX ) && defined( CH_CLIENT )
			m_inputId = 0;
			#endif
		};
		sockinetbuf( const sockinetbuf& si );
		sockinetbuf( sockbuf::type ty, int proto=0 );
		sockinetbuf( int soc );

		chparam GetUserData() { return m_pUserData ? *m_pUserData : 0; }
		void SetUserData( chparam userData );

		chuint32 GetBytesAvailable() const;

		#if defined( WS_ASYNC )

		sockinetbuf( sockbuf::type ty, ChSocketHandler pHandler,
						chparam userData = 0, chint16 sProto = 0 );

		#if defined( CH_MSW )

		static void InitWinsockNotification( HINSTANCE hInstance );

		#endif	// defined( CH_MSW )

#if defined( CH_UNIX ) && defined( CH_CLIENT )
		XtInputId GetInputId(void) { return m_inputId; };
#endif

		virtual ~sockinetbuf();

		#endif	// defined( WS_ASYNC )

		sockbuf*		open (sockbuf::type, int proto=0);

		sockinetaddr	localaddr() const;
		int				localport() const;
		const char*		localhost() const;

		sockinetaddr	peeraddr() const;
		int				peerport() const;
		const char*		peerhost() const;

		virtual int	bind( sockAddr& sa );
		int			bind();
		int			bind( unsigned long addr, int port_no=0 );
		int			bind( const char* host_name, int port_no=0 );
		int			bind( unsigned long addr, const char* service_name,
								const char* protocol_name="tcp" );
		int			bind( const char* host_name, const char* service_name,
								const char* protocol_name="tcp");

		virtual void	connect( sockAddr& sa );
		void			connect( unsigned long addr, int port_no=0 );
		void			connect( const char* host_name, int port_no=0 );
		void			connect( unsigned long addr, const char* service_name,
								const char* protocol_name="tcp" );
		void			connect( const char* host_name, const char* service_name,
								const char* protocol_name="tcp" );

		int				is_readready ( int wp_sec, int wp_usec=0 ) const;

	protected:
    	sockinetbuf& operator=( const sockbuf& si );
		sockinetbuf& operator=( const sockinetbuf& inetSocket );

	protected:
		chparam			*m_pUserData;
		ChSocketHandler	m_pHandler;

		#if defined( WS_ASYNC )
			#if defined( CH_MSW )

				static  HWND	hwndWSA;
				static	HWND	CreateWsaWindow( HINSTANCE hInstance );

			#endif	// defined( CH_MSW )
            
            #if !defined( NO_TEMPLATES )
			static ChPtrSplay<sockinetbuf>	bufTree;
			#else
			static ChSockBufTree			bufTree;
			#endif

		#endif	// defined( WS_ASYNC )

#if defined( CH_UNIX ) && defined( CH_CLIENT )
		XtInputId m_inputId;	// XtAppAddInput()'s return value.
#endif // CH_UNIX

	private:
		inline void SetFinalDestruct() { m_boolInFinalDestruct = true; }
		inline bool IsFinalDestruct() { return m_boolInFinalDestruct; }

	private:
		bool			m_boolInFinalDestruct;
};


/*----------------------------------------------------------------------------
	isockinet class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS isockinet: public isockstream
{
public:
    			isockinet (const sockbuf& sb);
    			isockinet (sockbuf::type ty=sockbuf::sock_stream,
	       			   int proto=0);
    			isockinet (sockinetbuf* sb)
    			: ios (sb) { _S_IOS_SETF (dont_close); }

    sockinetbuf*	rdbuf () { return (sockinetbuf*)ios::rdbuf (); }
    sockinetbuf*	operator -> () { return rdbuf (); }
};


/*----------------------------------------------------------------------------
	osockinet class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS osockinet: public osockstream
{
public:
    			osockinet (const sockbuf& sb);
    			osockinet (sockbuf::type ty=sockbuf::sock_stream,
				   int proto=0);
    			osockinet (sockinetbuf* sb)
    			: ios (sb) { _S_IOS_SETF (dont_close); }

    sockinetbuf*	rdbuf () { return (sockinetbuf*)ios::rdbuf (); }
    sockinetbuf*	operator -> () { return rdbuf (); }
};


/*----------------------------------------------------------------------------
	iosockinet class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS iosockinet: public iosockstream
{
public:
    			iosockinet (const sockbuf& sb);
    			iosockinet (sockbuf::type ty=sockbuf::sock_stream,
				    int proto=0);
    			iosockinet (sockinetbuf* sb)
    			: ios (sb) { _S_IOS_SETF (dont_close); }

    sockinetbuf*	rdbuf () { return (sockinetbuf*)ios::rdbuf (); }
    sockinetbuf*	operator -> () { return rdbuf (); }
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA NEAR    
#endif

#endif	// defined( CH_SERVER ) || defined( CH_UNIX )
#endif	// _SOCKINET_H
