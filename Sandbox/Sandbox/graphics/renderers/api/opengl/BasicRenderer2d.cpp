#include "BasicRenderer2d.h"
#include "GL/glew.h"
#include "SmartLogger.h"
#include "EventService.h"
#include "Timer.h"

using namespace sandbox;
using namespace std;

void sandbox::BasicRenderer2d::process()
{
	clearFrame();
	beginRendering();
	for (auto renderData : m_renderData)
	{
		render(renderData);
	}
	endRendering();
	unsigned int err = glGetError();
	if (err != GL_NO_ERROR)
	{
		SMARTLOG("OpenGL error:" + (char)err, kInfo);
	}
	m_fpsCounter++;
	double eleapsedTime = m_timer.eleapsed();
	if (eleapsedTime > 1000.0)
	{
		m_timer.start();
		SMARTLOG(std::to_string(m_fpsCounter).c_str(), kInfo);
		m_fpsCounter = 0;
	}
	
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
	m_timer.start();
	//glViewport(0, 0, 1280, 720);
	return AbstractOglRenderer::init();
}
