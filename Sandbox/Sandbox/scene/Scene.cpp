#include "Scene.h"

using namespace sandbox;

void
Scene::addObject(EEntity* object)
{
	std::shared_ptr<EEntity> sharedObject = std::shared_ptr<EEntity>(object);
	m_entities.push_back(sharedObject);
}

// void
// Scene::setCamera(Camera* camera)
// {
// 	m_camera = std::shared_ptr<Camera>(camera);
// 	this->addObject(camera);
// }

void
Scene::findObject(std::string name)
{
	throw std::logic_error("The method or operation is not implemented.");
}



