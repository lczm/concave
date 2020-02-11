#include "playerIdleState.h"

PlayerIdleState::PlayerIdleState(Input* input)
{
    PlayerIdleState::input = input;
    state = PLAYER_STATE::IDLE;
}

PlayerIdleState::~PlayerIdleState()
{
}

PLAYER_STATE PlayerIdleState::update(float frameTime, int index, Players* players)
{
    if (input->getMouseLButton()) {
        CoordF* dest = &players->getDestPositions(index);
        input->setMouseLButton(false);
        std::cout << "Mouse is down" << input->getMouseX() << input->getMouseY() << std::endl;
        players->setDestPosition(index, CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;
}
