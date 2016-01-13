#include "FRenderable2d.h"

#include "RenderingService.h"

using namespace sandbox;


FRenderable2d::FRenderable2d(EEntity* owner) :
	FRenderable(owner)
{

}



void
FRenderable2d::init()
{

	m_mesh2d.addVertex(vec3(-0.5, 0.5, 0.0));
	m_mesh2d.addVertex(vec3(0.5, 0.5, 0.0));
	m_mesh2d.addVertex(vec3(0.5, -0.5, 0.0));
	m_mesh2d.addVertex(vec3(0.5, -0.5, 0.0));
	m_mesh2d.addVertex(vec3(-0.5, -0.5, 0.0));
	m_mesh2d.addVertex(vec3(-0.5, 0.5, 0.0));

	unsigned int vertexCount = m_mesh2d.getVerticesCount();

	m_buffer = std::make_shared<GPUBuffer>(vertexCount * 3, m_mesh2d.getVerticesPosition());
	m_vao = std::make_shared<GPUVertexArray>(m_buffer.get(), vertexCount);
}

void
FRenderable2d::render() const
{
	m_material->enable();
	m_vao->bind();
	RENDERING_SERVICE->drawVertexArray(m_vao.get());
	m_material->disable();
}

