#include "OGLBatch2DRenderer.h"
#include "GraphicsService.h"

using namespace sandbox;

bool
OGLBatch2DRenderer::init()
{
	OGLAbstract2DRenderer::init();
	GpuRawBuffer* buffer = GraphicsService::getInstance()->provideGpuRawBuffer(
		batch_max_size, 
		batch_max_element_size, 
		nullptr);


	m_rawbuffer = std::shared_ptr<GpuRawBuffer>(buffer);
	m_indexBuffer = std::make_shared<GpuIndexBuffer>(batch_max_size,;

	return true;
}

void
OGLBatch2DRenderer::process()
{
	throw std::logic_error("The method or operation is not implemented.");
	
}


void
OGLBatch2DRenderer::renderableCreatedEvent(IEventData* renderable)
{
	FRenderable* featRenderable = static_cast<EvFeatureCreated<FRenderable>*>(renderable)->getFeature();
	GpuRawBuffer* rawBuffer = GraphicsService::getInstance()->buildGpuRawBufferFromMesh(featRenderable->getMesh());
	
	m_rawbuffer->addData(*rawBuffer);

	//TODO update ibo and vao;

	//delete rawBuffer;
}
