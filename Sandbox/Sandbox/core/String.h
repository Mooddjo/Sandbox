#pragma once

#include "Platform.h"

namespace sandbox
{
	class DLL_SPEC String
	{
	public:
		String(const char* str);
		const char* getCString();
	private:

		struct StringPImpl;
		StringPImpl* m_stringPImpl;
	};
}