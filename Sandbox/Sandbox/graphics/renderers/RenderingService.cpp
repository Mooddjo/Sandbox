#include "RenderingService.h"
#include "OGLRenderer.h"
#include "EventService.h"
#include "SmartLogger.h"

using namespace sandbox;
using namespace std;

RenderingService::RenderingService()
{
	m_renderer = make_shared<OGLRenderer>();
	m_renderer->init();
	REGISTER_FOR_EVENT(EVENT_RENDER_FEATURE_CREATED, EVENT_CALLBACK(&RenderingService::renderFeatureCreated, this));
}

RenderingService::~RenderingService()
{
}

void
RenderingService::renderFeatureCreated(IEventData* data)
{
	EvFeatureCreated<FRenderable>* renderCreatedEvent = static_cast<EvFeatureCreated<FRenderable>*>(data);
	FRenderable* renderableFeature = renderCreatedEvent->getFeature();
	if (renderableFeature)
	{
		m_renderableObjects.push_back(renderableFeature);
	}
	SMARTLOG("Rendering feature created", kInfo);
}

void
RenderingService::sortRenderingQueue()
{

}

void
RenderingService::render()
{
	m_renderer->clearFrame();
	for (auto renderable : m_renderableObjects)
	{
		renderable->render();
	}
}
