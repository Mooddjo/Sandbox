#pragma once
#include "FRenderable.h"
#include "OlgGpuVertexBuffer.h"
#include "GPUBuffers.h"
#include "Shader.h"
#include "Quad.h"
#include "Vertex.h"

namespace sandbox
{
	class DLL_SPEC FRenderable2d : public FRenderable
	{
		DECLARE_FEATURE(FRenderable2d)

	public:
		FRenderable2d(EEntity* owner);
		virtual void render() override;
		virtual void init() override;

	private:
// 		std::shared_ptr<OglGpuRawBuffer> m_buffer;
// 		std::shared_ptr<OlgGpuVertexBuffer> m_vao;
// 		std::shared_ptr<OglGpuIndexBuffer> m_ib;
	};
}