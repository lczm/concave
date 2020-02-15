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
enum DIRECTION16 { 
	PROJ_SOUTH,
	PROJ_SOUTH_SOUTH_WEST,
	PROJ_SOUTH_WEST,
	PROJ_WEST_SOUTH_WEST,
	PROJ_WEST,
	PROJ_WEST_NORTH_WEST,
	PROJ_NORTH_WEST,
	PROJ_NORTH_NORTH_WEST,
	PROJ_NORTH,
	PROJ_NORTH_NORTH_EAST,
	PROJ_NORTH_EAST,
	PROJ_EAST_NORTH_EAST,
	PROJ_EAST,
	PROJ_EASE_SOUTH_EAST,
	PROJ_SOUTH_EAST,
	PROJ_SOUTH_SOUTH_EAST
};

struct Movement
{
	float moveX;
	float moveY;
	float rotation;
};

