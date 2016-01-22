#include "FRenderable.h"
#include "EventService.h"
#include "EEntity.h"
#include "MathUtils.h"

using namespace sandbox;

FRenderable::FRenderable(EEntity* owner, Material* material):
	FFeature(owner)
{
	if (!material)
	{
		m_material = std::make_shared<Material>();
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

Material* sandbox::FRenderable::getMaterial() const
{
	return m_material.get();
}

void sandbox::FRenderable::setMaterial(Material* material)
{
	if (material)
	{
		m_material = std::shared_ptr<Material>(material);
		updateMaterial();
	}
}

void sandbox::FRenderable::updateMaterial()
{
	if (m_material)
	{
		if (m_mesh)
		{
			
		}
	}
}

