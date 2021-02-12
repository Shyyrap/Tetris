#pragma once
#include"Shapee.h"
class Curl:public Shapee
{
public:
	Curl(class Fieldee* field);
	void InitShape()override;
	void BuildVertical()override;
	void BuildHorizontal()override;
};

