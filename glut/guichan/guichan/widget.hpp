#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <list>
#include <string>

#include "color.hpp"
#include "rectangle.hpp"

namespace gcn
{
    class ActionListener;
    class BasicContainer;
    class DeathListener;
    class DefaultFont;
    class FocusHandler;
    class FocusListener;
    class Font;
    class Graphics;
    class KeyInput;
    class KeyListener;
    class MouseInput;
    class MouseListener;
    class WidgetListener;

    class GCN_CORE_DECLSPEC Widget
    {
    public:
        Widget();
        virtual ~Widget();
        virtual void draw(Graphics* graphics) = 0;
        virtual void drawFrame(Graphics* graphics);
        void setFrameSize(unsigned int frameSize);
        unsigned int getFrameSize() const;
        virtual void logic() { }
        virtual Widget* getParent() const;
        void setWidth(int width);
        int getWidth() const;
        void setHeight(int height);
        int getHeight() const;
        void setSize(int width, int height);
        void setX(int x);
        int getX() const;
        void setY(int y);
        int getY() const;
        void setPosition(int x, int y);
        void setDimension(const Rectangle& dimension);
        const Rectangle& getDimension() const;
        void setFocusable(bool focusable);
        bool isFocusable() const;
        virtual bool isFocused() const;
        void setEnabled(bool enabled);
        bool isEnabled() const;
        void setVisible(bool visible);
        bool isVisible() const;
        void setBaseColor(const Color& color);
        const Color& getBaseColor() const;
        void setForegroundColor(const Color& color);
        const Color& getForegroundColor() const;
        void setBackgroundColor(const Color& color);
        const Color& getBackgroundColor() const;
        void setSelectionColor(const Color& color);
        const Color& getSelectionColor() const;
        virtual void requestFocus();
        virtual void requestMoveToTop();
        virtual void requestMoveToBottom();
        virtual void _setFocusHandler(FocusHandler* focusHandler);
        virtual FocusHandler* _getFocusHandler();
        void addActionListener(ActionListener* actionListener);
        void removeActionListener(ActionListener* actionListener);
        void addDeathListener(DeathListener* deathListener);
        void removeDeathListener(DeathListener* deathListener);
        void addMouseListener(MouseListener* mouseListener);
        void removeMouseListener(MouseListener* mouseListener);
        void addKeyListener(KeyListener* keyListener);
        void removeKeyListener(KeyListener* keyListener);
        void addFocusListener(FocusListener* focusListener);
        void removeFocusListener(FocusListener* focusListener);
        void addWidgetListener(WidgetListener* widgetListener);
        void removeWidgetListener(WidgetListener* widgetListener);
        void setActionEventId(const std::string& actionEventId);
        const std::string& getActionEventId() const;
        virtual void getAbsolutePosition(int& x, int& y) const;
        virtual void _setParent(Widget* parent);
        Font *getFont() const;
        static void setGlobalFont(Font* font);
        void setFont(Font* font);
        virtual void fontChanged() { }
        static bool widgetExists(const Widget* widget);
        bool isTabInEnabled() const;
        void setTabInEnabled(bool enabled);
        bool isTabOutEnabled() const;
        void setTabOutEnabled(bool enabled);
        virtual void requestModalFocus();
        virtual void requestModalMouseInputFocus();
        virtual void releaseModalFocus();
        virtual void releaseModalMouseInputFocus();
        virtual bool isModalFocused() const;
        virtual bool isModalMouseInputFocused() const;
        virtual Widget *getWidgetAt(int x, int y);
        virtual const std::list<MouseListener*>& _getMouseListeners();
        virtual const std::list<KeyListener*>& _getKeyListeners();
        virtual const std::list<FocusListener*>& _getFocusListeners();
        virtual Rectangle getChildrenArea();
        virtual FocusHandler* _getInternalFocusHandler();
        void setInternalFocusHandler(FocusHandler* internalFocusHandler);
        virtual void moveToTop(Widget* widget) { };
        virtual void moveToBottom(Widget* widget) { };
        virtual void focusNext() { };
        virtual void focusPrevious() { };
        virtual void showWidgetPart(Widget* widget, Rectangle area) { };
        void setId(const std::string& id);
        const std::string& getId();
        virtual void showPart(Rectangle rectangle);

    protected:
        void distributeActionEvent();
        void distributeResizedEvent();
        void distributeMovedEvent();
        void distributeHiddenEvent();
        void distributeShownEvent();

        typedef std::list<MouseListener*> MouseListenerList;
        typedef MouseListenerList::iterator MouseListenerIterator;
        
        MouseListenerList mMouseListeners;

        typedef std::list<KeyListener*> KeyListenerList;

        KeyListenerList mKeyListeners;

        typedef KeyListenerList::iterator KeyListenerIterator;
        typedef std::list<ActionListener*> ActionListenerList;

        ActionListenerList mActionListeners;

        typedef ActionListenerList::iterator ActionListenerIterator;
        typedef std::list<DeathListener*> DeathListenerList;

        DeathListenerList mDeathListeners;

        typedef DeathListenerList::iterator DeathListenerIterator;
        typedef std::list<FocusListener*> FocusListenerList;

        FocusListenerList mFocusListeners;

        typedef FocusListenerList::iterator FocusListenerIterator;
        typedef std::list<WidgetListener*> WidgetListenerList;

        WidgetListenerList mWidgetListeners;

        typedef WidgetListenerList::iterator WidgetListenerIterator;

        Color mForegroundColor;
        Color mBackgroundColor;
        Color mBaseColor;
        Color mSelectionColor;
        FocusHandler* mFocusHandler;
        FocusHandler* mInternalFocusHandler;
        Widget* mParent;
        Rectangle mDimension;
        unsigned int mFrameSize;
        std::string mActionEventId;
        bool mFocusable;
        bool mVisible;
        bool mTabIn;
        bool mTabOut;
        bool mEnabled;
        std::string mId;
        Font* mCurrentFont;
        static DefaultFont mDefaultFont;
        static Font* mGlobalFont;
        static std::list<Widget*> mWidgets;
    };
}
