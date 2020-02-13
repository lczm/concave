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
bool checkHLineToWallCollision(Tiles& tiles, Line hLine, Line& vLine);
bool checkVLineToWallCollision(Tiles& tiles, Line vLine, Line& hLine);
bool checkHLinesToWallCollision(Tiles& tiles, Lines& hLines, Line& hLine, Line& vLine);
bool checkVLinesToWallCollision(Tiles& tiles, Lines& vLines, Line& vLine, Line& hLine);
bool checkHLineISetItersToWallCollision(Tiles& tiles, LineISetIters& hLineISetIters, LineI& hLineI, Line& vLine);
bool checkVLineISetItersToWallCollision(Tiles& tiles, LineISetIters& vLineISetIters, LineI& vLineI, Line& hLine);

//bool checkHLineToLineISetCollision(LineISet& vLineISet, Line& vLine, Line hLine);
//bool checkHLinesToLineISetCollision(LineISet& vLineISet, Line& hLine, LineI& vLineI, Lines hLines);
//bool checkHLinesToLineISetCollision()

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);