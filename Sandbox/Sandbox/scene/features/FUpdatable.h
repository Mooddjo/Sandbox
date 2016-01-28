#pragma once
#include "FFeature.h"

namespace sandbox
{
	class DLL_SPEC FUpdatable : public FFeature
	{
		DECLARE_FEATURE(FUpdatable)
	public:
		FUpdatable(EEntity* owner): FFeature(owner){}
		virtual void init() override = 0;
		virtual void update(double deltaMs) = 0;
		
	};
}