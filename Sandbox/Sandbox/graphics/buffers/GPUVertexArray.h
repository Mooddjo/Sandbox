#pragma once

#include "GPUBuffer.h"

namespace sandbox
{
	class GPUVertexArray
	{
	public:
		GPUVertexArray(GPURawBuffer* vbo, unsigned int vertexCount);
		void bind() const;
		void unbind() const;
		unsigned int getVertexCount() { return m_vertexCount; }

	private:
		unsigned int m_vertexArrayIndex;
		unsigned int m_vertexCount;
	};
}

