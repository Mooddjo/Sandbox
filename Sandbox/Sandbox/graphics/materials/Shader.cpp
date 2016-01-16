#include "Shader.h"
#include "StringUtils.h"
#include "SmartLogger.h"

#include <iostream>
#include <string>
#include <vector>

using namespace sandbox;
using namespace std;

/************************************************************************/
/* Shader Program                                                       */
/************************************************************************/

ShaderProgram*
ShaderProgram::createShaderProgram()
{
	ShaderProgram* shaderProgr = new ShaderProgram();
	shaderProgr->m_program = glCreateProgram();
	return  shaderProgr;
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_program);
}

void
ShaderProgram::addShader(Shader* shader)
{
	//deleteShader(shader->getType());
	m_shaders[shader->getType()] = shader;
	glAttachShader(m_program, shader->getId());
}

void
ShaderProgram::deleteShader(ShaderType type)
{
	//Not used
	auto found = m_shaders.find(type);
	if (found != m_shaders.end())
	{
		glDeleteShader(found->second->getId());
		m_shaders.erase(found);
	}
}

void
ShaderProgram::compile()
{
	glLinkProgram(m_program);

	int params = -1;
	glGetProgramiv(m_program, GL_LINK_STATUS, &params);
	if (GL_TRUE != params)
	{
		SMARTLOG("Shader link error", kInfo);
		GLint maxLength = 0;
		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);

		char* infoLog = new char[maxLength];
		glGetProgramInfoLog(m_program, maxLength, &maxLength, infoLog);
		SMARTLOG(infoLog, kInfo);
		glDeleteProgram(m_program);
	}

	
	for (auto it = m_shaders.begin(); it != m_shaders.end(); it++)
	{
		delete it->second;
	}

	m_shaders.clear();
}

unsigned int
ShaderProgram::getId()
{
	return m_program;
}

/************************************************************************/
/* SHADER                                                               */
/************************************************************************/

Shader*
Shader::createShader(SString shaderPath, ShaderType type)
{
	Shader* shader = new Shader();
	shader->m_id = glCreateShader(type);
	shader->m_type = type;
	SString shaderSource = StringUtils::parseFile(shaderPath);
	char* buffer = new char[shaderSource.length() + 1];
	shaderSource.copy(buffer, shaderSource.length());
	shader->m_name = shaderPath;
	buffer[shaderSource.length()] = '\0';
	glShaderSource(shader->getId(), 1, &buffer, nullptr); 
	shader->compileShader();
	delete buffer;
	return shader;
}

GLuint
Shader::getId() const
{
	return m_id;
}

ShaderType
Shader::getType() const
{
	return m_type;
}

SString
Shader::getName() const
{
	return m_name;
}


Shader::~Shader()
{
	glDeleteShader(m_id);
}

void
Shader::compileShader()
{
	GLint shaderId = getId();
	glCompileShader(shaderId);
	GLint result;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		SMARTLOG("Shader " + getName() + " Compilation failed", kInfo);
		GLint logLength;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
		string log;
		log.reserve(logLength);
		GLchar* logCStr = const_cast<GLchar*>(log.c_str());
		glGetShaderInfoLog(shaderId, logLength, NULL, logCStr);
		cout << logCStr << endl;
	}
	else {
		SMARTLOG("Shader " + getName() + " Compilation succeeded", kInfo);
	}
}

