#include "Material.h"
#include "SString.h"

using namespace sandbox;

Material::Material()
{
	Shader* vsShader = Shader::createShader("./resources/shaders/basic_shader.vs", VERTEX_SHADER);
	Shader* fsShader = Shader::createShader("./resources/shaders/basic_shader.fs", FRAGMENT_SHADER);
	m_shader = std::shared_ptr<ShaderProgram>(ShaderProgram::createShaderProgram());
	m_shader->addShader(vsShader);
	m_shader->addShader(fsShader);
	m_shader->compile();
	MaterialProperty* colorProp = MaterialProperty::create(SString("uColor"), vec4(0.3, 0.4, 0.2, 1.0), kVec4);
	addProperty(colorProp);
}

void Material::setShader(ShaderProgram* shaderProgram)
{
	m_shader = std::shared_ptr<ShaderProgram>(shaderProgram);
}

void Material::addProperty(MaterialProperty* property)
{
	//TODO delete property if exists
	if (property)
	{
		m_properties[property->getName()] = property;
	}
}

const std::map<SString, MaterialProperty*>& Material::getProperties()
{
	return m_properties;
}

void sandbox::Material::enable() const
{
	m_shader->enable();
	for (auto it : m_properties)
	{
		MaterialProperty* prop = it.second;
		prop->submit(m_shader->getId());
	}
}
