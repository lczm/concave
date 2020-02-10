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

        float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
        float moveX = 1.50 * sin(radAngle) * frameTime;
        float moveY = 1.50 * cos(radAngle) * frameTime;


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

        // std::cout << "Move X  : " << moveX << std::endl;
        // std::cout << "Move Y  : " << moveY << std::endl;

        movement->moveX = moveX;
        movement->moveY = moveY;
        position->x += moveY;
        position->y += moveX;
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;

}
