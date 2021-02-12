#include "Palka.h"
Palka::Palka(Fieldee* field) :Shapee(field)
{
	SetPosition(HORIZONTAL);
	SetDirection(DIRECTLY);
	InitShape();
}
void Palka::InitShape()
{
	int StartX = 1;
	int StartY = Columns / 2;
	for (int i = 0; i < 4; i++)
	{
		if (GetPosition() == VERTICAL) 
		{
			switch (i)
			{
			case FIRST:
				rects[i] = new Rect(StartX, StartY);
				break;
			case SECOND:
				rects[i] = new Rect(StartX + 1, StartY);
				break;
			case THIRD:
				rects[i] = new Rect(StartX + 2, StartY);
				break;
			case FOURTH:
				rects[i] = new Rect(StartX + 3, StartY);
				break;
			};
		}
		else
		{
			switch (i)
			{
			case FIRST:
				rects[i] = new Rect(StartX, StartY);
				break;
			case SECOND:
				rects[i] = new Rect(StartX, StartY+1);
				break;
			case THIRD:
				rects[i] = new Rect(StartX, StartY+2);
				break;
			case FOURTH:
				rects[i] = new Rect(StartX, StartY+3);
				break;
			};
		}
	}
}

void Palka::BuildVertical()
{
	float tempX = 0;
	float tempY = 0;
	if (GetPosition() == HORIZONTAL)
	{
		if (GetDirection() == DIRECTLY)
		{
			for (int i = FIRST; i < TOTAL_NUM; i++)
			{
				switch (i)
				{
				case FIRST:
					rects[i]->x = rects[i]->x;
					rects[i]->y = rects[i]->y;
					break;
				case SECOND:
					rects[i]->x = rects[i]->x+1;
					rects[i]->y = rects[i]->y-1;
					break;
				case THIRD:
					rects[i]->x = rects[i]->x+2;
					rects[i]->y = rects[i]->y-2;
					break;
				case FOURTH:
					rects[i]->x = rects[i]->x+3;
					rects[i]->y = rects[i]->y-3;
					break;
				};
			}
			SetPosition(VERTICAL);
			SetDirection(DIRECTLY);
		}
		else
		{
			if (GetDirection() == VERSA)
			{
				for (int i = FIRST; i < TOTAL_NUM; i++)
				{
					switch (i)
					{
					case FIRST:
						rects[i]->x = rects[i]->x;
						rects[i]->y = rects[i]->y;
						break;
					case SECOND:
						rects[i]->x = rects[i]->x-1;
						rects[i]->y = rects[i]->y+1;
						break;
					case THIRD:
						rects[i]->x = rects[i]->x-2;
						rects[i]->y = rects[i]->y+2;
						break;
					case FOURTH:
						rects[i]->x = rects[i]->x-3;
						rects[i]->y = rects[i]->y+3;
						break;
					};
				}
				SetPosition(VERTICAL);
				SetDirection(VERSA);
			}
		}
	}
}
void Palka::BuildHorizontal()
{
	float tempX = 0;
	float tempY = 0;
	if (GetPosition() == VERTICAL)
	{
		if (GetDirection() == DIRECTLY)
		{
			for (int i = FIRST; i < TOTAL_NUM; i++)
			{
				switch (i)
				{
				case FIRST:
					rects[i]->x = rects[i]->x;
					rects[i]->y = rects[i]->y;
					break;
				case SECOND:
					rects[i]->x = rects[i]->x-1;
					rects[i]->y = rects[i]->y-1;
					break;
				case THIRD:
					rects[i]->x = rects[i]->x-2;
					rects[i]->y = rects[i]->y-2;
					break;
				case FOURTH:
					rects[i]->x = rects[i]->x-3;
					rects[i]->y = rects[i]->y -3;
					break;
				};
			}
			SetPosition(HORIZONTAL);
			SetDirection(VERSA);
		}
		else
		{
			if (GetDirection() == VERSA)
			{
				for (int i = FIRST; i < TOTAL_NUM; i++)
				{
					switch (i)
					{
					case FIRST:
						rects[i]->x = rects[i]->x;
						rects[i]->y = rects[i]->y;
						break;
					case SECOND:
						rects[i]->x = rects[i]->x+1;
						rects[i]->y = rects[i]->y+1;
						break;
					case THIRD:
						rects[i]->x = rects[i]->x+2;
						rects[i]->y = rects[i]->y+2;
						break;
					case FOURTH:
						rects[i]->x = rects[i]->x+3;
						rects[i]->y = rects[i]->y+3;
						break;
					};
				}
			}
			SetPosition(HORIZONTAL);
			SetDirection(DIRECTLY);
		}
	}
}
