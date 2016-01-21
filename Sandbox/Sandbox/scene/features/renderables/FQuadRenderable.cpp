#include "FQuadRenderable.h"
#include "SmartLogger.h"
#include <iostream>

using namespace sandbox;

float vertex[] =
{
	0.0, 0.5, 0.0,
	0.5, -0.5, 0.0,
	-0.5, -0.5, 0.0
};

FQuadRenderable::FQuadRenderable(EEntity* owner) :
	FRenderable(owner)
{
	Shader* vsShader = Shader::createShader("./resources/shaders/basic_shader.vs", VERTEX_SHADER);
	Shader* fsShader = Shader::createShader("./resources/shaders/basic_shader.fs", FRAGMENT_SHADER);
	m_shader = ShaderProgram::createShaderProgram();
	m_shader->addShader(vsShader);
	m_shader->addShader(fsShader);
	m_shader->compile();

	//m_vbo = new OglGpuRawBuffer(9, sizeof(float),  vertex);
	//m_vao = new OlgGpuVertexBuffer(m_vbo, 3);

}

void
FQuadRenderable::render()
{
// 	m_shader->enable();
// 	m_vao->bind();
// 	RENDERING_SERVICE->drawVertexArray(m_vao);
}

void
FQuadRenderable::init()
{
	SMARTLOG("init FRenderableCube", kInfo);
}

