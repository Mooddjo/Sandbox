#pragma once

#include "Platform.h"
#include "Transform.h"
#include "FFeature.h"
#include "FUpdatable.h"
#include "SString.h"
#include <string>
#include <memory>

namespace sandbox
{
	class DLL_SPEC EEntity
	{
	public:
		EEntity();
		const Transform* getTransform() const;
		Transform* getTransform();
		void update(double deltaMs);
		void addFeature(FFeature* feature);
		void addFeature(FUpdatable* feature);
		void removeFeature(SString featureName);
		template<typename T> T* getFeature();
		bool isEnable() const { return m_isEnable; }
		void setEnable(bool val) { m_isEnable = val; }

	private:
		static unsigned int s_idCounter;
		unsigned int m_id;
		SString m_name;
		bool m_isEnable;
		Transform m_transform;
		std::list<std::shared_ptr<FFeature>> m_features;
		std::list<FUpdatable*> m_updatableFeatures;
	};

	template<typename T>
	T* sandbox::EEntity::getFeature()
	{
		for (auto feature : m_features)
		{
			if (feature->getName().compare(T::name()) == 0)
			{
				return static_cast<T*>(feature.get());
			}
		}

// 		for (auto updatablefeature : m_updatableFeatures)
// 		{
// 			if (updatablefeature->getName().compare(T::name()) == 0)
// 			{
// 				return static_cast<T*>(updatablefeature.get());
// 			}
// 		}
		return nullptr;
	}

}