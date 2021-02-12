#include "Fieldee.h"
#include"Shapee.h"
#include<iostream>
#include"Kvadrat.h"
#include<ctime>
#include<random>
#include"Treugolnik.h"
#include"Box.h"
#include"Palka.h"
#include"Curl.h"

Fieldee::Fieldee(Box* box, int type):Component(box, type)
{
	mOwner = box;
	InitField();
	CreateWalls();
	StartActiveShape();
}
void Fieldee::CheatUnits(int num_line)
{
	for (int i = 2; i < Columns - 1; i++)
	{
		mArray[Rows - num_line][i] = 1;
	}
}

bool Fieldee::IsDestroyable(int cur)
{
	for (int i = 2; i < Columns - 2; i++)
	{
		if (mArray[cur][i] == 0)
		{
			return false;
		}
	}
	return true;
}


void Fieldee::DestroyLines(int num_line)
{
	if (num_line < Rows-1)
	{
		for (int i = 2; i < Columns - 1; i++)
		{
			mArray[num_line][i] = 0;
		}
	}
	else
	{
		return;
	}
}
void Fieldee::CreateWalls()
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (j == 1)
			{
				mArray[i][j] = 1;
			}
			else
			{
				if (j == Columns - 1)
				{
					mArray[i][j] = 1;
				}
			}
		}
	}
}
void Fieldee::InitField()
{
	mArray = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		mArray[i] = new int[Columns];
		if (i == Rows - 1)
		{
			for (int j = 0; j < Columns; j++)
			{
				mArray[i][j] = 1;
			}
		}
		else
		{
			for (int j = 0; j < Columns; j++)
			{
				mArray[i][j] = int(0);
			}
		}
	}
}
void Fieldee::FillField()
{
	if (mActiveShape->GetShapeState() == ON_HOLD) 
	{
		for (int i = FIRST; i < TOTAL_NUM; i++)
		{
			mArray[mActiveShape->rects[i]->x][mActiveShape->rects[i]->y] = 1;
		}
	}
	else
	{
		return;
	}
}
void Fieldee::StartActiveShape()
{
	srand(time(NULL));
	int random = rand()%FOURTH;
	//int random = FIRST;
	switch (random)
	{
	case FIRST:
		mActiveShape = new Kvadrat(this);
		break;
	case SECOND:
		mActiveShape = new Treugolnik(this);
		break;
	case THIRD:
		mActiveShape = new Palka(this);
		break;
	case FOURTH:
		mActiveShape = new Curl(this);
		break;
	};
}
void Fieldee::PutDown(int fromLine, int toLine)
{
	while(fromLine > 1)
	{
		int* bufferLine = mArray[fromLine];
		for (int j = 0; j < Columns - 1; j++)
		{
			mArray[toLine][j] = bufferLine[j];
		}
		fromLine--;
		toLine--;
	}
}
void Fieldee::Update(float deltaTime)
{
	if (mActiveShape->GetShapeState() == ACTIVE)
	{
		mActiveShape->Console();
		mActiveShape->Fall();
	}
	else
	{
		if (mActiveShape->GetShapeState() == ON_HOLD)
		{
			FillField();
			StartActiveShape();
		}
	}
	int cur_line = Rows - 2;
	while (true)
	{
		if (IsDestroyable(cur_line))
		{
			DestroyLines(cur_line);
			PutDown(cur_line-1,cur_line);
		}
		else
		{
			break;
		}
	}
}
bool Fieldee::IsBusyField(int x, int y)
{
	if (mArray[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Shapee* Fieldee::GetActiveShape()
{
	return mActiveShape;
}