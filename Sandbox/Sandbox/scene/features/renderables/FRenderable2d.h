#pragma once
#include "FRenderable.h"
#include "GPUVertexArray.h"
#include "GPUBuffer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Vertex.h"

namespace sandbox
{
	class DLL_SPEC FRenderable2d : public FRenderable
	{
		DECLARE_FEATURE(FRenderable2d)

	public:
		FRenderable2d(EEntity* owner);
		virtual void render() const override;
		virtual void init() override;

	private:
		std::shared_ptr<GPUBuffer> m_buffer;
		std::shared_ptr<GPUVertexArray> m_vao;
		Mesh m_mesh2d;

		//GPUBuffer* m_vbo;
		//GPUVertexArray* m_vao;
		//ShaderProgram* m_shader;
	};
}