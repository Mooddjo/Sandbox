#include "RenderData.h"
#include "GraphicsService.h"

using namespace sandbox;



sandbox::RenderData::RenderData(const FRenderable* renderable)
{
	auto graphicsService = GraphicsService::getInstance();
	m_material = renderable->getMaterial();

	m_dataBuffer = graphicsService->provideGpuRawBuffer(
		renderable->getMesh()->getVerticesCount(), 
		renderable->getMesh()->getVertexSize(),
		renderable->getMesh()->getVerticesPointer);

	m_indexBuffer = graphicsService->provideGpuIndexBuffer(renderable->getMesh()->getIndexCount(), renderable->getMesh()->getIndicesPointer());
	m_vertexBuffer = graphicsService->provideGpuVertexArray(m_dataBuffer, renderable->getMesh()->getVerticesCount());
}




