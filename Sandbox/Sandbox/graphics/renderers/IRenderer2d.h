#pragma once

#include "IRenderer.h" 

namespace sandbox
{
	class IRenderer2d : public IRenderer
	{
		virtual bool init() override = 0;
		virtual void buildRenderable(const FRenderable* renderable) override = 0;
		virtual void beginRendering() override = 0;
		virtual void preRender(const FRenderable* renderable) override = 0;
		virtual void render(const FRenderable* renderable) override = 0;
		virtual void postRender(const FRenderable* renderable) override = 0;
		virtual void endRendering() override = 0;
		virtual void clearFrame() override = 0;
	};
}