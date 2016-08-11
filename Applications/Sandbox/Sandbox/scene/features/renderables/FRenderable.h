#pragma once

#include "FFeature.h"
#include "Material.h"
#include <memory>
#include "SString.h"
#include "Mesh.h"

namespace sandbox
{
	const SString EVENT_RENDER_FEATURE_CREATED = "EVENT_RENDER_FEATURE_CREATED";

	class DLL_SPEC FRenderable: public FFeature
	{
		DECLARE_FEATURE(FRenderable)

	public:
		FRenderable(EEntity* owner, Material* material = nullptr);
		const Mesh* getMesh() const;
		Material* getMaterial() const;
		void setMaterial(Material* material);
		virtual void render() = 0;
		virtual void init() override = 0;

	private:
		void updateMaterial();

	protected:
		std::shared_ptr<Material> m_material;
		std::shared_ptr<Mesh> m_mesh;
	};
}