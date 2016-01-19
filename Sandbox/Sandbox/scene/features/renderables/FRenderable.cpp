#include "FRenderable.h"
#include "EventService.h"

using namespace sandbox;

FRenderable::FRenderable(EEntity* owner, Material* material):
	FFeature(owner)
{
	EvFeatureCreated<FRenderable> feature(this);
	EventService::getInstance()->fireEvent(EVENT_RENDER_FEATURE_CREATED, &feature);

	if (!material)
	{
		m_material = std::make_shared<Material>();
	}
}

const Mesh* sandbox::FRenderable::getMesh() const
{
	return m_mesh.get();
}

const Material* sandbox::FRenderable::getMaterial() const
{
	return m_material.get();
}

