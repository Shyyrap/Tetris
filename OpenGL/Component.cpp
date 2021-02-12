#include"Component.h"
#include"Actor.h"
Component::Component(Actor* owner, int typeComponent)
{
	mOwner = owner;
	mTypeComponent = typeComponent;
	mOwner->AddComponent(this);
}
void Component::Update(float deltaTime)
{
	
}
Component::~Component()
{
	mOwner->DeleteComponent(this);
}
