#pragma once

#include<SDL.h>
#include<iostream>
#include<cmath>

namespace utils
{
	static float currentTime = 0.f;
	static float lastTime = 0.f;
	static int fps;

	inline float HireTimeInSeconds()
	{
		float t = (float)SDL_GetTicks();
		t *= 0.001f;

		return t;
	}

	inline void FPS()
	{
		currentTime = (float)SDL_GetTicks();
		if ((currentTime - lastTime) >= 1000.f)
		{
			lastTime = currentTime;
			std::cout << fps << std::endl;
			fps = 0;
		}
		fps++;
	}
}