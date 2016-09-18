#include "RenderData.h"
#include "GraphicsService.h"
#include "GL/glew.h"
#include "EEntity.h"
#include "MaterialInstance.h"

using namespace sandbox;



sandbox::RenderData::RenderData(const FRenderable* renderable)
{
	auto graphicsService = GraphicsService::getInstance();
	m_materialInstance = renderable->getMaterialInstance();
	m_modelMatrix = renderable->getOwner()->getTransform();

	m_dataBuffer = graphicsService->provideGpuRawBuffer(
		renderable->getMesh()->getVerticesCount(), 
		renderable->getMesh()->getVertexSize(),
		renderable->getMesh()->getVerticesPointer());

	m_indexBuffer = graphicsService->provideGpuIndexBuffer(renderable->getMesh()->getIndexCount(), renderable->getMesh()->getIndicesPointer());
	m_vertexBuffer = graphicsService->provideGpuVertexArray(m_dataBuffer, renderable->getMesh()->getVerticesCount());
	
}

void sandbox::RenderData::draw() const
{
	m_materialInstance->bind();
	m_materialInstance->setProperty("u_modelMatrix", m_modelMatrix->getLocalMatrix());
	m_vertexBuffer->bind();
	m_indexBuffer->bind();

	glDrawElements(GL_TRIANGLES, m_indexBuffer->getSize(), GL_UNSIGNED_SHORT, 0);

	m_vertexBuffer->unbind();
	m_indexBuffer->unbind();
	m_materialInstance->unbind();
}



