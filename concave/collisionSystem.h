#pragma once
#include "constants.h"
#include "component.h"
#include "tiles.h"
#include "players.h"
#include <set>
#include <cassert>
using namespace std;

Lines translateHLines(Lines lines, CoordF delta);
Lines translateVLines(Lines lines, CoordF delta);
Lines translateHLines(Lines lines, float x, float y);
Lines translateVLines(Lines lines, float x, float y);

void updateHLines(Lines& lines, CoordF delta);
void updateVLines(Lines& lines, CoordF delta);
void updateLines(Lines& lines, float deltaA, float deltaB);
void updateHLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, CoordF delta);
void updateVLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, CoordF delta);
void updateLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, float deltaA, float deltaB);

bool checkLineToLineCollision(Line hLine, Line vLine);
bool checkHLineToWallCollision(Tiles& tiles, Line& vLine, Line hLine);
bool checkVLineToWallCollision(Tiles& tiles, Line& hLine, Line vLine);
bool checkHLinesToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Lines hLines);
bool checkVLinesToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Lines vLines);
bool checkHLineISetItersToWallCollision(Tiles& tiles, LineI& hLineI, Line& vLine, LineISetIters hLineISetIters);
bool checkVLineISetItersToWallCollision(Tiles& tiles, LineI& vLineI, Line& hLine, LineISetIters vLineISetIters);

//bool checkHLinesToLineSetCollision()
//bool checkHLinesToLineSetCollision()

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);