#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
#include <set>
using namespace std;

// typedef vector<Line> Collision;
// typedef Sprite* Render;
// typedef AnimImage* RenderAnim;

// Lines (Collisions)
struct Line {
	float lower, upper, shift;
	Line() {}
	Line(float lower, float upper, float shift) { Line::lower = lower; Line::upper = upper; Line::shift = shift; }
	bool operator<(const Line& other) const { return shift < other.shift; }
};
struct LineI : Line {
	int id;
	LineI() {}
	LineI(Line line, int id) : Line(line) { LineI::id = id; }
	LineI(float lower, float upper, float shift, int id): Line(lower, upper, shift) { LineI::id = id; }
};
typedef vector<Line> Lines;
//typedef vector<LineI> LinesI;
typedef set<LineI> LineISet;
typedef LineISet::iterator LineISetIter;
typedef vector<LineISetIter> LineISetIters;

// Directions
enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
// enum DIRECTION16 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
