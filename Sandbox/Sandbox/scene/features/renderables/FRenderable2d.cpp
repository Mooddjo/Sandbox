#include "FRenderable2d.h"
#include "EventService.h"
#include "Vertex.h"

using namespace sandbox;


FRenderable2d::FRenderable2d(EEntity* owner) :
	FRenderable(owner) 
{
	m_mesh = std::make_shared<Quad>();
}


void
FRenderable2d::init()
{
	EvFeatureCreated<FRenderable>* feature = new EvFeatureCreated<FRenderable>(this);
	EventService::getInstance()->fireEvent(EVENT_RENDER_FEATURE_CREATED, feature);
}

void
FRenderable2d::render()
{
}
