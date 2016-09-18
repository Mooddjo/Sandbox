#pragma once

#include "FFeature.h"
#include <memory>
#include "SString.h"
#include "Mesh.h"

namespace sandbox
{
	class MaterialInstance;
	class Material;

	const SString EVENT_RENDER_FEATURE_CREATED = "EVENT_RENDER_FEATURE_CREATED";

	class DLL_SPEC FRenderable: public FFeature
	{
		DECLARE_FEATURE(FRenderable)

	public:
		FRenderable(EEntity* owner, Material* material = nullptr);
		const Mesh* getMesh() const;
		MaterialInstance* getMaterialInstance() const;
		void setMaterial(Material* material);
		virtual void render() = 0;
		virtual void init() override = 0;

	private:
		void updateMaterial();

	protected:
		std::shared_ptr<MaterialInstance> m_materialInstance;
		std::shared_ptr<Mesh> m_mesh;
	};
}