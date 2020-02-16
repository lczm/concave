#include "concave.h"

Concave::Concave()
{
    AllocConsole();
    freopen_s((FILE**)stdin, "CONIN$", "r", stdin); 
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout); 
    cout << "Initialized stdout" << endl;
}

Concave::~Concave()
{
	releaseAll();
}

void Concave::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	Window::graphics = graphics;
	Window::input = input;
	Window::mainMenu.initialize();
	Window::level.initialize();
	Window::options.initialize();
	Window::instructions.initialize();
	Window::credits.initialize();
	Window::hud.initialize();
	Window::inventory.initialize();
	Window::modifierSelect.initialize();
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
	if (Window::windows.empty()) exitGame();
	Window::frameTime = frameTime;
	Window::windows.back()->update();
}

void Concave::render()
{
	graphics->spriteBegin();
	for (Window* window : Window::windows) window->render();
	graphics->spriteEnd();
}