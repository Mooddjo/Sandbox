#pragma once

#include "SmartLogger.h"

namespace sandbox
{
	template<>
	void sandbox::MaterialProperty::Value<double>::submit()
	{
		//SMARTLOG("Iam a double property with value: " + std::to_string(data), kInfo);
	}

	template<>
	void sandbox::MaterialProperty::Value<int>::submit()
	{
		//SMARTLOG("Iam a int property with value: " + std::to_string(data), kInfo);
	}
}