#include "playerWalkState.h"

PlayerWalkState::PlayerWalkState(Level* level)
{
    PlayerWalkState::level = level;
    state = PLAYER_STATE::WALK;
}

PLAYER_STATE PlayerWalkState::update(float frameTime, int index, Players* players)
{
    CoordF* position = &players->getPosition(index);
    CoordF* destPosition = &players->getDestPositions(index);
    if (!isAtPosition(position, destPosition)) {
        Movement movement = players->getMovements(index);
        // players->setPosition(index, CoordF{ newX, newY });
        players->setPosition(index, CoordF{ position->x += movement.moveX,
                                            position->y += movement.moveY });
        return PLAYER_STATE::WALK;
    }
    players->setMovement(index, Movement{ 0, 0 });
    return PLAYER_STATE::IDLE;

}

bool PlayerWalkState::isAtPosition(CoordF* current, CoordF* destination)
{
    if ((abs(current->x - destination->x) < 0.1) && (abs(current->y - destination->y))) {
        return true;
    }
    return false;
}

