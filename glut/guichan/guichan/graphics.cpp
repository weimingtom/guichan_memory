#include "graphics.hpp"
#include "exception.hpp"
#include "font.hpp"
#include "image.hpp"

namespace gcn
{

    Graphics::Graphics()
    {
        mFont = NULL;
    }

    bool Graphics::pushClipArea(Rectangle area)
    {
        // Ignore area with a negate width or height
        // by simple pushing an empty clip area
        // to the stack.
        if (area.width < 0 || area.height < 0)
        {
            ClipRectangle carea;
            mClipStack.push(carea);
            return true;
        }
            
        if (mClipStack.empty())
        {
            ClipRectangle carea;
            carea.x = area.x;
            carea.y = area.y;
            carea.width = area.width;
            carea.height = area.height;
            carea.xOffset = area.x;
            carea.yOffset = area.y;
            mClipStack.push(carea);
            return true; 
        }

        const ClipRectangle &top = mClipStack.top();
        ClipRectangle carea;
        carea = area;
        carea.xOffset = top.xOffset + carea.x;
        carea.yOffset = top.yOffset + carea.y;
        carea.x += top.xOffset;
        carea.y += top.yOffset;

        // Clamp the pushed clip rectangle.
        if (carea.x < top.x)
        {
            carea.x = top.x;
        }
        
        if (carea.y < top.y)
        {
            carea.y = top.y;            
        }
                
        if (carea.x + carea.width > top.x + top.width)
        {
            carea.width = top.x + top.width - carea.x;

            if (carea.width < 0)
            {
                carea.width = 0;
            }
        }
        
        if (carea.y + carea.height > top.y + top.height)
        {
            carea.height = top.y + top.height - carea.y;
            
            if (carea.height < 0)
            {
                carea.height = 0;
            }
        }
        
        bool result = carea.isIntersecting(top);
        
        mClipStack.push(carea);
        
        return result;
    }

    void Graphics::popClipArea()
    {

        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Tried to pop clip area from empty stack.");
        }

        mClipStack.pop();
    }

    const ClipRectangle& Graphics::getCurrentClipArea()
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("The clip area stack is empty.");
        }

        return mClipStack.top();
    }

    void Graphics::drawImage(const Image* image, int dstX, int dstY)
    {
        drawImage(image, 0, 0, dstX, dstY, image->getWidth(), image->getHeight());
    }

    void Graphics::setFont(Font* font)
    {
        mFont = font;
    }

    void Graphics::drawText(const std::string& text, int x, int y,
                            Alignment alignment)
    {
        if (mFont == NULL)
        {
            throw GCN_EXCEPTION("No font set.");
        }

        switch (alignment)
        {
          case LEFT:
              mFont->drawString(this, text, x, y);
              break;
          case CENTER:
              mFont->drawString(this, text, x - mFont->getWidth(text) / 2, y);
              break;
          case RIGHT:
              mFont->drawString(this, text, x - mFont->getWidth(text), y);
              break;
          default:
              throw GCN_EXCEPTION("Unknown alignment.");
        }
    }
}
