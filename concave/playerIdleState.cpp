#include "playerIdleState.h"

PlayerIdleState::PlayerIdleState(Input* input)
{
    PlayerIdleState::input = input;
    state = PLAYER_STATE::IDLE;
}

PlayerIdleState::~PlayerIdleState()
{
}

PLAYER_STATE PlayerIdleState::update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement)
{
    if (input->getMouseLButton()) {
        input->setMouseLButton(false);
        std::cout << "Mouse is down" << input->getMouseX() << input->getMouseY() << std::endl;
        destPosition->x = input->getMouseX();
        destPosition->y = input->getMouseY();
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;
}
