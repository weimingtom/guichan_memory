#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "opengl/openglgraphics.hpp"
#include "opengl/openglimage.hpp"
#include "platform.hpp"

extern "C"
{
    GCN_EXTENSION_DECLSPEC extern void gcnOpenGL();
}
