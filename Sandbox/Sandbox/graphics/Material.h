#pragma once

#include "SString.h"
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
		void disable() { m_shader->disable(); }
		void addProperty(MaterialProperty* property);
		const std::map<SString, MaterialProperty*>& getProperties();

	private:
		std::map<SString, MaterialProperty*> m_properties;
		SString m_name;
		std::shared_ptr<ShaderProgram> m_shader;
	};

	

}