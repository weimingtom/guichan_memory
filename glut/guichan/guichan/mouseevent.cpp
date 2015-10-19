#include "mouseevent.hpp"

namespace gcn
{
    MouseEvent::MouseEvent(Widget* source,
                           bool isShiftPressed,
                           bool isControlPressed,
                           bool isAltPressed,
                           bool isMetaPressed,
                           unsigned int type,
                           unsigned int button,
                           int x,
                           int y,
                           int clickCount)
            :InputEvent(source,
                        isShiftPressed,
                        isControlPressed,
                        isAltPressed,
                        isMetaPressed),
             mType(type),
             mButton(button),
             mX(x),
             mY(y),
             mClickCount(clickCount)
    {

    }

    unsigned int MouseEvent::getButton() const
    {
        return mButton;
    }

    int MouseEvent::getX() const
    {
        return mX;
    }

    int MouseEvent::getY() const
    {
        return mY;
    }

    int MouseEvent::getClickCount() const
    {
        return mClickCount;
    }

    unsigned int MouseEvent::getType() const
    {
        return mType;
    }
}
