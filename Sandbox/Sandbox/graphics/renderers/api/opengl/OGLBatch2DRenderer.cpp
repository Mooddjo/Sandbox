#include "OGLBatch2DRenderer.h"
#include "GraphicsService.h"

bool sandbox::OGLBatch2DRenderer::init()
{
	OGLAbstract2DRenderer::init();
	GpuRawBuffer* buffer = GraphicsService::getInstance()->provideGpuRawBuffer(batch_element_size, batch_element_size, nullptr);

	m_buffer = std::shared_ptr<GpuRawBuffer>(buffer);

	return true;
}

void sandbox::OGLBatch2DRenderer::process()
{
	throw std::logic_error("The method or operation is not implemented.");
	
}

void sandbox::OGLBatch2DRenderer::renderableCreatedEvent(IEventData* renderable)
{
	
	throw std::logic_error("The method or operation is not implemented.");
}
