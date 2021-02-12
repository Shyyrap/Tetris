#include "Game.h"
#include"GameConstants.h"
#include <iostream>
#include"Actor.h"
#include"GLM/glm/glm.hpp"
#include"GLM/glm/gtc/matrix_transform.hpp"
#include"Fieldee.h"
#include"VertexArray.h"
Game::Game() :
	mIsRunning(0),
	mDisplay(0),
	mTicksCount(0),
	mColorCounter(0),
	mTicksGreater(2500)
{
	InitDisplay();
	InitShader();
	InitField();
	acceleration = -0.25;
}
void Game::InitField()
{
	float verticesLines[] =
	{
		-10.0f, 10.0f, -260.0f,
		10.0f,  10.0f, -260.0f,
		10.0f, -10.f, -260.0f,
		-10.0f,-10.f, -260.0f,
	};
	unsigned int indicesLines[] =
	{
		0,1,
		1,2,
		2,3,
		3,0,
	};
	float trianglesVertices[] =
	{
		10.0f, 10.0f, -260.0f,
		10.0f,  -10.0f, -260.0f,
		-10.0f, 10.f, -260.0f,

		10.0f, -10.f, -260.0f,
		-10.0f, -10.f, -260.0f,
		-10.0f, 10.f, -260.0f

	};
	unsigned int trianglesIndices[] =
	{
		0,1,3,
		1,2,3
	};
	VertexArray* mArrays = new VertexArray(trianglesVertices, (unsigned int)6, indicesLines, (unsigned int)6);
//	VertexArray* mArrays = new VertexArray(trianglesVertices, (unsigned int)6, indicesLines, (unsigned int)8);
	mBox = new Box(this);
	mBox->LoadVertices(mArrays);
	Fieldee* field = new Fieldee(mBox);
}

void Game::DeleteActor(Actor* actor)
{
	
}

void Game::AddActor(Actor* actor)
{
	
}
void Game::LoadActor()
{

}
Game::~Game()
{
}
void Game::AddShader(ShaderClass* shader, int id_shader)
{
	
}
void Game::GenerateOutput()
{
	mDisplay->SwapWindow();
	mDisplay->Clear(0.0f,0.0f,0.0f,1.0f);
}
void Game::IncreaseAcceration(float Multi)
{
	acceleration = acceleration * Multi;
}
void Game::SetDefaultAccelaration()
{
	acceleration = -0.25f;
}
void Game::UpdateGame()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 100+100*acceleration));
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTicksCount = SDL_GetTicks();
	if (SDL_TICKS_PASSED(mTicksCount,mTicksGreater))//if achieved 2500 ticks
	{
		if (mColorCounter < 5)
		{
			mBox->UpdateActor(deltaTime, mColorCounter++);
			mTicksGreater = mTicksCount+2500;
		}
		else
		{
			mColorCounter = 0;
			mBox->UpdateActor(deltaTime, mColorCounter);
			mTicksGreater = mTicksCount+2500;
		}
	}
	else//if not achieved 2500 ticks
	{
		if (mColorCounter < 5)
		{
			mBox->UpdateActor(deltaTime, mColorCounter);//update current color
		}
		else
		{
			mColorCounter = 0;
			mBox->UpdateActor(deltaTime, mColorCounter);//update current color
		}
	}
}
bool Game::IsItTimeToSwitchColor(float pursuing_time, float goal_time)
{
	if (pursuing_time < goal_time)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Game::InitDisplay()
{
	mDisplay = new Display(WIDTH, HEIGHT, "Game");
	if (mDisplay->IsClosedDisplay())
	{
		mIsRunning = false;
	}
	else
	{
		mIsRunning = true;
		mTicksCount = SDL_GetTicks();
	}
}
void Game::InitShader()
{
	const std::string Basic = "Basic";
	const std::string Vert = ".vert";
	const std::string Frag = ".frag";
	glm::mat4 mPerspective1(1.0f);
	mPerspective1 = glm::perspective(90.0f, WIDTH / HEIGHT, 0.1f, 400.0f);
	for (int i = 0; i < 5; i++) 
	{
		mGameShader.push_back(new ShaderClass);
		//mGameShader[0]->Load("Basic2.vert", "Basic2.frag");
		mGameShader[i]->Load(Basic + std::to_string(0) + Vert, Basic + std::to_string(i) + Frag);
		mGameShader[i]->SetActive();
		mGameShader[i]->LoadUniform((float*)&mPerspective1, "Projection");
	}
}
void Game::RunLoop()
{
	while (mIsRunning != false)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
		mKeyBoardState = SDL_GetKeyboardState(NULL);
		if (mKeyBoardState[SDL_SCANCODE_ESCAPE])
		{
			mIsRunning = false;
		}
		else
		{
			break;
		}
	}
}