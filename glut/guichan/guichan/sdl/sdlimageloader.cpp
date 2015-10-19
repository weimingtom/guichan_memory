#define USE_SDL_IMAGE 0

#include "sdlimage.hpp"
#if USE_SDL_IMAGE
#include <SDL/SDL_image.h>
#endif
#include "../exception.hpp"
#include "sdlimageloader.hpp"

namespace gcn
{
    Image* SDLImageLoader::load(const std::string& filename,
                                bool convertToDisplayFormat)
    {
        SDL_Surface *loadedSurface = loadSDLSurface(filename);

        if (loadedSurface == NULL)
        {
            throw GCN_EXCEPTION(
                    std::string("Unable to load image file: ") + filename);
        }

        SDL_Surface *surface = convertToStandardFormat(loadedSurface);
        SDL_FreeSurface(loadedSurface);

        if (surface == NULL)
        {
            throw GCN_EXCEPTION(
                    std::string("Not enough memory to load: ") + filename);
        }

        Image *image = new SDLImage(surface, true);

        if (convertToDisplayFormat)
        {
            image->convertToDisplayFormat();
        }

        return image;
    }

    SDL_Surface* SDLImageLoader::loadSDLSurface(const std::string& filename)
    {
#if USE_SDL_IMAGE
        return IMG_Load(filename.c_str());
#else
		return SDL_LoadBMP(filename.c_str());
#endif
    }

    SDL_Surface* SDLImageLoader::convertToStandardFormat(SDL_Surface* surface)
    {
        Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
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
}
