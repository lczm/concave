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

        Position* currentPosition = warriorStateManager->getPositionComponent();
        float currentX = currentPosition->sx;
        float currentY = currentPosition->sy;

        float destinationX = float(input->getMouseX());
        float destinationY = float(input->getMouseY());

        float radAngle = atan2(abs(currentX - destinationX), abs(currentY - destinationY));
        float degAngle = float(radAngle * (180 / PI));

        if (destinationX > currentX && destinationY < currentY) {
            degAngle += 0;
        }
        else if (destinationX > currentX && destinationY > currentY) {
            degAngle += 90;
        }
        else if (destinationX < currentX && destinationY > currentY) {
            degAngle += 180;
        }
        else if (destinationX < currentX && destinationY < currentY) {
            degAngle += 270;
        }

        cout << "Angle : " << degAngle << endl;

        warriorStateManager->updateMovementComponentRotation(degAngle);
        warriorStateManager->updateDestinationPositionComponent(destinationX, destinationY);
        warriorStateManager->updateMovementComponentVelocity(100);
        warriorStateManager->changeState(UNITSTATE::WALK);
    }
    else if (input->getMouseRButton()) {
        warriorStateManager->changeState(UNITSTATE::ATTACK);
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
