#pragma once
#include "graphics.h"
#include "input.h"
#include "mainMenu.h"
#include "level.h"
#include "hud.h"
#include <vector>
using namespace std;

class Window
{
public:
	static float frameTime;
	static Input* input;
	static Graphics* graphics;
	static vector<Window*> windows;
	static MainMenu mainMenu;
	static Level level;
	static HUD hud;
public:
	Window();
	~Window();
	virtual void initialize() = 0;
	virtual void releaseAll() = 0;
	virtual void resetAll() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};