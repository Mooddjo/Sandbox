#include "GPUVertexArray.h"
#include "GL/glew.h"

using namespace sandbox;

GPUVertexArray::GPUVertexArray(GPUBuffer* vertexBuffer, unsigned int vertexCount):
	m_vertexArrayIndex(0),
	m_vertexCount(vertexCount)
{
	glGenVertexArrays(1, &m_vertexArrayIndex);
	glBindVertexArray(m_vertexArrayIndex);
	glEnableVertexAttribArray(0);
	vertexBuffer->bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}

void
GPUVertexArray::bind() const
{
	glBindVertexArray(m_vertexArrayIndex);
}

void
GPUVertexArray::unbind() const
{
	glBindVertexArray(0);
}

