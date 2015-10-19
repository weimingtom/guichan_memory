#include "imagebutton.hpp"
#include "../graphics.hpp"
#include "../image.hpp"

namespace gcn
{
    ImageButton::ImageButton()
        : mImage(0), 
          mInternalImage(false)
    {
        setWidth(0);
        setHeight(0);
    }

    ImageButton::ImageButton(const std::string& filename)
        : mImage(0), 
          mInternalImage(false)
    {
        mImage = Image::load(filename);
        mInternalImage = true;
        setWidth(mImage->getWidth() + mImage->getWidth() / 2);
        setHeight(mImage->getHeight() + mImage->getHeight() / 2);
    }

    ImageButton::ImageButton(const Image* image)
        : mImage(image), 
          mInternalImage(false)
    {
        setWidth(mImage->getWidth() + mImage->getWidth() / 2);
        setHeight(mImage->getHeight() + mImage->getHeight() / 2);
    }

    ImageButton::~ImageButton()
    {
        if (mInternalImage)
        {
            delete mImage;
        }
    }

    void ImageButton::setImage(const Image* image)
    {
        if (mInternalImage)
        {
            delete mImage;
        }

        mImage = image;
        mInternalImage = false;
    }

    const Image* ImageButton::getImage() const
    {
        return mImage;
    }

    void ImageButton::draw(Graphics* graphics)
    {
        gcn::Color faceColor = getBaseColor();
        gcn::Color highlightColor, shadowColor;
        int alpha = getBaseColor().a;

        if (isPressed())
        {
            faceColor = faceColor - 0x303030;
            faceColor.a = alpha;
            highlightColor = faceColor - 0x303030;
            highlightColor.a = alpha;
            shadowColor = faceColor + 0x303030;
            shadowColor.a = alpha;
        }
        else
        {
            highlightColor = faceColor + 0x303030;
            highlightColor.a = alpha;
            shadowColor = faceColor - 0x303030;
            shadowColor.a = alpha;
        }

        graphics->setColor(faceColor);
        graphics->fillRectangle(Rectangle(1, 
                                          1, 
                                          getDimension().width - 1, 
                                          getHeight() - 1));

        graphics->setColor(highlightColor);
        graphics->drawLine(0, 0, getWidth() - 1, 0);
        graphics->drawLine(0, 1, 0, getHeight() - 1);

        graphics->setColor(shadowColor);
        graphics->drawLine(getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);
        graphics->drawLine(1, getHeight() - 1, getWidth() - 1, getHeight() - 1);

        graphics->setColor(getForegroundColor());

        const int textX = (getWidth() - (mImage ? mImage->getWidth() : 0) ) / 2;
        const int textY = (getHeight() - (mImage ? mImage->getHeight() : 0) ) / 2;

        if (isPressed())
        {
            if(mImage)
                graphics->drawImage(mImage, textX + 1, textY + 1);
        }
        else
        {
            if(mImage)
                graphics->drawImage(mImage, textX, textY);

            if (isFocused())
            {
                graphics->drawRectangle(Rectangle(2, 
                                                  2, 
                                                  getWidth() - 4,
                                                  getHeight() - 4));
            }
        }
    }
}
