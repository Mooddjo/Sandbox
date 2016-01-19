#pragma once
#include "IRenderer.h"
#include "GPUBuffers.h"

namespace sandbox
{
	class OGLRenderer : public IRenderer
	{
	public:
		static const float backgroundColor[];
		//virtual void drawVertexArray(OlgGpuVertexBuffer* vao) override;
		//virtual void drawElementArray(OglGpuIndexBuffer* ib) override;
		virtual bool init() override;
		virtual void clearFrame() override;
		virtual void buildRenderable(const FRenderable* renderable) override;
		virtual void beginRendering() override;
		virtual void preRender(const FRenderable* renderable) override;
		virtual void render(const FRenderable* renderable) override;
		virtual void postRender(const FRenderable* renderable) override;
		virtual void endRendering() override;

	};
}
