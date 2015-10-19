#include "keyevent.hpp"

namespace gcn
{
    KeyEvent::KeyEvent(Widget* source,
                       bool isShiftPressed,
                       bool isControlPressed,
                       bool isAltPressed,
                       bool isMetaPressed,
                       unsigned int type,
                       bool isNumericPad,
                       const Key& key)
            :InputEvent(source,
                        isShiftPressed,
                        isControlPressed,
                        isAltPressed,
                        isMetaPressed),
             mType(type),
             mIsNumericPad(isNumericPad),
             mKey(key)
    {

    }

    KeyEvent::~KeyEvent()
    {

    }

    unsigned int KeyEvent::getType() const
    {
        return mType;
    }

    bool KeyEvent::isNumericPad() const
    {
        return mIsNumericPad;
    }

    const Key& KeyEvent::getKey() const
    {
        return mKey;
    }
}
