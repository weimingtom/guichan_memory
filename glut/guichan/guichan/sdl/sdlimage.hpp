#pragma once

#include <SDL.h>
#include <string>
#include "../color.hpp"
#include "../platform.hpp"
#include "../image.hpp"

namespace gcn
{
    class GCN_EXTENSION_DECLSPEC SDLImage : public Image
    {
    public:
        SDLImage(SDL_Surface* surface, bool autoFree);
        virtual ~SDLImage();
        virtual SDL_Surface* getSurface() const;
        virtual void free();
        virtual int getWidth() const;
        virtual int getHeight() const;
        virtual Color getPixel(int x, int y);
        virtual void putPixel(int x, int y, const Color& color);
        virtual void convertToDisplayFormat();

    protected:
        SDL_Surface* mSurface;
        bool mAutoFree;
    };
}
