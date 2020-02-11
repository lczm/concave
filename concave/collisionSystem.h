#pragma once
#include "constants.h"
#include "component.h"
#include "tiles.h"
#include "players.h"
#include <cassert>

Lines translateHLines(Lines Lines, CoordF delta);
Lines translateVLines(Lines Lines, CoordF delta);
Lines translateHLines(Lines Lines, float x, float y);
Lines translateVLines(Lines Lines, float x, float y);

void updateHLines(Lines& Lines, CoordF delta);
void updateVLines(Lines& Lines, CoordF delta);
void updateLines(Lines& Lines, float deltaA, float deltaB);

bool checkLineToLineCollision(Line hLine, Line vLine);
bool checkHLineToWallCollision(Tiles& tiles, Line& vLine, Line hLine);
bool checkVLineToWallCollision(Tiles& tiles, Line& hLine, Line vLine);
bool checkHLinesToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Lines hLines);
bool checkVLinesToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Lines vLines);

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);