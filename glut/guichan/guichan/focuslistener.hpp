#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC FocusListener
    {
    public:
        virtual ~FocusListener() { }
        virtual void focusGained(const Event& event) { };
        virtual void focusLost(const Event& event) { };
    protected:
        FocusListener() { }
    };
}
