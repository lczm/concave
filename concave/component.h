#pragma once
#include "image.h"
#include <vector>
using namespace std;

namespace Component
{
	struct Collision
	{
		struct Line { float lower, upper, shift; };
		vector<Line> hLines;
		vector<Line> vLines;
	};

	struct Render
	{
		Sprite* sprite;
	};
}