#include "Abstract2DRenderer.h"

using namespace sandbox;



bool 
Abstract2DRenderer::init()
{
	REGISTER_FOR_EVENT(EVENT_RENDER_FEATURE_CREATED, EVENT_CALLBACK(&Abstract2DRenderer::renderableCreatedEvent, this));
	return true;
}

void sandbox::Abstract2DRenderer::renderableCreatedEvent(IEventData* data)
{
	EvFeatureCreated<FRenderable>* renderCreatedEvent = static_cast<EvFeatureCreated<FRenderable>*>(data);
	FRenderable* renderableFeature = renderCreatedEvent->getFeature();

	if (renderableFeature)
	{
		RenderData* renderData = new RenderData(renderableFeature);
		m_renderData.push_back(renderData);
		SMARTLOG("Rendering feature created", kInfo);
	}	
}

