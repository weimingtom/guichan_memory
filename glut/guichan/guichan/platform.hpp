#pragma once

#if defined (__MINGW32__) && defined(GUICHAN_BUILD)
#define GCN_CORE_DECLSPEC __declspec(dllexport)

#elif defined (__MINGW32__) && defined(GUICHAN_EXTENSION_BUILD)
#define GCN_EXTENSION_DECLSPEC __declspec(dllexport)
#define GCN_CORE_DECLSPEC __declspec(dllimport)

#elif defined (__MINGW32__) && defined(GUICHAN_DLL_IMPORT)
#define GCN_CORE_DECLSPEC __declspec(dllimport)
#define GCN_EXTENSION_DECLSPEC __declspec(dllimport)

#elif defined(_MSC_VER) && defined(GUICHAN_BUILD)
#define GCN_CORE_DECLSPEC _declspec(dllexport)

#elif defined(_MSC_VER) && defined(GUICHAN_EXTENSION_BUILD)
#define GCN_CORE_DECLSPEC _declspec(dllimport)
#define GCN_EXTENSION_DECLSPEC _declspec(dllexport)

#endif

#ifndef GCN_CORE_DECLSPEC
#define GCN_CORE_DECLSPEC
#endif

#ifndef GCN_EXTENSION_DECLSPEC
#define GCN_EXTENSION_DECLSPEC
#endif

#ifndef NULL
#define NULL 0
#endif

#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif
