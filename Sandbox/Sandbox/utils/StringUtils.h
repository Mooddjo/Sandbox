#pragma once
#include "SString.h"

#define TO_STRING(word) #word

namespace sandbox 
{
	class StringUtils
	{
	public:
		static SString parseFile(SString path);
	};

}