#include"ShaderClass.h"
#include"SDL.h"
#include<sstream>
#include<fstream>
#include<iostream>
#include"Model.h"
#include"GLM/glm/gtc/type_ptr.hpp"
ShaderClass::ShaderClass()
{
}
ShaderClass::~ShaderClass()
{
	Unload();
}
bool ShaderClass::CompileShader(const std::string& fileName,
	GLenum shaderType,
	GLuint& outShader)
{
	// Open file
	std::ifstream shaderFile(fileName);
if (shaderFile.is_open())
{
	// Read all the text into a string
	std::stringstream sstream;
	sstream << shaderFile.rdbuf();
	std::string contents = sstream.str();
	const char* contentsChar = contents.c_str();
	// Create a shader of the specified type
	outShader = glCreateShader(shaderType);
	// Set the source characters and try to compile
	glShaderSource(outShader, 1, &(contentsChar), nullptr); 
	glCompileShader(outShader);
	if (!IsCompiled(outShader))
	{
		SDL_Log("Failed to compile shader %s", fileName.c_str());
		return false;
	}
} 
else
{
	SDL_Log("Shader file not found: %s", fileName.c_str());
	return false;
} 
	return true;
}


bool ShaderClass::IsCompiled(GLuint shader)
{
	GLint status;
	// Query the compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetShaderInfoLog(shader, 511, nullptr, buffer);
		SDL_Log("GLSL Compile Failed:\n%s", buffer);
		return false;
	} 
	return true;
}
bool ShaderClass::IsValidProgram()
{
	GLint status;
	// Query the compile status
	glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetProgramInfoLog(mShaderProgram, 511, nullptr, buffer);
		SDL_Log("GLSL Compile Failed:\n%s", buffer);
		return false;
	}
	return true;
}
bool ShaderClass::Load(const std::string& vertName,
	const std::string& fragName)
{
	// Compile vertex and fragment shaders
	if (!CompileShader(vertName, GL_VERTEX_SHADER, mVertexShader) ||
		!CompileShader(fragName, GL_FRAGMENT_SHADER, mFragShader) 
		)
	{
		return false;
	}
	// Now create a shader program that
	// links together the vertex/frag shaders
	mShaderProgram = glCreateProgram();
	glBindAttribLocation(mShaderProgram, 0, "Position");
	glBindAttribLocation(mShaderProgram, 1, "TexCoord");
	glAttachShader(mShaderProgram, mVertexShader);
	glAttachShader(mShaderProgram, mFragShader);
	glLinkProgram(mShaderProgram);
	// Verify that the program linked successfully
	if (!IsValidProgram())
	{
		return false;
	}
	return true;
}
void ShaderClass::SetActive()
{
	glUseProgram(mShaderProgram);
}

void ShaderClass::LoadUniform(const float* matrix, const char* name)
{
	mLoc = glGetUniformLocation(mShaderProgram, name);
	glUniformMatrix4fv(mLoc, 1, GL_FALSE, matrix);
}
void ShaderClass::LoadModel(const Model& model, const char* name)
{
	glm::mat4 Model(1.0f);
	Model = model.GetModel();
	mLoc = glGetUniformLocation(mShaderProgram, name);
	glUniformMatrix4fv(mLoc, 1, GL_FALSE, &Model[0][0]);
}
void ShaderClass::Unload()
{
	glDeleteProgram(mShaderProgram);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragShader);
}