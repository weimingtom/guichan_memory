#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC WidgetListener
    {
    public:
        virtual ~WidgetListener() { }
        virtual void widgetResized(const Event& event) { }
        virtual void widgetMoved(const Event& event) { }
        virtual void widgetHidden(const Event& event) { }
        virtual void widgetShown(const Event& event) { }

    protected:
        WidgetListener() { }

    };
}
