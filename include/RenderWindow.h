#pragma once

#include<SDL.h>
#include<SDL_image.h>

#include"Entity.h"

class RenderWindow
{
private:
	SDL_Window* window;

public:
	SDL_Renderer* renderer;
	RenderWindow();
	void CreateWindow(const char* title, int w, int h);
	SDL_Texture* LoadTexture(const char* filePath);
	void Render(Entity& entity);
	void Clear();
	void Display();
	void CleanUp();
	int GetRefreshRate();
};