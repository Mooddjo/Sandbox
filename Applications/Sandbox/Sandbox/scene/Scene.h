#pragma once

#include "Platform.h"
#include <list>
#include <memory>
#include "EEntity.h"

namespace sandbox
{
	class DLL_SPEC Scene
	{
		
	public:
		void addObject(EEntity* object);
		void findObject(std::string name);
		std::list<std::shared_ptr<EEntity>>& getEntities() {return m_entities;};
		//void setCamera(Camera* camera);

	private:
		std::list<std::shared_ptr<EEntity>> m_entities;
		//std::shared_ptr<Camera> m_camera;
	};
}