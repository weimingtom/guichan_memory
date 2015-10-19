#include "event.hpp"

namespace gcn
{
    Event::Event(Widget* source)
            :mSource(source)
    {

    }

    Event::~Event()
    {

    }

    Widget* Event::getSource() const
    {
        return mSource;
    }
}

