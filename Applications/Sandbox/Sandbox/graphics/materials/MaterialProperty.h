#pragma once

#include <iostream>
#include "SString.h"

#define OPENGL 1

namespace sandbox
{
	enum PropertyType
	{
		kMatrix,
		kVec2,
		kVev3,
		kVec4,
		kInt,
		kFloat,
		kString,
		kDouble,
		kTexture
	};

	class MaterialProperty
	{

		class GenericValue
		{
		public:
			GenericValue(SString name) : m_name(name) {};
			SString m_name;
			virtual void submit(unsigned int materialId) = 0;
		};

		template<typename T>
		class Value : public GenericValue
		{
		public:
			Value(SString name, T value) :GenericValue(name)
			{
				data = value;
			}
			virtual void submit(unsigned int materialId) override
			{
				throw std::logic_error("Material type specialization has to be defined");
			};
			T data;
		};

	public:
		template<typename T> static MaterialProperty* create(SString name, T value)
		{
			MaterialProperty* matProp = new MaterialProperty();
			matProp->m_value = new Value<T>(name, value);
			return matProp;
		}

		template<typename T> void setValue(SString name, T value) { m_value = new Value<T>(name, value); }
		inline void submit(unsigned int materialId) const { m_value->submit(materialId); }
		SString getName() { return m_value->m_name; }

		GenericValue* m_value;
	private:
	};


}

#if OPENGL
#include "OGLMaterialProperty.h"
#endif