#pragma once
#include"GL/glew.h"
#include"GLM/glm/glm.hpp"
class Model
{
public:
	Model(
		const glm::vec3 pos = glm::vec3{}, 
		const glm::vec3 rotate = glm::vec3{}, 
		const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
);
	void SetPos(const glm::vec3 pos);
	void SetScale(const glm::vec3 scale) { mScale = scale; }
	void SetRotate(const glm::vec3 rotate) { mRotate = rotate; }
	glm::vec3& GetPos() { return mPos; }
	glm::vec3& GetScale() { return mScale; }
	glm::vec3& GetRotate() { return mRotate; }
	glm::mat4& GetModel()const;
private:
	glm::vec3 mPos, mRotate, mScale;
};

