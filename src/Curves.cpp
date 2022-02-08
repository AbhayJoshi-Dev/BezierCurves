#include"Curves.h"

#include<iostream>

void Curves::DrawQuadraticBezier(Vector _p0, Vector _p1, Vector _p2, SDL_Renderer* renderer)
{

	p0 = _p0;
	p1 = _p1;
	p2 = _p2;

	for (int i = 0; i < 1000; i++)
	{
		float t = (float)i / 999.f;
		QuadraticBezier(t);
		SDL_RenderDrawPoint(renderer, pFinal.GetX(), pFinal.GetY());
	}
}

void Curves::QuadraticBezier(float t)
{
	pFinal.SetX((float)std::pow(1 - t, 2) * p0.GetX() + (1 - t) * 2 * t * p1.GetX() + t * t * p2.GetX());

	pFinal.SetY((float)std::pow(1 - t, 2) * p0.GetY() + (1 - t) * 2 * t * p1.GetY() + t * t * p2.GetY());
}