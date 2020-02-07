#pragma once
#include "image.h"
#include "input.h"
#include "component.h"
#include "warriorStateManager.h"
#include <iostream>
#include <vector>

using namespace std;

class Warrior
{
private:
    Graphics* graphics;
    Input* input;
    WarriorStateManager* state;

    // Textures
    Texture unitTexture;
    GridMask unitAttackGridMask;
    GridMask unitDieGridMask;
	GridMask unitIdleGridMask;
	GridMask unitWalkGridMask;
	vector<GridMask> unitGridMasks;
	vector<int> unitEndFrames;
	AnimImage unitImage;

    Component::Position* positionComponent;
    int direction;

public:
    Warrior();
    ~Warrior();

    void initialize(Graphics* graphics, Input* input, Component::Position* positionComponent);
    void update(float frameTime);
    SpriteData getSpriteData();
    CoordF getGridCoords();

    void onLostDevice();
    void onResetDevice();
};
