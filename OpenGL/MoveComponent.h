#pragma once
#include"Actor.h"
class MoveComponent :public Component
{
public:
	MoveComponent(Actor* actor);
	~MoveComponent();
private:
	Actor* mActor;
};

