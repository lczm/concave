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
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        players->getStateArray()[index] = level->getStates()->at(PLAYER_STATE::WALK);
        players->getImageInfoArray()[index].state = PLAYER_STATE::WALK;
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        players->getStateArray()[index] = level->getStates()->at(PLAYER_STATE::FIRE);
        players->getImageInfoArray()[index].state = PLAYER_STATE::FIRE;
        return;
    }
    // Temporary, middle click is to change between states
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        players->getStateArray()[index] = level->getStates()->at(PLAYER_STATE::FIRE);
        players->getImageInfoArray()[index].state = PLAYER_STATE::FIRE;
        return;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return;
}

