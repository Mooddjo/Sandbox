#include "GPUBuffer.h"
#include "GL/glew.h"

using namespace sandbox;

GPURawBuffer::GPURawBuffer(unsigned int size, unsigned int elemenSize, const void* data)
{
	m_bufferSize = size;
	glGenBuffers(1, &m_bufferIndex);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferIndex);
	glBufferData(GL_ARRAY_BUFFER, size * elemenSize, data, GL_STATIC_DRAW);
}

void
GPURawBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferIndex);
}

void
GPURawBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


sandbox::GPUIndexBuffer::GPUIndexBuffer(unsigned int size, const void* data)
{
	m_bufferSize = size;
	glGenBuffers(1, &m_bufferIndex);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferIndex);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLushort), data, GL_STATIC_DRAW);
}

void sandbox::GPUIndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferIndex);
}

void sandbox::GPUIndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
