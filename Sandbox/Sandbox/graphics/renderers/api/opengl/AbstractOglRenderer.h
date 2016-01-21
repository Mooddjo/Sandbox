#pragma once

#include "AbstractRenderer.h"

namespace sandbox
{
	class AbstractOglRenderer: public AbstractRenderer
	{
	public:
		virtual bool init() override;
		virtual void clearFrame() override;

	};
}