#pragma once

#include "Vertex.h"
#include <vector>
#include <deque>
#include "GpuBuffers.h"

namespace sandbox
{
	class Mesh
	{
	public:
		Mesh();
		void addVertex(Vertex& vertex);
		void addVertex(const vec3& position,const vec3& normal = vec3(),const vec3& color = vec3(),const vec2& uv = vec2());
		void addIndex(unsigned short index);
		void addIndex(vec3 index);
		const std::vector<Vertex>& getVertices() const;
		const std::vector<unsigned short>& getIndices() const;
		const void* getVerticesPointer() const;
		const unsigned short* getIndicesPointer() const;
		unsigned int getVerticesCount() const;
		unsigned int getIndexCount() const;
		unsigned  short getVertexSize() const;
		void clearIndices();
		void clearVertices();
		void clear();

		static GpuRawBuffer* buildGpuRawBufferWithMesh(Mesh* mesh);
	private:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned short> m_indices;
	};
}