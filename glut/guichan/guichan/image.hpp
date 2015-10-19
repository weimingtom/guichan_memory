#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "platform.hpp"

namespace gcn
{
    class Color;
    class ImageLoader;

    class GCN_CORE_DECLSPEC Image
    {
    public:
        Image();
        virtual ~Image();
        static Image* load(const std::string& filename, bool convertToDisplayFormat = true);
        static ImageLoader* getImageLoader();
        static void setImageLoader(ImageLoader* imageLoader);
        virtual void free() = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual Color getPixel(int x, int y) = 0;
        virtual void putPixel(int x, int y, const Color& color) = 0;
        virtual void convertToDisplayFormat() = 0;

    protected:
        static ImageLoader* mImageLoader;
    };
}
