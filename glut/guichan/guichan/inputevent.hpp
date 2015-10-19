#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC InputEvent: public Event
    {
    public:
        InputEvent(Widget* source,
                   bool isShiftPressed,
                   bool isControlPressed,
                   bool isAltPressed,
                   bool isMetaPressed);
        bool isShiftPressed() const;
        bool isControlPressed() const;
        bool isAltPressed() const;
        bool isMetaPressed() const;
        void consume();
        bool isConsumed() const;

    protected:
        bool mShiftPressed;
        bool mControlPressed;
        bool mAltPressed;
        bool mMetaPressed;
        bool mIsConsumed;
    };
}
