#include "SceneService.h"
#include "SmartLogger.h"

using namespace sandbox;

void SceneService::update(double deltaMs)
{
	if (m_currentScene)
	{
		for (auto sceneObject : m_currentScene->getEntities())
		{
			sceneObject->update(deltaMs);
		}
	}
}

