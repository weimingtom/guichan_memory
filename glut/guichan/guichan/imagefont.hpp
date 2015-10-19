#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "font.hpp"
#include "platform.hpp"
#include "rectangle.hpp"

namespace gcn
{
    class Color;
    class Graphics;
    class Image;

    class GCN_CORE_DECLSPEC ImageFont: public Font
    {
    public:
        ImageFont(const std::string& filename, const std::string& glyphs);
        ImageFont(Image* image, const std::string& glyphs);
        ImageFont(const std::string& filename, 
                  unsigned char glyphsFrom=32,
                  unsigned char glyphsTo=126);
        virtual ~ImageFont();
        virtual int drawGlyph(Graphics* graphics, unsigned char glyph,
                              int x, int y);
        virtual void setRowSpacing(int spacing);
        virtual int getRowSpacing();
        virtual void setGlyphSpacing(int spacing);
        virtual int getGlyphSpacing();
        virtual int getWidth(unsigned char glyph) const;
        virtual int getWidth(const std::string& text) const;
        virtual void drawString(Graphics* graphics, const std::string& text,
                                int x, int y);
        virtual int getHeight() const;
        virtual int getStringIndexAt(const std::string& text, int x) const;

    protected:
        Rectangle scanForGlyph(unsigned char glyph, 
                                int x, 
                                int y, 
                                const Color& separator);
        
        Rectangle mGlyph[256];
        int mHeight;
        int mGlyphSpacing;
        int mRowSpacing;
        Image* mImage;
        std::string mFilename;
    };
}
