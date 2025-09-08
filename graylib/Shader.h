#pragma once

#include <string>
#include <unordered_map>

class Shader
{
public:
	Shader(std::string vertexFilePath, std::string fragmentFilePath);
	~Shader();

	void bind();
	void unbind();

	// Set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	unsigned int m_ID;
	std::string m_VertexFilePath;
	std::string m_FragmentFilePath;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	std::string parseShader(const std::string& filePath);
	unsigned int compileShader(unsigned int type, const std::string& source);
	int getUniformLocation(const std::string& name);
};