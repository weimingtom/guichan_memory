#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <list>
#include "deathlistener.hpp"
#include "platform.hpp"
#include "widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC BasicContainer : public Widget, public DeathListener
    {
    public:
        virtual ~BasicContainer();
        virtual void showWidgetPart(Widget* widget, Rectangle area);
        virtual void moveToTop(Widget* widget);
        virtual void moveToBottom(Widget* widget);
        virtual Rectangle getChildrenArea();
        virtual void focusNext();
        virtual void focusPrevious();
        virtual void logic();
        virtual void _setFocusHandler(FocusHandler* focusHandler);
        void setInternalFocusHandler(FocusHandler* focusHandler);
        virtual Widget *getWidgetAt(int x, int y);
        virtual void death(const Event& event);
    protected:
        void add(Widget* widget);
        virtual void remove(Widget* widget);
		virtual void clear();
        virtual void drawChildren(Graphics* graphics);
		virtual void logicChildren();
		virtual Widget* findWidgetById(const std::string& id);
		
		typedef std::list<Widget *> WidgetList;
		typedef WidgetList::iterator WidgetListIterator;
		typedef WidgetList::reverse_iterator WidgetListReverseIterator;
		
		WidgetList mWidgets;
    };
}
