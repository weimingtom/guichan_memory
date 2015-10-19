#include "keyinput.hpp"

namespace gcn
{
    KeyInput::KeyInput(const Key& key, unsigned int type)
            :mKey(key),
             mType(type),
             mShiftPressed(false),
             mControlPressed(false),
             mAltPressed(false),
             mMetaPressed(false),
             mNumericPad(false)
    {

    }

    void KeyInput::setType(unsigned int type)
    {
        mType = type;
    }

    int KeyInput::getType() const
    {
        return mType;
    }

    void KeyInput::setKey(const Key& key)
    {
        mKey = key;
    }

    const Key& KeyInput::getKey() const
    {
        return mKey;
    }

    bool KeyInput::isShiftPressed() const
    {
        return mShiftPressed;
    }

    void KeyInput::setShiftPressed(bool pressed)
    {
        mShiftPressed = pressed;
    }

    bool KeyInput::isControlPressed() const
    {
        return mControlPressed;
    }

    void KeyInput::setControlPressed(bool pressed)
    {
        mControlPressed = pressed;
    }

    bool KeyInput::isAltPressed() const
    {
        return mAltPressed;
    }

    void KeyInput::setAltPressed(bool pressed)
    {
        mAltPressed = pressed;
    }

    bool KeyInput::isMetaPressed() const
    {
        return mMetaPressed;
    }

    void KeyInput::setMetaPressed(bool pressed)
    {
        mMetaPressed = pressed;
    }

    bool KeyInput::isNumericPad() const
    {
        return mNumericPad;
    }

    void KeyInput::setNumericPad(bool numpad)
    {
        mNumericPad = numpad;
    }
}

