#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC ListModel
    {
    public:
        virtual ~ListModel() { }
        virtual int getNumberOfElements() = 0;
        virtual std::string getElementAt(int i) = 0;
    };
}
