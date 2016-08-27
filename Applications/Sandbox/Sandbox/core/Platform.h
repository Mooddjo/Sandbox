#pragma once

#if defined(_WIN64)
    #ifdef SANDBOX_DLL
        #define DLL_SPEC __declspec(dllexport)
    #else
        #define DLL_SPEC __declspec(dllimport)
    #endif
#elif defined(__APPLE__)
//    #define __gl_h_
//    #define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
    #define DLL_SPEC
#else
#endif