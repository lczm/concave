#pragma once
#include "image.h"
#include <iostream>
#include <vector>
using namespace std;

class Warrior
{
private:

    Graphics* graphics;

    Texture unitTexture;
    GridMask unitAttackGridMask;
    GridMask unitDieGridMask;
	GridMask unitIdleGridMask;
	GridMask unitWalkGridMask;
	vector<GridMask> unitGridMasks;
	vector<int> unitEndFrames;
	AnimImage unitImage;

public:
    Warrior();
    ~Warrior();

    void initialize(Graphics* graphics);
    void render(CoordF screenPos, float camScale);
    void onLostDevice();
    void onResetDevice();
};
