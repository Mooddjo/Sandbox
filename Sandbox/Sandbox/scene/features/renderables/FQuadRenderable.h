#pragma once
#include "FRenderable.h"
#include "OlgGpuVertexBuffer.h"
#include "GPUBuffers.h"
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
		//OglGpuRawBuffer* m_vbo;
		//OlgGpuVertexBuffer* m_vao;	
		ShaderProgram* m_shader;
	};
}