#pragma once

#include "FRenderable.h"
#include "GpuBuffers.h"

namespace sandbox
{
	class RenderData
	{
	public:
		RenderData(const FRenderable* renderable);
	private:
		GpuRawBuffer* m_dataBuffer;
		GpuVertexBuffer* m_vertexBuffer;
		GpuIndexBuffer* m_indexBuffer;
	};
}