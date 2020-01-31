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
	Window::graphics = graphics;
	Window::input = input;
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
	Window::fps = fps;
	for (Window* window : Window::windows) window->update();
}

void Concave::render()
{
	for (Window* window : Window::windows) window->render();
}
