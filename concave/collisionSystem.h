#pragma once
#include "constants.h"
#include "component.h"
#include "tiles.h"
#include "players.h"
#include <cassert>

Collision translateHCollision(Collision collision, CoordF delta);
Collision translateVCollision(Collision collision, CoordF delta);
Collision translateHCollision(Collision collision, float x, float y);
Collision translateVCollision(Collision collision, float x, float y);

void updateHCollision(Collision& collision, CoordF delta);
void updateVCollision(Collision& collision, CoordF delta);
void updateCollision(Collision& collision, float deltaA, float deltaB);

bool checkLineToLineCollision(Line hLine, Line vLine);
bool checkHLineToWallCollision(Tiles& tiles, Line& vLine, Line hLine);
bool checkVLineToWallCollision(Tiles& tiles, Line& hLine, Line vLine);
bool checkHCollisionToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Collision hCollision);
bool checkVCollisionToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Collision vCollision);

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);