#include "playerFSM.h"

void playerAttackState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0; frameNo = 0;
            fsm = playerIdleState;
            state = UNIT_STATE_IDLE;
        }
    }
}

void playerDieState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
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
            fsm = playerIdleState;
            state = UNIT_STATE_IDLE;
        }
    }
}

void playerIdleState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    float& rotation = players.getRotationArray()[index];
    float& velocity = players.getVelocityArray()[index];
    Projectiles& projectiles = level->getProjectiles();

    if (input->getMouseLButton()) {
        input->setMouseLButton(false);
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        velocity = 5;
        frameNo = 0;
        fsm = playerWalkState;
        state = UNIT_STATE_WALK;
        return;
    }
    else if (input->getMouseRButton()) {
        input->setMouseRButton(false);
        rotation = calculateRotation(position, level->screenToGrid(input->getMouseX(), input->getMouseY()));
        frameNo = 0;
        fsm = playerMagicFireState;
        state = PLAYER_STATE_MAGIC_FIRE;

        vector<float> temp = { float(rotation - PI/8), rotation, float(rotation + PI/8) };
        for (int i = 0; i < 3; i++) {
            projectiles.push(
                position, &level->getProjImage(),
                translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
                translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
            temp[i]);
        }
        return;
    }
    else if (input->getMouseMButton()) {
        input->setMouseMButton(false);
        rotation = calculateRotation(position, level->screenToGrid(input->getMouseX(), input->getMouseY()));
        frameNo = 0;
        fsm = playerGetHitState;
        state = UNIT_STATE_ATTACK;
        return;
    }
    else if (input->isKeyDown('Q')) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        position = destPosition;
        frameNo = 0;
        fsm = playerMagicSmokeState;
        state = PLAYER_STATE_MAGIC_LIGHTNING;
        return;
    }

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
        }
    }
}

void playerWalkState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    float& rotation = players.getRotationArray()[index];
    float& velocity = players.getVelocityArray()[index];
    Projectiles& projectiles = level->getProjectiles();

    if (input->getMouseLButton()) {
        input->setMouseLButton(false);
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        return;
    }
    else if (input->getMouseRButton()) {
        input->setMouseRButton(false);
        destPosition = position;
        velocity = 0;
        rotation = calculateRotation(position, level->screenToGrid(input->getMouseX(), input->getMouseY()));
        frameNo = 0;
        fsm = playerMagicFireState;
        state = PLAYER_STATE_MAGIC_FIRE;

        projectiles.push(
            position, &level->getProjImage(),
            translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
            translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
        rotation);
        return;
    }
    else if (input->getMouseMButton()) {
        input->setMouseMButton(false);
        destPosition = position;
        velocity = 0;
        rotation = calculateRotation(position, level->screenToGrid(input->getMouseX(), input->getMouseY()));
        frameNo = 0;
        fsm = playerAttackState;
        state = UNIT_STATE_ATTACK;
        return;
    }

    if (fastSquareProximityCheck(position, destPosition, 0.01)) {
        destPosition = position;
        velocity = 0;
        frameNo = 0;
        fsm = playerIdleState;
        state = UNIT_STATE_IDLE;
        return;
    }

    timer += frameTime;
    if (timer >= delay) {
        timer -= delay;
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
        }
    }
}

void playerGetHitState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            frameNo = 0;
            fsm = playerIdleState;
            state = UNIT_STATE_IDLE;
        }
    }
    return;
}

void playerMagicFireState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
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
            fsm = playerIdleState;
            state = UNIT_STATE_IDLE;
        }
    }
    return;
}

void playerMagicSmokeState(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getAnimImageArray()[index];
    FSM& fsm = players.getFSMArray()[index];
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
            fsm = playerIdleState;
            state = UNIT_STATE_IDLE;
        }
    }
    return;
}
