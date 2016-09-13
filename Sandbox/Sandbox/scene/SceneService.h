#pragma once

#include "Platform.h"
#include "Singleton.h"
#include <memory>
#include "Scene.h"

namespace sandbox
{
	class DLL_SPEC SceneService : public Singleton<SceneService>
	{
		friend class Singleton<SceneService>;
	public:

		std::shared_ptr<Scene> getScene() const { return m_currentScene; }
		void loadScene(Scene* scene) { m_currentScene = std::shared_ptr<Scene>(scene); }
		void update(double deltaMs);

	private:
		SceneService() = default;
		SceneService(const SceneService&) = delete;
		SceneService& operator= (const SceneService&) = delete;
		
		std::shared_ptr<Scene> m_currentScene;

	};

	

}