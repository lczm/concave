#pragma once
#include "image.h"
#include <vector>
using namespace std;

class Entity;

namespace Component
{
	struct Position
	{
		CoordF grid;
		CoordF screen;
	};

	struct Collision
	{
		struct Line { float lower, upper, shift; };
		vector<Line> hLines;
		vector<Line> vLines;
	};

	struct Render
	{
		Image* image;
		CoordI coord;
	};

	struct Movement
	{
		float velocity;
		float rotation;
	};

	struct AnimRender
	{
		AnimImage* image;
		int state, direction, frameNo;
	};
}