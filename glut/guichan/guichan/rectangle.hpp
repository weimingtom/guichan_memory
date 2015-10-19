#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"
#include <iostream>

namespace gcn
{
    class GCN_CORE_DECLSPEC Rectangle
    {
    public:
        Rectangle();
        Rectangle(int x, int y, int width, int height);
        void setAll(int x, int y, int width, int height);
        bool isIntersecting(const Rectangle& rectangle) const;
        bool isPointInRect(int x, int y) const;
        friend std::ostream& operator<<(std::ostream& out,
                                        const Rectangle& rectangle);
                                        
        int x;
        int y;
        int width;
        int height;
    };
}
