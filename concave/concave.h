#pragma once
#include "constants.h"
#include "game.h"
#include "window.h"
#include "mainMenu.h"
#include <vector>
using namespace std;

class Concave : public Game
{
private:
	vector<Window*> windows;
	MainMenu mainMenu;
public:
	Concave();
	~Concave();
	void initialize(HWND hwnd);
	void releaseAll();
	void resetAll();
	void update();
	void render();
};