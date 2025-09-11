#include "Shader.h"

#include <fstream>
#include <streambuf>
#include <iostream>
#include <glad/gl.h>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(std::string vertexFilePath, std::string fragmentFilePath) :
	m_VertexFilePath(vertexFilePath),
	m_FragmentFilePath(fragmentFilePath),
	m_ID(0)
{
	m_ID = glCreateProgram();

	unsigned int vs = compileShader(GL_VERTEX_SHADER, parseShader(vertexFilePath));
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, parseShader(fragmentFilePath));

	glAttachShader(m_ID, vs);
	glAttachShader(m_ID, fs);
	glLinkProgram(m_ID);
	glValidateProgram(m_ID);

	int result;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetProgramInfoLog(m_ID, length, &length, message);
		std::cout << "Failed to compile shader program" << std::endl;
		std::cout << message << std::endl;
		delete message;
		glDeleteProgram(m_ID);
	}

	glDeleteShader(vs);
	glDeleteShader(fs);
}
Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

void Shader::bind() const
{
	glUseProgram(m_ID);
}
void Shader::unbind() const
{
	glUseProgram(0);
}

void Shader::setUniform1i(const std::string& name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}
void Shader::setUniform1f(const std::string& name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}
void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}
void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

std::string Shader::parseShader(const std::string& filePath)
{
	std::ifstream fin(filePath);
	if (!fin.good())
	{
		std::cout << "Error reading shader file" << std::endl;
		return "";
	}

	return std::string(std::istreambuf_iterator<char>(fin),
					   std::istreambuf_iterator<char>());
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
		std::cout << message << std::endl;
		delete message;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

int Shader::getUniformLocation(const std::string& name)
{
	auto lookup = m_UniformLocationCache.find(name);
	if (lookup != m_UniformLocationCache.end())
		return lookup->second;

	int location = glGetUniformLocation(m_ID, name.c_str());
	if (location == -1)
		std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
	m_UniformLocationCache[name] = location;

	return location;
}