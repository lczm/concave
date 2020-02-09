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
        float degAngle = float(radAngle * (180 / PI));
        cout << "Rad Angle : " << radAngle << endl;
        cout << "Deg Angle : " << degAngle << endl;
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

        float moveX = velocity * sin(radAngle) * frameTime;
        float moveY = velocity * cos(radAngle) * frameTime;
        cout << "MoveX : " << moveX << endl;
        cout << "MoveY : " << moveY << endl;

        radAngle = tan(degAngle * (PI / 180));

        // Assigning quadrant negative/positive values
        if (degAngle <= 90) {
            moveX = moveX;
            moveY = -moveY;
        }
        else if (degAngle <= 180) {
            moveX = moveX;
            moveY = moveY;
        }
        else if (degAngle <= 270) {
            moveX = -moveX;
            moveY = moveY;
        }
        else {
            moveX = -moveX;
            moveY = -moveY;
        }

        warriorStateManager->updatePositionComponent(currentX + moveX, currentY + moveY);
        warriorStateManager->updateMovementComponentRotation(radAngle);
        // warriorStateManager->updatePositionComponent(calculatedX, calculatedY);
        updateFrameNo(frameTime);
    }
    else {
        warriorStateManager->changeState(UNITSTATE::IDLE);
    }
    // updateFrameNo(frameTime);
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
    return fabs(a - b) < (FLT_EPSILON * 50000000);
}

