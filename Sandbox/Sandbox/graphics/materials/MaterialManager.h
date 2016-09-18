#pragma once

#include "Singleton.h"
#include "Platform.h"
#include <map>

namespace sandbox
{
	class SString;
	class Material;


	class DLL_SPEC MaterialManager: public Singleton<MaterialManager>
	{
	public:
		Material* getMaterial(SString materialName);
		Material* createMaterial(SString materialName);
		bool releaseMaterial(SString materialName);

	private:
		std::map<SString, std::shared_ptr<Material>> m_materials;
	};
}