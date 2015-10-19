#include "sdlimage.hpp"
#include "../exception.hpp"
#include "sdlpixel.hpp"

namespace gcn
{
    SDLImage::SDLImage(SDL_Surface* surface, bool autoFree)
    {
        mAutoFree = autoFree;
        mSurface = surface;
    }

    SDLImage::~SDLImage()
    {
        if (mAutoFree)
        {
            free();
        }
    }

    SDL_Surface* SDLImage::getSurface() const
    {
        return mSurface;
    }

    int SDLImage::getWidth() const
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get the width of a non loaded image.");
        }

        return mSurface->w;
    }

    int SDLImage::getHeight() const
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get the height of a non loaded image.");
        }

        return mSurface->h;
    }

    Color SDLImage::getPixel(int x, int y)
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get a pixel from a non loaded image.");
        }

        return SDLgetPixel(mSurface, x, y);
    }

    void SDLImage::putPixel(int x, int y, const Color& color)
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to put a pixel in a non loaded image.");
        }

        SDLputPixel(mSurface, x, y, color);
    }

    void SDLImage::convertToDisplayFormat()
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to convert a non loaded image to display format.");
        }

        int i;
        bool hasPink = false;
        bool hasAlpha = false;

        for (i = 0; i < mSurface->w * mSurface->h; ++i)
        {
            if (((unsigned int*)mSurface->pixels)[i] == SDL_MapRGB(mSurface->format,255,0,255))
            {
                hasPink = true;
                break;
            }
        }

        for (i = 0; i < mSurface->w * mSurface->h; ++i)
        {
            Uint8 r, g, b, a;

            SDL_GetRGBA(((unsigned int*)mSurface->pixels)[i], mSurface->format,
                        &r, &g, &b, &a);

            if (a != 255)
            {
                hasAlpha = true;
                break;
            }
        }

        SDL_Surface *tmp;

        if (hasAlpha)
        {
            tmp = SDL_DisplayFormatAlpha(mSurface);
            SDL_FreeSurface(mSurface);
            mSurface = NULL;
        }
        else
        {
            tmp = SDL_DisplayFormat(mSurface);
            SDL_FreeSurface(mSurface);
            mSurface = NULL;
        }

        if (tmp == NULL)
        {
            throw GCN_EXCEPTION("Unable to convert image to display format.");
        }

        if (hasPink)
        {
            SDL_SetColorKey(tmp, SDL_SRCCOLORKEY,
                            SDL_MapRGB(tmp->format,255,0,255));
        }
        if (hasAlpha)
        {
            SDL_SetAlpha(tmp, SDL_SRCALPHA, 255);
        }

        mSurface = tmp;
    }

    void SDLImage::free()
    {
        SDL_FreeSurface(mSurface);
    }
}
