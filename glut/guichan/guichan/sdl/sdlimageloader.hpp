#pragma once

#include "../imageloader.hpp"
#include "../platform.hpp"
#include <SDL.h>

namespace gcn
{
    class Image;
    class GCN_EXTENSION_DECLSPEC SDLImageLoader : public ImageLoader
    {
    public:
        virtual Image* load(const std::string& filename, bool convertToDisplayFormat = true);

    protected:
        virtual SDL_Surface* loadSDLSurface(const std::string& filename);
        virtual SDL_Surface* convertToStandardFormat(SDL_Surface* surface);
    };
}
