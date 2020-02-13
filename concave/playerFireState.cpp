#include "playerFireState.h"

void PlayerFireState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getImageInfoArray()[index];
    if (renderInfo->frameNo == players->getImageArray()[index]->getEndFrame(renderInfo->state) - 1) {
        updateFrameNo(frameTime, index, players, renderInfo);
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        players->getStateArray()[index] = level->getStates()->at(PLAYER_STATE::IDLE);
        players->getImageInfoArray()[index].state = PLAYER_STATE::IDLE;
        return;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return;
}

