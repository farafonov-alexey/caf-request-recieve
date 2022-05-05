#pragma once

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64) ||  \
    defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) ||      \
    defined(_WINDOWS) || defined(_WIN32_WINCE)
#if defined(LIB_LIBRARY)
#define LIB_SHARED_EXPORT __declspec(dllexport)
#else
#define LIB_SHARED_EXPORT __declspec(dllimport)
#endif
#define LIB_SHARED_CCA __cdecl
#elif defined(__linux) || defined(__linux__) || defined(linux) ||              \
    defined(ANDROID)
#if __GNUC__ >= 4
#define LIB_SHARED_EXPORT __attribute__((visibility("default")))
#else
#define LIB_SHARED_EXPORT
#endif
#define LIB_SHARED_CCA
#elif defined(__APPLE__)
#define LIB_SHARED_EXPORT __attribute__((visibility("default")))
#define LIB_SHARED_CCA
#else
#define LIB_SHARED_EXPORT
#define LIB_SHARED_CCA __attribute__((cdecl))
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_create();
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_destroy();
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_do_stuff(int param_id, uint value);