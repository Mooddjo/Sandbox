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
			GenericValue(SString name, PropertyType type) : m_name(name), m_type(type) {};
			SString m_name;
			PropertyType m_type;
			virtual void submit() = 0;
		};

		template<typename T>
		class Value : public GenericValue
		{
		public:
			Value(SString name, T value, PropertyType type) :GenericValue(name, type)
			{
				data = value;
			}
			virtual void submit() override
			{
				throw std::logic_error("Material type specialization has to be defined");
			};
			T data;
		};

	public:
		template<typename T> static MaterialProperty* create(SString name, T value, PropertyType type)
		{
			MaterialProperty* matProp = new MaterialProperty();
			matProp->m_value = new Value<T>(name, value, type);
			return matProp;
		}

		void submit() const { m_value->submit(); }
		SString getName() { return m_value->m_name; }

	private:
		GenericValue* m_value;



	};


}

#if OPENGL
#include "OGLMaterialProperty.h"
#endif