#include "tab.hpp"
#include "../font.hpp"
#include "../graphics.hpp"
#include "button.hpp"
#include "label.hpp"
#include "tabbedarea.hpp"

namespace gcn
{
    Tab::Tab()
            :mHasMouse(false),
            mTabbedArea(NULL)
    {
        mLabel = new Label();
        mLabel->setPosition(4, 4);
        add(mLabel);

        addMouseListener(this);
    }

    Tab::~Tab()
    {
        delete mLabel;
    }

    void Tab::adjustSize()
    {
        setSize(mLabel->getWidth() + 8,
                mLabel->getHeight() + 8);

        if (mTabbedArea != NULL)
        {
            mTabbedArea->adjustTabPositions();
        }
    }

    void Tab::setTabbedArea(TabbedArea* tabbedArea)
    {
        mTabbedArea = tabbedArea;
    }

    TabbedArea* Tab::getTabbedArea()
    {
        return mTabbedArea;
    }

    void Tab::setCaption(const std::string& caption)
    {
        mLabel->setCaption(caption);
        mLabel->adjustSize();
        adjustSize();
    }

    const std::string& Tab::getCaption() const
    {
        return mLabel->getCaption();
    }

    void Tab::draw(Graphics *graphics)
    {
        const Color &faceColor = getBaseColor();
        const int alpha = getBaseColor().a;
        Color highlightColor = faceColor + 0x303030;
        highlightColor.a = alpha;
        Color shadowColor = faceColor - 0x303030;
        shadowColor.a = alpha;

        Color borderColor;
        Color baseColor;

        if ((mTabbedArea != NULL && mTabbedArea->isTabSelected(this))
            || mHasMouse)
        {
            // Draw a border.
            graphics->setColor(highlightColor);
            graphics->drawLine(0, 0, getWidth() - 1, 0);
            graphics->drawLine(0, 1, 0, getHeight() - 1);
            graphics->setColor(shadowColor);
            graphics->drawLine(getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);

            borderColor = highlightColor;
            baseColor = getBaseColor();
        }
        else
        {
            // Draw a border.
            graphics->setColor(shadowColor);
            graphics->drawLine(0, 0, getWidth() - 1, 0);
            graphics->drawLine(0, 1, 0, getHeight() - 1);
            graphics->drawLine(getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);

            baseColor = getBaseColor() - 0x151515;
            baseColor.a = alpha;
        }

        // Push a clip area so the other drawings don't need to worry
        // about the border.
        graphics->pushClipArea(Rectangle(1, 1, getWidth() - 2, getHeight() - 1));
        const Rectangle currentClipArea = graphics->getCurrentClipArea();

        graphics->setColor(baseColor);
        graphics->fillRectangle(Rectangle(0, 
                                          0, 
                                          currentClipArea.width, 
                                          currentClipArea.height));

        drawChildren(graphics);

        if (mTabbedArea != NULL
            && mTabbedArea->isFocused()
            && mTabbedArea->isTabSelected(this))
        {
            graphics->setColor(Color(0x000000));
            graphics->drawRectangle(Rectangle(2,
                                              2,
                                              currentClipArea.width - 4,
                                              currentClipArea.height - 4));
        }

        graphics->popClipArea();
    }

    void Tab::mouseEntered(MouseEvent& mouseEvent)
    {
        mHasMouse = true;
    }

    void Tab::mouseExited(MouseEvent& mouseEvent)
    {
        mHasMouse = false;
    }
}

