#include "OGLRenderer.h"
#include "GL/glew.h"
#include "SmartLogger.h"
#include <stdio.h>
#include "SString.h"

using namespace sandbox;
using namespace std;

const float OGLRenderer::backgroundColor[] = {0.1f, 0.1f, 0.1f, 1.0f };

bool
OGLRenderer::init()
{
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

	glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
	return true;
}

void
OGLRenderer::clearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void sandbox::OGLRenderer::buildRenderable(const FRenderable* renderable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::OGLRenderer::beginRendering()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::OGLRenderer::preRender(const FRenderable* renderable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::OGLRenderer::render(const FRenderable* renderable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::OGLRenderer::postRender(const FRenderable* renderable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::OGLRenderer::endRendering()
{
	throw std::logic_error("The method or operation is not implemented.");
}

// void
// OGLRenderer::drawVertexArray(OlgGpuVertexBuffer* vao)
// {
// 	glDrawArrays(GL_TRIANGLES, 0, vao->getVertexCount());
// }

// void sandbox::OGLRenderer::drawElementArray(OglGpuIndexBuffer* ib)
// {
// 	glDrawElements(GL_TRIANGLES, ib->getSize(), GL_UNSIGNED_SHORT, 0);
// }

