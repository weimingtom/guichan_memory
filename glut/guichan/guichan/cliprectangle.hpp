#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "rectangle.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC ClipRectangle : public Rectangle
    {
    public:
		ClipRectangle();
        ClipRectangle(int x, 
                      int y, 
                      int width, 
                      int height,
                      int xOffset, 
                      int yOffset);
		const ClipRectangle& operator=(const Rectangle& other);
		int xOffset;
		int yOffset;
    };
}
