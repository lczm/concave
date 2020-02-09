#include "warriorIdleState.h"

WarriorIdleState::WarriorIdleState()
{
    state = UNITSTATE::IDLE;
    frameNo = 0;
    endFrame = 10;

    timer = 0;
    delay = float(0.03);
}

WarriorIdleState::~WarriorIdleState()
{
}

UNITSTATE WarriorIdleState::update(Input* input, float frameTime)
{
    if (input->getMouseLButton()) {
        input->setMouseLButton(false);

        Position* currentPosition = warriorStateManager->getPositionComponent();
        float currentX = currentPosition->sx;
        float currentY = currentPosition->sy;

        float destinationX = float(input->getMouseX());
        float destinationY = float(input->getMouseY());

        float radAngle = atan2(abs(currentX - destinationX), abs(currentY - destinationY));
        float degAngle = float(radAngle * (180 / PI));

        if (destinationX > currentX && destinationY < currentY) {
            cout << "Angle adding 0 " << endl;
            degAngle += 0;
        }
        else if (destinationX > currentX && destinationY > currentY) {
            cout << "Angle adding 90 " << endl;
            degAngle += 90;
        }
        else if (destinationX < currentX && destinationY > currentY) {
            cout << "Angle adding 180 " << endl;
            degAngle += 180;
        }
        else if (destinationX < currentX && destinationY < currentY) {
            cout << "Angle adding 270 " << endl;
            degAngle += 270;
        }

        cout << "Angle : " << degAngle << endl;

        warriorStateManager->updateMovementComponentRotation(degAngle);
        warriorStateManager->updateDestinationPositionComponent(destinationX, destinationY);
        warriorStateManager->updateMovementComponentVelocity(1000);
        return UNITSTATE::WALK;
    }

    if (input->getMouseRButton()) {
        return UNITSTATE::ATTACK;
    }

    updateFrameNo(frameTime);
    return UNITSTATE::IDLE;
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

int WarriorIdleState::getFrameNo()
{
    return frameNo;
}
