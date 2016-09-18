#include "FRenderable.h"
#include "EventService.h"
#include "EEntity.h"
#include "MathUtils.h"
#include "MaterialManager.h"
#include "MaterialInstance.h"
#include "Material.h"

using namespace sandbox;

FRenderable::FRenderable(EEntity* owner, Material* material):
	FFeature(owner)
{
	if (!material)
	{
		MaterialManager* matMgr = MaterialManager::getInstance();
		Material* mat = matMgr->createMaterial("sandbox_diffuse_mat");
		MaterialInstance* matInstance = mat->createInstance();
		m_materialInstance = std::shared_ptr<MaterialInstance>(matInstance);
	}
	else
	{
		setMaterial(material);
	}
	
}

const Mesh* sandbox::FRenderable::getMesh() const
{
	return m_mesh.get();
}

MaterialInstance* sandbox::FRenderable::getMaterialInstance() const
{
	return m_materialInstance.get();
}

void sandbox::FRenderable::setMaterial(Material* material)
{
// 	if (material)
// 	{
// 		m_material = std::shared_ptr<Material>(material);
// 		updateMaterial();
// 	}
}

void sandbox::FRenderable::updateMaterial()
{
// 	if (m_material)
// 	{
// 		if (m_mesh)
// 		{
// 			
// 		}
// 	}
}

