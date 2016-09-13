#pragma once

#include "AbstractOglRenderer.h"

namespace sandbox
{
	class BasicRenderer2d : public AbstractOglRenderer
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