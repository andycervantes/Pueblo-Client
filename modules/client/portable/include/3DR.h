/* Copyright (C) 1994 Intel Corporation. All rights reserved */


#ifndef	_3DR_H_
#define	_3DR_H_

#ifdef	__cplusplus
extern	"C"{
#endif	/* __cplusplus */

#define	R3D_FUTURES

/*
// During a compile, at most one of these three must be defined to be 1,
// the rest should be 0.
//	WIN16	- for a 16 bit compiler, where a far pointer has 16,16 address.
//	WATCOM	- for Watcom, where a far pointer is 16,32 address.
//	WIN32	- for a Win32s compiler, where a far pointer is a 0,32 address.
//
// Note: Because all three are defined anyway, use #if instead of #ifdef.
*/

#ifndef	WATCOM	
#define	WATCOM	0
#endif

#ifndef	WIN32
#define	WIN32	0
#endif

#ifndef	WIN16	
#define	WIN16	0
#endif

#ifndef	WAT32	
#define	WAT32	0
#endif

#ifndef	UNUSED_PARAMETER
#define	UNUSED_PARAMETER(x)		x = x
#endif

/*
// Dictionary of Acronyms, Keywords etc.,
//
//	R3d	- 3DR, misspelt, for compilation reasons.
//
//	RC	- Rendering Context, as in RCInfo
//	Pt	- Point, as in PtLong_T
//	Clr	- Color, as in ClrLong_T
//	Ptr	- Pointer, as in LongPtrToByte_T
//	Prm	- Primitive, as in R3dPrmType_T
//	Vtx	- Vertex, as in R3dVtxType_T
//	SRC	- Source, as in R3D_STATE_SRC_BLEND
//	DST	- Destination, as in R3D_STATE_DST_BLEND
//	ROP	- Raster (logical) Operation, as in R3D_STATE_ROP_FUNCTION
//	Msg	- Message, as in R3dMsgType
//	MSG	- Message, as in R3D_MSG_NOP
//	Pkt	- Packet, as in R3dPktType
//	PKT	- Packet, as in R3D_PKT_END
//	Hdr	- Header, as in MsgHdrType
//	Gen	- Generic, as in MsgGenHdr
//	Bmp	- Bitmap, as in MsgBmpHdr
//	Sta	- State, as in PktStaType
//	STA	- STATE, as in R3D_STA_ENABLES
//	DB	- DoubleBuffer, as in  R3D_DB_FRONT
//	ZF	- Z buffer Function, as in R3D_ZF_NEVER 
//	LT	- Less Then, as in R3D_ZF_LT
//	EQ	- EQual to, as in R3D_ZF_EQ
//	LE	- Less then or Equal to, as in R3D_ZF_LE
//	GT	- Greater Then, as in R3D_ZF_GT
//	NE	- Not Equal to, as in R3D_ZF_NE
//	GE	- Greater then or Equal to, as in R3D_ZF_GE
//	BL	- Blending Function, as in R3D_BL_SRC_INV 
//	INV	- INVerse, as in R3D_BL_SRC_INV
//	RP	- Raster oPeration function, as in R3D_RP_AND 
//	TF	- Texture Filter function, as in R3D_TF_MIPMAP 
//	TM	- Texture Modulation function, as in R3D_TF_MIPMAP 
//	TT	- Texture Type information , as in R3D_TT_KEEP 
//	BT	- Bitmap Type information , as in R3D_BT_ALPHA 
//	ST	- State Type information , as in R3D_ST_LEFT 
//	CT	- Clearbuffer Type information , as in R3D_CT_DRAWBUFFER 
*/

/*
// Typedefs used commonly by 3dr.
*/
typedef		 	 void		Void_t;
typedef		 	 void	 *	PVoid_t;

typedef	unsigned char		Byte_t;
typedef unsigned short		Word_t;
typedef unsigned long		Dword_t;

typedef	         char		Char_t;
typedef          short		Short_t;
typedef		 	 long		Long_t;

typedef			 float		Float_t;
typedef		 	 WORD		Fixed16_t;
typedef 	 	 LONG		Fixed32_t;

typedef			 Dword_t	(*DWProc_t)();

typedef			 Dword_t	R3dHandle_t;

#if	WATCOM
typedef			 LPVOID			LPVoid_t;

typedef			 LPBYTE			LPByte_t;
typedef	unsigned short     *	LPWord_t;
typedef	unsigned long      *	LPDword_t;

typedef		 	 char      *	LPChar_t;
typedef		 	 short     *	LPShort_t;
typedef		 	 long      *	LPLong_t;

typedef		 	 float     *	LPFloat_t;

typedef		 	 void  FAR *	FPVoid_t;

typedef	unsigned char  FAR *	FPByte_t;
typedef	unsigned short FAR *	FPWord_t;
typedef	unsigned long  FAR *	FPDword_t;

typedef		 	 char  FAR *	FPChar_t;
typedef		 	 short FAR *	FPShort_t;
typedef		 	 long  FAR *	FPLong_t;

typedef		 	 float FAR *	FPFloat_t;
#endif	/* WATCOM */

#if	WIN16
typedef		 	 void  FAR *	LPVoid_t;

typedef	unsigned char  FAR *	LPByte_t;
typedef	unsigned short FAR *	LPWord_t;
typedef	unsigned long  FAR *	LPDword_t;

typedef		 	 char  FAR *	LPChar_t;
typedef		 	 short FAR *	LPShort_t;
typedef		 	 long  FAR *	LPLong_t;

typedef		 	 float FAR *	LPFloat_t;

typedef		 	 void  FAR *	FPVoid_t;

typedef	unsigned char  FAR *	FPByte_t;
typedef	unsigned short FAR *	FPWord_t;
typedef	unsigned long  FAR *	FPDword_t;

typedef		 	 char  FAR *	FPChar_t;
typedef		 	 short FAR *	FPShort_t;
typedef		 	 long  FAR *	FPLong_t;

typedef		 	 float FAR *	FPFloat_t;
#endif	/* WIN16 */

#if	WIN32
typedef		 	 void      *	LPVoid_t;

typedef	unsigned char      *	LPByte_t;
typedef	unsigned short     *	LPWord_t;
typedef	unsigned long      *	LPDword_t;

typedef		 	 char      *	LPChar_t;
typedef		 	 short     *	LPShort_t;
typedef		 	 long      *	LPLong_t;

typedef		 	 float     *	LPFloat_t;

typedef		 	 void      *	FPVoid_t;

typedef	unsigned char      *	FPByte_t;
typedef	unsigned short     *	FPWord_t;
typedef	unsigned long      *	FPDword_t;

typedef		 	 char      *	FPChar_t;
typedef		 	 short     *	FPShort_t;
typedef		 	 long      *	FPLong_t;

typedef		 	 float     *	FPFloat_t;
#endif	/* WIN32 */

/*D*
// 3DR data types - Points
*D*/
typedef	struct 
{ 
	Fixed32_t x, y, z;				
} R3dFixedVtx_t;

typedef	struct 
{ 
	Fixed32_t x, y, z; 
	Fixed16_t r, g, b, a; 	
} R3dFixedVtxClr_t;

typedef	struct 
{ 
	Fixed32_t x, y, z;
	Fixed32_t q, u, v; 			
} R3dFixedVtxTex_t;

typedef	struct 
{ 
	Fixed32_t x, y, z; 
	Fixed32_t q, u, v; 
	Fixed16_t r, g, b, a;
} R3dFixedVtxTexClr_t;

typedef	struct 
{ 
	Float_t x, y, z; 			
} R3dFloatVtx_t;

typedef	struct 
{ 
	Float_t x, y, z; 
	Float_t r, g, b, a; 		
} R3dFloatVtxClr_t;

typedef	struct 
{ 
	Float_t x, y, z; 
	Float_t q, u, v;		
} R3dFloatVtxTex_t;

typedef	struct 
{ 
	Float_t x, y, z; 
	Float_t q, u, v; 
	Float_t r, g, b, a;	
} R3dFloatVtxTexClr_t;

/*D*
// 3DR data types - Message Header
*D*/

typedef	struct {
	Word_t		MsgHdrType;
	Word_t		MsgHdrVersion;
	Dword_t		MsgHdrSize;
	R3dHandle_t	MsgHdrRC;
} R3dMsgHdr_t;

/*D*
// 3DR data types - Generic Message definition
*D*/

typedef	struct {
	R3dMsgHdr_t	MsgGenHdr;
	Word_t		MsgGenInfo0;
	Word_t		MsgGenInfo1;
	Dword_t		MsgGenData;			/* Buffer-wide Modifier */
	Dword_t		MsgGenBuffer[1]; 	/* variable size data	*/
} R3dMsgGen_t; 

/*D*
// 3DR data types - Texture Message definition
*D*/

typedef	struct {
	R3dMsgHdr_t	MsgTexHdr;		
	Word_t		MsgTexInfo;
	Word_t		MsgTexBitsPixel;
	Word_t		MsgTexMipLevel;	
	Word_t		MsgTexWidth;
	Word_t		MsgTexRows;		
	Short_t		MsgTexWidthBytes;
	Dword_t		MsgTexId;
	Dword_t		MsgTexData;			/* Buffer-wide Modifier */
	Dword_t		MsgTexBuffer[1]; 	/* variable size data	*/
} R3dMsgTex_t;
	
/*D*
// 3DR data types - Bitmap Message definition
*D*/

typedef	struct {
	R3dMsgHdr_t	MsgBmpHdr;	
	Word_t		MsgBmpPad;
	Word_t		MsgBmpInfo;
	Word_t		MsgBmpBitsPixel; 
	Word_t		MsgBmpWidth;
	Word_t		MsgBmpHeight; 
	Short_t		MsgBmpWidthBytes; 
	Short_t		MsgBmpSrcX;
	Short_t		MsgBmpSrcY;
	Short_t		MsgBmpDstX;
	Short_t		MsgBmpDstY;
	Dword_t		MsgBmpData;			/* Buffer-wide Modifier */
	Dword_t		MsgBmpBuffer[1]; 	/* variable size data	*/
} R3dMsgBmp_t; 

/*D*
// 3DR data types - Packet definition
*D*/

typedef	struct {
	R3dMsgHdr_t	MsgPktHdr;
	Dword_t		MsgPktBuffer[1];	/* variable size data	*/
} R3dMsgPkt_t; 

/*D*
// 3DR data types - Packet (of primitives) definition
*D*/

typedef struct	{
	Word_t		PktPrmPktType;
	Word_t		PktPrmVtxInfo;
	Word_t		PktPrmVtxNum;
	Word_t		PktPrmVtxSize;
	Dword_t		PktPrmBuffer[1];	/* variable size data	*/
} R3dPktPrm_t; 

/*D*
// 3DR data types - Packet (of State Information) definition
*D*/

typedef	struct {
	Word_t		PktStaPktType;
	Word_t		PktStaState;
	Dword_t		PktStaData;
} R3dPktSta_t; 

/*D*
// 3DR data types - Packet (of Vertices) definition
*D*/

typedef	struct {
	Word_t		PktGenPktType;
	Word_t		PktGenInfo;
} R3dPktGen_t; 

/*
// 3DR data types - far pointer types for above structures.
// FAR versions of the above for 16 bit compilers, 
// FAR is reduced to NULL for 32 bit compilers.
*/

#if	WATCOM
typedef	R3dFixedVtx_t			    *LPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		    *LPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		    *LPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		    *LPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			    *LPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		    *LPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		    *LPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		    *LPR3dFloatVtxTexClr_t;

typedef	R3dFixedVtx_t			FAR *FPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		FAR *FPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		FAR *FPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		FAR *FPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			FAR *FPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		FAR *FPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		FAR *FPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		FAR *FPR3dFloatVtxTexClr_t;

typedef	R3dMsgHdr_t			    	*LPR3dMsgHdr_t;
typedef	R3dMsgGen_t			    	*LPR3dMsgGen_t;
typedef	R3dMsgTex_t			    	*LPR3dMsgTex_t;
typedef	R3dMsgBmp_t			    	*LPR3dMsgBmp_t;
typedef	R3dMsgPkt_t			    	*LPR3dMsgPkt_t;
typedef	R3dPktPrm_t			    	*LPR3dPktPrm_t;
typedef	R3dPktSta_t			    	*LPR3dPktSta_t;
typedef	R3dPktGen_t			    	*LPR3dPktGen_t;

typedef	R3dMsgHdr_t				FAR *FPR3dMsgHdr_t;
typedef	R3dMsgGen_t				FAR *FPR3dMsgGen_t;
typedef	R3dMsgTex_t				FAR *FPR3dMsgTex_t;
typedef	R3dMsgBmp_t				FAR *FPR3dMsgBmp_t;
typedef	R3dMsgPkt_t				FAR *FPR3dMsgPkt_t;
typedef	R3dPktPrm_t				FAR *FPR3dPktPrm_t;
typedef	R3dPktSta_t				FAR *FPR3dPktSta_t;
typedef	R3dPktGen_t				FAR *FPR3dPktGen_t;
#endif	/* WIN16 */

#if	WIN16
typedef	R3dFixedVtx_t			FAR *LPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		FAR *LPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		FAR *LPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		FAR *LPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			FAR *LPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		FAR *LPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		FAR *LPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		FAR *LPR3dFloatVtxTexClr_t;

typedef	R3dFixedVtx_t			FAR *FPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		FAR *FPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		FAR *FPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		FAR *FPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			FAR *FPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		FAR *FPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		FAR *FPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		FAR *FPR3dFloatVtxTexClr_t;

typedef	R3dMsgHdr_t				FAR *LPR3dMsgHdr_t;
typedef	R3dMsgGen_t				FAR *LPR3dMsgGen_t;
typedef	R3dMsgTex_t				FAR *LPR3dMsgTex_t;
typedef	R3dMsgBmp_t				FAR *LPR3dMsgBmp_t;
typedef	R3dMsgPkt_t				FAR *LPR3dMsgPkt_t;
typedef	R3dPktPrm_t				FAR *LPR3dPktPrm_t;
typedef	R3dPktSta_t				FAR *LPR3dPktSta_t;
typedef	R3dPktGen_t				FAR *LPR3dPktGen_t;

typedef	R3dMsgHdr_t				FAR *FPR3dMsgHdr_t;
typedef	R3dMsgGen_t				FAR *FPR3dMsgGen_t;
typedef	R3dMsgTex_t				FAR *FPR3dMsgTex_t;
typedef	R3dMsgBmp_t				FAR *FPR3dMsgBmp_t;
typedef	R3dMsgPkt_t				FAR *FPR3dMsgPkt_t;
typedef	R3dPktPrm_t				FAR *FPR3dPktPrm_t;
typedef	R3dPktSta_t				FAR *FPR3dPktSta_t;
typedef	R3dPktGen_t				FAR *FPR3dPktGen_t;
#endif	/* WIN16 */

#if	WIN32
typedef	R3dFixedVtx_t			    *LPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		    *LPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		    *LPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		    *LPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			    *LPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		    *LPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		    *LPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		    *LPR3dFloatVtxTexClr_t;

typedef	R3dFixedVtx_t			    *FPR3dFixedVtx_t;
typedef	R3dFixedVtxClr_t		    *FPR3dFixedVtxClr_t;
typedef	R3dFixedVtxTex_t		    *FPR3dFixedVtxTex_t;
typedef	R3dFixedVtxTexClr_t		    *FPR3dFixedVtxTexClr_t;

typedef	R3dFloatVtx_t			    *FPR3dFloatVtx_t;
typedef	R3dFloatVtxClr_t		    *FPR3dFloatVtxClr_t;
typedef	R3dFloatVtxTex_t		    *FPR3dFloatVtxTex_t;
typedef	R3dFloatVtxTexClr_t		    *FPR3dFloatVtxTexClr_t;

typedef	R3dMsgHdr_t			   		*LPR3dMsgHdr_t;
typedef	R3dMsgGen_t			    	*LPR3dMsgGen_t;
typedef	R3dMsgTex_t			    	*LPR3dMsgTex_t;
typedef	R3dMsgBmp_t			    	*LPR3dMsgBmp_t;
typedef	R3dMsgPkt_t			    	*LPR3dMsgPkt_t;
typedef	R3dPktPrm_t			    	*LPR3dPktPrm_t;
typedef	R3dPktSta_t			    	*LPR3dPktSta_t;
typedef	R3dPktGen_t			    	*LPR3dPktGen_t;

typedef	R3dMsgHdr_t			    	*FPR3dMsgHdr_t;
typedef	R3dMsgGen_t			    	*FPR3dMsgGen_t;
typedef	R3dMsgTex_t			    	*FPR3dMsgTex_t;
typedef	R3dMsgBmp_t			    	*FPR3dMsgBmp_t;
typedef	R3dMsgPkt_t			    	*FPR3dMsgPkt_t;
typedef	R3dPktPrm_t			    	*FPR3dPktPrm_t;
typedef	R3dPktSta_t			    	*FPR3dPktSta_t;
typedef	R3dPktGen_t			    	*FPR3dPktGen_t;
#endif	/* WIN32 */

#ifdef	R3D_TYPES_ONLY
#else	/* R3D_TYPES_ONLY */
/*
// 3DR - Definitions
*/

/*
// These are the various packet identifers used by 3DR. 
//	These are used to create general packets.
//	These values are used in R3dMsgPtr_t.
// Pick ONE of ...
*/
#define	R3D_PKT_END					 0
#define	R3D_PKT_SETSTATE			 1
#define	R3D_PKT_CLEARBUFFERS		 2
#define	R3D_PKT_SWAPBUFFERS			 3
#define	R3D_PKT_POINTS				 4
#define	R3D_PKT_LINES				 5
#define	R3D_PKT_POLYLINE			 6 
#define	R3D_PKT_TRIANGLES			 7 
#define	R3D_PKT_TRISTRIP			 8
#define	R3D_PKT_POLYGON				 9
#define	R3D_PKT_QUADS				10
#define	R3D_PKT_QUADSTRIP			11

/*
// These are used by R3dPrimitive()
// Pick ONE of ...
*/
#define	R3D_PRM_POINTS				R3D_PKT_POINTS
#define	R3D_PRM_LINES				R3D_PKT_LINES
#define	R3D_PRM_POLYLINE			R3D_PKT_POLYLINE 
#define	R3D_PRM_TRIANGLES			R3D_PKT_TRIANGLES 
#define	R3D_PRM_TRISTRIP			R3D_PKT_TRISTRIP
#define	R3D_PRM_POLYGON				R3D_PKT_POLYGON

/*
// These are used by R3dGetState() and R3dSetState()
// Pick ONE of ...
*/

/*
// Enumerated states. 
// >> Possible values mentioned in the comments section.
// Pick ONE of ...
*/
#define	R3D_STA_ENABLES				1	/* use R3D_SE_...	*/
#define	R3D_STA_DISABLES			2	/* use R3D_SE_...	*/
#define	R3D_STA_DRAW_BUFFER			3	/* use R3D_DB_...	*/
#define	R3D_STA_Z_FUNCTION			4	/* use R3D_ZF_...	*/
#define	R3D_STA_SRC_BLEND_FUNCTION	5	/* use R3D_BF_...	*/
#define	R3D_STA_DST_BLEND_FUNCTION	6	/* use R3D_BF_...	*/
#define	R3D_STA_TEX_FILTER			7	/* use R3D_TX_...	*/
#define	R3D_STA_TEX_FUNCTION		8	/* use R3D_TF_...	*/
#define	R3D_STA_ROP_FUNCTION		9	/* use R3D_RF_...	*/

/* 
// Arbitary valued states.
// Pick ONE of ...
*/
#define	R3D_STA_AREA_MASK			16	/* Area pattern bitmask	*/
#define	R3D_STA_LINE_MASK			48	/* Line pattern bitmask	*/
#define	R3D_STA_PIXEL_MASK			49	/* RGBA or bitmask 	*/
#define	R3D_STA_FG_COLOR			50	/* long, RGBA or index	*/
#define	R3D_STA_BG_COLOR			51	/* long, RGBA or index	*/
#define	R3D_STA_FG_DEPTH			52	/* FIXED 16.16 for raster*/
#define	R3D_STA_BG_DEPTH			53	/* FIXED 16.16 for zclear*/
#define	R3D_STA_TEX_LUMINANCE		54	/* >> Will Go away!	*/
#define	R3D_STA_TEX_ID				55	/* Handle for current texture.*/
#define	R3D_STA_SCISSOR_LEFT		56	
#define	R3D_STA_SCISSOR_TOP 		57	
#define	R3D_STA_SCISSOR_RIGHT		58	/* right,bottom, not inclusive*/
#define	R3D_STA_SCISSOR_BOTTOM		59	/* Validity Check done here.	*/

/* 
// These are 3DR message type definitions
// Pick ONE of ...
*/
#define	R3D_MSG_NOP					 0
#define	R3D_MSG_CREATE_RC			 1
#define	R3D_MSG_DELETE_RC			 2
#define	R3D_MSG_GET_STATE			 8
#define	R3D_MSG_NEW_TEXTURE			 9
#define	R3D_MSG_LOAD_TEXTURE		10
#define	R3D_MSG_FREE_TEXTURE		11
#define	R3D_MSG_NEW_BITMAP			12 
#define	R3D_MSG_LOAD_BITMAP			13
#define	R3D_MSG_FREE_BITMAP			14
#define	R3D_MSG_PACKET				16
#define	R3D_MSG_BITMAP				17
#define	R3D_MSG_CACHED_BITMAP		18

#define	R3D_MSG_SET_EXACT_PALETTE_ENTRY		32
#define	R3D_MSG_SET_APPROX_PALETTE_ENTRY	33
#define	R3D_MSG_APPLY_NEW_PALETTE		34

/*
// Possible values for:	R3D_STA_ENABLES 
//			R3D_STA_DISABLES 
// Logical OR of ...
*/
#define	R3D_SE_SHADING				0x00000001L	/* interpolate r,g,b, a	      */
#define	R3D_SE_TEXTURING			0x00000002L	/* interpolate u,v,w	      */
#define	R3D_SE_MODULATION			0x00000004L	/* modulate color & texture   */
#define	R3D_SE_Z_BUFFERING			0x00000008L	/* interpolate z and compare  */
#define	R3D_SE_ANTIALIASING			0x00000010L	/* generate subpixel alpha    */

#define	R3D_SE_PIXEL_MASKING		0x00000020L	/* selective pixel update     */
#define	R3D_SE_Z_MASKING			0x00000040L	/* selective z update 	      */
#define	R3D_SE_PATTERNING			0x00000080L	/* selective pixel & z update */
#define	R3D_SE_SCISSORING			0x00000100L	/* selective pixel & z update */
#define	R3D_SE_CLIPPING				0x00000200L	/* selective pixel & z update */

#define	R3D_SE_BLENDING				0x00000400L	/* per-pixel operation	      */
#define	R3D_SE_RASTEROP				0x00000800L	/* per-pixel operation	      */
#define	R3D_SE_DITHERING			0x00001000L	/* per-pixel operation	      */

#define	R3D_SE_FILTERING			0x00002000L	/* texture filter control     */
#define	R3D_SE_TRANSPARENCY			0x00004000L	/* texel use control	      */

/*
// Possible values for:	R3D_STA_DRAW_BUFFER 
// Pick one of ...
*/
#define	R3D_DB_FRONT				 0
#define	R3D_DB_BACK					 1

#ifdef	R3D_FUTURES
#define	R3D_DB_FRONT_RIGHT			 2
#define	R3D_DB_BACK_RIGHT			 3
#endif	/* R3D_FUTURES */

/*
// Possible values for:	R3D_STA_Z_FUNCTION
// Pick one of ...
*/
#define	R3D_ZF_NEVER				 0
#define	R3D_ZF_LT					 1
#define	R3D_ZF_EQ					 2
#define	R3D_ZF_LE					 3
#define	R3D_ZF_GT					 4
#define	R3D_ZF_NE					 5
#define	R3D_ZF_GE					 6
#define	R3D_ZF_ALWAYS				 7

/*
// Possible values for:	R3D_STA_SRC_BLEND_FUNCTION
//			R3D_STA_DST_BLEND_FUNCTION
// Pick one of ...
*/
#define	R3D_BF_ZERO					 0
#define	R3D_BF_ONE					 1
#define	R3D_BF_SRC					 2	/* Only R3D_STA_DST_BLEND_FUNCTION */
#define	R3D_BF_SRC_INV				 3	/* Only R3D_STA_DST_BLEND_FUNCTION */
#define	R3D_BF_SRC_ALPHA			 4
#define	R3D_BF_SRC_ALPHA_INV		 5
#define	R3D_BF_DST					 6	/* Only R3D_STA_SRC_BLEND_FUNCTION */
#define	R3D_BF_DST_INV				 7	/* Only R3D_STA_SRC_BLEND_FUNCTION */
#define	R3D_BF_DST_ALPHA			 8
#define	R3D_BF_DST_ALPHA_INV		 9

/*
// Possible values for:	R3D_STA_ROP_FUNCTION
// Pick one of ...
*/
#define R3D_RF_CLEAR				 0
#define R3D_RF_AND					 1
#define R3D_RF_AND_REVERSE			 2
#define R3D_RF_COPY					 3
#define R3D_RF_AND_INVERT			 4
#define R3D_RF_NOOP					 5
#define R3D_RF_XOR					 6
#define R3D_RF_OR					 7
#define R3D_RF_NOR					 8
#define R3D_RF_EQUIV				 9
#define R3D_RF_INVERT				10
#define R3D_RF_OR_REVERSE			11
#define R3D_RF_COPY_INVERT			12
#define R3D_RF_OR_INVERT			13
#define R3D_RF_NAND					14
#define R3D_RF_SET					15

/* 
// Possible values for:	R3D_STA_TEX_FUNCTION
// Pick ONE of ...
*/
#define	R3D_TF_REDUCE				 1
#define	R3D_TF_MULTIPLY				 2
#define	R3D_TF_SHADE				 3

/*
// Possible values for:	R3D_STA_TEX_FILTER
// Pick ONE of ...
*/
#define	R3D_TX_BILINEAR				 1	/* interpolate 4 pixels		*/
#define	R3D_TX_CUSTOM				 9	/* your favorite filter		*/
#define	R3D_TX_MIPMAP_NEAREST		10	/* nearest mipmap		*/
#define	R3D_TX_MIPMAP_LINEAR		11	/* interpolate between mipmaps	*/
#define	R3D_TX_MIPMAP_BILINEAR		12	/* interpolate 4x within mipmap */
#define	R3D_TX_MIPMAP_TRILINEAR		13	/* interpolate mipmaps,4 pixels	*/


/* 
// Possible values for:	RCInfo in the R3dCreateRC() prototype below
// Logical OR of ...
*/
#define	R3D_RI_DEFAULT				0x0000
#define	R3D_RI_DOUBLE_BUFFER		0x0001
#define	R3D_RI_COLOR_INDEXED		0x0002
#define	R3D_RI_EXTENDED				0x0004

#define	R3D_RI_RESERVED0			0x0008
#define	R3D_RI_RESERVED1			0x0010
#define	R3D_RI_RESERVED2			0x0020
#define	R3D_RI_RESERVED3			0x0040
#define	R3D_RI_RESERVED4			0x0080
#define	R3D_RI_RESERVED5			0x0100
#define	R3D_RI_RESERVED6			0x0200
#define	R3D_RI_RESERVED7			0x0400
#define	R3D_RI_RESERVED8			0x0800

#ifdef	R3D_FUTURES
#define	R3D_RI_STEREO				R3D_RI_RESERVED0
#define	R3D_RI_ZBUFFER	 			R3D_RI_RESERVED8
#endif	/* R3D_FUTURES */

/*
// Possible values for : VtxInfo in the R3dPrimitive() prototype below
// Logical OR of ...
*/
#define R3D_VI_FIXED				0x0000
#define	R3D_VI_FLOAT				0x0001
#define	R3D_VI_COLOR				0x0002
#define	R3D_VI_TEXTURE				0x0004	
	
/*
// Possible values for:	BmpInfo in the R3dBitmap() prototype below
// Logical OR of ...
*/
#define	R3D_BI_INDEX				0x0001
#define	R3D_BI_CHROMAKEY			0x0002
#define	R3D_BI_ALPHA				0x0004

/*
// Possible values for:	SwapInfo in the R3dSwapBuffers() prototype below
// Logical OR of ...
*/
#ifdef	R3D_FUTURES
#define	R3D_SI_LEFT					0x0000
#define	R3D_SI_RIGHT				0x0001
#endif	/* R3D_FUTURES */

#define	R3D_SI_SCISSOR				0x0004

/*
// Possible values for:	ClearInfo in the R3dClearBuffers() prototype below
// Logical OR of ...
*/
#define	R3D_CI_DRAW_BUFFER			0x0001

#ifdef	R3D_FUTURES 
#define	R3D_CI_DRAW_BUFFER_LEFT		0x0001
#define	R3D_CI_DRAW_BUFFER_RIGHT	0x0002
#endif	/* R3D_FUTURES */

#define	R3D_CI_ZBUFFER				0x0004	

/*
// Possible values for:	TexInfo in the R3dNewTexture() prototype below.
// Logical OR of ...
*/
#define R3D_TI_DEFAULT				0x0000
#define	R3D_TI_MIPMAP				0x0001
#define	R3D_TI_HIRES				0x0002
#define	R3D_TI_KEEP					0x0004
#define	R3D_TI_INDEX				0x0010
#define	R3D_TI_CHROMAKEY			0x0020
#define	R3D_TI_ALPHA				0x0040

/*
// Possible values for:	R3dMsgHdr.MsgHdrVersion field
// Pick ONE of ...
*/
#define	R3D_MSG_VERSION				1

/*
// Maximum No of vertices to be passed using R3dPrimitive()
*/
#define	R3D_MAX_VERTICES			256

/*
//	3DR Function Prototypes :
*/

Dword_t	WINAPI
R3dBegin		(	);

Void_t	WINAPI
R3dEnd			(	);

Dword_t	WINAPI	
R3dCreateRC		(	R3dHandle_t	hDC, 
					Word_t	   	RCInfo		);

Dword_t WINAPI	
R3dDeleteRC		(	R3dHandle_t	hRC		);

Void_t WINAPI 
R3dPrimitive	(	R3dHandle_t	hRC, 
					Word_t		PrmType, 
					Word_t		VtxInfo, 
					Word_t		VtxCount, 
					Word_t		VtxSize,
					LPByte_t	VtxPtr		);

Dword_t	WINAPI 
R3dGetState		(	R3dHandle_t	hRC,
					Word_t		State		);

Void_t	WINAPI 
R3dSetState		(	R3dHandle_t	hRC,
					Word_t		State, 
					Dword_t		Data		);

Dword_t	WINAPI 
R3dNewTexture	(	R3dHandle_t	hRC, 
					Word_t		TexInfo,
					Word_t		TexBitsPixel,
					Word_t		TexWidth, 
					Word_t		TexHeight	);

Dword_t	WINAPI 
R3dLoadTexture	(	R3dHandle_t	hRC, 
					Word_t		TexInfo,
					Word_t		TexBitsPixel, 
					Word_t		TexMipLevel, 
					Word_t		TexWidth, 
					Word_t		TexRows, 
					Short_t		TexWidthBytes, 
					Dword_t		TexId, 
					Dword_t		TexData,
					LPByte_t	TexBuffer	);

Void_t 	WINAPI 
R3dFreeTexture	( 	R3dHandle_t	hRC, 
					R3dHandle_t	TexId		);

#ifdef	R3D_FUTURES
Dword_t	WINAPI 
R3dNewBitmap	(	R3dHandle_t	hRC, 
					Word_t		BmpInfo,
					Word_t		BmpBitsPixel,
					Word_t		BmpWidth, 
					Word_t		BmpHeight	);

Void_t	WINAPI 
R3dFreeBitmap	(	R3dHandle_t	hRC, 
					Dword_t		BmpId		);

Dword_t	WINAPI 
R3dLoadBitmap	(	R3dHandle_t	hRC, 
					Word_t		BmpInfo,
					Word_t		BmpBitsPixel,
					Word_t		BmpWidth, 
					Word_t		BmpHeight, 
					Short_t		BmpWidthBytes, 
					Dword_t		BmpData,
					LPByte_t	BmpBuffer	);

Void_t	WINAPI 
R3dCachedBitmap	(	R3dHandle_t	hRC, 
					Word_t		BmpInfo,
					Short_t		BmpSrcX, 
					Short_t		BmpSrcY,
					Short_t		BmpDstX, 
					Short_t		BmpDstY,
					Word_t		BmpWidth, 
					Word_t		BmpHeight,
					Dword_t		BmpData,
					Dword_t		BmpId		);
#endif	/* R3D_FUTURES */

Dword_t WINAPI
R3dSetPaletteEntry( Dword_t		hRC,
					Dword_t		PalEntry,
					Long_t		Exactness);
					
Void_t WINAPI
R3dApplyNewPalette(	Dword_t		hRC);

Void_t	WINAPI 
R3dBitmap		(	R3dHandle_t	hRC, 
					Word_t		BmpInfo,
					Word_t		BmpBitsPixel,
					Word_t		BmpWidth, 
					Word_t		BmpHeight, 
					Short_t		BmpWidthBytes, 
					Short_t		BmpSrcX, 
					Short_t		BmpSrcY,
					Short_t		BmpDstX, 
					Short_t		BmpDstY,
					Dword_t		BmpData,
					LPByte_t	BmpBuffer	);

Void_t	WINAPI
R3dSwapBuffers	(	R3dHandle_t	hRC, 
					Word_t		SwapInfo	);

Void_t	WINAPI	
R3dClearBuffers	(	R3dHandle_t	hRC, 
					Word_t		ClearInfo	);

Dword_t WINAPI 
R3dMessage		(	R3dHandle_t	hRC, 
					Dword_t		InDataSize, 
					LPByte_t	InDataPtr, 
					Dword_t		OutDataSize, 
					LPByte_t	OutDataPtr	);

#endif	/* R3D_TYPES_ONLY */

#ifdef	USE_3DR_PACKETS

#define R3D_BUF_SIZE		0x8000
#define R3D_BUF_PAD			0x0100
#define R3D_MAX_PKT_SIZE	(R3D_BUF_SIZE - R3D_BUF_PAD)

#define	R3dPacketsInit()													\
		Byte_t		R3dBufData[R3D_BUF_SIZE];								\
		LPByte_t	R3dBufPtr	= R3dBufData + sizeof(R3dMsgHdr_t);			\

#define	R3dPacketsExternInit()												\
extern	Byte_t		R3dBufData[];											\
extern	LPByte_t	R3dBufPtr;												\

/*
//	The following macros are for the support of the macros below.
//	Note R3dMemCopy() is a simple byte-at-a-time copy function.
*/
#define R3dMemCopy(DstPtr, SrcPtr, Size)									\
		while ((Dword_t)(Size)--) {											\
			 *(FPByte_t)(DstPtr)++ = *(FPByte_t)(SrcPtr)++;					\
		}

#define IsNotEnoughRoomInCurrentPacket(size)								\
	(((LPByte_t)(R3dBufPtr) + ((Dword_t)(size))) > 							\
				((LPByte_t)(R3dBufData) + R3D_MAX_PKT_SIZE)) 

#define R3dSendCurrentPacket(hRC)											\
{																			\
	const LPR3dMsgHdr_t hPtr = (LPR3dMsgHdr_t)  (LPByte_t)(R3dBufData);		\
	const LPR3dPktGen_t ePtr = (LPR3dPktGen_t)  (LPByte_t)(R3dBufPtr);		\
		  Dword_t	currentPktSize;											\
																			\
	currentPktSize = (Dword_t)((LPByte_t)(R3dBufPtr) - 						\
								(LPByte_t)(R3dBufData)) +					\
								sizeof(R3dPktGen_t);						\
																			\
	hPtr->MsgHdrType	= R3D_MSG_PACKET;									\
	hPtr->MsgHdrVersion	= R3D_MSG_VERSION;									\
	hPtr->MsgHdrSize	= currentPktSize;									\
	hPtr->MsgHdrRC 		= (R3dHandle_t)(hRC);								\
																			\
	ePtr->PktGenPktType	= R3D_PKT_END;										\
	ePtr->PktGenInfo	= 0;												\
																			\
	R3dMessage(	(Dword_t)	(hRC),											\
				(Dword_t)	currentPktSize,									\
				(LPByte_t)	(R3dBufData),									\
				(Dword_t)	8,												\
				(LPByte_t)	(R3dBufData));									\
																			\
	(LPByte_t)(R3dBufPtr) = (LPByte_t)(R3dBufData) + sizeof(R3dMsgHdr_t);	\
}


/*
// The following macros are intended to be used in exactly the same way that
// the API functions of the same name are used. One can consider the API 
// functions to be functions that create tiny messages just big enough to 
// contain the primitive in use. These following macros will fill the 
// message buffer until it reaches a high water mark, or, until the 
// R3dSwapBuffers() macro is used.
*/
#define R3dSetState(hRC, State, Value)										\
{																			\
	LPR3dPktSta_t StaPtr = (LPR3dPktSta_t ) (R3dBufPtr);					\
																			\
	if (IsNotEnoughRoomInCurrentPacket(sizeof(R3dPktSta_t))) {				\
		R3dSendCurrentPacket(hRC);											\
		StaPtr	= (LPR3dPktSta_t ) (R3dBufPtr);								\
	}																		\
																			\
	StaPtr->PktStaPktType	= R3D_PKT_SETSTATE;								\
	StaPtr->PktStaState		= (Word_t)(State);								\
	StaPtr->PktStaData		= (Dword_t)(Value);								\
																			\
	(LPByte_t)(R3dBufPtr)	+= sizeof(R3dPktSta_t);							\
																			\
}

#define R3dPrimitive(hRC, Prim, VtxInfo, Count, VtxSize, VtxDataPtr)		\
{																			\
	LPR3dPktPrm_t PrmPtr		= (LPR3dPktPrm_t ) (R3dBufPtr);				\
	const Dword_t curVtxSize	= (((Word_t)(Count))*((Word_t)(VtxSize)));	\
	const Dword_t curPktSize	= ((sizeof(R3dPktPrm_t) - 4) +	curVtxSize);	\
																			\
	if (IsNotEnoughRoomInCurrentPacket(curPktSize)) {						\
		R3dSendCurrentPacket(hRC);											\
		PrmPtr	= (LPR3dPktPrm_t ) (R3dBufPtr);								\
	}																		\
																			\
	PrmPtr->PktPrmPktType	= (Word_t) (Prim);								\
	PrmPtr->PktPrmVtxInfo	= (Word_t) (VtxInfo);							\
	PrmPtr->PktPrmVtxNum	= (Word_t) (Count);								\
	PrmPtr->PktPrmVtxSize	= (Word_t) (VtxSize);							\
																			\
	R3dMemCopy(	(LPByte_t)	PrmPtr->PktPrmBuffer, 							\
				(LPByte_t)	(VtxDataPtr), 									\
				(Dword_t)	curVtxSize);									\
																			\
	(LPByte_t)(R3dBufPtr)	+= curPktSize;									\
}

#define R3dClearBuffers(hRC, ClearInfo)										\
{																			\
	LPR3dPktGen_t GenPktPtr		= (LPR3dPktGen_t) (R3dBufPtr);				\
																			\
	if (IsNotEnoughRoomInCurrentPacket(sizeof(R3dPktGen_t))) {				\
		R3dSendCurrentPacket(hRC);											\
		GenPktPtr = (LPR3dPktGen_t) (R3dBufPtr);							\
	}																		\
																			\
	GenPktPtr->PktGenPktType	= R3D_PKT_CLEARBUFFERS;						\
	GenPktPtr->PktGenInfo		= (Word_t)ClearInfo;						\
																			\
	(LPByte_t)(R3dBufPtr)		+= sizeof(R3dPktGen_t);						\
}

#define R3dSwapBuffers(hRC, SwapInfo)										\
{																			\
	LPR3dPktGen_t GenPktPtr = (LPR3dPktGen_t ) (R3dBufPtr);					\
																			\
	if (IsNotEnoughRoomInCurrentPacket(sizeof(R3dPktGen_t))) {				\
		R3dSendCurrentPacket(hRC);											\
		GenPktPtr = (LPR3dPktGen_t ) (R3dBufPtr);							\
	}																		\
																			\
	GenPktPtr->PktGenPktType	= R3D_PKT_SWAPBUFFERS;						\
	GenPktPtr->PktGenInfo		= (Word_t)SwapInfo;							\
																			\
	(LPByte_t)(R3dBufPtr)		+= sizeof(R3dPktGen_t);						\
																			\
	R3dSendCurrentPacket(hRC);												\
}

/*
// The following macros are intended to be used where it is known that the
// full size of each primitive fits within the remaining space in the buffer.
// In particular the R3dPrimitiveFAST() macro stuffs the header info for the
// primitive, the user MUST then fill the rest of the primitive structure
// out with vertex information etc.
*/
#define R3dSetStateFAST(StaPtr, State, Value)								\
	((LPR3dPktSta_t)(StaPtr))->PktStaPktType	= R3D_PKT_SETSTATE;			\
	((LPR3dPktSta_t)(StaPtr))->PktStaState		= (Word_t) (State);			\
	((LPR3dPktSta_t)(StaPtr))->PktStaData		= (Dword_t)(Value);			\
	(LPByte_t)(StaPtr)	+= sizeof(R3dPktSta_t);

#define R3dPrimitiveFAST(PrmPtr, Prim, VtxInfo, Count, VtxSize)				\
	((LPR3dPktPrm_t)(PrmPtr))->PktPrmPktType	= (Word_t) (Prim);			\
	((LPR3dPktPrm_t)(PrmPtr))->PktPrmVtxInfo	= (Word_t) (VtxInfo); 		\
	((LPR3dPktPrm_t)(PrmPtr))->PktPrmVtxNum		= (Word_t) (Count);   		\
	((LPR3dPktPrm_t)(PrmPtr))->PktPrmVtxSize	= (Word_t) (VtxSize); 		\
	(LPByte_t)(PrmPtr)	+= (sizeof(R3dPktPrm_t) - 4);	

#define R3dClearBuffersFAST(GenPktPtr, ClearInfo)			  				\
	((LPR3dPktGen_t)(GenPktPtr))->PktGenPktType	= R3D_PKT_CLEARBUFFERS; 	\
	((LPR3dPktGen_t)(GenPktPtr))->PktGenInfo	= (Word_t)(ClearInfo); 		\
	(LPByte_t)(GenPktPtr) += sizeof(R3dPktGen_t);

#define R3dSwapBuffersFAST(GenPktPtr, hRC, SwapInfo)		  	   			\
	((LPR3dPktGen_t)(GenPktPtr))->PktGenPktType = R3D_PKT_SWAPBUFFERS; 		\
	((LPR3dPktGen_t)(GenPktPtr))->PktGenInfo	= (Word_t)(SwapInfo);		\
	(LPByte_t)(GenPktPtr)	+= sizeof(R3dPktGen_t);							\
	R3dSendCurrentPacket(hRC);

#endif	/* USE_3DR_PACKETS */

#define	R3D_SE_SWAP_WITH_ZOOM		0x00080000L
#define R3D_SE_COLOR_INDEXED_MODE	0x00200000L

#define	R3D_STA_ZOOM_X				60
#define	R3D_STA_ZOOM_Y				61

#ifdef	__cplusplus
};
#endif	/* __ cplusplus */

#endif /* _3DR_H_ */

