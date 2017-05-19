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

	This ALWAYS GENERATED file contains the definitions for the interfaces.

----------------------------------------------------------------------------*/

/* File created by MIDL compiler version 3.00.15 */
/* at Fri Aug 23 10:44:34 1996
 */
/* Compiler settings for ChIVRMLViewer.idl:
    Os, W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ChIVRMLViewer_h__
#define __ChIVRMLViewer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IChVRMLCallback_FWD_DEFINED__
#define __IChVRMLCallback_FWD_DEFINED__
typedef interface IChVRMLCallback IChVRMLCallback;
#endif 	/* __IChVRMLCallback_FWD_DEFINED__ */


#ifndef __IChVRMLViewer_FWD_DEFINED__
#define __IChVRMLViewer_FWD_DEFINED__
typedef interface IChVRMLViewer IChVRMLViewer;
#endif 	/* __IChVRMLViewer_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri Aug 23 10:44:34 1996
 * using MIDL 3.00.15
 ****************************************/
/* [local] */ 


#ifndef _VRSCOUTBROWSER_DEFINED
#define _VRSCOUTBROWSER_DEFINED
		
		
#define SCOUT_OK 			 ((HRESULT)0x00000000L)
#define SCOUT_FALSE			 ((HRESULT)0x00000001L)
		



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IChVRMLCallback_INTERFACE_DEFINED__
#define __IChVRMLCallback_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChVRMLCallback
 * at Fri Aug 23 10:44:34 1996
 * using MIDL 3.00.15
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IChVRMLCallback __RPC_FAR *pChVRMLCallback;


EXTERN_C const IID IID_IChVRMLCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IChVRMLCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE onDraw( 
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onViewPointChange( 
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onUpdateStatus( 
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [string][in] */ const char __RPC_FAR *pstrStatusMsg,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onError( 
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwErrorCode,
            /* [string][in] */ const char __RPC_FAR *pstrErrorMsg,
            /* [in] */ DWORD dwReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChVRMLCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChVRMLCallback __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChVRMLCallback __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChVRMLCallback __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onDraw )( 
            IChVRMLCallback __RPC_FAR * This,
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onViewPointChange )( 
            IChVRMLCallback __RPC_FAR * This,
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onUpdateStatus )( 
            IChVRMLCallback __RPC_FAR * This,
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [string][in] */ const char __RPC_FAR *pstrStatusMsg,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onError )( 
            IChVRMLCallback __RPC_FAR * This,
            /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
            /* [in] */ DWORD dwUserData,
            /* [in] */ DWORD dwErrorCode,
            /* [string][in] */ const char __RPC_FAR *pstrErrorMsg,
            /* [in] */ DWORD dwReserved);
        
        END_INTERFACE
    } IChVRMLCallbackVtbl;

    interface IChVRMLCallback
    {
        CONST_VTBL struct IChVRMLCallbackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChVRMLCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChVRMLCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChVRMLCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChVRMLCallback_onDraw(This,pViewer,dwUserData,dwReserved)	\
    (This)->lpVtbl -> onDraw(This,pViewer,dwUserData,dwReserved)

#define IChVRMLCallback_onViewPointChange(This,pViewer,dwUserData,dwReserved)	\
    (This)->lpVtbl -> onViewPointChange(This,pViewer,dwUserData,dwReserved)

#define IChVRMLCallback_onUpdateStatus(This,pViewer,dwUserData,pstrStatusMsg,dwReserved)	\
    (This)->lpVtbl -> onUpdateStatus(This,pViewer,dwUserData,pstrStatusMsg,dwReserved)

#define IChVRMLCallback_onError(This,pViewer,dwUserData,dwErrorCode,pstrErrorMsg,dwReserved)	\
    (This)->lpVtbl -> onError(This,pViewer,dwUserData,dwErrorCode,pstrErrorMsg,dwReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IChVRMLCallback_onDraw_Proxy( 
    IChVRMLCallback __RPC_FAR * This,
    /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
    /* [in] */ DWORD dwUserData,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IChVRMLCallback_onDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLCallback_onViewPointChange_Proxy( 
    IChVRMLCallback __RPC_FAR * This,
    /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
    /* [in] */ DWORD dwUserData,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IChVRMLCallback_onViewPointChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLCallback_onUpdateStatus_Proxy( 
    IChVRMLCallback __RPC_FAR * This,
    /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
    /* [in] */ DWORD dwUserData,
    /* [string][in] */ const char __RPC_FAR *pstrStatusMsg,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IChVRMLCallback_onUpdateStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLCallback_onError_Proxy( 
    IChVRMLCallback __RPC_FAR * This,
    /* [unique][in] */ IChVRMLViewer __RPC_FAR *pViewer,
    /* [in] */ DWORD dwUserData,
    /* [in] */ DWORD dwErrorCode,
    /* [string][in] */ const char __RPC_FAR *pstrErrorMsg,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IChVRMLCallback_onError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChVRMLCallback_INTERFACE_DEFINED__ */


#ifndef __IChVRMLViewer_INTERFACE_DEFINED__
#define __IChVRMLViewer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChVRMLViewer
 * at Fri Aug 23 10:44:34 1996
 * using MIDL 3.00.15
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IChVRMLViewer __RPC_FAR *pChVRMLViewer;

typedef /* [unique] */ void __RPC_FAR *pChNode;

typedef /* [unique] */ void __RPC_FAR *pChApplet;

typedef struct  tagChVRMLEvent
    {
    int iSize;
    struct tagChVRMLEvent __RPC_FAR *nextEvent;
    
    enum type
        {	invalid	= 0,
	SFBitMask	= 1,
	SFBool	= SFBitMask + 1,
	SFColor	= SFBool + 1,
	SFEnum	= SFColor + 1,
	SFFloat	= SFEnum + 1,
	SFImage	= SFFloat + 1,
	SFLong	= SFImage + 1,
	SFMatrix	= SFLong + 1,
	SFNode	= SFMatrix + 1,
	SFRotation	= SFNode + 1,
	SFString	= SFRotation + 1,
	SFVec2f	= SFString + 1,
	SFVec3f	= SFVec2f + 1,
	SFTime	= SFVec3f + 1,
	SFPick	= SFTime + 1,
	SFProximity	= SFPick + 1,
	SFCollision	= SFProximity + 1,
	MFBitMask	= 0x8001,
	MFBool	= MFBitMask + 1,
	MFColor	= MFBool + 1,
	MFEnum	= MFColor + 1,
	MFFloat	= MFEnum + 1,
	MFImage	= MFFloat + 1,
	MFLong	= MFImage + 1,
	MFMatrix	= MFLong + 1,
	MFNode	= MFMatrix + 1,
	MFRotation	= MFNode + 1,
	MFString	= MFRotation + 1,
	MFVec2f	= MFString + 1,
	MFVec3f	= MFVec2f + 1,
	MFTime	= MFVec3f + 1,
	MFPick	= MFTime + 1,
	MFProximity	= MFPick + 1,
	MFCollision	= MFProximity + 1
        }	eventType;
    double eventTime;
    /* [string] */ const char __RPC_FAR *eventName;
    int dataSize;
    /* [size_is] */ char __RPC_FAR *bytes;
    }	ChVRMLEvent;

typedef /* [unique] */ ChVRMLEvent __RPC_FAR *pChVRMLEvent;


EXTERN_C const IID IID_IChVRMLViewer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IChVRMLViewer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE sendEvent( 
            /* [unique][in] */ pChNode pNode,
            /* [unique][in] */ pChApplet pApplet,
            /* [unique][in] */ pChVRMLEvent pEventList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNode( 
            /* [string][in] */ const char __RPC_FAR *pstrName,
            /* [out] */ pChNode __RPC_FAR *ppNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE resolve( 
            /* [unique][in] */ pChNode relativeNode,
            /* [string][in] */ const char __RPC_FAR *pstrName,
            /* [out] */ pChNode __RPC_FAR *ppNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createVRMLFromString( 
            /* [string][in] */ const char __RPC_FAR *pstrVRML,
            /* [out] */ pChNode __RPC_FAR *ppNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE useNode( 
            /* [unique][in] */ pChNode pNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE freeNode( 
            /* [unique][in] */ pChNode pNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE loadWorld( 
            /* [string][in] */ const char __RPC_FAR *pstrURL) = 0;
        
        virtual int STDMETHODCALLTYPE getType( 
            /* [string][in] */ const char __RPC_FAR *pstrEventTypeName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getName( 
            /* [out] */ char __RPC_FAR *pstrName,
            /* [unique][out][in] */ long __RPC_FAR *plLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getVersion( 
            /* [out] */ char __RPC_FAR *pstrVersion,
            /* [unique][out][in] */ long __RPC_FAR *plLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getWorldURL( 
            /* [out] */ char __RPC_FAR *pstrURL,
            /* [unique][out][in] */ long __RPC_FAR *plLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCurrentSpeed( 
            /* [out] */ float __RPC_FAR *pfSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getVelocity( 
            /* [out] */ float __RPC_FAR fVel[ 3 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getViewpoint( 
            /* [out] */ pChNode __RPC_FAR *ppNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getViewpointPosition( 
            /* [out] */ float __RPC_FAR fLoc[ 3 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getViewpointOrientation( 
            /* [out] */ float __RPC_FAR fAxis[ 3 ],
            /* [out] */ float __RPC_FAR *pfAngle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setViewpointPosition( 
            /* [in] */ float __RPC_FAR loc[ 3 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setViewpointOrientation( 
            /* [in] */ float __RPC_FAR fAxis[ 3 ],
            /* [in] */ float __RPC_FAR *pfAngle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onActivate( 
            /* [in] */ short sActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onSize( 
            /* [in] */ int iWidth,
            /* [in] */ int iHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE show( 
            /* [in] */ short sShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE addClientCallback( 
            /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
            /* [in] */ DWORD dwUserData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE removeClientCallback( 
            /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
            /* [in] */ DWORD dwUserData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE translateError( 
            /* [in] */ DWORD dwErrorCode,
            /* [out] */ char __RPC_FAR *pstrDesc,
            /* [unique][out][in] */ long __RPC_FAR *plLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChVRMLViewerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChVRMLViewer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChVRMLViewer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *sendEvent )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ pChNode pNode,
            /* [unique][in] */ pChApplet pApplet,
            /* [unique][in] */ pChVRMLEvent pEventList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getNode )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [string][in] */ const char __RPC_FAR *pstrName,
            /* [out] */ pChNode __RPC_FAR *ppNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *resolve )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ pChNode relativeNode,
            /* [string][in] */ const char __RPC_FAR *pstrName,
            /* [out] */ pChNode __RPC_FAR *ppNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *createVRMLFromString )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [string][in] */ const char __RPC_FAR *pstrVRML,
            /* [out] */ pChNode __RPC_FAR *ppNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *useNode )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ pChNode pNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *freeNode )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ pChNode pNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *loadWorld )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [string][in] */ const char __RPC_FAR *pstrURL);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *getType )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [string][in] */ const char __RPC_FAR *pstrEventTypeName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getName )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ char __RPC_FAR *pstrName,
            /* [unique][out][in] */ long __RPC_FAR *plLen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getVersion )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ char __RPC_FAR *pstrVersion,
            /* [unique][out][in] */ long __RPC_FAR *plLen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getWorldURL )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ char __RPC_FAR *pstrURL,
            /* [unique][out][in] */ long __RPC_FAR *plLen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getCurrentSpeed )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ float __RPC_FAR *pfSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getVelocity )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ float __RPC_FAR fVel[ 3 ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getViewpoint )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ pChNode __RPC_FAR *ppNode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getViewpointPosition )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ float __RPC_FAR fLoc[ 3 ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getViewpointOrientation )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [out] */ float __RPC_FAR fAxis[ 3 ],
            /* [out] */ float __RPC_FAR *pfAngle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setViewpointPosition )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ float __RPC_FAR loc[ 3 ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setViewpointOrientation )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ float __RPC_FAR fAxis[ 3 ],
            /* [in] */ float __RPC_FAR *pfAngle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onActivate )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ short sActive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *onSize )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ int iWidth,
            /* [in] */ int iHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *show )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ short sShow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *addClientCallback )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
            /* [in] */ DWORD dwUserData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *removeClientCallback )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
            /* [in] */ DWORD dwUserData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *translateError )( 
            IChVRMLViewer __RPC_FAR * This,
            /* [in] */ DWORD dwErrorCode,
            /* [out] */ char __RPC_FAR *pstrDesc,
            /* [unique][out][in] */ long __RPC_FAR *plLen);
        
        END_INTERFACE
    } IChVRMLViewerVtbl;

    interface IChVRMLViewer
    {
        CONST_VTBL struct IChVRMLViewerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChVRMLViewer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChVRMLViewer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChVRMLViewer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChVRMLViewer_sendEvent(This,pNode,pApplet,pEventList)	\
    (This)->lpVtbl -> sendEvent(This,pNode,pApplet,pEventList)

#define IChVRMLViewer_getNode(This,pstrName,ppNode)	\
    (This)->lpVtbl -> getNode(This,pstrName,ppNode)

#define IChVRMLViewer_resolve(This,relativeNode,pstrName,ppNode)	\
    (This)->lpVtbl -> resolve(This,relativeNode,pstrName,ppNode)

#define IChVRMLViewer_createVRMLFromString(This,pstrVRML,ppNode)	\
    (This)->lpVtbl -> createVRMLFromString(This,pstrVRML,ppNode)

#define IChVRMLViewer_useNode(This,pNode)	\
    (This)->lpVtbl -> useNode(This,pNode)

#define IChVRMLViewer_freeNode(This,pNode)	\
    (This)->lpVtbl -> freeNode(This,pNode)

#define IChVRMLViewer_loadWorld(This,pstrURL)	\
    (This)->lpVtbl -> loadWorld(This,pstrURL)

#define IChVRMLViewer_getType(This,pstrEventTypeName)	\
    (This)->lpVtbl -> getType(This,pstrEventTypeName)

#define IChVRMLViewer_getName(This,pstrName,plLen)	\
    (This)->lpVtbl -> getName(This,pstrName,plLen)

#define IChVRMLViewer_getVersion(This,pstrVersion,plLen)	\
    (This)->lpVtbl -> getVersion(This,pstrVersion,plLen)

#define IChVRMLViewer_getWorldURL(This,pstrURL,plLen)	\
    (This)->lpVtbl -> getWorldURL(This,pstrURL,plLen)

#define IChVRMLViewer_getCurrentSpeed(This,pfSpeed)	\
    (This)->lpVtbl -> getCurrentSpeed(This,pfSpeed)

#define IChVRMLViewer_getVelocity(This,fVel)	\
    (This)->lpVtbl -> getVelocity(This,fVel)

#define IChVRMLViewer_getViewpoint(This,ppNode)	\
    (This)->lpVtbl -> getViewpoint(This,ppNode)

#define IChVRMLViewer_getViewpointPosition(This,fLoc)	\
    (This)->lpVtbl -> getViewpointPosition(This,fLoc)

#define IChVRMLViewer_getViewpointOrientation(This,fAxis,pfAngle)	\
    (This)->lpVtbl -> getViewpointOrientation(This,fAxis,pfAngle)

#define IChVRMLViewer_setViewpointPosition(This,loc)	\
    (This)->lpVtbl -> setViewpointPosition(This,loc)

#define IChVRMLViewer_setViewpointOrientation(This,fAxis,pfAngle)	\
    (This)->lpVtbl -> setViewpointOrientation(This,fAxis,pfAngle)

#define IChVRMLViewer_onActivate(This,sActive)	\
    (This)->lpVtbl -> onActivate(This,sActive)

#define IChVRMLViewer_onSize(This,iWidth,iHeight)	\
    (This)->lpVtbl -> onSize(This,iWidth,iHeight)

#define IChVRMLViewer_show(This,sShow)	\
    (This)->lpVtbl -> show(This,sShow)

#define IChVRMLViewer_addClientCallback(This,lpIClientCallback,dwUserData)	\
    (This)->lpVtbl -> addClientCallback(This,lpIClientCallback,dwUserData)

#define IChVRMLViewer_removeClientCallback(This,lpIClientCallback,dwUserData)	\
    (This)->lpVtbl -> removeClientCallback(This,lpIClientCallback,dwUserData)

#define IChVRMLViewer_translateError(This,dwErrorCode,pstrDesc,plLen)	\
    (This)->lpVtbl -> translateError(This,dwErrorCode,pstrDesc,plLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IChVRMLViewer_sendEvent_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ pChNode pNode,
    /* [unique][in] */ pChApplet pApplet,
    /* [unique][in] */ pChVRMLEvent pEventList);


void __RPC_STUB IChVRMLViewer_sendEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getNode_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [string][in] */ const char __RPC_FAR *pstrName,
    /* [out] */ pChNode __RPC_FAR *ppNode);


void __RPC_STUB IChVRMLViewer_getNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_resolve_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ pChNode relativeNode,
    /* [string][in] */ const char __RPC_FAR *pstrName,
    /* [out] */ pChNode __RPC_FAR *ppNode);


void __RPC_STUB IChVRMLViewer_resolve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_createVRMLFromString_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [string][in] */ const char __RPC_FAR *pstrVRML,
    /* [out] */ pChNode __RPC_FAR *ppNode);


void __RPC_STUB IChVRMLViewer_createVRMLFromString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_useNode_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ pChNode pNode);


void __RPC_STUB IChVRMLViewer_useNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_freeNode_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ pChNode pNode);


void __RPC_STUB IChVRMLViewer_freeNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_loadWorld_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [string][in] */ const char __RPC_FAR *pstrURL);


void __RPC_STUB IChVRMLViewer_loadWorld_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE IChVRMLViewer_getType_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [string][in] */ const char __RPC_FAR *pstrEventTypeName);


void __RPC_STUB IChVRMLViewer_getType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getName_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ char __RPC_FAR *pstrName,
    /* [unique][out][in] */ long __RPC_FAR *plLen);


void __RPC_STUB IChVRMLViewer_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getVersion_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ char __RPC_FAR *pstrVersion,
    /* [unique][out][in] */ long __RPC_FAR *plLen);


void __RPC_STUB IChVRMLViewer_getVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getWorldURL_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ char __RPC_FAR *pstrURL,
    /* [unique][out][in] */ long __RPC_FAR *plLen);


void __RPC_STUB IChVRMLViewer_getWorldURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getCurrentSpeed_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ float __RPC_FAR *pfSpeed);


void __RPC_STUB IChVRMLViewer_getCurrentSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getVelocity_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ float __RPC_FAR fVel[ 3 ]);


void __RPC_STUB IChVRMLViewer_getVelocity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getViewpoint_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ pChNode __RPC_FAR *ppNode);


void __RPC_STUB IChVRMLViewer_getViewpoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getViewpointPosition_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ float __RPC_FAR fLoc[ 3 ]);


void __RPC_STUB IChVRMLViewer_getViewpointPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_getViewpointOrientation_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [out] */ float __RPC_FAR fAxis[ 3 ],
    /* [out] */ float __RPC_FAR *pfAngle);


void __RPC_STUB IChVRMLViewer_getViewpointOrientation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_setViewpointPosition_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ float __RPC_FAR loc[ 3 ]);


void __RPC_STUB IChVRMLViewer_setViewpointPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_setViewpointOrientation_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ float __RPC_FAR fAxis[ 3 ],
    /* [in] */ float __RPC_FAR *pfAngle);


void __RPC_STUB IChVRMLViewer_setViewpointOrientation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_onActivate_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ short sActive);


void __RPC_STUB IChVRMLViewer_onActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_onSize_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ int iWidth,
    /* [in] */ int iHeight);


void __RPC_STUB IChVRMLViewer_onSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_show_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ short sShow);


void __RPC_STUB IChVRMLViewer_show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_addClientCallback_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
    /* [in] */ DWORD dwUserData);


void __RPC_STUB IChVRMLViewer_addClientCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_removeClientCallback_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [unique][in] */ IChVRMLCallback __RPC_FAR *lpIClientCallback,
    /* [in] */ DWORD dwUserData);


void __RPC_STUB IChVRMLViewer_removeClientCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChVRMLViewer_translateError_Proxy( 
    IChVRMLViewer __RPC_FAR * This,
    /* [in] */ DWORD dwErrorCode,
    /* [out] */ char __RPC_FAR *pstrDesc,
    /* [unique][out][in] */ long __RPC_FAR *plLen);


void __RPC_STUB IChVRMLViewer_translateError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChVRMLViewer_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0007
 * at Fri Aug 23 10:44:34 1996
 * using MIDL 3.00.15
 ****************************************/
/* [local] */ 


#define SHOW_TOOLBAR 0x00000001L

STDAPI ChCreateVRMLViewer( DWORD dwOption, LPRECT prtFrame, HWND hParent, pChVRMLViewer FAR * ppViewer );             
#endif


extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
