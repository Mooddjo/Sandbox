#include "FRenderable2d.h"

#include "RenderingService.h"
//#include "Material.h"

using namespace sandbox;

float square[] =
{
	0.0, 1.0, 0.0,
	1.0, 1.0, 0.0,
	1.0, 0.0, 0.0,
	0.0, 0.0, 0.0,
};

FRenderable2d::FRenderable2d(EEntity* owner) :
	FRenderable(owner)
{

}



void
FRenderable2d::init()
{
	//m_buffer = std::make_shared<GPUBuffer>(12, square);
	//m_vao = std::make_shared<GPUVertexArray>(m_buffer.get(), 4);

}

void
FRenderable2d::render() const
{
	//m_material->enable();
	//m_vao->bind();
	//RENDERING_SERVICE->drawVertexArray(m_vao.get());
}

