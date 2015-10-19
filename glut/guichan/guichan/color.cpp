#include "color.hpp"

namespace gcn
{
    Color::Color()
        : r(0), 
          g(0), 
          b(0), 
          a(255)
    {
    }

    Color::Color(int color)
      : r( (color >> 16) & 0xFF),
        g( (color >>  8) & 0xFF),
        b(  color        & 0xFF),
        a(255)
    {
    }

    Color::Color(int ar, int ag, int ab, int aa) 
        : r(ar), 
          g(ag), 
          b(ab), 
          a(aa)
    {
    }

    Color Color::operator+(const Color& color) const
    {
        Color result(r + color.r, 
                     g + color.g, 
                     b + color.b, 
                     255);

        result.r = (result.r>255?255:(result.r<0?0:result.r));
        result.g = (result.g>255?255:(result.g<0?0:result.g));
        result.b = (result.b>255?255:(result.b<0?0:result.b));

        return result;
    }

    Color Color::operator-(const Color& color) const
    {
        Color result(r - color.r, 
                     g - color.g, 
                     b - color.b, 
                     255);

        result.r = (result.r>255?255:(result.r<0?0:result.r));
        result.g = (result.g>255?255:(result.g<0?0:result.g));
        result.b = (result.b>255?255:(result.b<0?0:result.b));

        return result;
    }

    Color Color::operator*(float value) const
    {
        Color result((int)(r * value), 
                     (int)(g * value), 
                     (int)(b * value), 
                     a);

        result.r = (result.r>255?255:(result.r<0?0:result.r));
        result.g = (result.g>255?255:(result.g<0?0:result.g));
        result.b = (result.b>255?255:(result.b<0?0:result.b));

        return result;
    }

    bool Color::operator==(const Color& color) const
    {
        return r == color.r && g == color.g && b == color.b && a == color.a;
    }

    bool Color::operator!=(const Color& color) const
    {
        return !(r == color.r && g == color.g && b == color.b && a == color.a);
    }

	std::ostream& operator<<(std::ostream& out,
                             const Color& color)
    {
        out << "Color [r = "
            << color.r
            << ", g = "
            << color.g
            << ", b = "
            << color.b
            << ", a = "
            << color.a
            << "]";

        return out;
    }
}
