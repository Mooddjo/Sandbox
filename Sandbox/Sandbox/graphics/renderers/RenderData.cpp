#include "RenderData.h"
#include "GraphicsService.h"
#include "GL/glew.h"
#include "EEntity.h"

using namespace sandbox;



sandbox::RenderData::RenderData(const FRenderable* renderable)
{
	auto graphicsService = GraphicsService::getInstance();
	m_material = renderable->getMaterial();
	m_modelMatrix = renderable->getOwner()->getTransform();

	m_dataBuffer = graphicsService->provideGpuRawBuffer(
		renderable->getMesh()->getVerticesCount(), 
		renderable->getMesh()->getVertexSize(),
		renderable->getMesh()->getVerticesPointer());

	m_indexBuffer = graphicsService->provideGpuIndexBuffer(renderable->getMesh()->getIndexCount(), renderable->getMesh()->getIndicesPointer());
	m_vertexBuffer = graphicsService->provideGpuVertexArray(m_dataBuffer, renderable->getMesh()->getVerticesCount());
	//m_material->setProperty("uModelMatrix", m_modelMatrix->getLocalMatrix());
}

void sandbox::RenderData::draw() const
{
	m_material->enable();
	m_vertexBuffer->bind();
	m_indexBuffer->bind();

	glDrawElements(GL_TRIANGLES, m_indexBuffer->getSize(), GL_UNSIGNED_SHORT, 0);

	m_vertexBuffer->unbind();
	m_indexBuffer->unbind();
	m_material->disable();
}



