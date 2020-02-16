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

bool checkHLineToWallCollision(Tiles& tiles, Line hLine, Line& vLine)
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

bool checkVLineToWallCollision(Tiles& tiles, Line vLine, Line& hLine)
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

bool checkHLinesToWallCollision(Tiles& tiles, Lines& hLines, Line& hLine, Line& vLine)
{
	for (Line _hLine : hLines) {
		if (checkHLineToWallCollision(tiles, _hLine, vLine)) {
			hLine = _hLine;
			return true;
		}
	}
	return false;
}

bool checkVLinesToWallCollision(Tiles& tiles, Lines& vLines, Line& vLine, Line& hLine)
{
	for (Line _vLine : vLines) {
		if (checkVLineToWallCollision(tiles, _vLine, hLine)) {
			vLine = _vLine;
			return true;
		}
	}
	return false;
}

bool checkHLineISetItersToWallCollision(Tiles& tiles, LineISetIters& hLineISetIters, LineI& hLineI, Line& vLine)
{
	for (LineISetIter _hLineISetIter : hLineISetIters) {
		LineI _hLineI = *_hLineISetIter;
		if (checkHLineToWallCollision(tiles, _hLineI, vLine)) {
			hLineI = _hLineI;
			return true;
		}
	}
	return false;
}

bool checkVLineISetItersToWallCollision(Tiles& tiles, LineISetIters& vLineISetIters, LineI& vLineI, Line& hLine)
{
	for (LineISetIter _vLineISetIter : vLineISetIters) {
		LineI _vLineI = *_vLineISetIter;
		if (checkVLineToWallCollision(tiles, _vLineI, hLine)) {
			vLineI = _vLineI;
			return true;
		}
	}
	return false;
}

//bool checkHLineToVLineISetCollision(LineISet& vLineISet, Line hLine, LineI& vLineI)
//{
//	LineISetIter start = vLineISet.lower_bound(LineI{ -1, -1, hLine.lower, -1 });
//	LineISetIter end = vLineISet.upper_bound(LineI{ -1, -1, hLine.upper, -1 });
//	for (; start != end; start++) {
//		LineI _vLineI = *start;
//		if (_vLineI.lower < hLine.shift && hLine.shift < _vLineI.upper) {
//			vLineI = _vLineI;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool checkVLineToHLineISetCollision(LineISet& hLineISet, Line vLine, LineI& hLineI)
//{
//	LineISetIter start = hLineISet.lower_bound(LineI{ -1, -1, vLine.lower, -1 });
//	LineISetIter end = hLineISet.upper_bound(LineI{ -1, -1, vLine.upper, -1 });
//	for (; start != end; start++) {
//		LineI _hLineI = *start;
//		if (_hLineI.lower < vLine.shift && vLine.shift < _hLineI.upper) {
//			hLineI = _hLineI;
//			return true;
//		}
//	}
//	return false;
//}

bool checkLineToLineISetCollision(LineISet& lineISet, Line line, LineI& lineI)
{
	LineISetIter start = lineISet.lower_bound(LineI{ -1, -1, line.lower, -1 });
	LineISetIter end = lineISet.upper_bound(LineI{ -1, -1, line.upper, -1 });
	for (; start != end; start++) {
		LineI _lineI = *start;
		if (_lineI.lower < line.shift && line.shift < _lineI.upper) {
			lineI = _lineI;
			return true;
		}
	}
	return false;
}

//bool checkHLinesToVLineISetCollision(LineISet& vLineISet, Lines& hLines, Line& hLine, LineI& vLineI)
//{
//	for (Line _hLine : hLines) {
//		if (checkHLineToVLineISetCollision(vLineISet, _hLine, vLineI)) {
//			hLine = _hLine;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool checkVLinesToHLineISetCollision(LineISet& hLineISet, Lines& vLines, Line& vLine, LineI& hLineI)
//{
//	for (Line _vLine : vLines) {
//		if (checkVLineToHLineISetCollision(hLineISet, _vLine, hLineI)) {
//			vLine = _vLine;
//			return true;
//		}
//	}
//	return false;
//}

bool checkLinesToLineISetCollision(LineISet& lineISet, Lines& lines, Line& line, LineI& lineI)
{
	for (Line _line : lines) {
		if (checkLineToLineISetCollision(lineISet, _line, lineI)) {
			line = _line;
			return true;
		}
	}
	return false;
}

bool checkLineISetItersToLineISetCollision(LineISetIters& lineISetIters, LineISet& lineISet, LineI& rLineI, LineI& bLineI)
{
	for (LineISetIter lineISetIter : lineISetIters) {
		LineI lineI = *lineISetIter;
		if (checkLineToLineISetCollision(lineISet, lineI, bLineI)) {
			rLineI = lineI;
			return true;
		}
	}
	return false;
}

float getDeltaXResponse(Line rHLine, Line bVLine, CoordF pos)
{
	//assert(bVLine.shift != pos.x);
	if (bVLine.shift < pos.x)
		return bVLine.shift - rHLine.lower;
	else
		return bVLine.shift - rHLine.upper;
}

float getDeltaYResponse(Line rVLine, Line bHLine, CoordF pos)
{
	//assert(bHLine.shift != pos.y);
	if (bHLine.shift < pos.y)
		return bHLine.shift - rVLine.lower;
	else
		return bHLine.shift - rVLine.upper;
}

void updateLinesArray(int size, vector<Lines>& hLinesArray, vector<Lines>& vLinesArray, vector<CoordF> deltaArray)
{
	for (int i = 0; i < size; i++) {
		updateHLines(hLinesArray[i], deltaArray[i]);
		updateVLines(vLinesArray[i], deltaArray[i]);
	}
}

void updateAllWallCollision(Tiles& tiles, int size, vector<Lines>& hLinesArray, vector<Lines>& vLinesArray, vector<CoordF>& positionArray)
{
	for (int i = 0; i < size; i++) {
		CoordF& pos = positionArray[i];
		Lines& hLines = hLinesArray[i];
		Lines& vLines = vLinesArray[i];
		CoordF delta{ 0, 0 };
		Line hLine, vLine;
		if (checkHLinesToWallCollision(tiles, hLines, hLine, vLine))
			delta.x = getDeltaXResponse(hLine, vLine, pos);
		if (checkVLinesToWallCollision(tiles, vLines, vLine, hLine))
			delta.y = getDeltaYResponse(vLine, hLine, pos);
		pos += delta;
		updateHLines(hLines, delta);
		updateVLines(vLines, delta);
	}
}

void getHLineIArrayOfWallCollision(vector<LineI>& hLineIArray, vector<Line>& vLineArray, Tiles& tiles, int size, vector<Lines>& hLinesArray)
{
	for (int i = 0; i < size; i++) {
		Line hLine, vLine;
		if (checkHLinesToWallCollision(tiles, hLinesArray[i], hLine, vLine)) {
			hLineIArray.push_back(LineI{ hLine, i });
			vLineArray.push_back(vLine);
		}
	}
}

void getVLineIArrayOfWallCollision(vector<LineI>& vLineIArray, vector<Line>& hLineArray, Tiles& tiles, int size, vector<Lines>& vLinesArray)
{
	for (int i = 0; i < size; i++) {
		Line vLine, hLine;
		if (checkVLinesToWallCollision(tiles, vLinesArray[i], vLine, hLine)) {
			vLineIArray.push_back(LineI{ vLine, i });
			hLineArray.push_back(hLine);
		}
	}
}

//void getHLineIArrayOfWallCollision(vector<LineI>& hLineIArray, vector<Line>& vLineArray, Tiles& tiles, int size, vector<LineISetIters>& hLineISetItersArray)
//{
//	for (int i = 0; i < size; i++) {
//		LineI hLine; Line vLine;
//		//if (checkHLinesToWallCollision(tiles, ))
//	}
//}
//void getVLineIArrayOfWallCollision(vector<LineI>& vLineIArray, vector<Line>& hLineArray, Tiles& tiles, int size, vector<LineISetIters>& vLineISetItersArray);