/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2012 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#pragma once

#include "SDLMOD_video.h"

#ifdef __cplusplus
extern "C" {
#endif

//modified from sdlpixel.hpp
extern void SDLMOD_ext_getPixel(SDLMOD_Surface* surface, int x, int y, 
	uint8_t* colorR, uint8_t* colorG, uint8_t* colorB, uint8_t* colorA);
extern void SDLMOD_ext_putPixel(SDLMOD_Surface* surface, int x, int y, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB);

//modified from sdlpixel.hpp
extern uint32_t SDLMOD_ext_Alpha32(uint32_t src, uint32_t dst, uint8_t a);
extern uint16_t SDLMOD_ext_Alpha16(uint16_t src, uint16_t dst, uint8_t a, 
	SDLMOD_PixelFormat *f);
extern void SDLMOD_ext_putPixelAlpha(SDLMOD_Surface* surface, int x, int y, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA);

//modified from sdlgraphics.hpp
extern void SDLMOD_ext_drawPoint(SDLMOD_Surface* mTarget, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int x, int y);
extern void SDLMOD_ext_fillRectangle(SDLMOD_Surface* mTarget, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int areaX, int areaY, int areaWidth, int areaHeight);
extern void SDLMOD_ext_drawHLine(SDLMOD_Surface* mTarget,
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int x1, int y, int x2);
extern void SDLMOD_ext_drawVLine(SDLMOD_Surface* mTarget, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int x, int y1, int y2);

//modified from sdlgraphics.hpp
extern void SDLMOD_ext_drawLine(SDLMOD_Surface* mTarget, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int x1, int y1, int x2, int y2);
extern void SDLMOD_ext_drawRectangle(SDLMOD_Surface* mTarget, 
	uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA, 
	int areaX, int areaY, int areaWidth, int areaHeight);
extern void SDLMOD_ext_drawImage(SDLMOD_Surface* mTarget, 
	SDLMOD_Surface* srcSurface, 
	int srcX, int srcY, int dstX, int dstY,
    int width, int height);

#ifdef __cplusplus
}
#endif
