#pragma once

#include "AbstractOglRenderer.h"
#include "Platform.h"

namespace sandbox
{
	class DLL_SPEC BasicRenderer2d : public AbstractOglRenderer
	{
	public:
		virtual void process() override;
	protected:

		virtual bool init() override;
		virtual void beginRendering() override;
		virtual void render(const RenderData* renderData) override;
		virtual void endRendering() override;

	};
}