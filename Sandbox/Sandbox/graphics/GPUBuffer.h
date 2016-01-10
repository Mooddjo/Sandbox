#pragma once

namespace sandbox
{
	class GPUBuffer
	{
	public:
		GPUBuffer(unsigned int size, const float* data);
		void bind() const;
		void unbind() const;
		unsigned int getBufferIndex() const{ return m_bufferIndex; }

	private:
		unsigned int m_bufferIndex;
	};
}