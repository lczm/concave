#include "playerIdleState.h"

void PlayerIdleState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getImageInfoArray()[index];
    CoordF position = players->getPositionArray()[index];
    CoordF destPosition = players->getDestPositionArray()[index];

    if (input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(input->getMouseX()), float(input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, position, destPosition));
        players->setState(index, level->getStates()->at(PLAYER_STATE::WALK));
        players->updateStateInfo(index, PLAYER_STATE::WALK);
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        players->setState(index, level->getStates()->at(PLAYER_STATE::FIRE));
        players->updateStateInfo(index, PLAYER_STATE::FIRE);
        return;
    }
    // Temporary, middle click is to change between states
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        players->setState(index, level->getStates()->at(PLAYER_STATE::FIRE));
        players->updateStateInfo(index, PLAYER_STATE::FIRE);
        return;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return;
}

