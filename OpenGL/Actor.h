#pragma once
#include <vector>
#include"Component.h"
enum STATE
{
	EPAUSE,
	EACTIVE,
	EDEAD
};

class Actor
{
public:
	Actor(class Game* game);
	~Actor();
	virtual void UpdateActor(float deltaTime,int num);
	void AddComponent(Component* component);
	void DeleteComponent(Component* component);
	STATE GetState() {return mState;}
	void SetState(STATE state) { mState = state; }
	std::vector<Component*>& GetComponents();
	class Game* GetGame();
private:
	STATE mState;
	class Game* mGame;
	std::vector<Component*>mComponents;
	
};