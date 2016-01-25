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

const Transform* 
EEntity::getTransform() const
{
	return &m_transform;
}

Transform* sandbox::EEntity::getTransform()
{
	return const_cast<Transform*>(static_cast<const EEntity&>(*this).getTransform());
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
	//this->addFeature(static_cast<FFeature*>(feature));
	feature->init();
	m_updatableFeatures.push_back((feature));
}

void
EEntity::removeFeature(SString featureName)
{
	throw std::logic_error("The method or operation is not implemented.");
}


