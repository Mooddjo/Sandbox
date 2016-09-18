#include "Transform.h"
#include "EEntity.h"

using namespace glm;
using namespace sandbox;



Transform::Transform(EEntity* entity):
	m_entity(entity)
{
	
}

glm::mat4
Transform::getLocalMatrix() const
{
	return m_localMatrix;
}

glm::mat4
Transform::getWorldMatrix() const
{
	if (m_parent)
	{
		return m_parent->getLocalMatrix() * getLocalMatrix();
	}
	return getLocalMatrix();

}

void
Transform::setPosition(glm::vec3 position)
{
	m_localMatrix[3] = vec4(position,1.0);
}

void
Transform::setScale(float scale)
{
	m_localMatrix[0].x *= scale;
	m_localMatrix[1].y *= scale;
	m_localMatrix[2].z *= scale;
}

glm::vec4
Transform::getPositiion()
{
	return m_localMatrix[3];
}

EEntity*
Transform::getEntity() const
{
	return m_entity;
}

Transform*
Transform::getChild(SString& name) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

Transform*
Transform::getChild(unsigned int index) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void sandbox::Transform::addChild(Transform* child)
{
	throw std::logic_error("The method or operation is not implemented.");

}

void sandbox::Transform::rotateAboutY(float angle)
{
	mat4x4 rotationMatrix(
		cos(angle), 0.0, sin(angle), 0.0,
		0.0, 1.0, 0.0, 0.0,
		-sin(angle), 0.0, cos(angle), 0.0,
		0.0, 0.0, 0.0, 1.0);

	m_localMatrix *= rotationMatrix;
}
