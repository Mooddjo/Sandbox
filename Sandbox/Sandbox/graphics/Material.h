#pragma once

#include <string>
#include <map>
#include <iostream>
#include <memory>
#include "Shader.h"
#include "MaterialProperty.h"

namespace sandbox
{
	class DLL_SPEC Material
	{
	public:
		Material();
		void setShader(ShaderProgram* shaderProgram);
		void enable() { m_shader->enable(); }
		void addProperty(MaterialProperty* property);
		const std::map<std::string, MaterialProperty*>& getProperties();

	private:
		std::map<std::string, MaterialProperty*> m_properties;
		std::string m_name;
		std::shared_ptr<ShaderProgram> m_shader;
	};

	

}