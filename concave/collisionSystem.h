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
void updateHLines(LineSet& lineSet, LineSetIters& lineSetIters, CoordF delta);
void updateVLines(LineSet& lineSet, LineSetIters& lineSetIters, CoordF delta);
void updateLines(LineSet& lineSet, LineSetIters& lineSetIters, float deltaA, float deltaB);

bool checkLineToLineCollision(Line hLine, Line vLine);
bool checkHLineToWallCollision(Tiles& tiles, Line& vLine, Line hLine);
bool checkVLineToWallCollision(Tiles& tiles, Line& hLine, Line vLine);
bool checkHLinesToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Lines hLines);
bool checkVLinesToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Lines vLines);
bool checkHLinesToWallCollision(Tiles& tiles, LineI& hLine, Line& vLine, LineSetIters hLines);
bool checkVLinesToWallCollision(Tiles& tiles, LineI& vLine, Line& hLine, LineSetIters vLines);

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);