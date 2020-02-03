#include "window.h"

// Game
Graphics* Window::graphics;
Input* Window::input;
float Window::frameTime;
// Window
vector<Window*> Window::windows;
MainMenu Window::mainMenu;

Window::Window()
{}

Window::~Window()
{}