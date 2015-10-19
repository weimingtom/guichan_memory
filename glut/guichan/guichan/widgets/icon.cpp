#include "icon.hpp"
#include "../graphics.hpp"
#include "../image.hpp"
#include "../rectangle.hpp"

namespace gcn
{
    Icon::Icon()
        : mImage(0)
        , mInternalImage(false)
    {
        setSize(0, 0);
    }

    Icon::Icon(const std::string& filename)
        : mImage(0),
          mInternalImage(false)
    {
        mImage = Image::load(filename);
        mInternalImage = true;
        setSize(mImage->getWidth(),
                mImage->getHeight());
    }

    Icon::Icon(const Image* image)
        : mImage(image),
          mInternalImage(false)
    {
        setSize(mImage->getWidth(),
                mImage->getHeight());
    }

    Icon::~Icon()
    {
        if (mInternalImage)
        {
            delete mImage;
        }
    }

    void Icon::setImage(const Image* image)
    {
        if (mInternalImage)
        {
            delete mImage;
        }

        mImage = image;
        mInternalImage = false;
        setSize(mImage->getWidth(),
                mImage->getHeight());
    }

    const Image* Icon::getImage() const
    {
        return mImage;
    }

    void Icon::draw(Graphics* graphics)
    {
        if (mImage != NULL)
        {
            const int x = (getWidth() - mImage->getWidth()) / 2;
            const int y = (getHeight() - mImage->getHeight()) / 2;
            graphics->drawImage(mImage, x, y);
        }
    }
}
