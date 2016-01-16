#pragma once
#include "FRenderable.h"
#include "GPUVertexArray.h"
#include "GPUBuffer.h"
#include "Shader.h"
#include "EEntity.h"

namespace sandbox
{
	class DLL_SPEC FQuadRenderable : public FRenderable
	{
		DECLARE_FEATURE(FQuadRenderable)

	public:
		FQuadRenderable(EEntity* owner);
		virtual void render() override;
		virtual void init() override;

	private:
		GPURawBuffer* m_vbo;
		GPUVertexArray* m_vao;	
		ShaderProgram* m_shader;
	};
}