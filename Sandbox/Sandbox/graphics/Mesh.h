#pragma once

#include "Vertex.h"
#include <vector>
#include <memory>

namespace sandbox
{
	class Mesh
	{
	public:
		Mesh();
		void addVertex(Vertex* vertex);
		void addVertex(const vec3& position,const vec3& normal = vec3(),const vec3& color = vec3(),const vec2& uv = vec2());
		void addIndex(unsigned short index);
		const float* getVerticesPosition() const;
		const float* getVerticesNormal() const;
		const float* getVerticesColor() const;
		const float* getVerticesUV() const;
		const unsigned short* getIndices() const;
		unsigned int getVerticesCount() const;
	private:
		std::vector<float> m_position;
		std::vector<float> m_normal;
		std::vector<float> m_color;
		std::vector<float> m_uv;
		std::vector<unsigned short> m_indices;
		unsigned int m_count;
	};
}