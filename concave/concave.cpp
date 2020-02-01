#include "concave.h"

Concave::Concave()
{}

Concave::~Concave()
{
	releaseAll();
	/**/
}

void Concave::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	windows.push_back(&mainMenu);
}

void Concave::releaseAll()
{
	/**/
	Game::releaseAll();
}

void Concave::resetAll()
{
	/**/
	Game::resetAll();
}

void Concave::update()
{	
	for (Window* window : windows) window->update();
}

void Concave::render()
{
	graphics->spriteBegin();
	for (Window* window : windows) window->render();
	graphics->spriteEnd();
}
