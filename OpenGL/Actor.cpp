#include "Actor.h"
#include<iostream>
#include<map>
#include"Game.h"
Game* Actor::GetGame()
{
	return mGame;
}
Actor::Actor(Game* game)
{
	mGame = game;
	game->AddActor(this);
}

void Actor::UpdateActor(float deltaTime, int num)
{
	for (auto components : mComponents)
	{
		components->Update(deltaTime);
	}
}
void Actor::AddComponent(Component* component)
{
	mComponents.emplace_back(component);
}

void Actor::DeleteComponent(Component* component)
{
	for (auto it = mComponents.begin(); it != mComponents.end(); ++it)
	{
		if (*it == component)
		{
			mComponents.erase(it);
		}
		else
		{

		}
	}
}
std::vector<Component*>& Actor::GetComponents()
{
	return mComponents;
}
Actor::~Actor()
{
	mGame->DeleteActor(this);
}
 