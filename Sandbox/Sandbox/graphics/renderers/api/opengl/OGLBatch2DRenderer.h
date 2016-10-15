#pragma once

#include "OGLAbstract2DRenderer.h"
#include "GpuBuffers.h"
#include <memory>
#include "Vertex.h"

namespace sandbox
{
	class OGLBatch2DRenderer: public OGLAbstract2DRenderer
	{
		const unsigned int batch_max_size = 65536;
		const unsigned int batch_element_size = sizeof(Vertex);


	public:
		virtual bool init() override;
		virtual void process() override;

	protected:
		virtual void renderableCreatedEvent(IEventData* renderable) override;

	private:
		std::shared_ptr<GpuRawBuffer> m_buffer;
	};
}