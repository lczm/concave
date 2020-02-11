#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

// Lines (Collisions)
struct Line { float lower, upper, shift; };
struct LineI : Line { int id; };
typedef vector<Line> Lines;

// Directions
enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };