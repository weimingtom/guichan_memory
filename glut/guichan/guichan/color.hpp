#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"
#include <iostream>

namespace gcn
{
    class GCN_CORE_DECLSPEC Color
    {
    public:
		Color();
		Color(int color);
		Color(int r, int g, int b, int a = 255);
		Color operator+(const Color& color) const;
		Color operator-(const Color& color) const;
		Color operator*(float value) const;
		bool operator==(const Color& color) const;
		bool operator!=(const Color& color) const;
		friend std::ostream& operator<<(std::ostream& out,
                                        const Color& Color);
		int r;
		int g;
		int b;
		int a;
    };
}
