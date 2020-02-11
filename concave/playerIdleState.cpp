#include "playerIdleState.h"

PlayerIdleState::PlayerIdleState(Level* level)
{
    state = PLAYER_STATE::IDLE;
    PlayerIdleState::level = level;
}

PlayerIdleState::~PlayerIdleState()
{
}

PLAYER_STATE PlayerIdleState::update(float frameTime, int index, Players* players)
{
    if (level->input->getMouseLButton()) {
        players->setDestPosition(index, level->screenToGrid(CoordF{float(level->input->getMouseX()), float(level->input->getMouseY())}));
        players->setMovement(index, calculateMovement(frameTime, players->getPosition(index), players->getDestPositions(index)));
        return PLAYER_STATE::WALK;
    }
    return PLAYER_STATE::IDLE;
}

 Movement PlayerIdleState::calculateMovement(float frameTime, CoordF position, CoordF destPosition)
 {
     float currentX = position.x;
     float currentY = position.y;
 
     float destX = destPosition.x;
     float destY = destPosition.y;
     float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
     float moveX = 3.0 * sin(radAngle) * frameTime;
     float moveY = 3.0 * cos(radAngle) * frameTime;
 
     if (destX > currentX && destY < currentY) {
         moveX = moveX;
         moveY = -moveY;
     }
     else if (destX > currentX && destY > currentY) {
         moveX = moveX;
         moveY = moveY;
     }
     else if (destX < currentX && destY > currentY) {
         moveX = -moveX;
         moveY = moveY;
     }
     else if (destX < currentX && destY < currentY) {
         moveX = -moveX;
         moveY = -moveY;
     }
 
     return Movement{ moveX, moveY };
 }
