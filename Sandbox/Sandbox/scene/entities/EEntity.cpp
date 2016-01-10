#include "EEntity.h"

#include "SmartLogger.h"

using namespace sandbox;

unsigned int EEntity::s_idCounter = 0;


EEntity::EEntity():
	m_transform(this),
	m_id(s_idCounter)
{
	s_idCounter++;
}

Transform* 
EEntity::getTransform()
{
	return &m_transform;
}

void
EEntity::update(double deltaMs)
{
	for (auto updatable : m_updatableFeatures)
	{
		if (updatable->isEnable())
		{
			updatable->update(deltaMs);
		}
	}
}

void
EEntity::addFeature(FFeature* feature)
{
	feature->init();
	m_features.push_back(std::shared_ptr<FFeature>(feature));
}

void
EEntity::addFeature(FUpdatable* feature)
{
	this->addFeature(static_cast<FFeature*>(feature));
	m_updatableFeatures.push_back((feature));
}

void
EEntity::removeFeature(std::string featureName)
{
	throw std::logic_error("The method or operation is not implemented.");
}



