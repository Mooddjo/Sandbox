#pragma once

#include "FRenderable.h"
#include "GpuBuffers.h"

namespace sandbox
{
	class RenderData
	{
	public:
		RenderData(const FRenderable* renderable);
		void draw() const;

	private:
		GpuRawBuffer* m_dataBuffer;
		GpuVertexBuffer* m_vertexBuffer;
		GpuIndexBuffer* m_indexBuffer;
		Material* m_material;
	};
}