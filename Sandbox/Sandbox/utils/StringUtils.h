#pragma once
#include <string>

#define TO_STRING(word) #word

namespace smartray 
{
	class StringUtils
	{
	public:
		static std::string parseFile(std::string path);
	};

}