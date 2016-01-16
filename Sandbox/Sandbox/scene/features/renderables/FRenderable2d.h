#pragma once
#include "FRenderable.h"
#include "GPUVertexArray.h"
#include "GPUBuffer.h"
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
		std::shared_ptr<GPURawBuffer> m_buffer;
		std::shared_ptr<GPUVertexArray> m_vao;
		std::shared_ptr<GPUIndexBuffer> m_ib;
		Quad m_2dMesh;
	};
}