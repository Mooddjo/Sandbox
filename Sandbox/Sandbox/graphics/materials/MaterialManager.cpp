#include "MaterialManager.h"
#include "SString.h"
#include "Material.h"

using namespace sandbox;


Material*
MaterialManager::createMaterial(SString materialName)
{
	Material* mat = getMaterial(materialName);
	if (mat == nullptr)
	{
		std::shared_ptr<Material> material = std::make_shared<Material>(materialName);
		m_materials[materialName] = material;
		mat = material.get();
	}

	return mat;
}

bool
MaterialManager::releaseMaterial(SString materialName)
{
	//TODO check if count is 1 so delete on map/gpu to free memory
	// true if released false if count > 1
	std::logic_error("Release material is not implemented yet");
	return false;
}

Material*
MaterialManager::getMaterial(SString materialName)
{
	auto it = m_materials.find(materialName);

	if (it != m_materials.end())
	{
		return it->second.get();
	}

	return nullptr;
}