#pragma once
#include<string>
#include"GL/glew.h"
#include"GLM/glm/glm.hpp"
#include"Model.h"
#include<string>
class ShaderClass
{
public:
	ShaderClass();
	~ShaderClass();
	bool Load(const std::string& vertex,
		const std::string& fragment);
	void SetActive();
	void LoadUniform(const float* matrix, const char* name);
	void LoadModel(const Model& model, const char* name);
private:
	bool CompileShader(const std::string& fileName,
		GLenum shaderType, GLuint& outShader);
	// Tests whether shader compiled successfully
	bool IsCompiled(GLuint shader);
	// Tests whether vertex/fragment programs link
	bool IsValidProgram();
	void Unload();
	// Store the shader object IDs
	GLuint mVertexShader;
	GLuint mFragShader;
	GLuint mShaderProgram;
	GLuint mLoc;
};