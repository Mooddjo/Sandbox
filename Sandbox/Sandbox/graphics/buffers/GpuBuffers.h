#pragma once

#include "SmartLogger.h"

namespace sandbox
{

	class GpuBuffer
	{
	public:
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		unsigned int getId() const { return m_bufferId; }
		unsigned int getSize() const { return m_bufferSize;}
		const void* getData() const { return m_data; }

	protected:
		const void* m_data;
		unsigned int m_bufferId;
		unsigned int m_bufferSize;

	};

	class GpuRawBuffer: public GpuBuffer
	{
	public:
		virtual void addData(GpuRawBuffer& buffer) = 0;
		
		GpuRawBuffer(unsigned int size, unsigned int elementSize, const void* data):
			m_elementSize(elementSize){
			m_bufferSize = size;
			m_data = data;
		}
	protected:
		unsigned int m_elementSize;
	};

	class GpuIndexBuffer : public GpuBuffer
	{
	public:
		GpuIndexBuffer(unsigned int size, const void* data)
		{
			m_bufferSize = size;
			m_data = data;
		}
	protected:
	};

	class GpuVertexBuffer : public GpuBuffer
	{
	public: 
		GpuVertexBuffer(const GpuRawBuffer* rawBuffer, unsigned int vertexCount): 
			m_gpuRawBuffer(rawBuffer),
			m_vertexCount(vertexCount){};
	protected:
		const GpuRawBuffer* m_gpuRawBuffer;
		unsigned int m_vertexCount;
	};
}