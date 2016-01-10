#include "FRenderable.h"
#include "EventService.h"

using namespace sandbox;

FRenderable::FRenderable(EEntity* owner, Material* material):
	FFeature(owner)
{
	EFeatureCreated<FRenderable> feature(this);
	EventService::getInstance()->fireEvent(EVENT_RENDER_FEATURE_CREATED, &feature);

	if (!material)
	{
		m_material = std::shared_ptr<Material>();
	}
}


