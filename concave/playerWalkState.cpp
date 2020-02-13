#include "playerWalkState.h"

PLAYER_STATE PlayerWalkState::update(int index, Level* level)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players* players = level->getPlayers();
    RenderInfo* renderInfo = &players->getRenderInfos()[index];
    if (input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(level->input->getMouseX()), float(input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, players->getPosition(index), players->getDestPositions(index)));
        return PLAYER_STATE::WALK;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, players->getPosition(index),
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::FIRE;
    }
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, players->getPosition(index),
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players->setMovement(index, Movement{ 0, 0, rotation });
        renderInfo->timer = 0;
        renderInfo->frameNo = 0;
        return PLAYER_STATE::FIRE;
    }
    CoordF* position = &players->getPosition(index);
    CoordF* destPosition = &players->getDestPositions(index);
    Movement movement = players->getMovements(index);
    if (!isAtPosition(position, destPosition)) {
        Movement movement = players->getMovements(index);
        players->setPosition(index, CoordF{ position->x += movement.moveX,
                                            position->y += movement.moveY });
        updateFrameNo(frameTime, index, players, renderInfo);
        return PLAYER_STATE::WALK;
    }
    players->setMovement(index, Movement{ 0, 0, movement.rotation });
    renderInfo->timer = 0;
    renderInfo->frameNo = 0;
    return PLAYER_STATE::IDLE;
}

bool PlayerWalkState::isAtPosition(CoordF* current, CoordF* destination)
{
    if ((abs(current->x - destination->x) < 0.1) && (abs(current->y - destination->y))) {
        return true;
    }
    return false;
}

