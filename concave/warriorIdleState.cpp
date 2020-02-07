#include "warriorIdleState.h"

WarriorIdleState::WarriorIdleState()
{
    state = 2;
    frameNo = 0;
    endFrame = 10;

    timer = 0;
    delay = float(0.03);
}

WarriorIdleState::~WarriorIdleState()
{
}

void WarriorIdleState::update(Input* input, float frameTime)
{
    if (input->getMouseLButton()) {
        warriorStateManager->changeState(UNITSTATE::ATTACK);
        input->setMouseLButton(false);
    }

	timer += frameTime;
	if (timer >= delay) {
		timer -= delay;
		frameNo++;
		if (frameNo >= endFrame) {
			frameNo = 0;
		}
	}
}

void WarriorIdleState::initialize(WarriorStateManager* warriorStateManager)
{
    WarriorIdleState::warriorStateManager = warriorStateManager;
}

void WarriorIdleState::enter()
{
    frameNo = 0;
    timer = 0;
}

int WarriorIdleState::getState()
{
    return state;
}

int WarriorIdleState::getFrameNo()
{
    return frameNo;
}
