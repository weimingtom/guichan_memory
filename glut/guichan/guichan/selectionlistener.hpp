#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>

#include "selectionevent.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC SelectionListener
    {
    public:
        virtual ~SelectionListener() { }
        virtual void valueChanged(const SelectionEvent& event) { };

    protected:
        SelectionListener() { }

    };
}
