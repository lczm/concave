#pragma once

#include "constants.h"
#include "game.h"

class Concave : public Game
{
private:

public:
	Concave();
	virtual ~Concave();
	void initialize(HWND hwnd); void releaseAll();
	void resetAll();
	void update();
	void render();
};