#pragma once
#include "image.h"
#include "input.h"

class WarriorStateManager;

class State
{
public:
    virtual void update(Input* input, float frameTime) = 0;
    virtual void initialize(WarriorStateManager* warriorStateManager) = 0;
    virtual void enter() = 0;
    virtual int getState() = 0;
    virtual int getFrameNo() = 0;
};
