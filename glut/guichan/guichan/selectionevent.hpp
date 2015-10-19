#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class Widget;

    class GCN_CORE_DECLSPEC SelectionEvent: public Event
    {
    public:
        SelectionEvent(Widget* source);
        virtual ~SelectionEvent();
    };
}
