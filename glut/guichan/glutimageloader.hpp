#pragma once

#include "guichan/imageloader.hpp"
#include "guichan/platform.hpp"
#include "SDLMOD_video.h"

namespace gcn
{
    class Image;
    class GCN_EXTENSION_DECLSPEC GLUTImageLoader : public ImageLoader
    {
    public:
        virtual Image* load(const std::string& filename, bool convertToDisplayFormat = true);

    protected:
        virtual SDLMOD_Surface* loadSDLSurface(const std::string& filename);
//        virtual SDL_Surface* convertToStandardFormat(SDL_Surface* surface);

    };
}
