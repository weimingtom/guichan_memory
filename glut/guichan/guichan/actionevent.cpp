#include "actionevent.hpp"

namespace gcn
{
    ActionEvent::ActionEvent(Widget* source, const std::string& id)
            :Event(source),
             mId(id)
    {

    }

    ActionEvent::~ActionEvent()
    {

    }

    const std::string& ActionEvent::getId() const
    {
        return mId;
    }
}

