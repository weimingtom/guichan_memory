#include "glutimage.hpp"
#include "guichan/exception.hpp"

namespace gcn
{
    GLUTImage::GLUTImage(SDLMOD_Surface* surface, bool autoFree)
    {
        mAutoFree = autoFree;
        mSurface = surface;
    }

    GLUTImage::~GLUTImage()
    {
        if (mAutoFree)
        {
            free();
        }
    }

    SDLMOD_Surface* GLUTImage::getSurface() const
    {
        return mSurface;
    }

    int GLUTImage::getWidth() const
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get the width of a non loaded image.");
        }

        return mSurface->w;
    }

    int GLUTImage::getHeight() const
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get the height of a non loaded image.");
        }

        return mSurface->h;
    }

    Color GLUTImage::getPixel(int x, int y)
    {	
		if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to get a pixel from a non loaded image.");
        }

		uint8_t r, g, b, a;
        SDLMOD_ext_getPixel(mSurface, x, y, &r, &g, &b, &a);

		Color result(r, g, b, a);
        
		return result;
    }

    void GLUTImage::putPixel(int x, int y, const Color& color)
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to put a pixel in a non loaded image.");
        }

        SDLMOD_ext_putPixel(mSurface, x, y, color.r, color.g, color.b);
    }

    void GLUTImage::convertToDisplayFormat()
    {
        if (mSurface == NULL)
        {
            throw GCN_EXCEPTION("Trying to convert a non loaded image to display format.");
        }

        int i, j;
        bool hasPink = false;
        bool hasAlpha = false;

        for (j = 0; j < mSurface->h; ++j)
        {
			//SDLMOD_PixelFormat* format = mSurface->format;
			//uint32_t pinkColor = SDLMOD_MapRGB(format,255,0,255);
            //uint32_t pixel = ((unsigned int*)mSurface->pixels)[i];

			//if (pixel == pinkColor)
            //{
            //    hasPink = true;
            //    break;
            //}
			for (i = 0; i < mSurface->w; ++i)
			{
				uint8_t r, g, b, a;
				SDLMOD_ext_getPixel(mSurface, i, j, 
					&r, &g, &b, &a);
				if (r == 255 && g == 0 && b == 255)
				{
				    hasPink = true;
				    break;
				}
			}
        }

#if 0
        for (i = 0; i < mSurface->w * mSurface->h; ++i)
        {
            uint8_t r, g, b, a;

            SDLMOD_GetRGBA(((unsigned int*)mSurface->pixels)[i], mSurface->format,
                        &r, &g, &b, &a);

            if (a != 255)
            {
                hasAlpha = true;
                break;
            }
        }
#endif

        for (j = 0; j < mSurface->h; ++j)
        {
			for (i = 0; i < mSurface->w; ++i)
			{
				uint8_t r, g, b, a;
				SDLMOD_ext_getPixel(mSurface, i, j, 
					&r, &g, &b, &a);
				if (a != 255)
				{
					hasAlpha = true;
					break;
				}
			}
        }

        SDLMOD_Surface *tmp = mSurface; //FIXME:

#if 0
        if (hasAlpha)
        {
            tmp = SDL_DisplayFormatAlpha(mSurface);
            SDLMOD_FreeSurface(mSurface);
            mSurface = NULL;
        }
        else
        {
            tmp = SDL_DisplayFormat(mSurface);
            SDLMOD_FreeSurface(mSurface);
            mSurface = NULL;
        }
        if (tmp == NULL)
        {
            throw GCN_EXCEPTION("Unable to convert image to display format.");
        }
#endif

        if (hasPink)
        {
            SDLMOD_SetColorKey(tmp, SDLMOD_SRCCOLORKEY,
                            SDLMOD_MapRGB(tmp->format,255,0,255));
        }

#if 0
        if (hasAlpha)
        {
            SDL_SetAlpha(tmp, SDL_SRCALPHA, 255);
        }
#endif

        mSurface = tmp;
    }

    void GLUTImage::free()
    {
        SDLMOD_FreeSurface(mSurface);
    }
}

