#pragma once
#include "constants.h"
#include "tiles.h"

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

//bool checkHLineToVLineISetCollision(LineISet& vLineISet, Line hLine, LineI& vLineI);
//bool checkVLineToHLineISetCollision(LineISet& hLineISet, Line vLine, LineI& hLineI);
//bool checkHLinesToVLineISetCollision(LineISet& vLineISet, Lines& hLines, Line& hLine, LineI& vLineI);
//bool checkVLinesToHLineISetCollision(LineISet& hLineISet, Lines& vLines, Line& vLine, LineI& hLineI);
bool checkLineToLineISetCollision(LineISet& lineISet, Line line, LineI& lineI);
bool checkLinesToLineISetCollision(LineISet& lineISet, Lines& lines, Line& line, LineI& lineI);
bool checkLineISetItersToLineISetCollision(LineISet& lineISet, LineISetIters& lineISetIters, LineI& rLineI, LineI& bLineI);

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos);
float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos);

void updateLinesArray(int size, vector<Lines>& hLinesArray, vector<Lines>& vLinesArray, vector<CoordF> deltaArray);
//void updateAllWallCollision(Tiles& tiles, int size, vector<Lines>& hLinesArray, vector<Lines>& vLinesArray, vector<CoordF>& positionArray);

void getHLineIArrayOfWallCollision(vector<LineI>& hLineIArray, vector<Line>& vLineArray, Tiles& tiles, int size, vector<Lines>& hLinesArray);
void getVLineIArrayOfWallCollision(vector<LineI>& vLineIArray, vector<Line>& hLineArray, Tiles& tiles, int size, vector<Lines>& vLinesArray);
void getHLineIArrayOfWallCollision(vector<LineI>& hLineIArray, vector<Line>& vLineArray, Tiles& tiles, int size, vector<LineISetIters>& hLineISetItersArray);
void getVLineIArrayOfWallCollision(vector<LineI>& vLineIArray, vector<Line>& hLineArray, Tiles& tiles, int size, vector<LineISetIters>& vLineISetItersArray);

void getLineIArrayOfLineISetCollision(vector<LineI>& rLineIArray, vector<LineI>& bLineIArray, LineISet& bLineISet, int size, vector<Lines>& rLinesArray);
void getLineIArrayOfLineISetCollision(vector<LineI>& rLineIArray, vector<LineI>& bLineIArray, LineISet& bLineISet, int size, vector<LineISetIters>& rLineISetItersArray);