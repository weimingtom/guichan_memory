#pragma once

#include <SDL.h>
#include "../color.hpp"

namespace gcn
{
    inline const Color SDLgetPixel(SDL_Surface* surface, int x, int y)
    {
        int bpp = surface->format->BytesPerPixel;

        SDL_LockSurface(surface);

        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

        unsigned int color = 0;

        switch(bpp)
        {
          case 1:
              color = *p;
              break;

          case 2:
              color = *(Uint16 *)p;
              break;

          case 3:
              if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
              {
                  color = p[0] << 16 | p[1] << 8 | p[2];
              }
              else
              {
                  color = p[0] | p[1] << 8 | p[2] << 16;
              }
              break;

          case 4:
              color = *(Uint32 *)p;
              break;

        }

        Uint8/*unsigned char*/ r,g,b,a;

        SDL_GetRGBA(color, surface->format, &r, &g, &b, &a);
        SDL_UnlockSurface(surface);

        return Color(r,g,b,a);
    }

    inline void SDLputPixel(SDL_Surface* surface, int x, int y, const Color& color)
    {
        int bpp = surface->format->BytesPerPixel;

        SDL_LockSurface(surface);

        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

        Uint32 pixel = SDL_MapRGB(surface->format, color.r, color.g, color.b);

        switch(bpp)
        {
          case 1:
              *p = pixel;
              break;

          case 2:
              *(Uint16 *)p = pixel;
              break;

          case 3:
              if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
              {
                  p[0] = (pixel >> 16) & 0xff;
                  p[1] = (pixel >> 8) & 0xff;
                  p[2] = pixel & 0xff;
              }
              else
              {
                  p[0] = pixel & 0xff;
                  p[1] = (pixel >> 8) & 0xff;
                  p[2] = (pixel >> 16) & 0xff;
              }
              break;

          case 4:
              *(Uint32 *)p = pixel;
              break;
        }

        SDL_UnlockSurface(surface);
    }

    inline unsigned int SDLAlpha32(unsigned int src, unsigned int dst, unsigned char a)
    {
        unsigned int b = ((src & 0xff) * a + (dst & 0xff) * (255 - a)) >> 8;
        unsigned int g = ((src & 0xff00) * a + (dst & 0xff00) * (255 - a)) >> 8;
        unsigned int r = ((src & 0xff0000) * a + (dst & 0xff0000) * (255 - a)) >> 8;

        return (b & 0xff) | (g & 0xff00) | (r & 0xff0000);
    }

    inline unsigned short SDLAlpha16(unsigned short src, unsigned short dst, unsigned char a, const SDL_PixelFormat *f)
    {
        unsigned int b = ((src & f->Rmask) * a + (dst & f->Rmask) * (255 - a)) >> 8;
        unsigned int g = ((src & f->Gmask) * a + (dst & f->Gmask) * (255 - a)) >> 8;
        unsigned int r = ((src & f->Bmask) * a + (dst & f->Bmask) * (255 - a)) >> 8;

        return (unsigned short)((b & f->Rmask) | (g & f->Gmask) | (r & f->Bmask));
    }

    inline void SDLputPixelAlpha(SDL_Surface* surface, int x, int y, const Color& color)
    {
        int bpp = surface->format->BytesPerPixel;

        SDL_LockSurface(surface);

        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

        Uint32 pixel = SDL_MapRGB(surface->format, color.r, color.g, color.b);

        switch(bpp)
        {
          case 1:
              *p = pixel;
              break;

          case 2:
              *(Uint16 *)p = SDLAlpha16(pixel, *(Uint32 *)p, color.a, surface->format);
              break;

          case 3:
              if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
              {
                  unsigned int r = (p[0] * (255 - color.a) + color.r * color.a) >> 8;
                  unsigned int g = (p[1] * (255 - color.a) + color.g * color.a) >> 8;
                  unsigned int b = (p[2] * (255 - color.a) + color.b * color.a) >> 8;

                  p[2] = b;
                  p[1] = g;
                  p[0] = r;
              }
              else
              {
                  unsigned int r = (p[2] * (255 - color.a) + color.r * color.a) >> 8;
                  unsigned int g = (p[1] * (255 - color.a) + color.g * color.a) >> 8;
                  unsigned int b = (p[0] * (255 - color.a) + color.b * color.a) >> 8;

                  p[0] = b;
                  p[1] = g;
                  p[2] = r;
              }
              break;

          case 4:
              *(Uint32 *)p = SDLAlpha32(pixel, *(Uint32 *)p, color.a);
              break;
        }

        SDL_UnlockSurface(surface);
    }
}
