#include "VertexArray.h"
#include"GLM/glm/glm.hpp"
VertexArray::VertexArray(float* vertices, unsigned int numVerts, 
	unsigned int* indices, unsigned int numIndices)
{
	mVertexObj = 0;
	mBuffersVerts = 0;
	mBuffersIndices = 0;
	mNumIndices = numIndices;
	glGenVertexArrays(1, &mVertexObj);
	glBindVertexArray(mVertexObj);

	glGenBuffers(1, &mBuffersVerts);
	glBindBuffer(GL_ARRAY_BUFFER, mBuffersVerts);
	glBufferData(
		GL_ARRAY_BUFFER, // The active buffer type to write to
		numVerts * 3 * sizeof(float),
		vertices, // Source to copy from (pointer)
		GL_STATIC_DRAW // How will we use this data?
	);
	glGenBuffers(1, &mBuffersIndices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBuffersIndices);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, // The active buffer type to write to
		numIndices*sizeof(unsigned int),// Number of bytes to copy
		indices, // Source to copy from (pointer)
		GL_STATIC_DRAW // How will we use this data?
	);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0, // Attribute index (0 for first one)
		3, // Number of components (3 in this case)
		GL_FLOAT, // Type of the components
		GL_FALSE, // (Only used for integral types)
		sizeof(float) * 3, // Stride (usually size of each vertex)
		0 // Offset from start of vertex to this attribute
	);
	glBindVertexArray(0);
}

VertexArray::~VertexArray() 
{
	glDeleteBuffers(1, &mBuffersVerts);
	glDeleteBuffers(1, &mBuffersIndices);
	glDeleteVertexArrays(1, &mVertexObj);
}
void VertexArray::SetActive()
{
	glBindVertexArray(mVertexObj);
}
void VertexArray::DrawLines()
{
	glDrawElements(GL_LINES, mNumIndices, GL_UNSIGNED_INT, nullptr);
}
void VertexArray::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, mNumIndices);
}
