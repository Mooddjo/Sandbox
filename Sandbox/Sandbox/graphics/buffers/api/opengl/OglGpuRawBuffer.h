#pragma once

#include "GpuBuffers.h"

namespace sandbox
{
	class OglGpuRawBuffer : public GpuRawBuffer
	{
	public:
		OglGpuRawBuffer(unsigned int size, unsigned int elemenSize, const void* data);
		virtual void bind() const override;
		virtual void unbind() const override;

	private:
	};

}