#include "AbstractRenderer.h"


using namespace sandbox;


void sandbox::AbstractRenderer::renderable2dCreated(const FRenderable* renderable)
{
	RenderData* renderData = new RenderData(renderable);
	m_renderData.push_back(renderData);
}

void sandbox::AbstractRenderer::renderable2dOnStart(const FRenderable* renderable)
{

}

void sandbox::AbstractRenderer::renderable2dOnExit(const FRenderable* renderable)
{
	std::logic_error("Not implemented yet");
}