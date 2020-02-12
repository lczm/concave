#include "playerFireState.h"

PLAYER_STATE PlayerFireState::update(int index, Level* level)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getRenderInfos()[index];
    if (renderInfo->frameNo == players->getRender(index)->getEndFrame(renderInfo->state) - 1) {
        updateFrameNo(frameTime, index, players, renderInfo);
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::IDLE;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return PLAYER_STATE::FIRE;
}

