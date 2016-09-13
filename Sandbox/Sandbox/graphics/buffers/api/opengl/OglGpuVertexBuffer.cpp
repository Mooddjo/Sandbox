#include "OglGpuVertexBuffer.h"
#include "GL/glew.h"
#include "Vertex.h"

using namespace sandbox;

OglGpuVertexBuffer::OglGpuVertexBuffer(const GpuRawBuffer* rawBuffer, unsigned int vertexCount):
	GpuVertexBuffer(rawBuffer, vertexCount)
{
	glGenVertexArrays(1, &m_bufferId);
	glBindVertexArray(m_bufferId);
	glEnableVertexAttribArray(0);
	m_gpuRawBuffer->bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
}

void
OglGpuVertexBuffer::bind() const
{
	glBindVertexArray(m_bufferId);
}

void
OglGpuVertexBuffer::unbind() const
{
	glBindVertexArray(0);
}

