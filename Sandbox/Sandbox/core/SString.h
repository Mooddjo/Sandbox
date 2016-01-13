#pragma once

#include "Platform.h"

namespace sandbox
{
	/// @brief	Class representing a string
	class DLL_SPEC SString
	{

		friend bool operator<(const SString& str, const SString& str2);
		friend SString operator+(const SString& str, const SString& str2);

	public:
		SString(const char* str = "");
		~SString();
		SString(const SString& str);
		const SString& operator=(const SString& str);
		void append(const SString& str);
		void copy(char* buffer, unsigned int length);
		unsigned int length();
		/// @brief	Gets a c string.
		/// @return	null if it fails, else the c string.
		const char* getCString() const;
	private:
		struct StringPImpl;
		StringPImpl* m_stringPImpl;
	};
}
