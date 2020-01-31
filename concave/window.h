#pragma once
#include "graphics.h"
#include "input.h"
#include <vector>
using namespace std;

class Window
{
private:
public:
	Window();
	~Window();
	virtual void initialize() = 0;
	virtual void releaseAll() = 0;
	virtual void resetAll() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};