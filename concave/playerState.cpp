#include "playerState.h"

void PlayerAttackState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            fsm = level->getStates().at(PLAYER::IDLE);
            state = PLAYER::IDLE;
        }
    }
    return;
}

void PlayerDieState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
            fsm = level->getStates().at(PLAYER::IDLE);
            state = PLAYER::IDLE;
        }
    }
    return;
}

void PlayerIdleState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State*& fsm = players.getFsmArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];
    CoordF& dydx = players.getDyDxArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    float& rotation = players.getRotationArray()[index];

    if (input->getMouseLButton()) {
        input->setMouseLButton(false);
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = level->calculateRotation(position, destPosition);
        dydx = getMoveAmount(frameTime, rotation);
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::WALK);
        state = PLAYER::WALK;
        return;
    }
    else if (input->getMouseRButton()) {
        input->setMouseRButton(false);
        rotation = level->calculateRotation(position, CoordF{float(input->getMouseX()), float(input->getMouseY())});
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }
    else if (input->getMouseMButton()) {
        input->setMouseMButton(false);
        rotation = level->calculateRotation(position, CoordF{float(input->getMouseX()), float(input->getMouseY())});
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo>= animImage->getEndFrame(state)) {
            frameNo = 0;
        }
    }
    return;
}

void PlayerWalkState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State*& fsm = players.getFsmArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];
    CoordF& dydx = players.getDyDxArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    float& rotation = players.getRotationArray()[index];

    if (input->getMouseLButton()) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = level->calculateRotation(position, destPosition);
        dydx = getMoveAmount(frameTime, rotation);
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
        //     level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        // players.setMovement(index, Movement{ 0, 0, rotation });
        rotation = level->calculateRotation(position, CoordF{float(input->getMouseX()), float(input->getMouseY())});
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
        //     level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        // players.setMovement(index, Movement{ 0, 0, rotation });
        rotation = level->calculateRotation(position, CoordF{float(input->getMouseX()), float(input->getMouseY())});
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }

    if (isAtPosition(position, destPosition)) {
        // players.setMovement(index, Movement{ 0, 0, movement.rotation });
        // players.setState(index, level->getStates()->at(PLAYER::IDLE));
        // players.updateStateInfo(index, PLAYER::IDLE);
        rotation = level->calculateRotation(position, CoordF{float(input->getMouseX()), float(input->getMouseY())});
        frameNo = 0;
        fsm = level->getStates().at(PLAYER::FIRE);
        state = PLAYER::IDLE;
        return;
    }

    // If none of the previous if conditions, update movement 
    // players.setPosition(index, CoordF{ position.x += movement.moveX,
    //                                     position.y += movement.moveY });
    // updateFrameNo(frameTime, index, players, &renderInfo);
    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo>= animImage->getEndFrame(state)) {
            frameNo = 0;
        }
    }

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
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State*& fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
            fsm = level->getStates().at(PLAYER::IDLE);
            state = PLAYER::IDLE;
        }
    }
    return;
}

void PlayerFireState::update(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    State*& fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
            fsm = level->getStates().at(PLAYER::IDLE);
            state = PLAYER::IDLE;
        }
    }
    return;
}
