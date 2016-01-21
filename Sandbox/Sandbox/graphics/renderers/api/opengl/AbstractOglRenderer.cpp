#include "AbstractOglRenderer.h"
#include "SmartLogger.h"

using namespace sandbox;

bool sandbox::AbstractOglRenderer::init()
{
	m_clearColor.r = 0.2;
	m_clearColor.g = 0.2;
	m_clearColor.b = 0.2;
	m_clearColor.a = 1.0;

	SMARTLOG("-----SmartRay Initialization-----", kInfo);
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		SMARTLOG((char*)glewGetErrorString(err), kError);
		return false;
	}

	SString glewVersion = "Glew version: ";
	glewVersion.append((char*)glewGetString(GLEW_VERSION));

	SString glVersion = SString((char*)glGetString(GL_VERSION));

	SMARTLOG(glewVersion, kInfo);
	SMARTLOG("OpenGL version: " + glVersion, kInfo);
	SMARTLOG("-----SmartRay Initialization Succeeded-----", kInfo);

	glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
	return true;
}

void sandbox::AbstractOglRenderer::clearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
