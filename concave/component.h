#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

// Lines (Collisions)
struct Line {
	float lower, upper, shift;
	Line() {}
	Line(float lower, float upper, float shift) { Line::lower = lower; Line::upper = upper; Line::shift = shift; }
};
struct LineI : Line {
	int id;
	LineI(Line line, int id) : Line(line) { LineI::id = id; }
	LineI(float lower, float upper, float shift, int id): Line(lower, upper, shift) { LineI::id = id; }
};
typedef vector<Line> Lines;

// Directions
enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };