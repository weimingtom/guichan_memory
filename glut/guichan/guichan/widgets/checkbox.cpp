#include "checkbox.hpp"
#include "../font.hpp"
#include "../graphics.hpp"
#include "../key.hpp"
#include "../mouseinput.hpp"

namespace gcn
{

    CheckBox::CheckBox()
    {
        setSelected(false);

        setFocusable(true);
        addMouseListener(this);
        addKeyListener(this);
    }

    CheckBox::CheckBox(const std::string &caption, bool selected)
    {
        setCaption(caption);
        setSelected(selected);

        setFocusable(true);
        addMouseListener(this);
        addKeyListener(this);

        adjustSize();
    }

    void CheckBox::draw(Graphics* graphics)
    {
        drawBox(graphics);

        graphics->setFont(getFont());
        graphics->setColor(getForegroundColor());

        const int h = getHeight() + getHeight() / 2;

        graphics->drawText(getCaption(), h - 2, 0);
    }

    void CheckBox::drawBox(Graphics *graphics)
    {
        const int h = getHeight() - 2;
        const int alpha = getBaseColor().a;
        Color faceColor = getBaseColor();
        faceColor.a = alpha;
        Color highlightColor = faceColor + 0x303030;
        highlightColor.a = alpha;
        Color shadowColor = faceColor - 0x303030;
        shadowColor.a = alpha;

        graphics->setColor(shadowColor);
        graphics->drawLine(1, 1, h, 1);
        graphics->drawLine(1, 1, 1, h);

        graphics->setColor(highlightColor);
        graphics->drawLine(h, 1, h, h);
        graphics->drawLine(1, h, h - 1, h);

        graphics->setColor(getBackgroundColor());
        graphics->fillRectangle(Rectangle(2, 2, h - 2, h - 2));

        graphics->setColor(getForegroundColor());

        if (isFocused())
        {
            graphics->drawRectangle(Rectangle(0, 0, h + 2, h + 2));
        }

        if (mSelected)
        {
            graphics->drawLine(3, 5, 3, h - 2);
            graphics->drawLine(4, 5, 4, h - 2);

            graphics->drawLine(5, h - 3, h - 2, 4);
            graphics->drawLine(5, h - 4, h - 4, 5);
        }
    }

    bool CheckBox::isSelected() const
    {
        return mSelected;
    }

    void CheckBox::setSelected(bool selected)
    {
        mSelected = selected;
    }

    const std::string &CheckBox::getCaption() const
    {
        return mCaption;
    }

    void CheckBox::setCaption(const std::string& caption)
    {
        mCaption = caption;
    }

    void CheckBox::keyPressed(KeyEvent& keyEvent)
    {
        Key key = keyEvent.getKey();

        if (key.getValue() == Key::ENTER ||
            key.getValue() == Key::SPACE)
        {
            toggleSelected();
            keyEvent.consume();
        }
    }

    void CheckBox::mouseClicked(MouseEvent& mouseEvent)
    {
        if (mouseEvent.getButton() == MouseEvent::LEFT)
        {
            toggleSelected();
        }
    }

    void CheckBox::mouseDragged(MouseEvent& mouseEvent)
    {
        mouseEvent.consume();
    }

    void CheckBox::adjustSize()
    {
        int height = getFont()->getHeight();

        setHeight(height);
        setWidth(getFont()->getWidth(mCaption) + height + height / 2);
    }

    void CheckBox::toggleSelected()
    {
        mSelected = !mSelected;
        distributeActionEvent();
    }
}

