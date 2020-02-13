#include "playerState.h"

void PlayerAttackState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    if (renderInfo.frameNo == players.getImageArray()[index]->getEndFrame(renderInfo.state) - 1) {
        updateFrameNo(frameTime, index, players, &renderInfo);
        players.setState(index, level->getStates()->at(PLAYER::IDLE));
        players.updateStateInfo(index, PLAYER::IDLE);
        return;
    }
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}

void PlayerDieState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    if (renderInfo.frameNo == players.getImageArray()[index]->getEndFrame(renderInfo.state) - 1) {
        updateFrameNo(frameTime, index, players, &renderInfo);
        players.setState(index, level->getStates()->at(PLAYER::IDLE));
        players.updateStateInfo(index, PLAYER::IDLE);
        return;
    }
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}

void PlayerIdleState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    CoordF position = players.getPositionArray()[index];
    CoordF destPosition = players.getDestPositionArray()[index];

    if (input->getMouseLButton()) {
        players.setDestPosition(index, level->screenToGrid(CoordF{float(input->getMouseX()), float(input->getMouseY())}));
        players.setMovement(index, calculateMovement(frameTime, position, destPosition));
        players.setState(index, level->getStates()->at(PLAYER::WALK));
        players.updateStateInfo(index, PLAYER::WALK);
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players.setMovement(index, Movement{ 0, 0, rotation });
        players.setState(index, level->getStates()->at(PLAYER::FIRE));
        players.updateStateInfo(index, PLAYER::FIRE);
        return;
    }
    // Temporary, middle click is to change between states
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players.setMovement(index, Movement{ 0, 0, rotation });
        players.setState(index, level->getStates()->at(PLAYER::FIRE));
        players.updateStateInfo(index, PLAYER::FIRE);
        return;
    }
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}

void PlayerWalkState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    CoordF position = players.getPositionArray()[index];
    CoordF destPosition = players.getDestPositionArray()[index];
    Movement movement = players.getMovementArray()[index];

    if (input->getMouseLButton()) {
        players.setDestPosition(index, level->screenToGrid(CoordF{float(input->getMouseX()), float(input->getMouseY())}));
        players.setMovement(index, calculateMovement(frameTime, position, destPosition));
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players.setMovement(index, Movement{ 0, 0, rotation });
        players.setState(index, level->getStates()->at(PLAYER::FIRE));
        players.updateStateInfo(index, PLAYER::FIRE);
        return;
    }
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        float rotation = calculateMovement(frameTime, position,
            level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        players.setMovement(index, Movement{ 0, 0, rotation });
        players.setState(index, level->getStates()->at(PLAYER::FIRE));
        players.updateStateInfo(index, PLAYER::FIRE);
        return;
    }

    if (isAtPosition(position, destPosition)) {
        players.setMovement(index, Movement{ 0, 0, movement.rotation });
        players.setState(index, level->getStates()->at(PLAYER::IDLE));
        players.updateStateInfo(index, PLAYER::IDLE);
        return;
    }

    // If none of the previous if conditions, update movement 
    players.setPosition(index, CoordF{ position.x += movement.moveX,
                                        position.y += movement.moveY });
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}

bool PlayerWalkState::isAtPosition(CoordF current, CoordF destination)
{
    if ((abs(current.x - destination.x) < 0.1) && (abs(current.y - destination.y))) {
        return true;
    }
    return false;
}

void PlayerGetHitState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    if (renderInfo.frameNo == players.getImageArray()[index]->getEndFrame(renderInfo.state) - 1) {
        updateFrameNo(frameTime, index, players, &renderInfo);
        players.setState(index, level->getStates()->at(PLAYER::IDLE));
        players.updateStateInfo(index, PLAYER::IDLE);
        return;
    }
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}

void PlayerFireState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    RenderInfo& renderInfo = players.getImageInfoArray()[index];
    if (renderInfo.frameNo == players.getImageArray()[index]->getEndFrame(renderInfo.state) - 1) {
        updateFrameNo(frameTime, index, players, &renderInfo);
        players.setState(index, level->getStates()->at(PLAYER::IDLE));
        players.updateStateInfo(index, PLAYER::IDLE);
        return;
    }
    updateFrameNo(frameTime, index, players, &renderInfo);
    return;
}
