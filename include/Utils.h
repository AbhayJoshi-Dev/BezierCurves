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

	inline float DistanceXY(float x1, float y1, float x2, float y2)
	{
		float dx = x2 - x1;
		float dy = y2 - y1;

		return std::sqrt(dx * dx + dy * dy);
	}

	inline float CircleRadius(Entity c)
	{
		return c.GetPosition().GetX() + (c.GetCurrentFrame().w / 2) - c.GetPosition().GetX();
	}

	inline bool CirclePointCollision(float pointX, float pointY, Entity& circle)
	{
		return DistanceXY(pointX, pointY, circle.GetPosition().GetX() + circle.GetCurrentFrame().w / 2, circle.GetPosition().GetY() + circle.GetCurrentFrame().h / 2) <
			CircleRadius(circle);
	}

}