#include "GraphicsService.h"


#define OPENGL 1
#define BASIC_2D_RENDERER 1

#if OPENGL
#include "OglGpuIndexBuffer.h"
#include "OlgGpuVertexBuffer.h"
#include "OglGpuRawBuffer.h"
#endif

#if BASIC_2D_RENDERER
#include "BasicRenderer2d.h"
#endif

using namespace sandbox;

sandbox::GraphicsService::GraphicsService()
{

}

GpuRawBuffer* sandbox::GraphicsService::provideGpuRawBuffer(unsigned int size, unsigned int elementSize, const void* data)
{
	GpuRawBuffer* rawBuffer = nullptr;
#if OPENGL
	rawBuffer = new OglGpuRawBuffer(size, elementSize, data);
#endif

	return rawBuffer;
}

GpuIndexBuffer* sandbox::GraphicsService::provideGpuIndexBuffer(unsigned int size, const void* data)
{
	GpuIndexBuffer* indexBuffer = nullptr;
#if OPENGL
	indexBuffer = new OglGpuIndexBuffer();
#endif

	return indexBuffer;
}

GpuVertexBuffer* sandbox::GraphicsService::provideGpuVertexArray(const GpuRawBuffer* rawBuffer, unsigned int vertexCount)
{
	GpuVertexBuffer* vertexBuffer = nullptr;
#if OPENGL
	vertexBuffer = new OlgGpuVertexBuffer(rawBuffer, vertexCount);
#endif

	return vertexBuffer;
}

IRenderer2d* sandbox::GraphicsService::getRenderer2d()
{
	if (m_renderer2d)
	{
		return m_renderer2d;
	}
	else
	{
#if BASIC_2D_RENDERER
		m_renderer2d = new BasicRenderer2d();
#endif
	}

}

IRenderer3d* sandbox::GraphicsService::getRenderer3d()
{
	std::logic_error("Not implemented yet");
}
