#include "Kvadrat.h"
#include"Fieldee.h"

Kvadrat::Kvadrat(Fieldee* field):Shapee(field)
{
	InitShape();
}

void Kvadrat::InitShape()
{
	int StartX = 0;
	int StartY = Columns / 2;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case FIRST:
			rects[i] = new Rect(StartX, StartY);
			break;
		case SECOND:
			rects[i] = new Rect(StartX, StartY + 1);
			break;
		case THIRD:
			rects[i] = new Rect(StartX + 1, StartY);
			break;
		case FOURTH:
			rects[i] = new Rect(StartX + 1, StartY + 1);
			break;
		};
	}
}
void Kvadrat::BuildHorizontal()
{

}
void Kvadrat::BuildVertical()
{

}
