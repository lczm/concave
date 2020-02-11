#include "playerWalkState.h"

PlayerWalkState::PlayerWalkState(Input* input)
{
    PlayerWalkState::input = input;
    state = PLAYER_STATE::WALK;
}

PLAYER_STATE PlayerWalkState::update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement)
{
    // std::cout << "IN WALK STATE : " << std::endl;
    // Move towards the direction
    // std::cout << "Current Position : " << position->x << " | " << position->y << std::endl;
    // std::cout << "Destination Position : " << destPosition->x << " | " << destPosition->y << std::endl;

    if (!equalFloat(position->x, destPosition->x) && !equalFloat(position->y, destPosition->y)) {
        float currentX = position->x;
        float currentY = position->y;
        float destX = destPosition->x;
        float destY = destPosition->y;

        float radAngle = atan2(abs(currentX - destX), abs(currentY - destY)) + 1.57;
        float moveX = 1.50 * sin(radAngle) * frameTime;
        float moveY = 1.50 * cos(radAngle) * frameTime;

        std::cout << "Rad Angle " << radAngle << std::endl;
        std::cout << "Current X , Y " << currentX << " | " << currentY << std::endl;
        std::cout << "Destination X , Y " << destX << " | " << destY << std::endl;
        std::cout << "Move X  : " << moveX << std::endl;
        std::cout << "Move Y  : " << moveY << std::endl;

        if (destX > currentX && destY < currentY) {
            moveX = moveX;
            moveY = -moveY;
        }
        else if (destX > currentX && destY > currentY) {
            moveX = moveX;
            moveY = moveY;
        }
        else if (destX < currentX && destY > currentY) {
            moveX = -moveX;
            moveY = moveY;
        }
        else if (destX < currentX && destY < currentY) {
            moveX = -moveX;
            moveY = -moveY;
        }

        // movement->moveX = moveX;
        // movement->moveY = moveY;

        position->x += moveX;
        position->y += moveY;
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;

}
