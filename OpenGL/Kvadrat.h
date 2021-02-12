#pragma once
#include"Shapee.h"

class Kvadrat:public Shapee
{
public:
	Kvadrat(Fieldee* field);
	void InitShape()override;
	void BuildVertical()override;
	void BuildHorizontal()override;
};

