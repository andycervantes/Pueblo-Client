// protocol.h -*- C++ -*- socket library
// Copyright (C) 1992,1993,1994 Gnanasekaran Swaminathan <gs4t@virginia.edu>
// 
// Permission is granted to use at your own risk and distribute this software
// in source and binary forms provided the above copyright
// notice and this paragraph are preserved on all copies.
// This software is provided "as is" with no express or implied warranty.
//
// Version: 21May94 1.7

// $Header: /home/cvs/chaco/include/protocol.h,v 2.2 1995/10/14 16:57:11 coyote Exp $

#ifndef PROTOCOL_H
#define PROTOCOL_H


#if defined( CH_SERVER ) || defined( CH_UNIX )

#include <SocketXX.h>

class protocol: public iosockstream {
public:
  enum p_name {
    nil = 0,
    tcp = sockbuf::sock_stream,
    udp = sockbuf::sock_dgram
  };

  class protocolbuf: public sockinetbuf {
  private:
#ifdef CH_MSW
    p_name pn;
#else
    protocol::p_name pn;
#endif

    int bind (sockAddr& sa) { return sockbuf::bind (sa); }
    void connect (sockAddr& sa) { sockbuf::connect (sa); }
   
  public:
    protocolbuf (sockbuf& si): sockinetbuf (si), pn (nil) {}
#ifdef CH_MSW
    protocolbuf (p_name pname)
      : sockinetbuf ((sockbuf::type) pname, 0), pn (pname) {}
#else
    protocolbuf (protocol::p_name pname)
      : sockinetbuf ((sockbuf::type) pname, 0), pn (pname) {}
#endif

    int                bind () { return serve_clients (); }
    void                connect ();
    void                connect (unsigned long addr);
    void                connect (const char* host);
    void                connect (const char* host, int portno);

    const char*         protocol_name () const;

    virtual int        serve_clients (int portno = -1) = 0;
    virtual const char* rfc_name () const = 0;
    virtual const char* rfc_doc  () const = 0;
  };

  protocol (): ios (0), iosockstream((sockbuf*) 0) {}
};

inline const char* protocol::protocolbuf::protocol_name () const
{
  if (pn == protocol::tcp)
    return "tcp";
  if (pn == protocol::udp)
    return "udp";
  return "";
}

inline void protocol::protocolbuf::connect ()
{
  if (pn != nil)
    sockinetbuf::connect (localhost (), rfc_name (), protocol_name ());
}

inline void protocol::protocolbuf::connect (unsigned long addr)
     // addr is in host byte order
{
  if (pn != nil)
    sockinetbuf::connect (addr, rfc_name (), protocol_name ());
}

inline void protocol::protocolbuf::connect (const char* host)
{
  if (pn != nil)
    sockinetbuf::connect (host, rfc_name (), protocol_name ());
}

inline void protocol::protocolbuf::connect (const char* host, int portno)
{
  if (pn != nil)
    sockinetbuf::connect (host, portno);
}

#endif // defined( CH_SERVER ) || defined( CH_UNIX )

#endif // PROTOCOL_H
