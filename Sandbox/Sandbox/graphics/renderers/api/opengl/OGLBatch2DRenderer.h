#pragma once

#include "OGLAbstract2DRenderer.h"
#include "GpuBuffers.h"
#include <memory>
#include "Vertex.h"
#include <climits>



namespace sandbox
{
	class OGLBatch2DRenderer: public OGLAbstract2DRenderer
	{
		const unsigned int batch_max_size = std::numeric_limits<unsigned short>::max();
		const unsigned int batch_max_element_size = sizeof(Vertex);


	public:
		virtual bool init() override;
		virtual void process() override;

	protected:
		virtual void renderableCreatedEvent(IEventData* renderable) override;

	private:
		std::shared_ptr<GpuRawBuffer> m_rawbuffer;
		std::shared_ptr<GpuIndexBuffer> m_indexBuffer;
	};
}