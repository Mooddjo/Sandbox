#pragma once

#include "Platform.h"

namespace sandbox
{
	class DLL_SPEC SString
	{
	public:
		SString(const char* str);
		const char* getCString();
	private:

		struct StringPImpl;
		StringPImpl* m_stringPImpl;
	};
}