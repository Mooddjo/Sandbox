#pragma once

#include "SmartLogger.h"

namespace smartray
{
	template<>
	void smartray::MaterialProperty::Value<double>::submit()
	{
		SMARTLOG("Iam a double property with value: " + std::to_string(data), kInfo);
	}

	template<>
	void smartray::MaterialProperty::Value<int>::submit()
	{
		SMARTLOG("Iam a int property with value: " + std::to_string(data), kInfo);
	}
}