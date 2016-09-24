#pragma once

#include "Abstract2DRenderer.h"

namespace sandbox
{
	class OGLAbstract2DRenderer: public Abstract2DRenderer
	{
	public:
		virtual bool init() override;
		virtual void clearFrame();

	};
}