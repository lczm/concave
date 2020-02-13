#include "playerIdleState.h"

PLAYER_STATE PlayerIdleState::update(int index, Level* level)
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
        return PLAYER_STATE::WALK;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::FIRE;
    }
    // Temporary, middle click is to change between states
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::FIRE;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return PLAYER_STATE::IDLE;
}

