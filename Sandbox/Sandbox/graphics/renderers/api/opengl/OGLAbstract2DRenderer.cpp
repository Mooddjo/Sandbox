#include "OGLAbstract2DRenderer.h"
#include "SmartLogger.h"
#include "gl/glew.h"
#include "OGLUtils.h"


using namespace sandbox;



bool sandbox::OGLAbstract2DRenderer::init()
{
	Abstract2DRenderer::init();
	m_clearColor.r = 0.2f;
	m_clearColor.g = 0.2f;
	m_clearColor.b = 0.2f;
	m_clearColor.a = 1.0f;

	SMARTLOG("-----SmartRay Initialization-----", kInfo);

	glewExperimental = GL_TRUE;
	glewInit();
	GLenum err = glGetError();// HACK to avoid INVALID_ENUM after glewinit



	SString glewVersion = "Glew version: ";
	glewVersion.append((char*)glewGetString(GLEW_VERSION));

	SString glVersion = SString((char*)glGetString(GL_VERSION));


	SMARTLOG(glewVersion, kInfo);
	SMARTLOG("OpenGL version: " + glVersion, kInfo);
	SMARTLOG("-----SmartRay Initialization Succeeded-----", kInfo);

	

	glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
	return true;
}

void sandbox::OGLAbstract2DRenderer::clearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
