#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "platform.hpp"

namespace gcn
{
    class Widget;

    /**
     * Base class for all events. All events in Guichan should
     * inherit from this class.
     *
     * @author Olof Naessén
     * @since 0.6.0
     */
    class GCN_CORE_DECLSPEC Event
    {
    public:
        Event(Widget* source);
        virtual ~Event();
        Widget* getSource() const;

    protected:
        Widget* mSource;
    };
}
