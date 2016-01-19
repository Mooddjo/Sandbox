#pragma once
#include "FRenderable.h"
#include "Color.h"

namespace sandbox
{
	class IRenderer
	{
	public:
		virtual bool init() = 0;
		virtual void buildRenderable(const FRenderable* renderable) = 0;
		virtual void beginRendering() = 0;
		virtual void preRender(const FRenderable* renderable) = 0;
		virtual void render(const FRenderable* renderable) = 0;
		virtual void postRender(const FRenderable* renderable) = 0;
		virtual void endRendering() = 0;
		virtual void clearFrame() = 0;
	protected:
		Color m_clearColor;
	};
}