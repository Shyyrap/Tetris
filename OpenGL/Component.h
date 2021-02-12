#pragma once
class Component
{
public:
	Component(class Actor* owner, int typeComponent = 0);
	~Component();
	virtual void Update(float deltaTime) = 0;
	int GetTypeComponent() { return mTypeComponent; }
private:
	int mTypeComponent;
	class Actor* mOwner;
};
