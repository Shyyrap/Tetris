#include "Box.h"
#include"Game.h"
#include"Fieldee.h"
#include"VertexArray.h"
#include"Model.h"
#include<ctime>
Box::Box(Game* game):Actor(game)
{
	SetState(EACTIVE);
	mBoxModel = new Model;
	x = 0;
	y = 250;
	mBoxModel->GetPos().x = 0.0f;
	mBoxModel->GetPos().y = 250.0f;
	counter = 0;
}
Model* Box::GetModel()
{
	return mBoxModel;
}
void Box::LoadVertices(VertexArray* vert)
{
	mVerts = vert;
}
VertexArray* Box::GetVertices()
{
	return mVerts;
}
Box::~Box()
{

}
void Box::TransformFunction(int x, int y)
{
	
}
void Box::UpdateActor(float deltaTime,int num)
{
	Actor::UpdateActor(deltaTime,num);
	for (auto components : GetComponents())
	{
		if (components->GetTypeComponent() == 10)
		{
			int** field = static_cast<Fieldee*>(components)->GetField();
			for (int i = 0; i < Rows; i++)
			{
				for (int j = 0; j < Columns; j++)
				{
					if (field[i][j] == 1)
					{
						mBoxModel->GetPos().y = i * -20.0f+350.0f;
						mBoxModel->GetPos().x = j * 20.0f - 200.0f;
						GetGame()->GetGameShader(num)->SetActive();
						GetGame()->GetGameShader(num)->LoadModel(*GetModel(), "Model");
						DrawTriangles();
					}
					else
					{

					}
				}
			}
			for (int i = 0; i < 4; i++) 
			{
				y = static_cast<Fieldee*>(components)->GetActiveShape()->rects[i]->x*-20.0f+350.f;
				x = static_cast<Fieldee*>(components)->GetActiveShape()->rects[i]->y*20.0f-200.f;
				mBoxModel->GetPos().y = y;
				mBoxModel->GetPos().x = x;
				GetGame()->GetGameShader(num)->SetActive();
				GetGame()->GetGameShader(num)->LoadModel(*GetModel(), "Model");
				DrawTriangles();
			}
		}
	}
}
void Box::DrawLines()
{
	GetVertices()->SetActive();
	GetVertices()->DrawLines();
}
void Box::DrawTriangles()
{
	GetVertices()->SetActive();
	GetVertices()->DrawArrays();
}