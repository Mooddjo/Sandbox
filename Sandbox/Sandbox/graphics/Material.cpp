#include "Material.h"

using namespace sandbox;

Material::Material()
{
	Shader* vsShader = Shader::createShader("./resources/shaders/basic_shader.vs", VERTEX_SHADER);
	Shader* fsShader = Shader::createShader("./resources/shaders/basic_shader.fs", FRAGMENT_SHADER);
	m_shader = std::shared_ptr<ShaderProgram>(ShaderProgram::createShaderProgram());
	m_shader->addShader(vsShader);
	m_shader->addShader(fsShader);
	m_shader->compile();
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

const std::map<std::string, MaterialProperty*>& Material::getProperties()
{
	return m_properties;
}