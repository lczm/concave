#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

struct LineI : Line { int id; };

typedef vector<Line> Collision;
typedef Sprite* Render;