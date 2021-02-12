#pragma once
#include<vector>
#include"Display.h"
#include<algorithm>
#include"ShaderClass.h"
class Game
{
public:
	Game();
	~Game();
	void RunLoop();
	void InitDisplay();
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	const Uint8* GetKeyboardState() { return mKeyBoardState; }
	bool IsGameRunning() { return mIsRunning; }
	void InitShader();
	void AddActor(class Actor* actor);
	void DeleteActor(class Actor* actor);
	void LoadActor();
	void InitField();
	ShaderClass* GetGameShader(int id) 
	{
		return mGameShader[id];
	}
	void IncreaseAcceration(float Multi);
	void SetDefaultAccelaration();
	void AddShader(class ShaderClass* shader, int id_shader);
	void RemoveShader(class ShaderClass* shader, int id_shader);
	bool IsItTimeToSwitchColor(float pursuing_time, float goal_time);
private:
	std::vector<ShaderClass*> mGameShader;
	class Box* mBox;
	Uint32 mTicksCount;
	Uint32 mTicksGreater;
	Display* mDisplay;
	const Uint8* mKeyBoardState;
	bool mIsRunning;
	float acceleration;
	int mColorCounter;
};	

