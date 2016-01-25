#pragma once

#include "SmartLogger.h"
#include "MathUtils.h"
#include "gtc/type_ptr.hpp"

namespace sandbox
{
	template<>
	void sandbox::MaterialProperty::Value<float>::submit(unsigned int materialId)
	{
		glUniform1f(0, data);
	}

	template<>
	void sandbox::MaterialProperty::Value<vec4>::submit(unsigned int materialId)
	{
		unsigned int location = glGetUniformLocation(materialId, m_name.getCString());
		glUniform4f(location, data.r, data.g, data.b, data.a);
	}

	template<>
	void sandbox::MaterialProperty::Value<mat4x4>::submit(unsigned int materialId)
	{
		unsigned int location = glGetUniformLocation(materialId, m_name.getCString());
		float* mat = glm::value_ptr(data);
		glUniform4fv(location, 16, mat);
	}
}