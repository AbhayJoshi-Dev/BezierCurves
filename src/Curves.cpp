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

void Curves::DrawCubicBezier(Entity _p0, Entity _p1, Entity _p2, Entity _p3, SDL_Renderer* renderer)
{

	_p0.SetPosition(Vector(_p0.GetPosition().GetX() + _p0.GetCurrentFrame().w / 2, _p0.GetPosition().GetY() + _p0.GetCurrentFrame().h / 2));
	_p3.SetPosition(Vector(_p3.GetPosition().GetX() + _p3.GetCurrentFrame().w / 2, _p3.GetPosition().GetY() + _p3.GetCurrentFrame().h / 2));

	p0 = _p0.GetPosition();
	p1 = _p1.GetPosition();
	p2 = _p2.GetPosition();
	p3 = _p3.GetPosition();

	for (int i = 0; i < 1000; i++)
	{
		float t = (float)i / 999.f;
		CubicBezier(t);
		SDL_RenderDrawPoint(renderer, pFinal.GetX(), pFinal.GetY());
	}
}

void Curves::QuadraticBezier(float t)
{
	pFinal.SetX((float)std::pow(1 - t, 2) * p0.GetX() + (1 - t) * 2 * t * p1.GetX() + t * t * p2.GetX());

	pFinal.SetY((float)std::pow(1 - t, 2) * p0.GetY() + (1 - t) * 2 * t * p1.GetY() + t * t * p2.GetY());
}

void Curves::CubicBezier(float t)
{
	pFinal.SetX(std::pow(1 - t, 3) * p0.GetX() + std::pow(1 - t, 2) * 3 * t * p1.GetX() + (1 - t) * 3 * t * t * p2.GetX() + t * t * t * p3.GetX());
	pFinal.SetY(std::pow(1 - t, 3) * p0.GetY() + std::pow(1 - t, 2) * 3 * t * p1.GetY() + (1 - t) * 3 * t * t * p2.GetY() + t * t * t * p3.GetY());
}