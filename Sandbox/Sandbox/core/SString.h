#pragma once

#include "Platform.h"

namespace sandbox
{
	/// @brief	Class representing a string
	class DLL_SPEC SString
	{
	public:
		SString(const char* str);
		/// @brief	Gets a c string.
		/// @return	null if it fails, else the c string.
		const char* getCString();
	private:
		struct StringPImpl;
		StringPImpl* m_stringPImpl;
	};
}