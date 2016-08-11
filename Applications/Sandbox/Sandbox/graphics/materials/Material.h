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
		~Material();
		void setShader(ShaderProgram* shaderProgram);
		void enable() const;
		void disable() const { m_shader->disable(); }
		template<typename T> void setProperty(SString name, T value);
		const MaterialProperty* getProperty(SString name) const;
		const std::map<SString, MaterialProperty*>& getProperties();

	private:
		MaterialProperty* getProperty(SString name);
		void setProperty(MaterialProperty* property);
		std::map<SString, MaterialProperty*> m_properties;
		SString m_name;
		std::shared_ptr<ShaderProgram> m_shader;
	};

	template<typename T>
	void sandbox::Material::setProperty(SString name, T value)
	{
		MaterialProperty* matProp = getProperty(name);
		if (matProp)
		{
			matProp->setValue(name, value);
		}
		else {
			MaterialProperty* mat = MaterialProperty::create(name, value);
			setProperty(mat);
		}
	}
	

}