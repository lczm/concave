#include "playerAttackState.h"

PLAYER_STATE PlayerAttackState::update(int index, Level* level)
{
    Input* input = level->input;
    Players* players = level->getPlayers();
    float frameTime = level->frameTime;
    RenderInfo* renderInfo = &players->getRenderInfos()[index];
    if (renderInfo->frameNo == players->getRender(index)->getEndFrame(renderInfo->state) - 1) {
        updateFrameNo(frameTime, index, players, renderInfo);
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::IDLE;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return PLAYER_STATE::ATTACK;
}

