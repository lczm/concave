#include "state.h"

Movement State::calculateMovement(float frameTime, CoordF position, CoordF destPosition)
{
     float currentX = position.x;
     float currentY = position.y;
 
     float destX = destPosition.x;
     float destY = destPosition.y;
     float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
     float moveX = float(3.0 * sin(radAngle) * frameTime);
     float moveY = float(3.0 * cos(radAngle) * frameTime);
 
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
