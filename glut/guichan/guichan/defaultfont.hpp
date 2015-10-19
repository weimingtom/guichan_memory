#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "font.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC DefaultFont : public Font
    {
    public:
		virtual ~DefaultFont(){}
        virtual int drawGlyph(Graphics* graphics, unsigned char glyph, int x, int y);
		virtual void drawString(Graphics* graphics, const std::string& text, int x, int y);
		virtual int getWidth(const std::string& text) const;
		virtual int getHeight() const;
		virtual int getStringIndexAt(const std::string& text, int x) const;
    };
}
