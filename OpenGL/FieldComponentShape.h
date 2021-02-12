#pragma once
#include"Component.h"
enum ShapeNumeration
{
	FIRST,
	SECOND,
	THIRD,
	FOURTH
};
enum COORD
{
	X,
	Y
};
enum SHAPE_STATE
{
	ACTIVE,
	ON_HOLD,
	DESTROYED
};
enum ROTATE_STATE
{
	ZERO,
	NINETY,
	HUNDRED_EIGHTY,
	TWOHUNDRED_EIGHTY
};
class FieldComponentShape :public Component
{
public:
	FieldComponentShape(class Field* field);
	~FieldComponentShape();
	void Update(float deltaTime);
	virtual void Fall();
	ROTATE_STATE GetRotateState() { return mRotateState; }
	void SetRotateState(ROTATE_STATE state) { mRotateState = state; }
	SHAPE_STATE GetState()const;
	void SetState(SHAPE_STATE state) { mShapeState = state; }
	int** GetArray(){ return mArray; }
	CentralPoint* GetCentralPoint() {return mPoint;}
	virtual void DetectCollision() = 0;
	void ProcessInput();
	void MoveRight();
	void MoveLeft();
	virtual void Rotate();
private:
	Shape* massShapes;
	ROTATE_STATE mRotateState;
	SHAPE_STATE mShapeState;
	class Field* mOwner;
};