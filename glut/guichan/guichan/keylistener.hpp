#pragma once

#include "keyevent.hpp"
#include "platform.hpp"

namespace gcn
{
    class Key;
    class GCN_CORE_DECLSPEC KeyListener
    {
    public:
        virtual ~KeyListener() { }
        virtual void keyPressed(KeyEvent& keyEvent) { }
        virtual void keyReleased(KeyEvent& keyEvent) { }

    protected:
        KeyListener() { }
    };
}
