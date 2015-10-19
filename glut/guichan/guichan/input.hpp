#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"

namespace gcn
{
    class KeyInput;
    class MouseInput;

    class GCN_CORE_DECLSPEC Input
    {
    public:
        virtual ~Input(){ }
        virtual bool isKeyQueueEmpty() = 0;
        virtual KeyInput dequeueKeyInput() = 0;
        virtual bool isMouseQueueEmpty() = 0;
        virtual MouseInput dequeueMouseInput() = 0;
        virtual void _pollInput() = 0;
    };
}
