#include"Game.h"

Game::Game()
	:gameRunning(true), background(Vector(0.f, 0.f)), isDragging(false)
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

	background.SetTexture(window.LoadTexture("res/gfx/Background.png"));

	handles[0].SetPosition(Vector(100.f, 500.f));
	handles[0].SetTexture(window.LoadTexture("res/gfx/Handle.png"));

	handles[1].SetPosition(Vector(300.f, 250.f));
	handles[1].SetTexture(window.LoadTexture("res/gfx/Handle.png"));

	handles[2].SetPosition(Vector(500.f, 400.f));
	handles[2].SetTexture(window.LoadTexture("res/gfx/Handle.png"));

	handles[3].SetPosition(Vector(700.f, 200.f));
	handles[3].SetTexture(window.LoadTexture("res/gfx/Handle.png"));
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

				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						int x, y;
						SDL_GetMouseState(&x, &y);

						for (int i = 0; i < 4; i++)
						{
							if (utils::CirclePointCollision(x, y, handles[i]))
							{
								isDragging = true;
								draggingHandle = i;
							}
						}
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isDragging = false;
					}
					break;
				}
				

			}

			accumulator -= timeStep;
		}

		alpha = accumulator / timeStep;

		if (isDragging)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);

			handles[draggingHandle].SetPosition(Vector((float)x - handles[draggingHandle].GetCurrentFrame().w / 2, (float)y - handles[draggingHandle].GetCurrentFrame().h / 2));
		}

		window.Clear();

		window.Render(background);

		for (int i = 0; i < 4; i++)
		{
			window.Render(handles[i]);
		}

		bezierCurves.DrawCubicBezier(handles[0], handles[1], handles[2], handles[3], window.renderer);

		window.Display();

		frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}

	window.CleanUp();
}