#include "Model.h"
#include"GLM/glm/gtx/transform.hpp"
Model::Model(
	const glm::vec3 pos,
	const glm::vec3 rotate,
	const glm::vec3 scale
	):
	mPos(pos),
	mRotate(rotate),
	mScale(scale)
{
	
}
void Model::SetPos(const glm::vec3 pos)
{
	mPos = pos;
}
glm::mat4& Model::GetModel()const
{
	glm::mat4 MatrixScale = glm::scale(mScale);
	glm::mat4 rotateMatrixX = glm::rotate(mRotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotateMatrixY = glm::rotate(mRotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotateMatrixZ = glm::rotate(mRotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 MatrixPos = glm::translate(mPos);
	glm::mat4 MatrixRot = rotateMatrixX * rotateMatrixY * rotateMatrixZ;
	glm::mat4 Model = MatrixScale * MatrixRot * MatrixPos;
	return Model;
}
