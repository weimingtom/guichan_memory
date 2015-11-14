#include "glutgraphics.hpp"
#include "guichan/exception.hpp"
#include "guichan/font.hpp"
#include "guichan/image.hpp"
#include "glutimage.hpp"

#ifndef ABS
#define ABS(x) ((x)<0?-(x):(x))
#endif

//TODO: clip rect, SDLMOD_xxx draw rect overflow
namespace gcn
{

    GLUTGraphics::GLUTGraphics()
    {
        mAlpha = false;
    }

    void GLUTGraphics::_beginDraw()
    {
        Rectangle area;
        area.x = 0;
        area.y = 0;
        area.width = mTarget->w;
        area.height = mTarget->h;
        pushClipArea(area);
    }

    void GLUTGraphics::_endDraw()
    {
        popClipArea();
    }

    void GLUTGraphics::setTarget(SDLMOD_Surface* target)
    {
        mTarget = target;
    }

    bool GLUTGraphics::pushClipArea(Rectangle area)
    {
        SDLMOD_Rect rect;
        bool result = Graphics::pushClipArea(area);

        const ClipRectangle& carea = mClipStack.top();
        rect.x = carea.x;
        rect.y = carea.y;
        rect.w = carea.width;
        rect.h = carea.height;

        SDLMOD_SetClipRect(mTarget, &rect);

        return result;
    }

    void GLUTGraphics::popClipArea()
    {
        Graphics::popClipArea();

        if (mClipStack.empty())
        {
            return;
        }

        const ClipRectangle& carea = mClipStack.top();
        SDLMOD_Rect rect;
        rect.x = carea.x;
        rect.y = carea.y;
        rect.w = carea.width;
        rect.h = carea.height;

        SDLMOD_SetClipRect(mTarget, &rect);
#ifdef _DEBUG
		//fprintf(stderr, 
		//	"[GLUTGraphics::popClipArea]rect={x=%d, y=%d, w=%d, h=%d}\n", 
		//	rect.x, rect.y, rect.w, rect.h);
#endif
    }

    SDLMOD_Surface* GLUTGraphics::getTarget() const
    {
        return mTarget;
    }

    void GLUTGraphics::drawImage(const Image* image,
                                int srcX,
                                int srcY,
                                int dstX,
                                int dstY,
                                int width,
                                int height)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        SDLMOD_Rect src;
        SDLMOD_Rect dst;
        src.x = srcX;
        src.y = srcY;
        src.w = width;
        src.h = height;
        dst.x = dstX + top.xOffset;
        dst.y = dstY + top.yOffset;

        const GLUTImage* srcImage = dynamic_cast<const GLUTImage*>(image);

        if (srcImage == NULL)
        {
            throw GCN_EXCEPTION("Trying to draw an image of unknown format, must be an SDLImage.");
        }

        SDLMOD_BlitSurface(srcImage->getSurface(), &src, mTarget, &dst);
    }

    void GLUTGraphics::fillRectangle(const Rectangle& rectangle)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();
        
        Rectangle area = rectangle;
        area.x += top.xOffset;
        area.y += top.yOffset;

        if(!area.isIntersecting(top))
        {
            return;
        }

		SDLMOD_ext_fillRectangle(mTarget, 
			mColor.r, mColor.g, mColor.b, mColor.a,
			area.x, area.y, area.width, area.height);
    }

    void GLUTGraphics::drawPoint(int x, int y)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();
        
        x += top.xOffset;
        y += top.yOffset;

        if (!top.isPointInRect(x,y))
            return;

		SDLMOD_ext_drawPoint(mTarget, 
			mColor.r, mColor.g, mColor.b, mColor.a,
			x, y);
    }

    void GLUTGraphics::drawHLine(int x1, int y, int x2)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        x1 += top.xOffset;
        y += top.yOffset;
        x2 += top.xOffset;

        if (y < top.y || y >= top.y + top.height)
        {
            return;
        }

        if (x1 > x2)
        {
            x1 ^= x2;
            x2 ^= x1;
            x1 ^= x2;
        }

        if (top.x > x1)
        {
            if (top.x > x2)
            {
                return;
            }

            x1 = top.x;
        }

        if (top.x + top.width <= x2)
        {
            if (top.x + top.width <= x1)
            {
                return;
            }
            
            x2 = top.x + top.width -1;
        }

 		SDLMOD_ext_drawHLine(mTarget,
			mColor.r, mColor.g, mColor.b, mColor.a,
			x1, y, x2);
    }

    void GLUTGraphics::drawVLine(int x, int y1, int y2)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        x += top.xOffset;
        y1 += top.yOffset;
        y2 += top.yOffset;

        if (x < top.x || x >= top.x + top.width)
        {
            return;
        }
        
        if (y1 > y2)
        {
            y1 ^= y2;
            y2 ^= y1;
            y1 ^= y2;
        }

        if (top.y > y1)
        {
            if (top.y > y2)
            {
                return;
            }

            y1 = top.y;
        }

        if (top.y + top.height <= y2)
        {
            if (top.y + top.height <= y1)
            {
                return;
            }

            y2 = top.y + top.height - 1;
        }

		SDLMOD_ext_drawVLine(mTarget,
			mColor.r, mColor.g, mColor.b, mColor.a,
			x, y1, y2);
    }

    void GLUTGraphics::drawRectangle(const Rectangle& rectangle)
    {
        int x1 = rectangle.x;
        int x2 = rectangle.x + rectangle.width - 1;
        int y1 = rectangle.y;
        int y2 = rectangle.y + rectangle.height - 1;

        drawHLine(x1, y1, x2);
        drawHLine(x1, y2, x2);

        drawVLine(x1, y1, y2);
        drawVLine(x2, y1, y2);
    }

    void GLUTGraphics::drawLine(int x1, int y1, int x2, int y2)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        x1 += top.xOffset;
        y1 += top.yOffset;
        x2 += top.xOffset;
        y2 += top.yOffset;

		SDLMOD_ext_drawLine(mTarget,
			mColor.r, mColor.g, mColor.b, mColor.a,
			x1, y1, x2, y2);
    }

    void GLUTGraphics::setColor(const Color& color)
    {
        mColor = color;

        mAlpha = color.a != 255;
    }

    const Color& GLUTGraphics::getColor() const
    {
        return mColor;
    }

    void GLUTGraphics::drawSDLSurface(SDLMOD_Surface* surface,
                                     SDLMOD_Rect source,
                                     SDLMOD_Rect destination)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        destination.x += top.xOffset;
        destination.y += top.yOffset;

        SDLMOD_BlitSurface(surface, &source, mTarget, &destination);
    }
}
