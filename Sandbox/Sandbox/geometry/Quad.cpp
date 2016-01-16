#include "Quad.h"

using namespace sandbox;

Quad::Quad()
{
	addVertex(vec3(-0.5, 0.5, 0.0));
	addVertex(vec3(0.5, 0.5, 0.0));
	addVertex(vec3(0.5, -0.5, 0.0));
	addVertex(vec3(-0.5, -0.5, 0.0));

	addIndex(vec3(0, 1, 2));
	addIndex(vec3(2, 3, 0));
}

