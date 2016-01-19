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
