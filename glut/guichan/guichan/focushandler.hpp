#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <vector>
#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class Widget;

    class GCN_CORE_DECLSPEC FocusHandler
    {
    public:
        FocusHandler();
        virtual ~FocusHandler() { };
        virtual void requestFocus(Widget* widget);
        virtual void requestModalFocus(Widget* widget);
        virtual void requestModalMouseInputFocus(Widget* widget);
        virtual void releaseModalFocus(Widget* widget);
        virtual void releaseModalMouseInputFocus(Widget* widget);
        virtual bool isFocused(const Widget* widget) const;
		virtual Widget* getFocused() const;
		virtual Widget* getModalFocused() const;
		virtual Widget* getModalMouseInputFocused() const;
        virtual void focusNext();
        virtual void focusPrevious();
        virtual void add(Widget* widget);
        virtual void remove(Widget* widget);
        virtual void focusNone();
        virtual void tabNext();
        virtual void tabPrevious();
        virtual Widget* getDraggedWidget();
        virtual void setDraggedWidget(Widget* draggedWidget);
        virtual Widget* getLastWidgetWithMouse();
        virtual void setLastWidgetWithMouse(Widget* lastWidgetWithMouse);
        virtual Widget* getLastWidgetWithModalFocus();
        virtual void setLastWidgetWithModalFocus(Widget* lastWidgetWithModalFocus);
        virtual Widget* getLastWidgetWithModalMouseInputFocus();
        virtual void setLastWidgetWithModalMouseInputFocus(Widget* lastWidgetWithModalMouseInputFocus);
        virtual Widget* getLastWidgetPressed();
        virtual void setLastWidgetPressed(Widget* lastWidgetPressed);

    protected:
        virtual void distributeFocusLostEvent(const Event& focusEvent);
        virtual void distributeFocusGainedEvent(const Event& focusEvent);
        
        typedef std::vector<Widget*> WidgetVector;
        typedef WidgetVector::iterator WidgetIterator;
        WidgetVector mWidgets;
        Widget* mFocusedWidget;
        Widget* mModalFocusedWidget;
        Widget* mModalMouseInputFocusedWidget;
        Widget* mDraggedWidget;
        Widget* mLastWidgetWithMouse;
        Widget* mLastWidgetWithModalFocus;
        Widget* mLastWidgetWithModalMouseInputFocus;
        Widget* mLastWidgetPressed;
    };
}
