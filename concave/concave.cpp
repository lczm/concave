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
	mainMenu.initialize();
	Window::windows.push_back(&mainMenu);
}

void Concave::releaseAll()
{
	//mainMenu.releaseAll();
	//Window::level.releaseAll();
	//Window::hud.releaseAll();
	Game::releaseAll();
}

void Concave::resetAll()
{
	//mainMenu.resetAll();
	//Window::level.resetAll();
	//Window::hud.resetAll();
	Game::resetAll();
}

void Concave::update()
{
	Window::windows.back()->update();
}

void Concave::render()
{
	graphics->spriteBegin();
	for (Window* window : Window::windows) window->render();
	graphics->spriteEnd();
}