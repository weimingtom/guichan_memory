#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "inputevent.hpp"
#include "key.hpp"
#include "platform.hpp"

namespace gcn
{
    class Widget;

    class GCN_CORE_DECLSPEC KeyEvent: public InputEvent
    {
    public:
        enum
        {
            PRESSED = 0,
            RELEASED
        };

        KeyEvent(Widget* source,
                 bool isShiftPressed,
                 bool isControlPressed,
                 bool isAltPressed,
                 bool isMetaPressed,
                 unsigned int type,
                 bool isNumericPad,
                 const Key& key);
        virtual ~KeyEvent();
        unsigned int getType() const;
        bool isNumericPad() const;
        const Key& getKey() const;

    protected:
        unsigned int mType;
        bool mIsNumericPad;
        Key mKey;
    };
}
