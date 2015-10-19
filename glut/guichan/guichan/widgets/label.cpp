#include "label.hpp"
#include "../exception.hpp"
#include "../font.hpp"
#include "../graphics.hpp"

namespace gcn
{
    Label::Label()
    {
        mAlignment = Graphics::LEFT;
    }

    Label::Label(const std::string& caption)
    {
        mCaption = caption;
        mAlignment = Graphics::LEFT;

        setWidth(getFont()->getWidth(caption));
        setHeight(getFont()->getHeight());
    }

    const std::string &Label::getCaption() const
    {
        return mCaption;
    }

    void Label::setCaption(const std::string& caption)
    {
        mCaption = caption;
    }

    void Label::setAlignment(Graphics::Alignment alignment)
    {
        mAlignment = alignment;
    }

    Graphics::Alignment Label::getAlignment() const
    {
        return mAlignment;
    }

    void Label::draw(Graphics* graphics)
    {
        int textX;
        int textY = getHeight() / 2 - getFont()->getHeight() / 2;

        switch (getAlignment())
        {
          case Graphics::LEFT:
              textX = 0;
              break;
          case Graphics::CENTER:
              textX = getWidth() / 2;
              break;
          case Graphics::RIGHT:
              textX = getWidth();
              break;
          default:
              throw GCN_EXCEPTION("Unknown alignment.");
        }

        graphics->setFont(getFont());
        graphics->setColor(getForegroundColor());
        graphics->drawText(getCaption(), textX, textY, getAlignment());
    }

    void Label::adjustSize()
    {
        setWidth(getFont()->getWidth(getCaption()));
        setHeight(getFont()->getHeight());
    }
}
