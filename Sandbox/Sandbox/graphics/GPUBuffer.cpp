#include "GPUBuffer.h"
#include "GL/glew.h"

using namespace sandbox;

GPUBuffer::GPUBuffer(unsigned int size,const float* data)
{
	glGenBuffers(1, &m_bufferIndex);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferIndex);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat) , data, GL_STATIC_DRAW);
}

void
GPUBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferIndex);
}

void
GPUBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
