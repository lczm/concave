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
        // Temporary setting it false
        input->setMouseLButton(false);
        float screenX = float(input->getMouseX());
        float screenY = float(input->getMouseY());

        warriorStateManager->updateDestinationPositionComponent(screenX, screenY);
        cout << "IDLE : Updating Destination Position Component " << screenX << " | " << screenY << endl;
        warriorStateManager->updateMovementComponent(500);
        cout << "IDLE : Setting Movement Component " << 1.0 << endl;

        warriorStateManager->changeState(UNITSTATE::WALK);
    }
    updateFrameNo(frameTime);
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
