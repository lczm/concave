#include "concave.h"

Concave::Concave()
{}

Concave::~Concave()
{
	releaseAll();
}

void Concave::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	mainMenu.initialize(&windows);
	windows.push_back(&mainMenu);
}

void Concave::releaseAll()
{
	mainMenu.releaseAll();
	//Window::level.releaseAll();
	//Window::hud.releaseAll();
	Game::releaseAll();
}

void Concave::resetAll()
{
	mainMenu.resetAll();
	//Window::level.resetAll();
	//Window::hud.resetAll();
	Game::resetAll();
}

void Concave::update()
{
	windows.back()->update();
}

void Concave::render()
{
	graphics->spriteBegin();
	for (Window* window : windows) window->render();
	graphics->spriteEnd();
}