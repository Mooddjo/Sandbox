#pragma once

#ifdef SANDBOX_DLL
#define DLL_SPEC __declspec(dllexport)
#else
#define DLL_SPEC __declspec(dllimport)
#endif