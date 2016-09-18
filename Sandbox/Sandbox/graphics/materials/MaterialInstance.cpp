#include "MaterialInstance.h"
#include "Material.h"

using namespace sandbox;

MaterialInstance::MaterialInstance(Material* material)
{
	m_material = std::shared_ptr<Material>(material);
}

void
MaterialInstance::bind()
{
	m_material->enable();
	for (auto it : m_properties)
	{
		MaterialProperty* prop = it.second;
		prop->submit(m_material->getMaterialId());
	}
}

void
MaterialInstance::unbind()
{
	m_material->disable();
}

void MaterialInstance::setProperty(MaterialProperty* property)
{
	//TODO delete property if exists
	if (property)
	{
		m_properties[property->getName()] = property;
	}
}


const MaterialProperty*
MaterialInstance::getProperty(SString name) const
{
	auto it = m_properties.find(name);
	if (it != m_properties.end())
	{
		return it->second;
	}

	return nullptr;
}

MaterialProperty*
MaterialInstance::getProperty(SString name)
{
	const MaterialInstance& mat = static_cast<const MaterialInstance&>(*this);
	MaterialProperty* matProp = const_cast<MaterialProperty*>(mat.getProperty(name));
	return matProp;
}