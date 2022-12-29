#pragma once

#if defined _MSC_VER

    #define B_OS_WINDOWS

    #define UNICODE
    #define _UNICODE

    #ifdef BUILD_SHARED_LIBS
        #define UTILITY_EXPORT __declspec(dllexport)
        #define UTILITY_IMPORT __declspec(dllimport)
    #else
        #define UTILITY_EXPORT
        #define UTILITY_IMPORT
    #endif

    #define UTILITY_LOCAL

#elif defined __APPLE__

    #define B_OS_MACOS

    #ifdef BUILD_SHARED_LIBS
        #define UTILITY_EXPORT __attribute__ ((visibility ("default")))
        #define UTILITY_IMPORT
        #define UTILITY_LOCAL __attribute__ ((visibility ("hidden")))
    #else
        #define UTILITY_EXPORT
        #define UTILITY_IMPORT
        #define UTILITY_LOCAL
    #endif

#else

#define B_OS_LINUX

    #ifdef BUILD_SHARED_LIBS
        #define UTILITY_EXPORT __attribute__ ((visibility ("default")))
        #define UTILITY_IMPORT
        #define UTILITY_LOCAL __attribute__ ((visibility ("hidden")))
    #else
        #define UTILITY_EXPORT
        #define UTILITY_IMPORT
        #define UTILITY_LOCAL
    #endif

#endif