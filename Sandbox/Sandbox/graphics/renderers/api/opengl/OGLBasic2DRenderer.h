#pragma once

#include "OGLAbstract2DRenderer.h"
#include "Platform.h"

namespace sandbox
{
	class DLL_SPEC OGLBasic2DRenderer : public OGLAbstract2DRenderer
	{
	public:
		virtual void process() override;
	protected:

		virtual bool init() override;
		virtual void render(const RenderData* renderData);

	};
}