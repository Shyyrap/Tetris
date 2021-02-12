#pragma once
#include<GL/glew.h>
#include"GLM/glm/glm.hpp"
class VertexArray
{
public:
	VertexArray(float* vertices,unsigned int numVerts, 
		unsigned int* indices, unsigned int numIndices);
	~VertexArray();
	void SetActive();
	void DrawLines();
	void DrawArrays();
private:
	GLuint mVertexObj;
	GLuint mBuffersVerts;
	GLuint mBuffersIndices;
	unsigned int mNumIndices;
};

