#pragma once
#include"Component.h"
#include"GameConstants.h"
#include"Game.h"
#include"Box.h"
#include"Shapee.h"
#include<map>
class Fieldee:public Component
{
public:
	Fieldee(Box* box, int type = 10);
	void FillField();
	void InitField();
	void StartActiveShape();
	void Update(float deltaTime)override;
	bool IsBusyField(int x, int y);
	int** GetField() { return mArray; }
	Shapee* GetActiveShape();
	Box* GetBox() { return mOwner; }
	void CreateWalls();
	void DestroyLines(int num_line);
	bool IsDestroyable(int cur);
	void SwapUp(int x, int y);
	void CheatUnits(int num_line);
	void PutDown(int from_line, int toLine);
private:
	int** mArray;
	Shapee* mActiveShape;
	Box* mOwner;
};

