#pragma once
#include"Actor.h"
class Box:public Actor
{
public:
	Box(class Game* game);
	~Box();
	void UpdateActor(float deltaTime,int num)override;
	class VertexArray* GetVertices();
	void LoadVertices(class VertexArray* vert);
	void DrawLines();
	void DrawTriangles();
	class Model* GetModel();
	int GetCounter() const { return counter; }
	void SetCounter(int count) { counter = count; }
	void TransformFunction(int x, int y);
private:
	class Model* mBoxModel;
	class VertexArray* mVerts;
	int counter;
	float x, y;
};

