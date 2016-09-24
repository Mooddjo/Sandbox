#include "GraphicsService.h"


#define OPENGL 1
#define BASIC_2D_RENDERER 1

#if OPENGL
#include "OglGpuIndexBuffer.h"
#include "OglGpuVertexBuffer.h"
#include "OglGpuRawBuffer.h"
#endif

#if BASIC_2D_RENDERER
#include "OGLBasic2DRenderer.h"
#endif

using namespace sandbox;

sandbox::GraphicsService::GraphicsService()
{
#if OPENGL
	m_renderer2d = new OGLBasic2DRenderer();
	m_renderer2d->init();
#endif
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
	indexBuffer = new OglGpuIndexBuffer(size, data);
#endif

	return indexBuffer;
}

GpuVertexBuffer* sandbox::GraphicsService::provideGpuVertexArray(const GpuRawBuffer* rawBuffer, unsigned int vertexCount)
{
	GpuVertexBuffer* vertexBuffer = nullptr;
#if OPENGL
	vertexBuffer = new OglGpuVertexBuffer(rawBuffer, vertexCount);
#endif

	return vertexBuffer;
}

void sandbox::GraphicsService::render()
{
	m_renderer2d->process();
}

AbstractRenderer* sandbox::GraphicsService::getRenderer2d()
{
	if (m_renderer2d)
	{
		return m_renderer2d;
	}
	else
	{
#if BASIC_2D_RENDERER
		m_renderer2d = new OGLBasic2DRenderer();
#endif
	}

	return m_renderer2d;

}

AbstractRenderer* sandbox::GraphicsService::getRenderer3d()
{
	std::logic_error("Not implemented yet");
	return nullptr;
}
