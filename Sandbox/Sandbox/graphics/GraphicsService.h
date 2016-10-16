#pragma once

#include "Singleton.h"
#include "GpuBuffers.h"
#include "AbstractRenderer.h"
#include "Mesh.h"

namespace sandbox
{
	class GraphicsService : public Singleton<GraphicsService>
	{
		friend class Singleton<GraphicsService>;

	public:
		GraphicsService();
		GpuRawBuffer* provideGpuRawBuffer(unsigned int size, unsigned int elementSize, const void* data);
		GpuIndexBuffer* provideGpuIndexBuffer(unsigned int size, const void* data);
		GpuVertexBuffer* provideGpuVertexArray(const GpuRawBuffer* rawBuffer, unsigned int vertexCount);
		void render();
		AbstractRenderer* getRenderer2d();
		AbstractRenderer* getRenderer3d();
		GpuRawBuffer* buildGpuRawBufferFromMesh(const Mesh* mesh);
	private:
		AbstractRenderer* m_renderer2d;
	};
}