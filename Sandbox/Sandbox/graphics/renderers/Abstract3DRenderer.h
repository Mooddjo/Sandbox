#pragma once

#include "AbstractRenderer.h"
#include "Platform.h"

namespace sandbox
{
	class Abstract3DRenderer : public AbstractRenderer
	{
	public:
		virtual bool init() override;
		virtual void process() override;
	};

};