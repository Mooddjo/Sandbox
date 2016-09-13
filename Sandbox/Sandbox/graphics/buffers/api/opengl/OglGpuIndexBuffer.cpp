#include "OglGpuIndexBuffer.h"
#include "GL/glew.h"

using namespace sandbox;

sandbox::OglGpuIndexBuffer::OglGpuIndexBuffer(unsigned int size, const void* data):
	GpuIndexBuffer(size, data)
{
	glGenBuffers(1, &m_bufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_bufferSize * sizeof(GLushort), m_data, GL_STATIC_DRAW);
}

void sandbox::OglGpuIndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
}

void sandbox::OglGpuIndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}