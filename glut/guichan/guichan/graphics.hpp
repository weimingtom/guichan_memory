#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <iosfwd>
#include <stack>
#include "cliprectangle.hpp"
#include "platform.hpp"

namespace gcn
{
    class Color;
    class Font;
    class Image;

    class GCN_CORE_DECLSPEC Graphics
    {
    public:
        enum Alignment
        {
            LEFT = 0,
            CENTER,
            RIGHT
        };

        Graphics();
        virtual ~Graphics() { }
        virtual void _beginDraw() { }
        virtual void _endDraw() { }
        virtual bool pushClipArea(Rectangle area);
        virtual void popClipArea();
        virtual const ClipRectangle& getCurrentClipArea();
        virtual void drawImage(const Image* image,
                               int srcX,
                               int srcY,
                               int dstX,
                               int dstY,
                               int width,
                               int height) = 0;
        virtual void drawImage(const Image* image, int dstX, int dstY);
        virtual void drawPoint(int x, int y) = 0;
        virtual void drawLine(int x1, int y1, int x2, int y2) = 0;
        virtual void drawRectangle(const Rectangle& rectangle) = 0;
        virtual void fillRectangle(const Rectangle& rectangle) = 0;
        virtual void setColor(const Color& color) = 0;
        virtual const Color& getColor() const = 0;
        virtual void setFont(Font* font);
        virtual void drawText(const std::string& text,
                              int x,
                              int y,
                              Alignment alignment = LEFT);

        std::stack<ClipRectangle> mClipStack;
        Font* mFont;
    };
}
