#pragma once

#include "IRenderer2d.h"

namespace sandbox
{
	class BasicRenderer2d : public IRenderer2d
	{
	public:
		virtual bool init() override;
		virtual void beginRendering() override;
		virtual void buildRenderable(const FRenderable* renderable) override;
		virtual void preRender(const FRenderable* renderable) override;
		virtual void render(const FRenderable* renderable) override;
		virtual void postRender(const FRenderable* renderable) override;
		virtual void endRendering() override;
		virtual void clearFrame() override;

	};
}