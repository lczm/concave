#pragma once
#include "image.h"
#include "input.h"
#include "component.h"
#include "warriorStateManager.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace Component;

class Warrior
{
private:
    Graphics* graphics;
    Input* input;
    WarriorStateManager* stateManager;

    // Textures
    Texture unitTexture;
    GridMask unitAttackGridMask;
    GridMask unitDieGridMask;
	GridMask unitIdleGridMask;
	GridMask unitWalkGridMask;
	vector<GridMask> unitGridMasks;
	vector<int> unitEndFrames;
	AnimImage unitImage;

    Position* positionComponent;
    Movement* movementComponent;
    int direction;

public:
    Warrior();
    ~Warrior();

    void initialize(Graphics* graphics, Input* input, Position* positionComponent, Movement* movementComponent);
    void update(float frameTime);
    SpriteData getSpriteData();

    void onLostDevice();
    void onResetDevice();
};
