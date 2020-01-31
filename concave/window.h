#pragma once

#include "graphics.h"
#include "input.h"
#include <vector>
using namespace std;

class Window
{
private:
public:
	static Graphics* graphics;
	static Input* input;
	static float fps;
	static vector<Window*> windows;

	Window();
	~Window();
	static void initialize();
	virtual void initialize() = 0;
	virtual void releaseAll() = 0;
	virtual void resetAll() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};