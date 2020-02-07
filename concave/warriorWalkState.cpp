#include "warriorWalkState.h"

WarriorWalkState::WarriorWalkState()
{
    state = 3;
    frameNo = 0;
    endFrame = 8;

    timer = 0;
    delay = float(0.03);
}

WarriorWalkState::~WarriorWalkState()
{
}

void WarriorWalkState::update(Input* input, float frameTime)
{
    if (input->getMouseLButton()) {
        warriorStateManager->changeState(UNITSTATE::DIE);
        input->setMouseLButton(false);
        cout << "Changing state to die" << endl;
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

void WarriorWalkState::initialize(WarriorStateManager* warriorStateManager)
{
    WarriorWalkState::warriorStateManager = warriorStateManager;
}

void WarriorWalkState::enter()
{
    frameNo = 0;
    timer = 0;
}

int WarriorWalkState::getState()
{
    return state;
}

int WarriorWalkState::getFrameNo()
{
    return frameNo;
}
