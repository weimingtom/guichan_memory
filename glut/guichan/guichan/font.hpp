#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "platform.hpp"

namespace gcn
{
    class Graphics;
    
    class GCN_CORE_DECLSPEC Font
    {
    public:
		virtual ~Font(){ }
		virtual int getWidth(const std::string& text) const = 0;
		virtual int getHeight() const = 0;
		virtual int getStringIndexAt(const std::string& text, int x) const;
		virtual void drawString(Graphics* graphics, const std::string& text,
                                int x, int y) = 0;
    };
}
