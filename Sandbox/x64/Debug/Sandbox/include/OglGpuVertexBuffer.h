#pragma once

#include "GPUBuffers.h"

namespace sandbox
{
	class OglGpuVertexBuffer: public GpuVertexBuffer
	{
	public:
		OglGpuVertexBuffer(const GpuRawBuffer* rawBuffer, unsigned int vertexCount);
		void bind() const;
		void unbind() const;
		unsigned int getVertexCount() { return m_vertexCount; }

	private:
	};
}
