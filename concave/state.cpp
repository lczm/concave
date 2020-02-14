#include "state.h"

// Movement State::calculateMovement(float frameTime, CoordF position, CoordF destPosition)
// {
//      float currentX = position.x;
//      float currentY = position.y;
//  
//      float destX = destPosition.x;
//      float destY = destPosition.y;
// 
//      float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
//      float degAngle = radAngle * (180 / PI);
//      // TODO : SPEED
//      float moveX = float(SPEED * sin(radAngle) * frameTime);
//      float moveY = float(SPEED * cos(radAngle) * frameTime);
// 
//      if (destX > currentX && destY < currentY) {
//          moveX = moveX;
//          moveY = -moveY;
//      }
//      else if (destX > currentX && destY > currentY) {
//          degAngle = 180 - degAngle;
//          moveX = moveX;
//          moveY = moveY;
//      }
//      else if (destX < currentX && destY > currentY) {
//          degAngle = 180 + degAngle;
//          moveX = -moveX;
//          moveY = moveY;
//      }
//      else if (destX < currentX && destY < currentY) {
//          degAngle = 360 - degAngle;
//          moveX = -moveX;
//          moveY = -moveY;
//      }
// 
//      // Dimetric angle offset
//      degAngle += 25.565;
//      return Movement{ moveX, moveY, degAngle };
// }

// void State::updateFrameNo(float frameTime, int index, Players players, RenderInfo* renderInfo)
// {
//     renderInfo->timer += frameTime;
//     if (renderInfo->timer >= renderInfo->delay) {
//         renderInfo->timer -= renderInfo->delay;
//         renderInfo->frameNo++;
//         if (renderInfo->frameNo == players.getImageArray()[index]->getEndFrame(renderInfo->state)) {
//             renderInfo->frameNo = 0;
//         }
//     }
// }

// bool State::peekChangeState(float frameTime, int index, Players players, RenderInfo* renderInfo, State* newState, PLAYER state)
// {
//     if (renderInfo->frameNo == players.getImageArray()[index]->getEndFrame(renderInfo->state) - 1) {
//         updateFrameNo(frameTime, index, players, renderInfo);
//         players.setState(index, newState);
//         players.updateStateInfo(index, state);
//         return true;
//     }
//     return false;
// }

void PlayerAttackState::operator()(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    // if (peekChangeState(frameTime, index, players, &renderInfo, level->getStates()->at(PLAYER::IDLE), PLAYER::IDLE)) {
    //     return;
    // }
    // updateFrameNo(frameTime, index, players, &renderInfo);

    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerIdleState();
            // fsm = &level->playerIdleState;
            delete fsm;
            fsm = new PlayerIdleState();
        }
    }
    return;
}

void PlayerDieState::operator()(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    // if (peekChangeState(frameTime, index, players, &renderInfo, level->getStates()->at(PLAYER::IDLE), PLAYER::IDLE)) {
    //     return;
    // }
    // updateFrameNo(frameTime, index, players, &renderInfo);
    // return;
    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerIdleState();
            // fsm = &level->playerIdleState;
            delete fsm;
            fsm = new PlayerIdleState();
        }
    }
    return;
}

void PlayerIdleState::operator()(Level* level, int index)
{
    std::cout << "idle" << endl;
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];

    if (input->getMouseLButton()) {
        // players.setDestPosition(index, level->screenToGrid(CoordF{float(input->getMouseX()), float(input->getMouseY())}));
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });

        // players.setMovement(index, calculateMovement(frameTime, position, destPosition));
        // TODO -- CalculateMovement

        // players.setState(index, level->getStates()->at(PLAYER::WALK));
        // fsm = PlayerWalkState();
        // fsm = &level->playerWalkState;
        delete fsm;
        fsm = new PlayerWalkState();

        // players.updateStateInfo(index, PLAYER::WALK);
        state = PLAYER::WALK;
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
            // level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;

        // players.setMovement(index, Movement{ 0, 0, rotation });

        // players.setState(index, level->getStates()->at(PLAYER::FIRE));
        // fsm = PlayerFireState();
        // fsm = &level->playerFireState;
        delete fsm;
        fsm = new PlayerFireState();

        // players.updateStateInfo(index, PLAYER::FIRE);
        state = PLAYER::WALK;
        return;
    }
    // Temporary, middle click is to change between states
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
            // level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;
        // players.setMovement(index, Movement{ 0, 0, rotation });

        // players.setState(index, level->getStates()->at(PLAYER::FIRE));
        // fsm = PlayerFireState();
        // fsm = &level->playerFireState;
        delete fsm;
        fsm = new PlayerFireState();

        // players.updateStateInfo(index, PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }
    // updateFrameNo(frameTime, index, players, &renderInfo);
    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerIdleState();
        }
    }
    return;
}

void PlayerWalkState::operator()(Level* level, int index)
{
    std::cout << "walk" << std::endl;
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];
    CoordF& position = players.getPositionArray()[index];
    CoordF& destPosition = players.getDestPositionArray()[index];

    if (input->getMouseLButton()) {
        // players.setDestPosition(index, level->screenToGrid(CoordF{float(input->getMouseX()), float(input->getMouseY())}));
        destPosition = level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) });

        // TODO
        // players.setMovement(index, calculateMovement(frameTime, position, destPosition));
        return;
    }
    else if (input->getMouseRButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
            // level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;

        // TODO 
        // players.setMovement(index, Movement{ 0, 0, rotation });

        // players.setState(index, level->getStates()->at(PLAYER::FIRE));
        // fsm = PlayerFireState();
        // fsm = &level->playerFireState;
        delete fsm;
        fsm = new PlayerFireState();

        // players.updateStateInfo(index, PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }
    else if (input->getMouseMButton()) {
        // Change directions based on where mouse is 
        // float rotation = calculateMovement(frameTime, position,
            // level->screenToGrid(CoordF{ float(input->getMouseX()), float(input->getMouseY()) })).rotation;

        // TODO 
        // players.setMovement(index, Movement{ 0, 0, rotation });

        // players.setState(index, level->getStates()->at(PLAYER::FIRE));
        // fsm = PlayerFireState();
        // fsm = &level->playerFireState;
        delete fsm;
        fsm = new PlayerFireState();

        // players.updateStateInfo(index, PLAYER::FIRE);
        state = PLAYER::FIRE;
        return;
    }

    // if (isAtPosition(position, destPosition)) {
    //     players.setMovement(index, Movement{ 0, 0, movement.rotation });
    //     players.setState(index, level->getStates()->at(PLAYER::IDLE));
    //     players.updateStateInfo(index, PLAYER::IDLE);
    //     return;
    // }
    if (abs(position.x - destPosition.x) < 0.1 && abs(position.y - destPosition.y)) {
        // TODO
        // players.setMovement(index, Movement{ 0, 0, movement.rotation });

        // players.setState(index, level->getStates()->at(PLAYER::IDLE));
        // fsm = PlayerIdleState();
        // fsm = &level->playerFireState;
        delete fsm;
        fsm = new PlayerFireState();

        // players.updateStateInfo(index, PLAYER::IDLE);
        state = PLAYER::IDLE;
        return;
    }

    // If none of the previous if conditions, update movement 
    // TODO : System moves the players
    // players.setPosition(index, CoordF{ position.x += movement.moveX,
                                        // position.y += movement.moveY });
    // updateFrameNo(frameTime, index, players, &renderInfo);
    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerIdleState();
        }
    }
    return;
}

void PlayerGetHitState::operator()(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    // if (peekChangeState(frameTime, index, players, &renderInfo, level->getStates()->at(PLAYER::IDLE), PLAYER::IDLE)) {
    //     return;
    // }
    // updateFrameNo(frameTime, index, players, &renderInfo);

    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerIdleState();
            delete fsm;
            fsm = new PlayerIdleState();
        }
    }
    return;
}

void PlayerFireState::operator()(Level* level, int index)
{
    float frameTime = level->frameTime;
    Input* input = level->input;
    Players& players = level->getPlayers();
    AnimImage*& animImage = players.getImageArray()[index];
    State* fsm = players.getFsmArray()[index];
    int& state = players.getStateArray()[index];
    int& frameNo = players.getFrameNoArray()[index];
    float& timer = players.getTimerArray()[index];
    float& delay = players.getDelayArray()[index];

    // if (peekChangeState(frameTime, index, players, &renderInfo, level->getStates()->at(PLAYER::IDLE), PLAYER::IDLE)) {
    //     return;
    // }
    // updateFrameNo(frameTime, index, players, &renderInfo);

    timer += frameTime;
    if (timer >= delay) {
        frameNo++;
        if (frameNo >= animImage->getEndFrame(state)) {
            timer = 0;
            frameNo = 0;
            // fsm = PlayerAttackState();
            // fsm = &level->playerAttackState;
            delete fsm;
            fsm = new PlayerAttackState();
        }
    }
    return;
}
