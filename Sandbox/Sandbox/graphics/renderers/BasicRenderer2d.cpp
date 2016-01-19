#include "BasicRenderer2d.h"
#include "FRenderable2d.h"

using namespace sandbox;
using namespace std;

bool sandbox::BasicRenderer2d::init()
{
	m_clearColor.r = 0.2;
	m_clearColor.g = 0.2;
	m_clearColor.b = 0.2;
	m_clearColor.a = 1.0;

	return true;
}

void sandbox::BasicRenderer2d::beginRendering()
{
	
}

void sandbox::BasicRenderer2d::buildRenderable(const FRenderable* renderable)
{

}

void sandbox::BasicRenderer2d::preRender(const FRenderable* renderable)
{
}

void sandbox::BasicRenderer2d::render(const FRenderable* renderable)
{
	const FRenderable2d* rend2d = static_cast<const FRenderable2d*>(renderable);


}

void sandbox::BasicRenderer2d::postRender(const FRenderable* renderable)
{
}

void sandbox::BasicRenderer2d::endRendering()
{
}

void sandbox::BasicRenderer2d::clearFrame()
{

}
