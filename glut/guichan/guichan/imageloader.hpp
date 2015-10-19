#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "platform.hpp"

namespace gcn
{
    class Image;
    
    class GCN_CORE_DECLSPEC ImageLoader
    {
    public:
        virtual ~ImageLoader() { }
        virtual Image* load(const std::string& filename, bool convertToDisplayFormat = true) = 0;
    };
}
