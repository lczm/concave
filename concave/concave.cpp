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
	Window::graphics = graphics;
	Window::input = input;
	Window::windows.push_back(&Window::mainMenu);
}

void Concave::releaseAll()
{
	Window::mainMenu.releaseAll();
	Window::level.releaseAll();
	Window::hud.releaseAll();
	Game::releaseAll();
}

void Concave::resetAll()
{
	Window::mainMenu.resetAll();
	Window::level.resetAll();
	Window::hud.resetAll();
	Game::resetAll();
}

void Concave::update()
{
	Window::frameTime = frameTime;
	Window::windows.back()->update();
}

void Concave::render()
{
	graphics->spriteBegin();
	for (Window* window : Window::windows) window->render();
	graphics->spriteEnd();
}