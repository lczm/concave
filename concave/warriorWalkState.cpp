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
        float degAngle = radAngle * 180 / PI;
        cout << "Rad Angle : " << radAngle << endl;
        cout << "Deg Angle : " << degAngle << endl;
        // cout << "Angle : " << angle * 180 / atan(1)*4 << endl;
        float moveX = velocity * sin(radAngle) * frameTime;
        float moveY = velocity * cos(radAngle) * frameTime;
        cout << "MoveX : " << moveX << endl;
        cout << "MoveY : " << moveY << endl;

        warriorStateManager->updatePositionComponent(currentX + moveX, currentY + moveY);
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
    return fabs(a - b) < (FLT_EPSILON * 5000000);
}

