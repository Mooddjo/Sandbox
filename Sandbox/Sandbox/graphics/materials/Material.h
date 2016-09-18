#pragma once

#include "SString.h"
#include <map>
#include <iostream>
#include <memory>
#include "MaterialManager.h"
#include "Shader.h"


namespace sandbox
{

	class MaterialInstance;

	class DLL_SPEC Material
	{

	public:
		void setShader(ShaderProgram* shaderProgram);
		void enable() const;
		void disable() const { m_shader->disable(); }
		unsigned int getMaterialId() const { return m_shader->getId(); }

		//template<typename T> void setProperty(SString name, T value);
		//const MaterialProperty* getProperty(SString name) const;
		//const std::map<SString, MaterialProperty*>& getProperties();
		
		MaterialInstance* createInstance();
		Material(SString materialName = "sandbox_diffuse_mat");
		~Material();

	private:


		
		SString m_name;
//		std::map<SString, MaterialProperty*> m_properties;
		std::shared_ptr<ShaderProgram> m_shader;
	};

// 	template<typename T>
// 	void sandbox::Material::setProperty(SString name, T value)
// 	{
// 		MaterialProperty* matProp = getProperty(name);
// 		if (matProp)
// 		{
// 			matProp->setValue(name, value);
// 		}
// 		else {
// 			MaterialProperty* mat = MaterialProperty::create(name, value);
// 			setProperty(mat);
// 		}
// 	}
	

}