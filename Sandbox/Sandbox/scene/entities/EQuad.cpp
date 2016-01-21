#include "EQuad.h"
#include "FRenderable2d.h"
#include "SmartLogger.h"

using namespace sandbox;


EQuad::EQuad(float size)
{
	FRenderable* renderFeature = new FRenderable2d(this);
	addFeature(renderFeature);
}
