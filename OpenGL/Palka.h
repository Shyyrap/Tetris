#pragma once
#include"Shapee.h"
class Palka:public Shapee
{
public:
	Palka(class Fieldee* field);
	void InitShape()override;
	void BuildVertical()override;
	void BuildHorizontal()override;
};