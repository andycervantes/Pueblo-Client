/*
 * $Id: RLWIN.H,v 1.3 1995/11/20 22:13:10 jimd Exp $
 *
 * Copyright (c) RenderMorphics Ltd. 1993, 1994
 * Version 1.1
 *
 * All rights reserved.
 *
 * This file contains private, unpublished information and may not be
 * copied in part or in whole without express permission of
 * RenderMorphics Ltd.
 *
 */

#ifndef __RLWIN_H__
#define __RLWIN_H__

#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Create a device for rendering onto the given window with the width and
 * height specified.
 *
 * The type field specifies which driver should be loaded under a DLL
 * environment. If NULL is passed, then the "best" available driver will
 * be used.
 */
RLDevice RLWinCreateDevice(HWND win, char* type, int width, int height);

#ifdef DDRAW
#include <ddraw.h>

#define RLDDRAW_FLIP	0x01		/* Do we flip buffers to update? */
#define RLDDRAW_BLIT	0x02		/* Do we blit to update? */

RLDevice RLWinDDrawCreateDevice(char* type,
				HWND hwnd,
				LPDIRECTDRAW lpDD,
				LPDIRECTDRAWSURFACE lpDDSFront,
				LPDIRECTDRAWSURFACE lpDDSBack,
				LPDIRECTDRAWPALETTE lpDDPal,
				DWORD dwFlags);
#endif /* DIRECTDRAW */

/*
 * Repaint the window with the last frame which was rendered.
 */
RLError RLWinHandlePaint(RLDevice dev, HDC hdc);

/*
 * Respond to a WM_ACTIVATE message.
 */
RLError RLWinHandleActivate(RLDevice dev, WORD wparam);

/*
 * Respond to a WM_MOVE message.
 */
RLError RLWinHandleMove(RLDevice dev);

#if defined(__cplusplus)
};
#endif

#endif /* rlwin.h */
