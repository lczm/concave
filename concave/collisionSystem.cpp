#include "collisionSystem.h"

Lines translateHLines(Lines lines, CoordF delta)
{
	updateLines(lines, delta.x, delta.y);
	return lines;
}

Lines translateVLines(Lines lines, CoordF delta)
{
	updateLines(lines, delta.y, delta.x);
	return lines;
}

Lines translateHLines(Lines lines, float x, float y)
{
	updateLines(lines, x, y);
	return lines;
}

Lines translateVLines(Lines lines, float x, float y)
{
	updateLines(lines, y, x);
	return lines;
}

void updateHLines(Lines& lines, CoordF delta)
{
	updateLines(lines, delta.x, delta.y);
}

void updateVLines(Lines& lines, CoordF delta)
{
	updateLines(lines, delta.y, delta.x);
}

void updateLines(Lines& lines, float deltaA, float deltaB)
{
	for (Line& line : lines) {
		line.lower += deltaA;
		line.upper += deltaA;
		line.shift += deltaB;
	}
}

void updateHLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, CoordF delta)
{
	updateLineISetIters(lineISet, lineISetIters, delta.x, delta.y);
}

void updateVLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, CoordF delta)
{
	updateLineISetIters(lineISet, lineISetIters, delta.y, delta.x);
}

void updateLineISetIters(LineISet& lineISet, LineISetIters& lineISetIters, float deltaA, float deltaB)
{
	for (LineISetIter& lineISetIter : lineISetIters) {
		LineI lineI = *lineISetIter;
		lineI.lower += deltaA;
		lineI.upper += deltaA;
		lineI.shift += deltaB;
		LineISetIter hint = lineISet.erase(lineISetIter);
		lineISetIter = lineISet.insert(hint, lineI);
	}
}

bool checkLineToLineCollision(Line hLine, Line vLine)
{
	// Compiler please do your optimisation
	bool xCollide = hLine.lower < vLine.shift && vLine.shift < hLine.upper;
	bool yCollide = vLine.lower < hLine.shift && hLine.shift < vLine.upper;
	return xCollide && yCollide;
}

bool checkHLineToWallCollision(Tiles& tiles, Line& vLine, Line hLine)
{
	for (int start = (int)hLine.lower, end = (int)hLine.upper; start <= end; start++) {
		Lines tVLines = tiles.getVLines(hLine.shift, start);
		for (Line tVLine : tVLines) {
			if (checkLineToLineCollision(hLine, tVLine)) {
				vLine = tVLine;
				return true;
			}
		}
	}
	return false;
}

bool checkVLineToWallCollision(Tiles& tiles, Line& hLine, Line vLine)
{
	for (int start = (int)vLine.lower, end = (int)vLine.upper; start <= end; start++) {
		Lines tHLines = tiles.getHLines(start, vLine.shift);
		for (Line tHLine : tHLines) {
			if (checkLineToLineCollision(tHLine, vLine)) {
				hLine = tHLine;
				return true;
			}
		}
	}
	return false;
}

bool checkHLinesToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Lines hLines)
{
	for (Line _hLine : hLines) {
		if (checkHLineToWallCollision(tiles, vLine, _hLine)) {
			hLine = _hLine;
			return true;
		}
	}
	return false;
}

bool checkVLinesToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Lines vLines)
{
	for (Line _vLine : vLines) {
		if (checkVLineToWallCollision(tiles, hLine, _vLine)) {
			vLine = _vLine;
			return true;
		}
	}
	return false;
}

bool checkHLineISetItersToWallCollision(Tiles& tiles, LineI& hLineI, Line& vLine, LineISetIters hLineISetIters)
{
	for (LineISetIter _hLineISetIter : hLineISetIters) {
		LineI _hLineI = *_hLineISetIter;
		if (checkHLineToWallCollision(tiles, vLine, _hLineI)) {
			hLineI = _hLineI;
			return true;
		}
	}
}

bool checkVLineISetItersToWallCollision(Tiles& tiles, LineI& vLineI, Line& hLine, LineISetIters vLineISetIters)
{
	for (LineISetIter _vLineISetIter : vLineISetIters) {
		LineI _vLineI = *_vLineISetIter;
		if (checkVLineToWallCollision(tiles, hLine, _vLineI)) {
			vLineI = _vLineI;
			return true;
		}
	}
}

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos)
{
	assert(bVLine.shift != pos.x);
	if (bVLine.shift < pos.x)
		return bVLine.shift - rHLine.lower;
	else
		return bVLine.shift - rHLine.upper;
}

float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos)
{
	assert(bHLine.shift != pos.y);
	if (bHLine.shift < pos.y)
		return bHLine.shift - rVLine.lower;
	else
		return bHLine.shift - rVLine.upper;
}