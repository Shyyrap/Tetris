#pragma once
#include"Shapee.h"
class Treugolnik :public Shapee
{
public:
	Treugolnik(class Fieldee* field);
	void InitShape()override;
	void BuildVertical()override;
	void BuildHorizontal()override;
};

