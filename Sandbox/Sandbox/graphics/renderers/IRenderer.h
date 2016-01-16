#pragma once
#include "GPUVertexArray.h"

namespace sandbox
{
	class IRenderer
	{
	public:
		virtual void drawVertexArray(GPUVertexArray* vao) = 0;
		virtual void drawElementArray(GPUIndexBuffer* ib) = 0;
		virtual bool init() = 0;
		virtual void clear() = 0;
	};
}