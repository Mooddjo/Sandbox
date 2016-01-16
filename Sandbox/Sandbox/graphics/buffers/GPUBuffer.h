#pragma once

namespace sandbox
{

	class IGPUBuffer
	{
	public:
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		unsigned int getBufferIndex() const { return m_bufferIndex; }
		unsigned int getSize() const { return m_bufferSize;}
	protected:
		unsigned int m_bufferIndex;
		unsigned int m_bufferSize;
	};

	class GPURawBuffer: public IGPUBuffer
	{
	public:
		GPURawBuffer(unsigned int size, unsigned int elemenSize, const void* data);
		virtual void bind() const override;
		virtual void unbind() const override;

	private:
	};

	class GPUIndexBuffer: public IGPUBuffer
	{
	public:
		GPUIndexBuffer(unsigned int size, const void* data);
		virtual void bind() const override;
		virtual void unbind() const override;

	};
}