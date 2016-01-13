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
OGLRenderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
OGLRenderer::drawVertexArray(GPUVertexArray* vao)
{
	glDrawArrays(GL_TRIANGLES, 0, vao->getVertexCount());
}
