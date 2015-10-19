#include "genericinput.hpp"
#include "exception.hpp"

namespace gcn
{
    GenericInput::GenericInput()
    {

    }
    
    void GenericInput::pushKeyPressed(int unicode)
    {
        // TODO
    }
    
    void GenericInput::pushKeyReleased(int unicode)
    {
        // TODO
    }
        
    void GenericInput::pushMouseButtonPressed(int x, int y, int button)
    {
        MouseInput mouseInput;
        mouseInput.setX(x);
        mouseInput.setY(y);
        mouseInput.setButton(button);
        mouseInput.setType(MouseInput::PRESSED);

        mMouseInputQueue.push(mouseInput);
    }
    
    void GenericInput::pushMouseButtonReleased(int x, int y, int button)
    {
        MouseInput mouseInput;
        mouseInput.setX(x);
        mouseInput.setY(y);
        mouseInput.setButton(button);
        mouseInput.setType(MouseInput::RELEASED);

        mMouseInputQueue.push(mouseInput);
    }
    
    void GenericInput::pushMouseWheelMovedUp(int x, int y)
    {
        MouseInput mouseInput;
        mouseInput.setX(x);
        mouseInput.setY(y);
        mouseInput.setType(MouseInput::WHEEL_MOVED_UP);

        mMouseInputQueue.push(mouseInput);
    }
    
    void GenericInput::pushMouseWheelMovedDown(int x, int y)
    {
        MouseInput mouseInput;
        mouseInput.setX(x);
        mouseInput.setY(y);
        mouseInput.setType(MouseInput::WHEEL_MOVED_DOWN);

        mMouseInputQueue.push(mouseInput);
    }
    
    void GenericInput::pushMouseMoved(int x, int y)
    {
        MouseInput mouseInput;
        mouseInput.setX(x);
        mouseInput.setY(y);
        mouseInput.setType(MouseInput::MOVED);

        mMouseInputQueue.push(mouseInput);
    }

    bool GenericInput::isKeyQueueEmpty()
    {
        return mKeyInputQueue.empty();
    }

    KeyInput GenericInput::dequeueKeyInput()
    {
        KeyInput keyInput;

        if (mKeyInputQueue.empty())
        {
            throw GCN_EXCEPTION("The queue is empty.");
        }

        keyInput = mKeyInputQueue.front();
        mKeyInputQueue.pop();

        return keyInput;
    }
    
    bool GenericInput::isMouseQueueEmpty()
    {
        return mMouseInputQueue.empty();
    }

    MouseInput GenericInput::dequeueMouseInput()
    {
        MouseInput mouseInput;
        
        if (mMouseInputQueue.empty())
        {
            throw GCN_EXCEPTION("The queue is empty.");
        }
        
        mouseInput = mMouseInputQueue.front();
        mMouseInputQueue.pop();
        
        return mouseInput;        
    }
    
    void GenericInput::_pollInput()
    {
        // Does nothing.
    }
}
