#include "window.h"

// Game
Graphics* Window::graphics;
Input* Window::input;
float Window::frameTime;
// Window
vector<Window*> Window::windows;
MainMenu Window::mainMenu;
Level Window::level;
HUD Window::hud;

Window::Window()
{}

Window::~Window()
{}