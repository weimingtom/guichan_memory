#include "rectangle.hpp"

namespace gcn
{
    Rectangle::Rectangle()
        : x(0),
          y(0),
          width(0),
          height(0)
    {
    }

    Rectangle::Rectangle(int x_, int y_, int width_, int height_)
      : x(x_),
        y(y_),
        width(width_),
        height(height_)
    {
    }

    void Rectangle::setAll(int x_, int y_, int width_, int height_)
    {
        x = x_;
        y = y_;
        width = width_;
        height = height_;
    }

    bool Rectangle::isIntersecting(const Rectangle& rectangle) const
    {
        int x_ = x;
        int y_ = y;
        int width_ = width;
        int height_ = height;

        x_ -= rectangle.x;
        y_ -= rectangle.y;

        if (x_ < 0)
        {
            width_ += x_;
            x_ = 0;
        }
        else if (x_ + width_ > rectangle.width)
        {
            width_ = rectangle.width - x_;
        }

        if (y_ < 0)
        {
            height_ += y_;
            y_ = 0;
        }
        else if (y_ + height_ > rectangle.height)
        {
            height_ = rectangle.height - y_;
        }

        if (width_ <= 0 || height_ <= 0)
        {
            return false;
        }

        return true;
    }

    bool Rectangle::isPointInRect(int x_, int y_) const
    {
        return x_ >= x
            && y_ >= y
            && x_ < x + width
            && y_ < y + height;
    }

    std::ostream& operator<<(std::ostream& out,
                             const Rectangle& rectangle)
    {
        out << "Rectangle [x = " << rectangle.x
            << ", y = " << rectangle.y
            << ", width = " << rectangle.width
            << ", height = " << rectangle.height
            << "]";

        return out;
    }
}
