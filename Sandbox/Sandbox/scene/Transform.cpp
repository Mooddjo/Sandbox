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
Transform::setPosition(glm::vec4 position)
{
	m_localMatrix[3] = position;
}

glm::vec4
Transform::getPositiion()
{
	return m_localMatrix[3];
}

EEntity*
Transform::getEnity() const
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
