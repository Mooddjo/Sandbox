#pragma once
#include "FRenderable.h"
#include "RenderData.h"
#include "EventService.h"
#include "Color.h"
#include <list>

namespace sandbox
{
	class AbstractRenderer
	{
	public:
		AbstractRenderer();
		virtual bool init() = 0;
		virtual void process() = 0;

	protected:
		virtual void renderable2dCreated(const FRenderable* renderable);
		virtual void renderable2dOnStart(const FRenderable* renderable);
		virtual void renderable2dOnExit(const FRenderable* renderable);

		virtual void beginRendering() = 0;
		virtual void render(const RenderData* renderData) = 0;
		virtual void endRendering() = 0;
		virtual void clearFrame() = 0;
		
		Color m_clearColor;
		std::list<const RenderData*> m_renderData;

	private:
		void renderableCreatedEvent(IEventData* data);
	};
}