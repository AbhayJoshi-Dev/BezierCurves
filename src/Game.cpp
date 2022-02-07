#include"Game.h"

Game::Game()
	:gameRunning(true)
{
	Init();
	GameLoop();
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "Error: Failed to initialize SDL. " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "Error: Failed to initialize SDL_image. " << IMG_GetError() << std::endl;

	window.CreateWindow("Bezier Curves", 800, 600);
}

void Game::GameLoop()
{
	while (gameRunning)
	{
		utils::FPS();

		startTicks = SDL_GetTicks();

		newTime = utils::HireTimeInSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					gameRunning = false;
					break;
				}
			}

			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		window.Clear();

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}