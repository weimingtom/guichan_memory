#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>
#include "../basiccontainer.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC ScrollArea:
        public BasicContainer,
        public MouseListener
    {
    public:
        enum ScrollPolicy
        {
            SHOW_ALWAYS = 0,
            SHOW_NEVER,
            SHOW_AUTO
        };

        ScrollArea();
        ScrollArea(Widget *content);
        ScrollArea(Widget *content, 
                   ScrollPolicy hPolicy, 
                   ScrollPolicy vPolicy);
        virtual ~ScrollArea();
        void setContent(Widget* widget);
        Widget* getContent();
        void setHorizontalScrollPolicy(ScrollPolicy hPolicy);
        ScrollPolicy getHorizontalScrollPolicy() const;
        void setVerticalScrollPolicy(ScrollPolicy vPolicy);
        ScrollPolicy getVerticalScrollPolicy() const;
        void setScrollPolicy(ScrollPolicy hPolicy, ScrollPolicy vPolicy);
        void setVerticalScrollAmount(int vScroll);
        int getVerticalScrollAmount() const;
        void setHorizontalScrollAmount(int hScroll);
        int getHorizontalScrollAmount() const;
        void setScrollAmount(int hScroll, int vScroll);
        int getHorizontalMaxScroll();
        int getVerticalMaxScroll();
        void setScrollbarWidth(int width);
        int getScrollbarWidth() const;
        void setLeftButtonScrollAmount(int amount);
        void setRightButtonScrollAmount(int amount);
        void setUpButtonScrollAmount(int amount);
        void setDownButtonScrollAmount(int amount);
        int getLeftButtonScrollAmount() const;
        int getRightButtonScrollAmount() const;
        int getUpButtonScrollAmount() const;
        int getDownButtonScrollAmount() const;
        void setOpaque(bool opaque);
        bool isOpaque() const;
        virtual void showWidgetPart(Widget* widget, Rectangle area);
        virtual Rectangle getChildrenArea();
        virtual Widget *getWidgetAt(int x, int y);
        virtual void draw(Graphics *graphics);
        virtual void logic();
        void setWidth(int width);
        void setHeight(int height);
        void setDimension(const Rectangle& dimension);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseReleased(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedUp(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent);

    protected:
        virtual void drawBackground(Graphics *graphics);
        virtual void drawUpButton(Graphics *graphics);
        virtual void drawDownButton(Graphics *graphics);
        virtual void drawLeftButton(Graphics *graphics);
        virtual void drawRightButton(Graphics *graphics);
        virtual void drawVBar(Graphics* graphics);
        virtual void drawHBar(Graphics* graphics);
        virtual void drawVMarker(Graphics* graphics);
        virtual void drawHMarker(Graphics* graphics);
        virtual void checkPolicies();
        Rectangle getUpButtonDimension();
        Rectangle getDownButtonDimension();
        Rectangle getLeftButtonDimension();
        Rectangle getRightButtonDimension();
        Rectangle getVerticalBarDimension();
        Rectangle getHorizontalBarDimension();
        Rectangle getVerticalMarkerDimension();
        Rectangle getHorizontalMarkerDimension();
        
        int mVScroll;
        int mHScroll;
        int mScrollbarWidth;
        ScrollPolicy mHPolicy;
        ScrollPolicy mVPolicy;
        bool mVBarVisible;
        bool mHBarVisible;
        bool mUpButtonPressed;
        bool mDownButtonPressed;
        bool mLeftButtonPressed;
        bool mRightButtonPressed;
        int mUpButtonScrollAmount;
        int mDownButtonScrollAmount;
        int mLeftButtonScrollAmount;
        int mRightButtonScrollAmount;
        bool mIsVerticalMarkerDragged;
        bool mIsHorizontalMarkerDragged;
        int mHorizontalMarkerDragOffset;
        int mVerticalMarkerDragOffset;
        bool mOpaque;
    };
}
