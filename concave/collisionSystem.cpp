#include "collisionSystem.h"

Collision translateHCollision(Collision collision, CoordF delta)
{
	updateCollision(collision, delta.x, delta.y);
	return collision;
}

Collision translateVCollision(Collision collision, CoordF delta)
{
	updateCollision(collision, delta.y, delta.x);
	return collision;
}

Collision translateHCollision(Collision collision, float x, float y)
{
	updateCollision(collision, x, y);
	return collision;
}

Collision translateVCollision(Collision collision, float x, float y)
{
	updateCollision(collision, y, x);
	return collision;
}

void updateHCollision(Collision& collision, CoordF delta)
{
	updateCollision(collision, delta.x, delta.y);
}

void updateVCollision(Collision& collision, CoordF delta)
{
	updateCollision(collision, delta.y, delta.x);
}

void updateCollision(Collision& collision, float deltaA, float deltaB)
{
	for (Line& line : collision) {
		line.lower += deltaA;
		line.upper += deltaA;
		line.shift += deltaB;
	}
}

bool checkLineToLineCollision(Line hLine, Line vLine)
{
	// Compiler please do your optimisation
	bool xCollide = hLine.lower < vLine.shift && vLine.shift < hLine.upper;
	bool yCollide = vLine.lower < hLine.shift && hLine.shift < vLine.upper;
	return xCollide && yCollide;
}

bool checkHLineToWallCollision(Tiles &tiles, Line& vLine, Line hLine)
{
	for (int start = (int)hLine.lower, end = (int)hLine.upper; start <= end; start++) {
		Collision tVCollision = tiles.getVCollision(hLine.shift, start);
		for (Line tVLine : tVCollision) {
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
		Collision tHCollision = tiles.getHCollision(start, vLine.shift);
		for (Line tHLine : tHCollision) {
			if (checkLineToLineCollision(tHLine, vLine)) {
				hLine = tHLine;
				return true;
			}
		}
	}
	return false;
}

bool checkHCollisionToWallCollision(Tiles& tiles, Line& hLine, Line& vLine, Collision hCollision)
{
	for (Line _hLine : hCollision) {
		if (checkHLineToWallCollision(tiles, vLine, _hLine)) {
			hLine = _hLine;
			return true;
		}
	}
	return false;
}

bool checkVCollisionToWallCollision(Tiles& tiles, Line& vLine, Line& hLine, Collision vCollision)
{
	for (Line _vLine : vCollision) {
		if (checkVLineToWallCollision(tiles, hLine, _vLine)) {
			vLine = _vLine;
			return true;
		}
	}
	return false;
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