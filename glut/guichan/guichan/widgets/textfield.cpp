#include "textfield.hpp"
#include "../font.hpp"
#include "../graphics.hpp"
#include "../key.hpp"
#include "../mouseinput.hpp"

namespace gcn
{
    TextField::TextField()
    {
        mCaretPosition = 0;
        mXScroll = 0;

        setFocusable(true);

        addMouseListener(this);
        addKeyListener(this);
    }

    TextField::TextField(const std::string& text)
    {
        mCaretPosition = 0;
        mXScroll = 0;

        mText = text;
        adjustSize();

        setFocusable(true);

        addMouseListener(this);
        addKeyListener(this);
    }

    void TextField::setText(const std::string& text)
    {
        if(text.size() < mCaretPosition )
        {
            mCaretPosition = text.size();
        }

        mText = text;
    }

    void TextField::draw(Graphics* graphics)
    {
        Color faceColor = getBaseColor();
        Color highlightColor, shadowColor;
        int alpha = getBaseColor().a;
        highlightColor = faceColor + 0x303030;
        highlightColor.a = alpha;
        shadowColor = faceColor - 0x303030;
        shadowColor.a = alpha;

        // Draw a border.
        graphics->setColor(shadowColor);
        graphics->drawLine(0, 0, getWidth() - 1, 0);
        graphics->drawLine(0, 1, 0, getHeight() - 2);
        graphics->setColor(highlightColor);
        graphics->drawLine(getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);
        graphics->drawLine(0, getHeight() - 1, getWidth() - 1, getHeight() - 1);

        // Push a clip area so the other drawings don't need to worry
        // about the border.
        graphics->pushClipArea(Rectangle(1, 1, getWidth() - 2, getHeight() - 2));

        graphics->setColor(getBackgroundColor());
        graphics->fillRectangle(Rectangle(0, 0, getWidth(), getHeight()));

        if (isFocused())
        {
            graphics->setColor(getSelectionColor());
            graphics->drawRectangle(Rectangle(0, 0, getWidth() - 2, getHeight() - 2));
            graphics->drawRectangle(Rectangle(1, 1, getWidth() - 4, getHeight() - 4));
        }

        if (isFocused())
        {
            drawCaret(graphics, getFont()->getWidth(mText.substr(0, mCaretPosition)) - mXScroll);
        }

        graphics->setColor(getForegroundColor());
        graphics->setFont(getFont());
        graphics->drawText(mText, 3 - mXScroll, 1);

        graphics->popClipArea();
    }

    void TextField::drawCaret(Graphics* graphics, int x)
    {
        // Check the current clip area as a clip area with a different
        // size than the widget might have been pushed (which is the
        // case in the draw method when we push a clip area after we have
        // drawn a border).
        const Rectangle clipArea = graphics->getCurrentClipArea();

        graphics->setColor(getForegroundColor());
        graphics->drawLine(x, clipArea.height - 2, x, 1);
	}

    void TextField::mousePressed(MouseEvent& mouseEvent)
    {
        if (mouseEvent.getButton() == MouseEvent::LEFT)
        {
            mCaretPosition = getFont()->getStringIndexAt(mText, mouseEvent.getX() + mXScroll);
            fixScroll();
        }
    }

    void TextField::mouseDragged(MouseEvent& mouseEvent)
    {
        mouseEvent.consume();
    }
    
    void TextField::keyPressed(KeyEvent& keyEvent)
    {
        Key key = keyEvent.getKey();

        if (key.getValue() == Key::LEFT && mCaretPosition > 0)
        {
            --mCaretPosition;
        }

        else if (key.getValue() == Key::RIGHT && mCaretPosition < mText.size())
        {
            ++mCaretPosition;
        }

        else if (key.getValue() == Key::DELETE && mCaretPosition < mText.size())
        {
            mText.erase(mCaretPosition, 1);
        }

        else if (key.getValue() == Key::BACKSPACE && mCaretPosition > 0)
        {
            mText.erase(mCaretPosition - 1, 1);
            --mCaretPosition;
        }

        else if (key.getValue() == Key::ENTER)
        {
            distributeActionEvent();
        }

        else if (key.getValue() == Key::HOME)
        {
            mCaretPosition = 0;
        }

        else if (key.getValue() == Key::END)
        {
            mCaretPosition = mText.size();
        }

        else if (key.isCharacter()
                 && key.getValue() != Key::TAB)
        {
            mText.insert(mCaretPosition, std::string(1,(char)key.getValue()));
            ++mCaretPosition;
        }

        if (key.getValue() != Key::TAB)
        {
            keyEvent.consume();
        }
        
        fixScroll();
    }

    void TextField::adjustSize()
    {
        setWidth(getFont()->getWidth(mText) + 7);
        adjustHeight();

        fixScroll();
    }

    void TextField::adjustHeight()
    {
        setHeight(getFont()->getHeight() + 4);
    }

    void TextField::fixScroll()
    {
        if (isFocused())
        {
            int caretX = getFont()->getWidth(mText.substr(0, mCaretPosition));

            if (caretX - mXScroll >= getWidth() - 4)
            {
                mXScroll = caretX - getWidth() + 4;
            }
            else if (caretX - mXScroll <= 0)
            {
                mXScroll = caretX - getWidth() / 2;

                if (mXScroll < 0)
                {
                    mXScroll = 0;
                }
            }
        }
    }

    void TextField::setCaretPosition(unsigned int position)
    {
        if (position > mText.size())
        {
            mCaretPosition = mText.size();
        }
        else
        {
            mCaretPosition = position;
        }

        fixScroll();
    }

    unsigned int TextField::getCaretPosition() const
    {
        return mCaretPosition;
    }

    const std::string& TextField::getText() const
    {
        return mText;
    }

    void TextField::fontChanged()
    {
        fixScroll();
    }
}
