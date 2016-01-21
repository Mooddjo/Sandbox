#include "BasicRenderer2d.h"
#include "GL/glew.h"
#include "SmartLogger.h"
#include "EventService.h"

using namespace sandbox;
using namespace std;

void sandbox::BasicRenderer2d::process()
{
	beginRendering();
	for (auto renderData : m_renderData)
	{
		render(renderData);
	}
	endRendering();
	clearFrame();
}


void sandbox::BasicRenderer2d::beginRendering()
{
}


void sandbox::BasicRenderer2d::render(const RenderData* renderData)
{
	renderData->draw();
}


void sandbox::BasicRenderer2d::endRendering()
{
}

bool sandbox::BasicRenderer2d::init()
{
	return AbstractOglRenderer::init();
}
