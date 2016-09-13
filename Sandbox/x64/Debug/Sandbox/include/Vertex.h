#pragma once

#include "MathUtils.h"

namespace sandbox
{
	class Vertex
	{
	public:
		Vertex(vec3 position = vec3(), vec3 normal = vec3(), vec3 color = vec3(), vec2 uv = vec2());
		~Vertex() = default;
		Vertex(const Vertex&) = default;
		Vertex(Vertex&&) = default;
		Vertex& operator=(const Vertex& v) = default;
		Vertex& operator=(Vertex&& v) = default;


		const vec3& getPosition() { return m_position; }
		const vec3& getNormal() { return m_normal; }
		const vec3& getColor() { return m_color; }
		const vec2& getUV() { return m_uv; }
	public:
		vec3 m_position;
		vec3 m_normal;
		vec3 m_color;
		vec2 m_uv;
	};

}