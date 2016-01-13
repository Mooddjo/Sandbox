#include "Mesh.h"


using namespace sandbox;


sandbox::Mesh::Mesh():
	m_count(0)
{

}

void
Mesh::addVertex(Vertex* vertex)
{
	if (vertex)
	{
		addVertex(vertex->getPosition(),
			vertex->getNormal(),
			vertex->getColor(),
			vertex->getUV());
	}
}

void
Mesh::addVertex(const vec3& position, const vec3& normal, const vec3& color, const vec2& uv)
{
	m_position.push_back(position.x);
	m_position.push_back(position.y);
	m_position.push_back(position.z);

	m_color.push_back(color.r);
	m_color.push_back(color.g);
	m_color.push_back(color.b);

	m_normal.push_back(normal.x);
	m_normal.push_back(normal.y);
	m_normal.push_back(normal.z);

	m_uv.push_back(uv.s);
	m_uv.push_back(uv.t);

	m_count++;
}

void
Mesh::addIndex(unsigned short index)
{
	m_indices.push_back(index);
}

const unsigned short*
Mesh::getIndices() const
{
	return (&m_indices[0]);
}

const float*
Mesh::getVerticesUV() const
{
	return (&m_uv[0]);
}


const float* sandbox::Mesh::getVerticesPosition() const
{
	return (&m_position[0]);
}

unsigned int
Mesh::getVerticesCount() const
{
	return m_count;
}

const float*
Mesh::getVerticesColor() const
{
	return (&m_color[0]);
}

const float*
Mesh::getVerticesNormal() const
{
	return (&m_normal[0]);
}
