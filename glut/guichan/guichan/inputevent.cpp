#include "inputevent.hpp"

namespace gcn
{
    InputEvent::InputEvent(Widget* source,
                           bool isShiftPressed,
                           bool isControlPressed,
                           bool isAltPressed,
                           bool isMetaPressed)
            :Event(source),
             mShiftPressed(isShiftPressed),
             mControlPressed(isControlPressed),
             mAltPressed(isAltPressed),
             mMetaPressed(isMetaPressed),
             mIsConsumed(false)
    {

    }

    bool InputEvent::isShiftPressed() const
    {
        return mShiftPressed;
    }

    bool InputEvent::isControlPressed() const
    {
        return mControlPressed;
    }

    bool InputEvent::isAltPressed() const
    {
        return mAltPressed;
    }

    bool InputEvent::isMetaPressed() const
    {
        return mMetaPressed;
    }

    void InputEvent::consume()
    {
        mIsConsumed = true;
    }

    bool InputEvent::isConsumed() const
    {
        return mIsConsumed;
    }
}
