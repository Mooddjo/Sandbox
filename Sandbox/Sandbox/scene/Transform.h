#pragma once

#include "Platform.h"
#include "MathUtils.h"
#include "SString.h"
#include <list>

namespace sandbox
{
	class EEntity;

	class DLL_SPEC Transform
	{
	public:
		Transform(EEntity* entity);
		Transform(const EEntity&) = delete;
		Transform& operator=(const EEntity&) = delete;

		void addChild(Transform* child);
		Transform* getChild(SString& name) const;
		Transform* getChild(unsigned int index) const;

		mat4x4 getLocalMatrix() const;
		mat4x4 getWorldMatrix() const;
		void setPosition(vec3 position);
		vec4 getPositiion();
		EEntity* getEnity() const;

	private:
		mat4x4 m_localMatrix;
		std::list<Transform*> children;
		Transform* m_parent;
		EEntity* m_entity;
	};
}