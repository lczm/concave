#include "warriorAttackState.h"

WarriorAttackState::WarriorAttackState()
{
    cout << "Setting state to 0" << endl;
    state = 0;
    frameNo = 0;
    endFrame = 16;

    timer = 0;
    delay = float(0.03);
}

WarriorAttackState::~WarriorAttackState()
{
}

void WarriorAttackState::update(float frameTime)
{
	timer += frameTime;
	if (timer >= delay) {
		timer -= delay;
		frameNo++;
		if (frameNo >= endFrame) {
			frameNo = 0;
		}
	}
}

void WarriorAttackState::enter()
{
    frameNo = 0;
    timer = 0;
}

int WarriorAttackState::getState()
{
    return state;
}

int WarriorAttackState::getFrameNo()
{
    return frameNo;
}