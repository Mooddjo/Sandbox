#pragma once

#include "FRenderable.h"
#include "Singleton.h"
#include "Platform.h"
#include "AbstractRenderer.h"
#include <memory>
#include <list>

#define RENDERING_SERVICE sandbox::RenderingService::getInstance()

namespace sandbox
{
	class IEventData;

	class DLL_SPEC RenderingService: public Singleton<RenderingService>
	{
		friend class Singleton<RenderingService>;

	public:
		void render();
	private:
		std::shared_ptr<AbstractRenderer> m_renderer;
		std::list<FRenderable*> m_renderableObjects;

	protected:
		RenderingService();
		~RenderingService();

		void renderFeatureCreated(IEventData* data);
		void sortRenderingQueue();
	};

	
}