#pragma once

#include "GpuBuffers.h"

namespace sandbox
{
	class OglGpuIndexBuffer : public GpuIndexBuffer
	{
	public:
		OglGpuIndexBuffer(unsigned int size, const void* data);
		virtual void bind() const override;
		virtual void unbind() const override;

	};
}