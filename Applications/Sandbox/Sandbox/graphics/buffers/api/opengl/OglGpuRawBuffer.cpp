#include <GL/glew.h>
#include "OglGpuRawBuffer.h"

using namespace sandbox;

OglGpuRawBuffer::OglGpuRawBuffer(unsigned int size, unsigned int elemenSize, const void* data):
	GpuRawBuffer(size, elemenSize, data)
{
	glGenBuffers(1, &m_bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
	glBufferData(GL_ARRAY_BUFFER, m_bufferSize * m_elementSize, m_data, GL_STATIC_DRAW);
}

void
OglGpuRawBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
}

void
OglGpuRawBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

