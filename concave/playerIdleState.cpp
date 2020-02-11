#include "playerIdleState.h"

PlayerIdleState::PlayerIdleState()
{
    state = PLAYER_STATE::IDLE;
}

PlayerIdleState::~PlayerIdleState()
{
}

PLAYER_STATE PlayerIdleState::update(float frameTime, int index, Level* level)
{
    Input* input = level->input;
    Players* players = level->getPlayers();
    if (input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(level->input->getMouseX()), float(input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, players->getPosition(index), players->getDestPositions(index)));
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;
}

