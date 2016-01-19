#include "BasicRenderer2d.h"

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

bool sandbox::BasicRenderer2d::process()
{
	beginRendering();
	for (auto renderData : m_renderData)
	{
		render(renderData);
	}
	endRendering();
}


void sandbox::BasicRenderer2d::beginRendering()
{
	
}


void sandbox::BasicRenderer2d::render(const RenderData* renderable)
{

}


void sandbox::BasicRenderer2d::endRendering()
{
}

void sandbox::BasicRenderer2d::clearFrame()
{

}
