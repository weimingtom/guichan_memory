#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"

#if defined (_WIN32) && defined(DELETE)
#undef DELETE
#endif

namespace gcn
{
    class GCN_CORE_DECLSPEC Key
    {
    public:
		Key(int value = 0);
		bool isCharacter() const;
		bool isNumber() const;
		bool isLetter() const;
		int getValue() const;
		bool operator==(const Key& key) const;
		bool operator!=(const Key& key) const;
		
		enum
        {
            SPACE              = ' ',
            TAB                = '\t',
            ENTER              = '\n',
            LEFT_ALT           = 1000,
            RIGHT_ALT,
            LEFT_SHIFT,
            RIGHT_SHIFT,
            LEFT_CONTROL,
            RIGHT_CONTROL,
            LEFT_META,
            RIGHT_META,
            LEFT_SUPER,
            RIGHT_SUPER,
            INSERT,
            HOME,
            PAGE_UP,
            DELETE,
            END,
            PAGE_DOWN,
            ESCAPE,
            CAPS_LOCK,
            BACKSPACE,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            PRINT_SCREEN,
            SCROLL_LOCK,
            PAUSE,
            NUM_LOCK,
            ALT_GR,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

    protected:
        int mValue;
    };
}
