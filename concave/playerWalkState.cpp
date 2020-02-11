#include "playerWalkState.h"

PlayerWalkState::PlayerWalkState(Input* input)
{
    PlayerWalkState::input = input;
    state = PLAYER_STATE::WALK;
}

PLAYER_STATE PlayerWalkState::update(float frameTime, int index, Players* players)
{
    // std::cout << "IN WALK STATE : " << std::endl;
    // Move towards the direction
    // std::cout << "Current Position : " << position->x << " | " << position->y << std::endl;
    // std::cout << "Destination Position : " << destPosition->x << " | " << destPosition->y << std::endl;

    CoordF* position = &players->getPosition(index);
    CoordF* destPosition = &players->getDestPositions(index);
    if (!isAtPosition(position, destPosition)) {
        float currentX = position->x;
        float currentY = position->y;
        float destX = destPosition->x;
        float destY = destPosition->y;

        float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));

        // TODO : 1.50 is the current velcoity
        float moveX = 3.00 * sin(radAngle) * frameTime;
        float moveY = 3.00 * cos(radAngle) * frameTime;

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

        position->x += moveX;
        position->y += moveY;
        float newX = position->x += moveX;
        float newY = position->y += moveY;
        players->setPosition(index, CoordF{ newX, newY });
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;

}

bool PlayerWalkState::isAtPosition(CoordF* current, CoordF* destination)
{
    if ((abs(current->x - destination->x) < 0.1) && (abs(current->y - destination->y))) {
        return true;
    }
    return false;
}

