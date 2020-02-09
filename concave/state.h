#pragma once
#include "image.h"
#include "input.h"
#include "iostream"

class WarriorStateManager;

class State
{
public:
    UNITSTATE state;
    int frameNo;
    int endFrame;

    float timer;
    float delay;
    virtual UNITSTATE update(Input* input, float frameTime) = 0;
    virtual void initialize(WarriorStateManager* warriorStateManager) = 0;
    virtual void enter() = 0;
    virtual int getFrameNo() = 0;
    void updateFrameNo(float frameTime);
};
