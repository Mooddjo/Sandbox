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
		GpuRawBuffer* provideGpuRawBuffer();
		GpuIndexBuffer* provideGpuIndexBuffer();
		GpuVertexBuffer* provideGpuVertexArray();

		IRenderer2d* getRenderer2d();
		IRenderer3d* getRenderer3d();

	private:

	};
}