#include "playerWalkState.h"

PlayerWalkState::PlayerWalkState()
{
    state = PLAYER_STATE::WALK;
}

PLAYER_STATE PlayerWalkState::update(float frameTime, int index, Level* level)
{
    Input* input = level->input;
    Players* players = level->getPlayers();
    if (input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(level->input->getMouseX()), float(input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, players->getPosition(index), players->getDestPositions(index)));
        return PLAYER_STATE::WALK;
    }

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

