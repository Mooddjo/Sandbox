#include "Mesh.h"


using namespace sandbox;
using namespace std;

const unsigned short vertices_size = 1000;

sandbox::Mesh::Mesh()
{
	m_vertices.reserve(vertices_size);
}

void
Mesh::addVertex(Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void
Mesh::addVertex(const vec3& position, const vec3& normal, const vec3& color, const vec2& uv)
{
	Vertex v(position, normal, color, uv);
	addVertex(v);
}

void
Mesh::addIndex(unsigned short index)
{
	m_indices.push_back(index);
}

void
Mesh::addIndex(vec3 index)
{
	m_indices.push_back(index.x);
	m_indices.push_back(index.y);
	m_indices.push_back(index.z);
}


const std::vector<Vertex>& 
sandbox::Mesh::getVertices() const
{
	return m_vertices;
}

const std::vector<unsigned short>&
sandbox::Mesh::getIndices() const
{
	return m_indices;
}

const unsigned short*
Mesh::getIndicesPointer() const
{
	return (&m_indices[0]);
}

const void* sandbox::Mesh::getVerticesPointer()
{
	return (&m_vertices[0]);
}


unsigned int sandbox::Mesh::getIndexCount() const
{
	return m_indices.size();
}

void sandbox::Mesh::clearIndices()
{
	m_indices.clear();
}

void sandbox::Mesh::clearVertices()
{
	m_vertices.clear();
}

void sandbox::Mesh::clear()
{
	clearIndices();
	clearVertices();
}

unsigned short
Mesh::getVertexSize() const
{
	return sizeof(Vertex);
}

unsigned int
Mesh::getVerticesCount() const
{
	return m_vertices.size();
}
