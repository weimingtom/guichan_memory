#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <list>
#include <deque>
#include "keyevent.hpp"
#include "mouseevent.hpp"
#include "mouseinput.hpp"
#include "platform.hpp"

namespace gcn
{
    class FocusHandler;
    class Graphics;
    class Input;
    class KeyListener;
    class Widget;

    class GCN_CORE_DECLSPEC Gui
    {
    public:
        Gui();
        virtual ~Gui();
        virtual void setTop(Widget* top);
        virtual Widget* getTop() const;
        virtual void setGraphics(Graphics* graphics);
        virtual Graphics* getGraphics() const;
        virtual void setInput(Input* input);
        virtual Input* getInput() const;
        virtual void logic();
        virtual void draw();
        virtual void focusNone();
        virtual void setTabbingEnabled(bool tabbing);
        virtual bool isTabbingEnabled();
        virtual void addGlobalKeyListener(KeyListener* keyListener);
        virtual void removeGlobalKeyListener(KeyListener* keyListener);

    protected:
        virtual void handleMouseInput();
        virtual void handleKeyInput();
        virtual void handleMouseMoved(const MouseInput& mouseInput);
        virtual void handleMousePressed(const MouseInput& mouseInput);
        virtual void handleMouseWheelMovedDown(const MouseInput& mouseInput);
        virtual void handleMouseWheelMovedUp(const MouseInput& mouseInput);
        virtual void handleMouseReleased(const MouseInput& mouseInput);
        virtual void handleModalFocus();
        virtual void handleModalMouseInputFocus();
        virtual void handleModalFocusGained();
        virtual void handleModalFocusReleased();
        virtual void distributeMouseEvent(Widget* source,
                                          int type,
                                          int button,
                                          int x,
                                          int y,
                                          bool force = false,
                                          bool toSourceOnly = false);
        virtual void distributeKeyEvent(KeyEvent& keyEvent);
        virtual void distributeKeyEventToGlobalKeyListeners(KeyEvent& keyEvent);
        virtual Widget* getWidgetAt(int x, int y);
        virtual Widget* getMouseEventSource(int x, int y);
        virtual Widget* getKeyEventSource();

        Widget* mTop;
        Graphics* mGraphics;
        Input* mInput;
        FocusHandler* mFocusHandler;
        bool mTabbing;

        typedef std::list<KeyListener*> KeyListenerList;
        typedef KeyListenerList::iterator KeyListenerListIterator;

        KeyListenerList mKeyListeners;
        bool mShiftPressed;
        bool mMetaPressed;
        bool mControlPressed;
        bool mAltPressed;
        unsigned int mLastMousePressButton;
        int mLastMousePressTimeStamp;
        int mLastMouseX;
        int mLastMouseY;
        int mClickCount;
        int mLastMouseDragButton;
        std::deque<Widget*> mWidgetWithMouseQueue;
    };
}
