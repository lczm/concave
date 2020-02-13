#include "playerFireState.h"

PLAYER_STATE PlayerFireState::update(int index, Level* level)
{
    cout << "IN FIRE" << endl;
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getImageInfoArray()[index];
    if (renderInfo->frameNo == players->getImageArray()[index]->getEndFrame(renderInfo->state) - 1) {
        updateFrameNo(frameTime, index, players, renderInfo);
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::IDLE;
    }
    updateFrameNo(frameTime, index, players, renderInfo);
    return PLAYER_STATE::FIRE;
}

