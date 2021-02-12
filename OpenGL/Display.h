#pragma once
#include<string>
#include"SDL.h"
#include<GL/glew.h>
#include<SDL_opengl.h>

class Display
{
public:
	Display(int width, int height, const std::string& str);
	virtual ~Display();
	void SwapWindow();
	void Clear(float r, float g, float b, float a);
	bool IsClosedDisplay() { return mIsClosed; }
private:
	SDL_Window* mWindow;
	SDL_GLContext mGlContext;
	bool mIsClosed;
};

