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
    if (input->getMouseRButton()) {
        warriorStateManager->changeState(UNITSTATE::ATTACK);
    }
    else {
        Position* currentPosition = warriorStateManager->getPositionComponent();
        float currentX = currentPosition->sx;
        float currentY = currentPosition->sy;

        Position* destinationPosition = warriorStateManager->getDestinationComponent();
        float destinationX = destinationPosition->sx;
        float destinationY = destinationPosition->sy;

        Movement* movement = warriorStateManager->getMovementComponent();
        float velocity = movement->velocity;

        // While current position is not destination position
        if (!equalFloat(currentX, destinationX) && !equalFloat(currentY, destinationY)) {
            // Move unit towards it
            float radAngle = atan2(abs(currentX - destinationX), abs(currentY - destinationY));
            float moveX = velocity * sin(radAngle) * frameTime;
            float moveY = velocity * cos(radAngle) * frameTime;

            if (destinationX > currentX && destinationY < currentY) {
                moveX = moveX;
                moveY = -moveY;
            }
            else if (destinationX > currentX && destinationY > currentY) {
                moveX = moveX;
                moveY = moveY;
            }
            else if (destinationX < currentX && destinationY > currentY) {
                moveX = -moveX;
                moveY = moveY;
            }
            else if (destinationX < currentX && destinationY < currentY) {
                moveX = -moveX;
                moveY = -moveY;
            }

            warriorStateManager->updatePositionComponent(currentX + moveX, currentY + moveY);
            updateFrameNo(frameTime);
        }
        else {
            warriorStateManager->changeState(UNITSTATE::IDLE);
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

bool WarriorWalkState::equalFloat(float a, float b)
{
    // Multiply epsilon by a big number to get a decent estimate
    // else, it would take a long time to centralize the position to
    // the exact epsilon difference
    return fabs(a - b) < (FLT_EPSILON * 20000000);
}

