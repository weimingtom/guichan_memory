#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "inputevent.hpp"
#include "platform.hpp"

namespace gcn
{
    class Gui;
    class Widget;

    class GCN_CORE_DECLSPEC MouseEvent: public InputEvent
    {
    public:
        MouseEvent(Widget* source,
                   bool isShiftPressed,
                   bool isControlPressed,
                   bool isAltPressed,
                   bool isMetaPressed,
                   unsigned int type,
                   unsigned int button,
                   int x,
                   int y,
                   int clickCount);
        unsigned int getButton() const;
        int getX() const;
        int getY() const;
        int getClickCount() const;

        unsigned int getType() const;

        enum
        {
            MOVED = 0,
            PRESSED,
            RELEASED,
            WHEEL_MOVED_DOWN,
            WHEEL_MOVED_UP,
            CLICKED,
            ENTERED,
            EXITED,
            DRAGGED

        };

        enum
        {
            EMPTY = 0,
            LEFT,
            RIGHT,
            MIDDLE
        };

    protected:
        unsigned int mType;
        unsigned int mButton;
        int mX;
        int mY;
        int mClickCount;
        friend class Gui;
    };
}
