#include "playerDieState.h"

PlayerDieState::PlayerDieState()
{
    state = PLAYER_STATE::DIE;
}

PlayerDieState::~PlayerDieState()
{
}

PLAYER_STATE PlayerDieState::update(int index, Level* level)
{
    return PLAYER_STATE::DIE;
}
