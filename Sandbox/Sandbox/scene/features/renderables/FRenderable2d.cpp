#include "FRenderable2d.h"

#include "RenderingService.h"
#include "Vertex.h"

using namespace sandbox;


FRenderable2d::FRenderable2d(EEntity* owner) :
	FRenderable(owner) {}


void
FRenderable2d::init()
{
	m_buffer = std::make_shared<GPURawBuffer>(
		m_2dMesh.getVerticesCount(),
		m_2dMesh.getVertexSize(),
		m_2dMesh.getVerticesPointer());
	
	m_vao = std::make_shared<GPUVertexArray>(m_buffer.get(), m_2dMesh.getVerticesCount());
	m_ib = std::make_shared<GPUIndexBuffer>(m_2dMesh.getIndexCount(), m_2dMesh.getIndicesPointer());

}

void
FRenderable2d::render()
{
	m_material->enable();
	m_vao->bind();
	m_ib->bind();
	RENDERING_SERVICE->drawElementArray(m_ib.get());
	m_material->disable();
}
