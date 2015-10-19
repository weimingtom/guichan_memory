#include "glutimage.hpp"
#include "guichan/exception.hpp"
#include "glutimageloader.hpp"

#include "TextureLoader.h"
#include "SDLMOD_endian.h"

#define Rmask 0x000000FF
#define Gmask 0x0000FF00
#define Bmask 0x00FF0000
//#define Amask 0xFF000000
#define Amask 0x00000000
#define SDL_VIDEO_MODE_BPP 24

namespace gcn
{
    Image* GLUTImageLoader::load(const std::string& filename,
                                bool convertToDisplayFormat)
    {
        SDLMOD_Surface *loadedSurface = loadSDLSurface(filename);

        if (loadedSurface == NULL)
        {
            throw GCN_EXCEPTION(
                    std::string("Unable to load image file: ") + filename);
        }

#if 0
        SDLMOD_Surface *surface = convertToStandardFormat(loadedSurface);
        SDLMOD_FreeSurface(loadedSurface);

        if (surface == NULL)
        {
            throw GCN_EXCEPTION(
                    std::string("Not enough memory to load: ") + filename);
        }
#else
		SDLMOD_Surface *surface = loadedSurface;
#endif

        Image *image = new GLUTImage(surface, true);

        if (convertToDisplayFormat)
        {
            image->convertToDisplayFormat();
        }

        return image;
    }

    SDLMOD_Surface* GLUTImageLoader::loadSDLSurface(const std::string& filename)
    {
		//SDLMOD_Surface *result = 0;
		SDLMOD_Surface *screen2;

		unsigned char *texture_data2 = NULL;
		unsigned int g_TextureWidth2 = 100;
		unsigned int g_TextureHeight2 = 100;
		int i, j;

		texture_data2 = loadBMPRaw(filename.c_str(), 
			&g_TextureWidth2, &g_TextureHeight2, 1, 1);
		if (!texture_data2)
		{
			return NULL;
		}
		screen2 = SDLMOD_CreateRGBSurface(0,
			g_TextureWidth2, g_TextureHeight2, 
			SDL_VIDEO_MODE_BPP,
			Rmask, Gmask, Bmask, Amask
			);
		if (texture_data2)
		{
			//SDLMOD_LockSurface(screen2);
			for (j = 0; j < g_TextureHeight2; ++j)
			{
				for (i = 0; i < g_TextureWidth2; ++i)
				{
					unsigned char r, g, b;
					r = texture_data2[3 * j * g_TextureWidth2 + 3 * i];
					g = texture_data2[3 * j * g_TextureWidth2 + 3 * i + 1];
					b = texture_data2[3 * j * g_TextureWidth2 + 3 * i + 2];
					//if (g_TextureHeight2 - j - 1 == 0)
					//{
					//	fprintf(stderr, "hit\n");
					//}
					//SDLMOD_ext_putPixel(screen2, i, g_TextureHeight2 - j - 1, r, g, b);
#ifdef _DEBUG
					if (i < 10 && filename == "fixedfont.bmp")
					{
						fprintf(stderr, "[GLUTImageLoader::loadSDLSurface] hit (%d, %d) (%X, %X, %X)\n",
							i, j, r, g, b);
					}
#endif
					SDLMOD_ext_putPixel(screen2, i, j, r, g, b);
				}
			}
			//SDLMOD_UnlockSurface(screen2);
			free(texture_data2);
		}




		return screen2;
    }

#if 0
    SDL_Surface* SDLImageLoader::convertToStandardFormat(SDL_Surface* surface)
    {
        Uint32 rmask, gmask, bmask, amask;
#if SDLMOD_BYTEORDER == SDLMOD_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
#else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
#endif

        SDL_Surface *colorSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                0, 0, 32,
                rmask, gmask, bmask, amask);

        SDL_Surface *tmp = NULL;

        if (colorSurface != NULL)
        {
            tmp = SDL_ConvertSurface(surface, colorSurface->format,
                                     SDL_SWSURFACE);
            SDL_FreeSurface(colorSurface);
        }

        return tmp;
    }
#endif


}
