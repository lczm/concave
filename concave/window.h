#pragma once
#include "graphics.h"
#include "input.h"
#include <vector>
using namespace std;

class MainMenu;

class Window
{
public:
	// Game
	static Graphics* graphics;
	static Input* input;
	static float frameTime;
	// Window
	static vector<Window*> windows;
	static MainMenu mainMenu;
public:
	Window();
	~Window();
	virtual void initialize() = 0;
	virtual void releaseAll() = 0;
	virtual void resetAll() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

#include "mainMenu.h"