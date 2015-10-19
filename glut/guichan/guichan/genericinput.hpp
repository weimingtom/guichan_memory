#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <queue>
#include "input.hpp"
#include "keyinput.hpp"
#include "mouseinput.hpp"
#include "platform.hpp"

namespace gcn
{
    class Key;
    
    class GCN_CORE_DECLSPEC GenericInput: public Input
    {
    public:
        GenericInput();
        void pushKeyPressed(int unicode);
        void pushKeyReleased(int unicode);
        void pushMouseButtonPressed(int x, int y, int button);
        void pushMouseButtonReleased(int x, int y, int button);
        void pushMouseWheelMovedUp(int x, int y);
        void pushMouseWheelMovedDown(int x, int y);
        void pushMouseMoved(int x, int y);
        virtual bool isKeyQueueEmpty();
        virtual KeyInput dequeueKeyInput();
        virtual bool isMouseQueueEmpty();
        virtual MouseInput dequeueMouseInput();
        virtual void _pollInput();

    protected:
        std::queue<KeyInput> mKeyInputQueue;
        std::queue<MouseInput> mMouseInputQueue;
    };
}
