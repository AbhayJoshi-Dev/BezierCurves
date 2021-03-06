#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"RenderWindow.h"
#include"Utils.h"
#include"Curves.h"

class Game
{
private:
	RenderWindow window;


	bool gameRunning;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::HireTimeInSeconds();
	float newTime = 0.0f;
	float frameTime = 0.0f;
	float alpha = 0.0f;
	int startTicks = 0;
	int frameTicks = 0;

	SDL_Event event;

	Entity background;
	Entity handles[4];

	Curves bezierCurves;
	bool isDragging;
	int draggingHandle;

public:
	Game();
	void Init();
	void GameLoop();
};