#pragma once
#include "FRenderable.h"
#include "GPUVertexArray.h"
#include "GPUBuffer.h"
#include "Shader.h"
#include "EEntity.h"

namespace sandbox
{
	class DLL_SPEC FRenderableCube : public FRenderable
	{
		DECLARE_FEATURE(FRenderableCube)

	public:
		FRenderableCube(EEntity* owner);
		virtual void render() const override;
		virtual void init() override;

	private:
		GPUBuffer* m_vbo;
		GPUVertexArray* m_vao;	
		ShaderProgram* m_shader;
	};
}