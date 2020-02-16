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
Instructions Window::instructions;
Options Window::options;
Credits Window::credits;
Inventory Window::inventory;
ModifierSelect Window::modifierSelect;

Window::Window()
{}

Window::~Window()
{}