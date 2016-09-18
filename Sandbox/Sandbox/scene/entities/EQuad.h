#pragma once

#include "Platform.h"
#include "EEntity.h"

namespace sandbox
{
	class DLL_SPEC EQuad: public EEntity
	{
	public:
		EQuad(float size, const vec3& position = vec3(0.f, 0.f, 0.f));

	private:
	};
}