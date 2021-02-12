#include"Display.h"
#include<iostream>

Display::Display(int width, int height, const std::string& str):mWindow(nullptr)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); //OpenGL core profil
	int doubleBufferSize = 1;
	int bufferSize = 32;
	int attrVal = 8;
	int* attrPtr = &attrVal;
	int* bufferPtr = &bufferSize;
	int* doubleBufferPtr = &doubleBufferSize;
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	mWindow = SDL_CreateWindow(str.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	mGlContext = SDL_GL_CreateContext(mWindow);
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initalize" << std::endl;
	}
	mIsClosed = false;
}
 
Display::~Display()
{
	SDL_GL_DeleteContext(mGlContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Display::SwapWindow()
{
	SDL_GL_SwapWindow(mWindow);
}
void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

