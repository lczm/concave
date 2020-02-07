#include "warriorAttackState.h"

WarriorAttackState::WarriorAttackState()
{
    state = 0;
    frameNo = 0;
    endFrame = 16;

    timer = 0;
    delay = float(0.03);
}

WarriorAttackState::~WarriorAttackState()
{
}

void WarriorAttackState::update(Input* input, float frameTime)
{
    if (input->getMouseLButton()) {
        warriorStateManager->changeState(UNITSTATE::WALK);
        input->setMouseLButton(false);
        cout << "Changing state to walk" << endl;
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

void WarriorAttackState::initialize(WarriorStateManager* warriorStateManager)
{
    WarriorAttackState::warriorStateManager = warriorStateManager;
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