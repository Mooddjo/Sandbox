#pragma once

#include "AbstractRenderer.h"

namespace sandbox
{
	class BasicRenderer2d : public AbstractRenderer
	{
	public:
		virtual bool init() override;
		virtual bool process() override;
	protected:

		virtual void beginRendering() override;
		virtual void render(const RenderData* renderable) override;
		virtual void endRendering() override;
		virtual void clearFrame() override;

	};
}