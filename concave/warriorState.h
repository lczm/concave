#pragma once
#include "image.h"

class WarriorState
{
public:
    virtual void update(float frameTime) = 0;
    virtual void enter() = 0;
    virtual int getState() = 0;
    virtual int getFrameNo() = 0;
};
