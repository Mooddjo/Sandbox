#include "Material.h"
#include "SString.h"
#include "MaterialInstance.h"
using namespace sandbox;

Material::Material(SString materialName):
	m_name(materialName)
{
	Shader* vsShader = Shader::createShader("./resources/shaders/basic_shader.vs", VERTEX_SHADER);
	Shader* fsShader = Shader::createShader("./resources/shaders/basic_shader.fs", FRAGMENT_SHADER);
	m_shader = std::shared_ptr<ShaderProgram>(ShaderProgram::createShaderProgram());
	m_shader->addShader(vsShader);
	m_shader->addShader(fsShader);
	m_shader->compile();
	//setProperty("uColor", vec4(0.3, 0.7, 0.9, 1.0));
	//MaterialProperty* colorProp = MaterialProperty::create(SString("uColor"), vec4(0.3, 0.4, 0.2, 1.0));
	//setProperty(colorProp);
}

MaterialInstance* 
Material::createInstance()
{
	MaterialInstance* matInst = new MaterialInstance(this);
	return matInst;
}

void Material::setShader(ShaderProgram* shaderProgram)
{
	m_shader = std::shared_ptr<ShaderProgram>(shaderProgram);
}


// 
// const std::map<SString, MaterialProperty*>& Material::getProperties()
// {
// 	return m_properties;
// }


sandbox::Material::~Material()
{
	
}

void sandbox::Material::enable() const
{
	m_shader->enable();
}


