#pragma once
#include "FFeature.h"

namespace sandbox
{
	class FUpdatable : public FFeature
	{
		DECLARE_FEATURE(FUpdatable)
	public:
		FUpdatable(EEntity* owner): FFeature(owner){}
		virtual void update(double deltaMs) = 0;
		
	};
}