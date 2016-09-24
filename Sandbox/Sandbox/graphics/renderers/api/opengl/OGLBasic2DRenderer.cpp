#include "OGLBasic2DRenderer.h"
#include "GL/glew.h"
#include "SmartLogger.h"
#include "EventService.h"
#include "Timer.h"

using namespace sandbox;
using namespace std;

void sandbox::OGLBasic2DRenderer::process()
{
	OGLAbstract2DRenderer::init();
	clearFrame();
	//beginRendering();
	for (auto renderData : m_renderData)
	{
		render(renderData);
	}
	//endRendering();
	m_fpsCounter++;
	double eleapsedTime = m_timer.eleapsed();
	if (eleapsedTime > 1000.0)
	{
		m_timer.start();
		SMARTLOG(std::to_string(m_fpsCounter).c_str(), kInfo);
		m_fpsCounter = 0;
	}
	
}

void sandbox::OGLBasic2DRenderer::render(const RenderData* renderData)
{
	renderData->draw();
}


bool sandbox::OGLBasic2DRenderer::init()
{
	m_timer.start();
	return OGLAbstract2DRenderer::init();
}
