#include "AbstractRenderer.h"


using namespace sandbox;



sandbox::AbstractRenderer::AbstractRenderer()
{
	REGISTER_FOR_EVENT(EVENT_RENDER_FEATURE_CREATED, EVENT_CALLBACK(&AbstractRenderer::renderableCreatedEvent, this));
}

void sandbox::AbstractRenderer::renderable2dCreated(const FRenderable* renderable)
{
	RenderData* renderData = new RenderData(renderable);
	m_renderData.push_back(renderData);
}

void sandbox::AbstractRenderer::renderable2dOnStart(const FRenderable* renderable)
{

}

void sandbox::AbstractRenderer::renderable2dOnExit(const FRenderable* renderable)
{
	std::logic_error("Not implemented yet");
}

void sandbox::AbstractRenderer::renderableCreatedEvent(IEventData* data)
{
	EvFeatureCreated<FRenderable>* renderCreatedEvent = static_cast<EvFeatureCreated<FRenderable>*>(data);
	FRenderable* renderableFeature = renderCreatedEvent->getFeature();

	if (renderableFeature)
	{
		renderable2dCreated(renderableFeature);
		SMARTLOG("Rendering feature created", kInfo);
	}
}
