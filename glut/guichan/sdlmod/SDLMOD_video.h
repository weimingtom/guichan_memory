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

#include "SDLMOD_endian.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SDLMOD_ALPHA_OPAQUE 255
#define SDLMOD_ALPHA_TRANSPARENT 0

typedef struct SDLMOD_Rect {
	int16_t x, y;
	uint16_t w, h;
} SDLMOD_Rect;

typedef struct SDLMOD_Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t unused;
} SDLMOD_Color;
#define SDLMOD_Colour SDLMOD_Color

typedef struct SDLMOD_Palette {
	int       ncolors;
	SDLMOD_Color *colors;
} SDLMOD_Palette;

typedef struct SDLMOD_PixelFormat {
	SDLMOD_Palette *palette;
	uint8_t  BitsPerPixel;
	uint8_t  BytesPerPixel;
	uint8_t  Rloss;
	uint8_t  Gloss;
	uint8_t  Bloss;
	uint8_t  Aloss;
	uint8_t  Rshift;
	uint8_t  Gshift;
	uint8_t  Bshift;
	uint8_t  Ashift;
	uint32_t Rmask;
	uint32_t Gmask;
	uint32_t Bmask;
	uint32_t Amask;
	uint32_t colorkey;
	uint8_t  alpha;
} SDLMOD_PixelFormat;

typedef struct SDLMOD_Surface {
	uint32_t flags;
	SDLMOD_PixelFormat *format;
	int w, h;
	uint16_t pitch;
	void *pixels;
	int offset;
	struct private_hwdata *hwdata;
	SDLMOD_Rect clip_rect;
	uint32_t unused1;
	uint32_t locked;
	struct SDLMOD_BlitMap *map;
	unsigned int format_version;
	int refcount;
} SDLMOD_Surface;

#define SDLMOD_SWSURFACE	0x00000000
#define SDLMOD_HWSURFACE	0x00000001
#define SDLMOD_ASYNCBLIT	0x00000004

#define SDLMOD_ANYFORMAT	0x10000000
#define SDLMOD_HWPALETTE	0x20000000
#define SDLMOD_DOUBLEBUF	0x40000000
#define SDLMOD_FULLSCREEN	0x80000000
#define SDLMOD_OPENGL       0x00000002
#define SDLMOD_OPENGLBLIT	0x0000000A
#define SDLMOD_RESIZABLE	0x00000010
#define SDLMOD_NOFRAME	    0x00000020

#define SDLMOD_HWACCEL	    0x00000100
#define SDLMOD_SRCCOLORKEY	0x00001000
#define SDLMOD_RLEACCELOK	0x00002000
#define SDLMOD_RLEACCEL	    0x00004000
#define SDLMOD_SRCALPHA	    0x00010000
#define SDLMOD_PREALLOC	    0x01000000

#define SDLMOD_MUSTLOCK(surface)	\
  (surface->offset ||		\
  ((surface->flags & (SDLMOD_HWSURFACE|SDLMOD_ASYNCBLIT|SDLMOD_RLEACCEL)) != 0))

typedef int (*SDLMOD_blit)(struct SDLMOD_Surface *src, SDLMOD_Rect *srcrect,
			struct SDLMOD_Surface *dst, SDLMOD_Rect *dstrect);

#define SDLMOD_YV12_OVERLAY  0x32315659
#define SDLMOD_IYUV_OVERLAY  0x56555949
#define SDLMOD_YUY2_OVERLAY  0x32595559
#define SDLMOD_UYVY_OVERLAY  0x59565955
#define SDLMOD_YVYU_OVERLAY  0x55595659

typedef struct SDLMOD_Overlay {
	uint32_t format;
	int w, h;
	int planes;
	uint16_t *pitches;
	uint8_t **pixels;
	struct private_yuvhwfuncs *hwfuncs;
	struct private_yuvhwdata *hwdata;
	uint32_t hw_overlay :1;
	uint32_t UnusedBits :31;
} SDLMOD_Overlay;

extern uint8_t SDLMOD_FindColor(SDLMOD_Palette *pal, 
				uint8_t r, uint8_t g, uint8_t b);
extern uint32_t SDLMOD_MapRGB(const SDLMOD_PixelFormat* const format, 
				const uint8_t r, const uint8_t g, const uint8_t b);
extern uint32_t SDLMOD_MapRGBA(const SDLMOD_PixelFormat* const format, 
				const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);
extern void SDLMOD_GetRGBA(uint32_t pixel, const SDLMOD_PixelFormat * const fmt,
				uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);
extern void SDLMOD_GetRGB(uint32_t pixel, const SDLMOD_PixelFormat * const fmt,
                uint8_t *r,uint8_t *g,uint8_t *b);

#define SDLMOD_AllocSurface    SDLMOD_CreateRGBSurface
extern SDLMOD_Surface * SDLMOD_CreateRGBSurface
			(uint32_t flags, int width, int height, int depth, 
			uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
extern SDLMOD_Surface * SDLMOD_CreateRGBSurfaceFrom(void *pixels,
			int width, int height, int depth, int pitch,
			uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
extern void SDLMOD_FreeSurface(SDLMOD_Surface *surface);
extern int SDLMOD_LockSurface(SDLMOD_Surface *surface);
extern void SDLMOD_UnlockSurface(SDLMOD_Surface *surface);

extern int SDLMOD_SetClipRect(SDLMOD_Surface *surface, const SDLMOD_Rect *rect);

extern SDLMOD_Overlay * SDLMOD_CreateYUVOverlay(int width, int height,
				uint32_t format, SDLMOD_Surface *display);
extern int SDLMOD_LockYUVOverlay(SDLMOD_Overlay *overlay);
extern void SDLMOD_UnlockYUVOverlay(SDLMOD_Overlay *overlay);
extern int SDLMOD_DisplayYUVOverlay(SDLMOD_Overlay *overlay, SDLMOD_Rect *dstrect);
extern void SDLMOD_FreeYUVOverlay(SDLMOD_Overlay *overlay);

extern int SDLMOD_SoftStretch(SDLMOD_Surface *src, SDLMOD_Rect *srcrect,
			SDLMOD_Surface *dst, SDLMOD_Rect *dstrect);


extern int SDLMOD_FillRect(SDLMOD_Surface *dst, 
			SDLMOD_Rect *dstrect, uint32_t color);


extern int SDLMOD_SetColorKey(SDLMOD_Surface *surface, 
			uint32_t flag, uint32_t key);




/*=====================*/



typedef struct {
	uint8_t *s_pixels;
	int s_width;
	int s_height;
	int s_skip;
	uint8_t *d_pixels;
	int d_width;
	int d_height;
	int d_skip;
	void *aux_data;
	SDLMOD_PixelFormat *src;
	uint8_t *table;
	SDLMOD_PixelFormat *dst;
} SDLMOD_BlitInfo;

typedef void (*SDLMOD_loblit)(SDLMOD_BlitInfo *info);

struct private_swaccel {
	SDLMOD_loblit blit;
	void *aux_data;
};

typedef struct SDLMOD_BlitMap {
	SDLMOD_Surface *dst;
	int identity;
	uint8_t *table;
	SDLMOD_blit hw_blit;
	SDLMOD_blit sw_blit;
	struct private_hwaccel *hw_data;
	struct private_swaccel *sw_data;
    unsigned int format_version;
} SDLMOD_BlitMap;

extern SDLMOD_loblit SDLMOD_CalculateBlit0(SDLMOD_Surface *surface, int complex);
extern SDLMOD_loblit SDLMOD_CalculateBlit1(SDLMOD_Surface *surface, int complex);
extern SDLMOD_loblit SDLMOD_CalculateBlitN(SDLMOD_Surface *surface, int complex);
extern SDLMOD_loblit SDLMOD_CalculateAlphaBlit(SDLMOD_Surface *surface, int complex);



#define SDLMOD_BlitSurface SDLMOD_UpperBlit

extern int SDLMOD_UpperBlit(SDLMOD_Surface *src, SDLMOD_Rect *srcrect,
	SDLMOD_Surface *dst, SDLMOD_Rect *dstrect);






/*======================*/



/* This is a very useful loop for optimizing blitters */
#if defined(_MSC_VER) && (_MSC_VER == 1300)
/* There's a bug in the Visual C++ 7 optimizer when compiling this code */
#else
#define USE_DUFFS_LOOP
#endif
#ifdef USE_DUFFS_LOOP

/* 8-times unrolled loop */
#define DUFFS_LOOP8(pixel_copy_increment, width)			\
{ int n = (width+7)/8;							\
	switch (width & 7) {						\
	case 0: do {	pixel_copy_increment;				\
	case 7:		pixel_copy_increment;				\
	case 6:		pixel_copy_increment;				\
	case 5:		pixel_copy_increment;				\
	case 4:		pixel_copy_increment;				\
	case 3:		pixel_copy_increment;				\
	case 2:		pixel_copy_increment;				\
	case 1:		pixel_copy_increment;				\
		} while ( --n > 0 );					\
	}								\
}

/* 4-times unrolled loop */
#define DUFFS_LOOP4(pixel_copy_increment, width)			\
{ int n = (width+3)/4;							\
	switch (width & 3) {						\
	case 0: do {	pixel_copy_increment;				\
	case 3:		pixel_copy_increment;				\
	case 2:		pixel_copy_increment;				\
	case 1:		pixel_copy_increment;				\
		} while ( --n > 0 );					\
	}								\
}

/* 2 - times unrolled loop */
#define DUFFS_LOOP_DOUBLE2(pixel_copy_increment,			\
				double_pixel_copy_increment, width)	\
{ int n, w = width;							\
	if( w & 1 ) {							\
	    pixel_copy_increment;					\
	    w--;							\
	}								\
	if ( w > 0 )	{						\
	    n = ( w + 2) / 4;						\
	    switch( w & 2 ) {						\
	    case 0: do {	double_pixel_copy_increment;		\
	    case 2:		double_pixel_copy_increment;		\
		    } while ( --n > 0 );					\
	    }								\
	}								\
}

/* 2 - times unrolled loop 4 pixels */
#define DUFFS_LOOP_QUATRO2(pixel_copy_increment,			\
				double_pixel_copy_increment,		\
				quatro_pixel_copy_increment, width)	\
{ int n, w = width;								\
        if(w & 1) {							\
	  pixel_copy_increment;						\
	  w--;								\
	}								\
	if(w & 2) {							\
	  double_pixel_copy_increment;					\
	  w -= 2;							\
	}								\
	if ( w > 0 ) {							\
	    n = ( w + 7 ) / 8;						\
	    switch( w & 4 ) {						\
	    case 0: do {	quatro_pixel_copy_increment;		\
	    case 4:		quatro_pixel_copy_increment;		\
		    } while ( --n > 0 );					\
	    }								\
	}								\
}

/* Use the 8-times version of the loop by default */
#define DUFFS_LOOP(pixel_copy_increment, width)				\
	DUFFS_LOOP8(pixel_copy_increment, width)

#else

/* Don't use Duff's device to unroll loops */
#define DUFFS_LOOP_DOUBLE2(pixel_copy_increment,			\
			 double_pixel_copy_increment, width)		\
{ int n = width;								\
    if( n & 1 ) {							\
	pixel_copy_increment;						\
	n--;								\
    }									\
    n=n>>1;								\
    for(; n > 0; --n) {   						\
	double_pixel_copy_increment;					\
    }									\
}

/* Don't use Duff's device to unroll loops */
#define DUFFS_LOOP_QUATRO2(pixel_copy_increment,			\
				double_pixel_copy_increment,		\
				quatro_pixel_copy_increment, width)	\
{ int n = width;								\
        if(n & 1) {							\
	  pixel_copy_increment;						\
	  n--;								\
	}								\
	if(n & 2) {							\
	  double_pixel_copy_increment;					\
	  n -= 2;							\
	}								\
	n=n>>2;								\
	for(; n > 0; --n) {   						\
	  quatro_pixel_copy_increment;					\
        }								\
}

/* Don't use Duff's device to unroll loops */
#define DUFFS_LOOP(pixel_copy_increment, width)				\
{ int n;								\
	for ( n=width; n > 0; --n ) {					\
		pixel_copy_increment;					\
	}								\
}
#define DUFFS_LOOP8(pixel_copy_increment, width)			\
	DUFFS_LOOP(pixel_copy_increment, width)
#define DUFFS_LOOP4(pixel_copy_increment, width)			\
	DUFFS_LOOP(pixel_copy_increment, width)

#endif /* USE_DUFFS_LOOP */

/*======================*/




#if defined(_MSC_VER)
#if _MSC_VER >= 1700
#ifndef _XKEYCHECK_H
#define _XKEYCHECK_H
#endif
#endif
#define inline _inline
#endif

#define SDL_static_cast(type, expression) ((type)(expression))

#define SDLMOD_memset4(dst, val, len)		\
do {						\
	unsigned _count = (len);		\
	unsigned _n = (_count + 3) / 4;		\
	uint32_t *_p = SDL_static_cast(uint32_t *, dst);	\
	uint32_t _val = (val);			\
	if (len == 0) break;			\
        switch (_count % 4) {			\
        case 0: do {    *_p++ = _val;		\
        case 3:         *_p++ = _val;		\
        case 2:         *_p++ = _val;		\
        case 1:         *_p++ = _val;		\
		} while ( --_n );		\
	}					\
} while(0)

#define FORMAT_EQUAL(A, B)						\
    ((A)->BitsPerPixel == (B)->BitsPerPixel				\
     && ((A)->Rmask == (B)->Rmask) && ((A)->Amask == (B)->Amask))


#ifdef __NDS__ /* FIXME */
#define PIXEL_FROM_RGBA(Pixel, fmt, r, g, b, a)				\
{									\
	Pixel = ((r>>fmt->Rloss)<<fmt->Rshift)|				\
		((g>>fmt->Gloss)<<fmt->Gshift)|				\
		((b>>fmt->Bloss)<<fmt->Bshift)|				\
		((a>>fmt->Aloss)<<fmt->Ashift) | (1<<15);				\
}
#else
#define PIXEL_FROM_RGBA(Pixel, fmt, r, g, b, a)				\
{									\
	Pixel = ((r>>fmt->Rloss)<<fmt->Rshift)|				\
		((g>>fmt->Gloss)<<fmt->Gshift)|				\
		((b>>fmt->Bloss)<<fmt->Bshift)|				\
		((a>>fmt->Aloss)<<fmt->Ashift);				\
}
#endif /* __NDS__ FIXME */
#define ASSEMBLE_RGBA(buf, bpp, fmt, r, g, b, a)			\
{									\
	switch (bpp) {							\
		case 2: {						\
			uint16_t Pixel;					\
									\
			PIXEL_FROM_RGBA(Pixel, fmt, r, g, b, a);	\
			*((uint16_t *)(buf)) = Pixel;			\
		}							\
		break;							\
									\
		case 3: { /* FIXME: broken code (no alpha) */		\
                        if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		\
			        *((buf)+fmt->Rshift/8) = r;		\
				*((buf)+fmt->Gshift/8) = g;		\
				*((buf)+fmt->Bshift/8) = b;		\
			} else {					\
			        *((buf)+2-fmt->Rshift/8) = r;		\
				*((buf)+2-fmt->Gshift/8) = g;		\
				*((buf)+2-fmt->Bshift/8) = b;		\
			}						\
		}							\
		break;							\
									\
		case 4: {						\
			uint32_t Pixel;					\
									\
			PIXEL_FROM_RGBA(Pixel, fmt, r, g, b, a);	\
			*((uint32_t *)(buf)) = Pixel;			\
		}							\
		break;							\
	}								\
}


#define RETRIEVE_RGB_PIXEL(buf, bpp, Pixel)				   \
do {									   \
	switch (bpp) {							   \
		case 2:							   \
			Pixel = *((uint16_t *)(buf));			   \
		break;							   \
									   \
		case 3: {						   \
		        uint8_t *B = (uint8_t *)(buf);			   \
			if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		   \
			        Pixel = B[0] + (B[1] << 8) + (B[2] << 16); \
			} else {					   \
			        Pixel = (B[0] << 16) + (B[1] << 8) + B[2]; \
			}						   \
		}							   \
		break;							   \
									   \
		case 4:							   \
			Pixel = *((uint32_t *)(buf));			   \
		break;							   \
									   \
		default:						   \
			Pixel = 0; /* appease gcc */			   \
		break;							   \
	}								   \
} while(0)

#define DISEMBLE_RGB(buf, bpp, fmt, Pixel, r, g, b)			   \
do {									   \
	switch (bpp) {							   \
		case 2:							   \
			Pixel = *((uint16_t *)(buf));			   \
		break;							   \
									   \
		case 3: {						   \
		        uint8_t *B = (uint8_t *)buf;			   \
			if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		   \
			        Pixel = B[0] + (B[1] << 8) + (B[2] << 16); \
			} else {					   \
			        Pixel = (B[0] << 16) + (B[1] << 8) + B[2]; \
			}						   \
		}							   \
		break;							   \
									   \
		case 4:							   \
			Pixel = *((uint32_t *)(buf));			   \
		break;							   \
									   \
	        default:						   \
		        Pixel = 0;	/* prevent gcc from complaining */ \
		break;							   \
	}								   \
	RGB_FROM_PIXEL(Pixel, fmt, r, g, b);				   \
} while(0)

/* Blend the RGB values of two Pixels based on a source alpha value */
#define ALPHA_BLEND(sR, sG, sB, A, dR, dG, dB)	\
do {						\
	dR = (((sR-dR)*(A)+255)>>8)+dR;		\
	dG = (((sG-dG)*(A)+255)>>8)+dG;		\
	dB = (((sB-dB)*(A)+255)>>8)+dB;		\
} while(0)







#define RGB_FROM_PIXEL(Pixel, fmt, r, g, b)				\
{									\
	r = (((Pixel&fmt->Rmask)>>fmt->Rshift)<<fmt->Rloss); 		\
	g = (((Pixel&fmt->Gmask)>>fmt->Gshift)<<fmt->Gloss); 		\
	b = (((Pixel&fmt->Bmask)>>fmt->Bshift)<<fmt->Bloss); 		\
}
#define RGB_FROM_RGB565(Pixel, r, g, b)					\
{									\
	r = (((Pixel&0xF800)>>11)<<3);		 			\
	g = (((Pixel&0x07E0)>>5)<<2); 					\
	b = ((Pixel&0x001F)<<3); 					\
}
#define RGB_FROM_RGB555(Pixel, r, g, b)					\
{									\
	r = (((Pixel&0x7C00)>>10)<<3);		 			\
	g = (((Pixel&0x03E0)>>5)<<3); 					\
	b = ((Pixel&0x001F)<<3); 					\
}
#define RGB_FROM_RGB888(Pixel, r, g, b)					\
{									\
	r = ((Pixel&0xFF0000)>>16);		 			\
	g = ((Pixel&0xFF00)>>8);		 			\
	b = (Pixel&0xFF);			 			\
}
#define ASSEMBLE_RGB(buf, bpp, fmt, r, g, b) 				\
{									\
	switch (bpp) {							\
		case 2: {						\
			uint16_t Pixel;					\
									\
			PIXEL_FROM_RGB(Pixel, fmt, r, g, b);		\
			*((uint16_t *)(buf)) = Pixel;			\
		}							\
		break;							\
									\
		case 3: {						\
                        if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		\
			        *((buf)+fmt->Rshift/8) = r;		\
				*((buf)+fmt->Gshift/8) = g;		\
				*((buf)+fmt->Bshift/8) = b;		\
			} else {					\
			        *((buf)+2-fmt->Rshift/8) = r;		\
				*((buf)+2-fmt->Gshift/8) = g;		\
				*((buf)+2-fmt->Bshift/8) = b;		\
			}						\
		}							\
		break;							\
									\
		case 4: {						\
			uint32_t Pixel;					\
									\
			PIXEL_FROM_RGB(Pixel, fmt, r, g, b);		\
			*((uint32_t *)(buf)) = Pixel;			\
		}							\
		break;							\
	}								\
}


#ifdef __NDS__ /* FIXME */
#define PIXEL_FROM_RGB(Pixel, fmt, r, g, b)				\
{									\
	Pixel = ((r>>fmt->Rloss)<<fmt->Rshift)|				\
		((g>>fmt->Gloss)<<fmt->Gshift)|				\
		((b>>fmt->Bloss)<<fmt->Bshift) | (1<<15);				\
}
#else
#define PIXEL_FROM_RGB(Pixel, fmt, r, g, b)				\
{									\
	Pixel = ((r>>fmt->Rloss)<<fmt->Rshift)|				\
		((g>>fmt->Gloss)<<fmt->Gshift)|				\
		((b>>fmt->Bloss)<<fmt->Bshift);				\
}
#endif /* __NDS__ FIXME */







#define ALPHA_BLEND(sR, sG, sB, A, dR, dG, dB)	\
do {						\
	dR = (((sR-dR)*(A)+255)>>8)+dR;		\
	dG = (((sG-dG)*(A)+255)>>8)+dG;		\
	dB = (((sB-dB)*(A)+255)>>8)+dB;		\
} while(0)


#define DISEMBLE_RGB(buf, bpp, fmt, Pixel, r, g, b)			   \
do {									   \
	switch (bpp) {							   \
		case 2:							   \
			Pixel = *((uint16_t *)(buf));			   \
		break;							   \
									   \
		case 3: {						   \
		        uint8_t *B = (uint8_t *)buf;			   \
			if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		   \
			        Pixel = B[0] + (B[1] << 8) + (B[2] << 16); \
			} else {					   \
			        Pixel = (B[0] << 16) + (B[1] << 8) + B[2]; \
			}						   \
		}							   \
		break;							   \
									   \
		case 4:							   \
			Pixel = *((uint32_t *)(buf));			   \
		break;							   \
									   \
	        default:						   \
		        Pixel = 0;	/* prevent gcc from complaining */ \
		break;							   \
	}								   \
	RGB_FROM_PIXEL(Pixel, fmt, r, g, b);				   \
} while(0)










#define RGBA_FROM_PIXEL(Pixel, fmt, r, g, b, a)				\
{									\
	r = ((Pixel&fmt->Rmask)>>fmt->Rshift)<<fmt->Rloss; 		\
	g = ((Pixel&fmt->Gmask)>>fmt->Gshift)<<fmt->Gloss; 		\
	b = ((Pixel&fmt->Bmask)>>fmt->Bshift)<<fmt->Bloss; 		\
	a = ((Pixel&fmt->Amask)>>fmt->Ashift)<<fmt->Aloss;	 	\
}
#define RGBA_FROM_8888(Pixel, fmt, r, g, b, a)	\
{						\
	r = (Pixel&fmt->Rmask)>>fmt->Rshift;	\
	g = (Pixel&fmt->Gmask)>>fmt->Gshift;	\
	b = (Pixel&fmt->Bmask)>>fmt->Bshift;	\
	a = (Pixel&fmt->Amask)>>fmt->Ashift;	\
}
#define RGBA_FROM_RGBA8888(Pixel, r, g, b, a)				\
{									\
	r = (Pixel>>24);						\
	g = ((Pixel>>16)&0xFF);						\
	b = ((Pixel>>8)&0xFF);						\
	a = (Pixel&0xFF);						\
}
#define RGBA_FROM_ARGB8888(Pixel, r, g, b, a)				\
{									\
	r = ((Pixel>>16)&0xFF);						\
	g = ((Pixel>>8)&0xFF);						\
	b = (Pixel&0xFF);						\
	a = (Pixel>>24);						\
}
#define RGBA_FROM_ABGR8888(Pixel, r, g, b, a)				\
{									\
	r = (Pixel&0xFF);						\
	g = ((Pixel>>8)&0xFF);						\
	b = ((Pixel>>16)&0xFF);						\
	a = (Pixel>>24);						\
}
#define DISEMBLE_RGBA(buf, bpp, fmt, Pixel, r, g, b, a)			   \
do {									   \
	switch (bpp) {							   \
		case 2:							   \
			Pixel = *((uint16_t *)(buf));			   \
		break;							   \
									   \
		case 3:	{/* FIXME: broken code (no alpha) */		   \
		        uint8_t *b = (uint8_t *)buf;			   \
			if(SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN) {		   \
			        Pixel = b[0] + (b[1] << 8) + (b[2] << 16); \
			} else {					   \
			        Pixel = (b[0] << 16) + (b[1] << 8) + b[2]; \
			}					   \
		}	 \
		break;							   \
									   \
		case 4:							   \
			Pixel = *((uint32_t *)(buf));			   \
		break;							   \
									   \
		default:						   \
		        Pixel = 0; /* stop gcc complaints */		   \
		break;							   \
	}								   \
	RGBA_FROM_PIXEL(Pixel, fmt, r, g, b, a);			   \
	Pixel &= ~fmt->Amask;						   \
} while(0)


/*======================*/




#ifdef __cplusplus
}
#endif
