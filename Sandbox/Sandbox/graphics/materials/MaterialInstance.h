#pragma once

#include "Platform.h"
#include <vector>
#include <map>
#include "MaterialProperty.h"

namespace sandbox
{
	class Material;

	class DLL_SPEC MaterialInstance
	{
	public:
		MaterialInstance(Material* material);
		void bind();
		void unbind();
		template<typename T> void setProperty(SString name, T value);
		const MaterialProperty* getProperty(SString name) const;

	private:
		MaterialProperty* getProperty(SString name);
		void setProperty(MaterialProperty* property);


		std::shared_ptr<Material> m_material;
		std::map<SString, MaterialProperty*> m_properties;
	};


	template<typename T>
	void MaterialInstance::setProperty(SString name, T value)
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