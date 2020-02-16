#pragma once
#include "graphics.h"
#include "input.h"
#include <vector>
using namespace std;

class MainMenu;
class Level;
class HUD;
class Instructions;
class Options;
class Credits;
class Inventory;

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
	static Level level;
	static HUD hud;
	static Instructions instructions;
	static Options options;
	static Credits credits;
	static Inventory inventory;

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
#include "level.h"
#include "hud.h"
#include "instructions.h"
#include "options.h"
#include "credits.h"
#include "inventory.h"
