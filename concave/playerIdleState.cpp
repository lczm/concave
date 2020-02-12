#include "playerIdleState.h"

PLAYER_STATE PlayerIdleState::update(int index, Level* level)
{
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getRenderInfos()[index];
    float frameTime = level->frameTime;
    if (input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(level->input->getMouseX()), float(input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, players->getPosition(index), players->getDestPositions(index)));
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::WALK;
    }
    else if (input->getMouseRButton()) {
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::ATTACK;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return PLAYER_STATE::IDLE;
}

