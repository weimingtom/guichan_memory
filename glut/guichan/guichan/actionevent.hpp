#pragma once

#include "event.hpp"
#include "platform.hpp"

#include <string>

namespace gcn
{
    class Widget;

    class GCN_CORE_DECLSPEC ActionEvent: public Event
    {
    public:
        ActionEvent(Widget* source, const std::string& id);
        virtual ~ActionEvent();
        const std::string& getId() const;
        
    protected:
        std::string mId;
    };
}
