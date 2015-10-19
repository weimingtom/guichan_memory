#include "cliprectangle.hpp"

namespace gcn
{
    ClipRectangle::ClipRectangle()
    {
        x = y = width = height = xOffset = yOffset  = 0;
    }

    ClipRectangle::ClipRectangle(int x, int y, int width, int height, int xOffset, int yOffset)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->xOffset = xOffset;
        this->yOffset = yOffset;
    }

    const ClipRectangle& ClipRectangle::operator=(const Rectangle& other)
    {
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;

        return *this;
    }
}
