#include"Shapee.h"
#include"GameConstants.h"
#include"Fieldee.h"
Shapee::Shapee(Fieldee* field)
{
	mField = field;
	mState = ACTIVE;
	InitShape();
}
void Shapee::InitShape()
{

}
bool Shapee::IsCollisionFall()
{
	for (int i = 0; i < 4; i++)
	{
		if (GetField()->IsBusyField(rects[i]->x + 1, rects[i]->y))
		{
			return true;
		}
		else
		{
		}
	}
	return false;
}

bool Shapee::IsCollisionMove()
{
	for (int i = 0; i < 4; i++)
	{
		if (GetField()->IsBusyField(rects[i]->x, rects[i]->y - 1))
		{
			return true;
		}
		else
		{
			if (GetField()->IsBusyField(rects[i]->x, rects[i]->y + 1))
			{
				return true;
			}
		}
	}
	return false;
}
void Shapee::Console()
{
	const Uint8* console = GetField()->GetBox()->GetGame()->GetKeyboardState();
	if (console[SDL_SCANCODE_A])
	{
		MoveLeft();
	}
	else
	{
		if (console[SDL_SCANCODE_D])
		{
			MoveRight();
		}
		else
		{
			if (console[SDL_SCANCODE_SPACE])
			{
				Rotate();
			}
			else
			{
				if (console[SDL_SCANCODE_F])
				{
					GetField()->CheatUnits(2);
				}
				else
				{
					if (console[SDL_SCANCODE_S])
					{
						GetField()->GetBox()->GetGame()->IncreaseAcceration(1.2f);
					}
				}
			}
		}
	}
}
void Shapee::BuildHorizontal( )
{
	
}
void Shapee::BuildVertical()
{

}
void Shapee::MoveLeft()
{
	if (!IsCollisionMove())
	{
		for (int i = 0; i < 4; i++)
		{
			rects[i]->y--;
		}
	}
	else
	{
		
	}
}
void Shapee::MoveRight()
{
	if (!IsCollisionMove())
	{
		for (int i = 0; i < 4; i++)
		{
			rects[i]->y++;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			rects[i]->y;
		}
	}
}

void Shapee::Rotate()
{
	if (GetPosition() == VERTICAL)
	{
		BuildHorizontal();
	}
	else
	{
		BuildVertical();
	}
}
Direction Shapee::GetDirection()
{
	return mDirection;
}
Position Shapee::GetPosition()
{
	return mPosition;
}
void Shapee::Fall()
{
		if (!IsCollisionFall())
		{
			for (int i = 0; i < 4; i++)
			{
				rects[i]->x++;
			}
		}
		else
		{
			SetState(ON_HOLD);
			GetField()->GetBox()->GetGame()->SetDefaultAccelaration();
		}
}