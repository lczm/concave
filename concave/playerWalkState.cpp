#include "playerWalkState.h"

void PlayerWalkState::update(Level* level, int index)
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

    Movement movement = players->getMovementArray()[index];
    if (!isAtPosition(position, destPosition)) {
        players->setPosition(index, CoordF{ position.x += movement.moveX,
                                            position.y += movement.moveY });
        updateFrameNo(frameTime, index, players, renderInfo);
        return;
    }

    players->setMovement(index, Movement{ 0, 0, movement.rotation });
    renderInfo->timer = 0;
    renderInfo->frameNo = 0;
    players->getStateArray()[index] = level->getStates()->at(PLAYER_STATE::IDLE);
    players->getImageInfoArray()[index].state = PLAYER_STATE::IDLE;
    return;
}

bool PlayerWalkState::isAtPosition(CoordF current, CoordF destination)
{
    if ((abs(current.x - destination.x) < 0.1) && (abs(current.y - destination.y))) {
        return true;
    }
    return false;
}

