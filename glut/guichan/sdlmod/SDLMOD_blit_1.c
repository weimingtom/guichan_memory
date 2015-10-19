#include <memory.h>
#if defined(_DEBUG)
#include <stdio.h>
#endif
#include "SDLMOD_video.h"

static void Blit1to1(SDLMOD_BlitInfo *info)
{
#ifndef USE_DUFFS_LOOP
	int c;
#endif
	int width, height;
	uint8_t *src, *map, *dst;
	int srcskip, dstskip;

	/* Set up some basic variables */
	width = info->d_width;
	height = info->d_height;
	src = info->s_pixels;
	srcskip = info->s_skip;
	dst = info->d_pixels;
	dstskip = info->d_skip;
	map = info->table;

	while ( height-- ) {
#ifdef USE_DUFFS_LOOP
		DUFFS_LOOP(
			{
			  *dst = map[*src];
			}
			dst++;
			src++;
		, width);
#else
		for ( c=width; c; --c ) {
		        *dst = map[*src];
			dst++;
			src++;
		}
#endif
		src += srcskip;
		dst += dstskip;
	}
}
/* This is now endian dependent */
#if ( SDLMOD_BYTEORDER == SDLMOD_LIL_ENDIAN )
#define HI	1
#define LO	0
#else /* ( SDLMOD_BYTEORDER == SDLMOD_BIG_ENDIAN ) */
#define HI	0
#define LO	1
#endif
static void Blit1to2(SDLMOD_BlitInfo *info)
{
#ifndef USE_DUFFS_LOOP
	int c;
#endif
	int width, height;
	uint8_t *src, *dst;
	uint16_t *map;
	int srcskip, dstskip;

	/* Set up some basic variables */
	width = info->d_width;
	height = info->d_height;
	src = info->s_pixels;
	srcskip = info->s_skip;
	dst = info->d_pixels;
	dstskip = info->d_skip;
	map = (uint16_t *)info->table;

#ifdef USE_DUFFS_LOOP
	while ( height-- ) {
		DUFFS_LOOP(
		{
			*(uint16_t *)dst = map[*src++];
			dst += 2;
		},
		width);
		src += srcskip;
		dst += dstskip;
	}
#else
	/* Memory align at 4-byte boundary, if necessary */
	if ( (long)dst & 0x03 ) {
		/* Don't do anything if width is 0 */
		if ( width == 0 ) {
			return;
		}
		--width;

		while ( height-- ) {
			/* Perform copy alignment */
			*(uint16_t *)dst = map[*src++];
			dst += 2;

			/* Copy in 4 pixel chunks */
			for ( c=width/4; c; --c ) {
				*(uint32_t *)dst =
					(map[src[HI]]<<16)|(map[src[LO]]);
				src += 2;
				dst += 4;
				*(uint32_t *)dst =
					(map[src[HI]]<<16)|(map[src[LO]]);
				src += 2;
				dst += 4;
			}
			/* Get any leftovers */
			switch (width & 3) {
				case 3:
					*(uint16_t *)dst = map[*src++];
					dst += 2;
				case 2:
					*(uint32_t *)dst =
					  (map[src[HI]]<<16)|(map[src[LO]]);
					src += 2;
					dst += 4;
					break;
				case 1:
					*(uint16_t *)dst = map[*src++];
					dst += 2;
					break;
			}
			src += srcskip;
			dst += dstskip;
		}
	} else { 
		while ( height-- ) {
			/* Copy in 4 pixel chunks */
			for ( c=width/4; c; --c ) {
				*(uint32_t *)dst =
					(map[src[HI]]<<16)|(map[src[LO]]);
				src += 2;
				dst += 4;
				*(uint32_t *)dst =
					(map[src[HI]]<<16)|(map[src[LO]]);
				src += 2;
				dst += 4;
			}
			/* Get any leftovers */
			switch (width & 3) {
				case 3:
					*(uint16_t *)dst = map[*src++];
					dst += 2;
				case 2:
					*(uint32_t *)dst =
					  (map[src[HI]]<<16)|(map[src[LO]]);
					src += 2;
					dst += 4;
					break;
				case 1:
					*(uint16_t *)dst = map[*src++];
					dst += 2;
					break;
			}
			src += srcskip;
			dst += dstskip;
		}
	}
#endif /* USE_DUFFS_LOOP */
}
static void Blit1to3(SDLMOD_BlitInfo *info)
{
#ifndef USE_DUFFS_LOOP
	int c;
#endif
	int o;
	int width, height;
	uint8_t *src, *map, *dst;
	int srcskip, dstskip;

	/* Set up some basic variables */
	width = info->d_width;
	height = info->d_height;
	src = info->s_pixels;
	srcskip = info->s_skip;
	dst = info->d_pixels;
	dstskip = info->d_skip;
	map = info->table;

	while ( height-- ) {
#ifdef USE_DUFFS_LOOP
		DUFFS_LOOP(
			{
				o = *src * 4;
				dst[0] = map[o++];
				dst[1] = map[o++];
				dst[2] = map[o++];
			}
			src++;
			dst += 3;
		, width);
#else
		for ( c=width; c; --c ) {
			o = *src * 4;
			dst[0] = map[o++];
			dst[1] = map[o++];
			dst[2] = map[o++];
			src++;
			dst += 3;
		}
#endif /* USE_DUFFS_LOOP */
		src += srcskip;
		dst += dstskip;
	}
}
static void Blit1to4(SDLMOD_BlitInfo *info)
{
#ifndef USE_DUFFS_LOOP
	int c;
#endif
	int width, height;
	uint8_t *src;
	uint32_t *map, *dst;
	int srcskip, dstskip;

	/* Set up some basic variables */
	width = info->d_width;
	height = info->d_height;
	src = info->s_pixels;
	srcskip = info->s_skip;
	dst = (uint32_t *)info->d_pixels;
	dstskip = info->d_skip/4;
	map = (uint32_t *)info->table;

	while ( height-- ) {
#ifdef USE_DUFFS_LOOP
		DUFFS_LOOP(
			*dst++ = map[*src++];
		, width);
#else
		for ( c=width/4; c; --c ) {
			*dst++ = map[*src++];
			*dst++ = map[*src++];
			*dst++ = map[*src++];
			*dst++ = map[*src++];
		}
		switch ( width & 3 ) {
			case 3:
				*dst++ = map[*src++];
			case 2:
				*dst++ = map[*src++];
			case 1:
				*dst++ = map[*src++];
		}
#endif /* USE_DUFFS_LOOP */
		src += srcskip;
		dst += dstskip;
	}
}

static void Blit1to1Key(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint8_t *dst = info->d_pixels;
	int dstskip = info->d_skip;
	uint8_t *palmap = info->table;
	uint32_t ckey = info->src->colorkey;
        
	if ( palmap ) {
		while ( height-- ) {
			DUFFS_LOOP(
			{
				if ( *src != ckey ) {
				  *dst = palmap[*src];
				}
				dst++;
				src++;
			},
			width);
			src += srcskip;
			dst += dstskip;
		}
	} else {
		while ( height-- ) {
			DUFFS_LOOP(
			{
				if ( *src != ckey ) {
				  *dst = *src;
				}
				dst++;
				src++;
			},
			width);
			src += srcskip;
			dst += dstskip;
		}
	}
}

static void Blit1to2Key(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint16_t *dstp = (uint16_t *)info->d_pixels;
	int dstskip = info->d_skip;
	uint16_t *palmap = (uint16_t *)info->table;
	uint32_t ckey = info->src->colorkey;

	/* Set up some basic variables */
	dstskip /= 2;

	while ( height-- ) {
		DUFFS_LOOP(
		{
			if ( *src != ckey ) {
				*dstp=palmap[*src];
			}
			src++;
			dstp++;
		},
		width);
		src += srcskip;
		dstp += dstskip;
	}
}

static void Blit1to3Key(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint8_t *dst = info->d_pixels;
	int dstskip = info->d_skip;
	uint8_t *palmap = info->table;
	uint32_t ckey = info->src->colorkey;
	int o;

	while ( height-- ) {
		DUFFS_LOOP(
		{
			if ( *src != ckey ) {
				o = *src * 4;
				dst[0] = palmap[o++];
				dst[1] = palmap[o++];
				dst[2] = palmap[o++];
			}
			src++;
			dst += 3;
		},
		width);
		src += srcskip;
		dst += dstskip;
	}
}

static void Blit1to4Key(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint32_t *dstp = (uint32_t *)info->d_pixels;
	int dstskip = info->d_skip;
	uint32_t *palmap = (uint32_t *)info->table;
	uint32_t ckey = info->src->colorkey;

	/* Set up some basic variables */
	dstskip /= 4;

	while ( height-- ) {
		DUFFS_LOOP(
		{
			if ( *src != ckey ) {
				*dstp = palmap[*src];
			}
			src++;
			dstp++;
		},
		width);
		src += srcskip;
		dstp += dstskip;
	}
}

static void Blit1toNAlpha(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint8_t *dst = info->d_pixels;
	int dstskip = info->d_skip;
	SDLMOD_PixelFormat *dstfmt = info->dst;
	const SDLMOD_Color *srcpal	= info->src->palette->colors;
	int dstbpp;
	const int A = info->src->alpha;

	/* Set up some basic variables */
	dstbpp = dstfmt->BytesPerPixel;

	while ( height-- ) {
	        int sR, sG, sB;
		int dR, dG, dB;
	    	DUFFS_LOOP4(
			{
			        uint32_t pixel;
				sR = srcpal[*src].r;
				sG = srcpal[*src].g;
				sB = srcpal[*src].b;
				DISEMBLE_RGB(dst, dstbpp, dstfmt,
					     pixel, dR, dG, dB);
				ALPHA_BLEND(sR, sG, sB, A, dR, dG, dB);
			  	ASSEMBLE_RGB(dst, dstbpp, dstfmt, dR, dG, dB);
				src++;
				dst += dstbpp;
			},
			width);
		src += srcskip;
		dst += dstskip;
	}
}

static void Blit1toNAlphaKey(SDLMOD_BlitInfo *info)
{
	int width = info->d_width;
	int height = info->d_height;
	uint8_t *src = info->s_pixels;
	int srcskip = info->s_skip;
	uint8_t *dst = info->d_pixels;
	int dstskip = info->d_skip;
	SDLMOD_PixelFormat *srcfmt = info->src;
	SDLMOD_PixelFormat *dstfmt = info->dst;
	const SDLMOD_Color *srcpal	= info->src->palette->colors;
	uint32_t ckey = srcfmt->colorkey;
	int dstbpp;
	const int A = srcfmt->alpha;

	/* Set up some basic variables */
	dstbpp = dstfmt->BytesPerPixel;

	while ( height-- ) {
	        int sR, sG, sB;
		int dR, dG, dB;
		DUFFS_LOOP(
		{
			if ( *src != ckey ) {
			        uint32_t pixel;
				sR = srcpal[*src].r;
				sG = srcpal[*src].g;
				sB = srcpal[*src].b;
				DISEMBLE_RGB(dst, dstbpp, dstfmt,
							pixel, dR, dG, dB);
				ALPHA_BLEND(sR, sG, sB, A, dR, dG, dB);
			  	ASSEMBLE_RGB(dst, dstbpp, dstfmt, dR, dG, dB);
			}
			src++;
			dst += dstbpp;
		},
		width);
		src += srcskip;
		dst += dstskip;
	}
}

static SDLMOD_loblit one_blit[] = {
	NULL, Blit1to1, Blit1to2, Blit1to3, Blit1to4
};

static SDLMOD_loblit one_blitkey[] = {
        NULL, Blit1to1Key, Blit1to2Key, Blit1to3Key, Blit1to4Key
};

SDLMOD_loblit SDLMOD_CalculateBlit1(SDLMOD_Surface *surface, int blit_index)
{
	int which;
	SDLMOD_PixelFormat *dstfmt;

	dstfmt = surface->map->dst->format;
	if ( dstfmt->BitsPerPixel < 8 ) {
		which = 0;
	} else {
		which = dstfmt->BytesPerPixel;
	}
	switch(blit_index) {
	case 0:			/* copy */
	    return one_blit[which];

	case 1:			/* colorkey */
	    return one_blitkey[which];

	case 2:			/* alpha */
	    /* Supporting 8bpp->8bpp alpha is doable but requires lots of
	       tables which consume space and takes time to precompute,
	       so is better left to the user */
	    return which >= 2 ? &Blit1toNAlpha : NULL;

	case 3:			/* alpha + colorkey */
	    return which >= 2 ? &Blit1toNAlphaKey : NULL;

	}
	return NULL;
}
