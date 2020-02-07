#pragma once
#include "image.h"
#include "input.h"
#include <iostream>
#include <vector>

#include "warriorStateManager.h"
using namespace std;

class Warrior
{
private:
    Graphics* graphics;
    Input* input;
    WarriorStateManager* state;

    int direction;

    // Textures
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

    void initialize(Graphics* graphics, Input* input);
    void update(float frameTime);
    void render(CoordF screenPos, float camScale);

    void onLostDevice();
    void onResetDevice();
};
