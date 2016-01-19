#pragma once

#include "Singleton.h"
#include "GpuBuffers.h"
#include "IRenderer2d.h"
#include "IRenderer3d.h"

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
		IRenderer2d* getRenderer2d();
		IRenderer3d* getRenderer3d();

	private:
		IRenderer2d* m_renderer2d;
	};
}