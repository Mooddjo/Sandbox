#include "FRenderable2d.h"

#include "RenderingService.h"
#include "Vertex.h"

using namespace sandbox;


FRenderable2d::FRenderable2d(EEntity* owner) :
	FRenderable(owner) 
{
	m_mesh = std::make_shared<Quad>();
}


void
FRenderable2d::init()
{
// 	m_buffer = std::make_shared<OglGpuRawBuffer>(
// 		m_mesh->getVerticesCount(),
// 		m_mesh->getVertexSize(),
// 		m_mesh->getVerticesPointer());
// 
// 	m_vao = std::make_shared<GPUVertexArray>(m_buffer.get(), m_mesh->getVerticesCount());
// 	m_ib = std::make_shared<OglGpuIndexBuffer>(m_mesh->getIndexCount(), m_mesh->getIndicesPointer());

}

void
FRenderable2d::render()
{
// 	m_material->enable();
// 	m_vao->bind();
// 	m_ib->bind();
// 	RENDERING_SERVICE->drawElementArray(m_ib.get());
// 	m_material->disable();
}
