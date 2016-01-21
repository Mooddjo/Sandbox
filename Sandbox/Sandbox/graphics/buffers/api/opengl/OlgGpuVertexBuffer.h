#pragma once

#include "GPUBuffers.h"

namespace sandbox
{
	class OlgGpuVertexBuffer: public GpuVertexBuffer
	{
	public:
		OlgGpuVertexBuffer(const GpuRawBuffer* rawBuffer, unsigned int vertexCount);
		void bind() const;
		void unbind() const;
		unsigned int getVertexCount() { return m_vertexCount; }

	private:
	};
}
