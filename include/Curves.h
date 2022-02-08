#pragma once

#include<cmath>
#include<SDL.h>

#include"Vector.h"
#include"Entity.h"

class Curves
{
private:
	Vector p0;
	Vector p1;
	Vector p2;
	Vector p3;
	Vector pFinal;
public:
	Curves() = default;
	void DrawQuadraticBezier(Vector _p0, Vector _p1, Vector _p2, SDL_Renderer* renderer);
	void DrawCubicBezier(Entity _p0, Entity _p1, Entity _p2, Entity _p3, SDL_Renderer* renderer);
	void QuadraticBezier(float t);
	void CubicBezier(float t);
};