#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include <string>
#include "platform.hpp"

#ifndef __FUNCTION__
#define __FUNCTION__ "?"
#endif

#define GCN_EXCEPTION(mess) gcn::Exception(mess,   \
                            __FUNCTION__,          \
                            __FILE__,              \
                            __LINE__)

namespace gcn
{
    class GCN_CORE_DECLSPEC Exception
    {
    public:
        Exception();
        Exception(const std::string& message);
        Exception(const std::string& message,
                  const std::string& function,
                  const std::string& filename,
                  unsigned int line);
        const std::string& getFunction() const;
        const std::string& getMessage() const;
        const std::string& getFilename() const;
        unsigned int getLine() const;
		
    protected:
        std::string mFunction;
        std::string mMessage;
        std::string mFilename;
        unsigned int mLine;
    };
}

