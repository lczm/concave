#pragma once
#include "window.h"

class ModifierSelect : public Window
{
private:
	Graphics* graphics;
	Input* input;
	GridMask modifierGridMask;
	CoordI wandCoord;
	CoordI shieldCoord;
	CoordI swordCoord;

public:
	ModifierSelect();
};


