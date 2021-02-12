#pragma once
#include"Rect.h"
#include"GameConstants.h"
enum NumerationOfShapes
{
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	TOTAL_NUM
};
enum Position
{
	VERTICAL,
	HORIZONTAL,
	TOTAL_POS
};
enum Direction
{
	DIRECTLY,
	VERSA,
	TOTAL_DIR
};
enum ShapeState
{
	ACTIVE,
	ON_HOLD
};
class Shapee
{
public:
	Shapee(class Fieldee* field);
	void Fall();
	virtual void InitShape() = 0;
	void SetState(ShapeState state) { mState = state; }
	ShapeState GetShapeState() { return mState; }
	Rect* rects[4];
	Fieldee* GetField() { return mField; }
	Position GetPosition();
	void SetPosition(Position PosState) { mPosition = PosState; }
	void SetDirection(Direction DirState) { mDirection = DirState; }
	Direction GetDirection();
	void MoveRight();
	void MoveLeft();
	bool IsCollisionFall();
	bool IsCollisionMove();
	void Console();
	void Rotate();
	virtual void BuildVertical() = 0;
	virtual void BuildHorizontal() = 0;
	//virtual void MoveOther() = 0;
private:
	ShapeState mState;
	class Fieldee* mField;
	Position mPosition;
	Direction mDirection;
	class mShaderClass* mShader;
};