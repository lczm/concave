#include "state.h"

Movement State::calculateMovement(float frameTime, CoordF position, CoordF destPosition)
{
     float currentX = position.x;
     float currentY = position.y;
 
     float destX = destPosition.x;
     float destY = destPosition.y;

     float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
     float degAngle = radAngle * (180 / PI);
     float moveX = float(3.0 * sin(radAngle) * frameTime);
     float moveY = float(3.0 * cos(radAngle) * frameTime);

     if (destX > currentX && destY < currentY) {
         moveX = moveX;
         moveY = -moveY;
     }
     else if (destX > currentX && destY > currentY) {
         degAngle = 180 - degAngle;
         moveX = moveX;
         moveY = moveY;
     }
     else if (destX < currentX && destY > currentY) {
         degAngle = 180 + degAngle;
         moveX = -moveX;
         moveY = moveY;
     }
     else if (destX < currentX && destY < currentY) {
         degAngle = 360 - degAngle;
         moveX = -moveX;
         moveY = -moveY;
     }

     // Dimetric angle offset
     degAngle += 25.565;
     // cout << degAngle << endl;
 
     return Movement{ moveX, moveY, degAngle };
}

void State::updateFrameNo(float frameTime, int index, Players* players, RenderInfo* renderInfo)
{
    renderInfo->timer += frameTime;
    if (renderInfo->timer >= renderInfo->delay) {
        renderInfo->timer -= renderInfo->delay;
        renderInfo->frameNo++;
        if (renderInfo->frameNo == players->getRender(index)->getEndFrame(renderInfo->state)) {
            renderInfo->frameNo = 0;
        }
    }
}
