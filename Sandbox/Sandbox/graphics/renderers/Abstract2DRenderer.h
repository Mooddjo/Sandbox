#pragma once

#include "AbstractRenderer.h"
#include "FRenderable.h"
#include "RenderData.h"
#include "Color.h"
#include "EventService.h"

namespace sandbox
{
	class Abstract2DRenderer: public AbstractRenderer
	{
	public:
		virtual bool init() override;
	
	protected:
		virtual void renderableCreatedEvent(IEventData* renderable);

		Color m_clearColor;
		std::list<RenderData*> m_renderData;
	};
}