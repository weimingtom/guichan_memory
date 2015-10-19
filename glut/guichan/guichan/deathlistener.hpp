#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>
#include "event.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC DeathListener
    {
    public:
        virtual ~DeathListener() { }
        virtual void death(const Event& event) = 0;
    
    protected:
        DeathListener() { }
    };
}
