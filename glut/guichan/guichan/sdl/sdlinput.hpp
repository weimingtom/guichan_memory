#pragma once

#include <queue>
#include <SDL.h>
#include "../input.hpp"
#include "../keyinput.hpp"
#include "../mouseinput.hpp"
#include "../platform.hpp"

namespace gcn
{
    class Key;

    class GCN_EXTENSION_DECLSPEC SDLInput : public Input
    {
    public:
        SDLInput();
        virtual void pushInput(SDL_Event event);
        virtual void _pollInput() { }
        virtual bool isKeyQueueEmpty();
        virtual KeyInput dequeueKeyInput();
        virtual bool isMouseQueueEmpty();
        virtual MouseInput dequeueMouseInput();

    protected:
        int convertMouseButton(int button);
        int convertSDLEventToGuichanKeyValue(SDL_Event event);
        
        std::queue<KeyInput> mKeyInputQueue;
        std::queue<MouseInput> mMouseInputQueue;
        bool mMouseDown;
        bool mMouseInWindow;
    };
}
