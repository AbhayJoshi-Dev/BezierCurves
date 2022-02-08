#pragma once

#include<cmath>
#include<SDL.h>

#include"Vector.h"

class Curves
{
private:
	Vector p0;
	Vector p1;
	Vector p2;
	Vector pFinal;
public:
	Curves() = default;
	void DrawQuadraticBezier(Vector p0, Vector p1, Vector p2, SDL_Renderer* renderer);
	void QuadraticBezier(float t);
};