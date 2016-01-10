#pragma once
#include "IRenderer.h"
#include "GPUVertexArray.h"

namespace sandbox
{
	class OGLRenderer : public IRenderer
	{
	public:
		static const float backgroundColor[];
		virtual void drawVertexArray(GPUVertexArray* vao) override;
		virtual bool init() override;
		virtual void clear() override;
	};
}
