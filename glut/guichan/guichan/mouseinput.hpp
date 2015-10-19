#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"

namespace gcn
{
	class GCN_CORE_DECLSPEC MouseInput
    {
    public:
		MouseInput() { };
		MouseInput(unsigned int button,
                   unsigned int type,
                   int x,
                   int y,
                   int timeStamp);
		void setType(unsigned int type);
		unsigned int getType() const;
		void setButton(unsigned int button);
        unsigned int getButton() const;
        void setTimeStamp(int timeStamp);
        int getTimeStamp() const;
        void setX(int x);
        int getX() const;
        void setY(int y);
        int getY() const;
        
        enum
        {
            MOVED = 0,
            PRESSED,
            RELEASED,
            WHEEL_MOVED_DOWN,
            WHEEL_MOVED_UP
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
        int mTimeStamp;
        int mX;
        int mY;
    };
}
