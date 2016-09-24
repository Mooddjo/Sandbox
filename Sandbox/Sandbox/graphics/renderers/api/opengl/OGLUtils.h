#pragma once

#include "gl/glew.h"
#include "Platform.h"

namespace sandbox
{
	class DLL_SPEC OGLUtils
	{
	public:
		static void CheckOpenGLError(const char* stmt, const char* fname, int line);
	};
}

#ifdef _DEBUG
#define GL_CHECK(stmt){\
            stmt;\
            sandbox::OGLUtils::CheckOpenGLError(#stmt, __FILE__, __LINE__);}
#else
#define GL_CHECK(stmt) stmt
#endif