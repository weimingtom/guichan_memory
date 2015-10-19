#pragma once

#include "SDLMOD_video.h"
#include "SDLMOD_ext_pixel.h"
#include "guichan/color.hpp"
#include "guichan/graphics.hpp"
#include "guichan/platform.hpp"

namespace gcn
{
    class Image;
    class Rectangle;

    class GCN_EXTENSION_DECLSPEC GLUTGraphics : public Graphics
    {
    public:
        using Graphics::drawImage;
        GLUTGraphics();
        virtual void setTarget(SDLMOD_Surface* target);
        virtual SDLMOD_Surface* getTarget() const;
        virtual void drawSDLSurface(SDLMOD_Surface* surface,
                                    SDLMOD_Rect source,
                                    SDLMOD_Rect destination);
        virtual void _beginDraw();
        virtual void _endDraw();
        virtual bool pushClipArea(Rectangle area);
        virtual void popClipArea();
        virtual void drawImage(const Image* image,
                               int srcX,
                               int srcY,
                               int dstX,
                               int dstY,
                               int width,
                               int height);
        virtual void drawPoint(int x, int y);
        virtual void drawLine(int x1, int y1, int x2, int y2);
        virtual void drawRectangle(const Rectangle& rectangle);
        virtual void fillRectangle(const Rectangle& rectangle);
        virtual void setColor(const Color& color);
        virtual const Color& getColor() const;

    protected:
        virtual void drawHLine(int x1, int y, int x2);
        virtual void drawVLine(int x, int y1, int y2);
			
        SDLMOD_Surface* mTarget;
        Color mColor;
        bool mAlpha;
    };
}
