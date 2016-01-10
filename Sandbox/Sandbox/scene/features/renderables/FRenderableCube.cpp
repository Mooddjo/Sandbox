#include "FRenderableCube.h"
#include "SmartLogger.h"
#include <iostream>
#include "RenderingService.h"

using namespace sandbox;

float vertex[] =
{
	0.0, 0.5, 0.0,
	0.5, -0.5, 0.0,
	-0.5, -0.5, 0.0
};

FRenderableCube::FRenderableCube(EEntity* owner) :
	FRenderable(owner)
{
	Shader* vsShader = Shader::createShader("./resources/shaders/basic_shader.vs", VERTEX_SHADER);
	Shader* fsShader = Shader::createShader("./resources/shaders/basic_shader.fs", FRAGMENT_SHADER);
	m_shader = ShaderProgram::createShaderProgram();
	m_shader->addShader(vsShader);
	m_shader->addShader(fsShader);
	m_shader->compile();

	m_vbo = new GPUBuffer(9, vertex);
	m_vao = new GPUVertexArray(m_vbo, 3);

}

void
FRenderableCube::render() const
{
	m_shader->enable();
	m_vao->bind();
	RENDERING_SERVICE->drawVertexArray(m_vao);
}

void
FRenderableCube::init()
{
	SMARTLOG("init FRenderableCube", kInfo);
}

