#include"FieldComponentShape.h"
#include"GameConstants.h"
#include "Field.h"
#include"TriangleShape.h"
CentralPoint::CentralPoint()
{
	x = 1;
	y = Columns/2;
}
int CentralPoint::GetX()
{
	return x;
}
int CentralPoint::GetY()
{
	return y;
}
void CentralPoint::SetX(int a)
{
	x = a;
}
void CentralPoint::SetY(int b)
{
	y = b;
}

FieldComponentShape::FieldComponentShape(Field* field):Component(field)
{
	mPoint = new CentralPoint;
	mArray = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mArray[i] = new int[j];
		}
	}
	mRotateState = ZERO;
	mShapeState = ACTIVE;
	mOwner = field;
}
SHAPE_STATE FieldComponentShape::GetState()const
{
	return mShapeState;
}

void FieldComponentShape::Fall()
{
	int temp = mPoint->GetX();
	if (temp < Rows)
	{
		temp++;
		if (temp < Rows) 
		{
			mPoint->SetX(temp);
		}
		else
		{
			SetState(ON_HOLD);
		}
	}
	else
	{
		SetState(ON_HOLD);
	}
} 
FieldComponentShape::~FieldComponentShape()
{
	GetOwner()->DeleteComponent(this);
}
void FieldComponentShape::Update(float deltaTime)
{
	if (GetState() == ACTIVE)
	{
		ProcessInput();
		/a
	}
	else
	{
		if (GetState() == ON_HOLD)
		{
			mOwner->PushBackHoldingShape(this);
			mOwner->InitActiveShape();
		}
	}
}
void FieldComponentShape::MoveRight()
{
	int temp = GetCentralPoint()->GetY();
	if (temp < Columns)
	{
		GetCentralPoint()->SetY(temp++);
		for (int i = 0; i < 4; i++)
		{
			mArray[i][1] = mArray[i][1] + 1;
		}
	}
	else
	{
		GetCentralPoint()->SetY(Columns);
	}
}
void FieldComponentShape::MoveLeft()
{
	int temp = GetCentralPoint()->GetY();
	if (temp > 0) 
	{
		GetCentralPoint()->SetY(temp--);
		for (int i = 0; i < 4; i++)
		{
			mArray[i][1] = mArray[i][1] - 1;
		}
	}
	else
	{
		GetCentralPoint()->SetY(1);
	}
}
void FieldComponentShape::Rotate()
{
	SetRotateState(NINETY);
}
void FieldComponentShape::ProcessInput()
{
	const Uint8* keyBoardState;
	keyBoardState = mOwner->GetGame()->GetKeyboardState();
	if (keyBoardState[SDL_SCANCODE_SPACE])
	{
		Rotate();
	}
	else
	{
		if (keyBoardState[SDL_SCANCODE_D])
		{
			MoveRight();
		}
		else
		{
			if (keyBoardState[SDL_SCANCODE_A])
			{
				MoveLeft();
			}
			else
			{
				if (keyBoardState[SDL_SCANCODE_S])
				{
					//Accelerate();
				}
				else
				{
					Fall();
				}
			}
		}
	}
	
}