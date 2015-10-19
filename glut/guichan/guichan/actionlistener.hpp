#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>

#include "actionevent.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC ActionListener
    {
    public:
		virtual ~ActionListener() { }
		virtual void action(const ActionEvent& actionEvent) = 0;
		
    protected:
        ActionListener() { }
    };
}
