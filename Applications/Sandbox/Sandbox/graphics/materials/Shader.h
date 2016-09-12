#pragma once

#include "Platform.h"
//#include "gl/glew.h"
#include <OpenGL/gl3.h>
#include "SString.h"
#include <map>
#include <iostream>

namespace sandbox
{
	enum ShaderType
	{
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
		VERTEX_SHADER = GL_VERTEX_SHADER,
		GEOMETRY_SHADER = GL_GEOMETRY_SHADER,
		//COMPUTE_SHADER = GL_COMPUTE_SHADER
	};
	class DLL_SPEC Shader
	{
	public:

		/// @brief 		Create a shader from filename path
		/// @details	You have to manage memory of the instance returned
		/// @return 	Shader*
		/// @param 		filename path
		/// @param 		shader type
		static Shader* createShader(SString shaderPath, ShaderType type);
		/// @brief 		Destructor of the shader, the shader is deleted if it has been created by 3D API
		/// @return 	
		~Shader();
		/// @brief 		Id of the shader provides by 3D API
		/// @return 	Id of the shader
		GLuint getId() const;
		/// @brief 		Type of the shader, vertex, fragment,...
		/// @return 	smartray::ShaderType
		ShaderType getType() const;
		/// @brief 		Name can be useful to retrieve a shader
		/// @return 	std::string
		SString getName() const;
		/// @brief 		Shader compilation and error checking
		void compileShader();
	private:
		Shader() = default;
		Shader(const Shader&) = delete;
		Shader& operator= (const Shader&) = delete;
		GLuint m_id;
		ShaderType m_type;
		SString m_name;
	};


	class DLL_SPEC ShaderProgram
	{
	public:
		/// @brief 		Create a shader program with 3D API
		/// @details	You have to manage memory of the instance returned
		/// @return 	ShaderProgram*
		static ShaderProgram* createShaderProgram();
		~ShaderProgram();
		/// @brief 		Enable this shader program for drawing
		void enable() { glUseProgram(m_program); }
		/// @brief		Disable this shader program
		void disable() { glUseProgram(0); }
		/// @brief 		Get the id of the shader program provide by 3D API 
		/// @return		id
		unsigned int getId();
		/// @brief 		Add a type of Shader to this program
		/// @details	If the type already exists, the old shader is replaced. Be careful, the old one is not deleted
		/// @param 		The shader to add
		void addShader(Shader* shader);
		void deleteShader(ShaderType type);
		void compile();
	private:
		ShaderProgram() = default;
		ShaderProgram(const ShaderProgram&) = delete;
		ShaderProgram& operator= (const ShaderProgram&) = delete;
		GLuint m_program;
		std::map<ShaderType, Shader*> m_shaders;
	};
}
