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
// 
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

