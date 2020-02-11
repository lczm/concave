#include "playerDieState.h"

PlayerDieState::PlayerDieState()
{
    state = PLAYER_STATE::DIE;
}

PlayerDieState::~PlayerDieState()
{
}

PLAYER_STATE PlayerDieState::update(float frameTime, int index, Level* level)
{
    return PLAYER_STATE::DIE;
}
