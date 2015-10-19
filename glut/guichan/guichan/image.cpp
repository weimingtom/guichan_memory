#include "image.hpp"
#include "exception.hpp"
#include "imageloader.hpp"

namespace gcn
{

    ImageLoader* Image::mImageLoader = NULL;

    Image::Image()
    {
    }

    Image::~Image()
    {
    }

    void Image::setImageLoader(ImageLoader* imageLoader)
    {
        mImageLoader = imageLoader;
    }

    ImageLoader* Image::getImageLoader()
    {
        return mImageLoader;
    }

    Image* Image::load(const std::string& filename, bool convertToDisplayFormat)
    {
        if (mImageLoader == NULL)
        {
            throw GCN_EXCEPTION("Trying to load an image but no image loader is set.");
        }

        return mImageLoader->load(filename, convertToDisplayFormat);
    }
}
