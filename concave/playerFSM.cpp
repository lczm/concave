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

    handlePotionInput(input, players, index);
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

    handlePotionInput(input, players, index);
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
    float& staticVelocity = players.getStaticVelocityArray()[index];
    Projectiles& projectiles = level->getProjectiles();

    handlePotionInput(input, players, index);
    if (input->getMouseLButton()) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        velocity = staticVelocity;
        frameNo = 0;
        fsm = playerWalkState;
        state = UNIT_STATE_WALK;
        return;
    }
    else if (input->getMouseRButton()) {
        rotation = calculateRotation(position, level->screenToGrid(input->getMouseX(), input->getMouseY()));
        frameNo = 0;
        fsm = playerMagicFireState;
        state = PLAYER_STATE_MAGIC_FIRE;

        if (players.getNoProjArray()[index] == 1) {
            projectiles.push(
                position, &level->getProjImage(),
                translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
                translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
            rotation);
        }
        else {
            float range = PI / 4; // 90 degrees
            float left = rotation - (range / 2); // get the most left edge
            float increment = range / players.getNoProjArray()[index]; 
            for (int i = 0; i < players.getNoProjArray()[index]; i++) {
                projectiles.push(
                    position, &level->getProjImage(),
                    translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
                    translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, position),
                left + ( i * increment));
            }
            return;
        }

    }
    else if (input->getMouseMButton() || input->isKeyDown('Q')) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        position = destPosition;
        velocity = 0;
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

    handlePotionInput(input, players, index);
    if (input->getMouseLButton()) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        return;
    }
    else if (input->getMouseRButton()) {
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
    else if (input->getMouseMButton() || input->isKeyDown('Q')) {
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });
        rotation = calculateRotation(position, destPosition);
        position = destPosition;
        velocity = 0;
        frameNo = 0;
        fsm = playerMagicSmokeState;
        state = PLAYER_STATE_MAGIC_LIGHTNING;
        return;
    }

    if (fastSquareProximityCheck(position, destPosition, 0.1)) {
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

    handlePotionInput(input, players, index);
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

    handlePotionInput(input, players, index);
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

    handlePotionInput(input, players, index);
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

void handlePotionInput(Input* input, Players& players, int index)
{
    vector<Potion>& potions = players.getPotionArray()[index];
    int& health = players.getHealthArray()[index];
    int& maxHealth = players.getMaxHealthArray()[index];
    int& mana = players.getManaArray()[index];
    int& maxMana = players.getMaxManaArray()[index];
    // Number 1 - Health
    if (input->wasKeyPressed(0x31)) {
        potions[0].charge = 0;
        health += 40;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }
    // Number 2 - Health
    if (input->wasKeyPressed(0x32)) {
        potions[1].charge = 0;
        health += 40;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }
    // Number 3 - Mana
    if (input->wasKeyPressed(0x33)) {
        potions[2].charge = 0;
        mana += 40;
        if (mana > maxMana) {
            mana = maxMana;
        }
    }
    // Number 4 - Mana
    if (input->wasKeyPressed(0x34)) {
        potions[3].charge = 0;
        mana += 40;
        if (mana > maxMana) {
            mana = maxMana;
        }
    }
}
