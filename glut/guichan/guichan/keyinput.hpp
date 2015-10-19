#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "key.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC KeyInput
    {
    public:
        KeyInput() { };
        KeyInput(const Key& key, unsigned int type);
        void setType(unsigned int type);
        int getType() const;
        void setKey(const Key& key);
        const Key& getKey() const;
        bool isShiftPressed() const;
        void setShiftPressed(bool pressed);
        bool isControlPressed() const;
        void setControlPressed(bool pressed);
        bool isAltPressed() const;
        void setAltPressed(bool pressed);
        bool isMetaPressed() const;
        void setMetaPressed(bool pressed);
        bool isNumericPad() const;
        void setNumericPad(bool numpad);

        enum
        {
            PRESSED = 0,
            RELEASED
        };

    protected:
        Key mKey;
        unsigned int mType;
        bool mShiftPressed;
        bool mControlPressed;
        bool mAltPressed;
        bool mMetaPressed;
        bool mNumericPad;
    };
}
