#pragma once
#include <vector>
using namespace std;

namespace Component
{
	struct Position
	{
		float gx, gy;
		float sx, sy;
	};

	struct Movement
	{
		float velocity;
		float rotation;
	};

	struct Collision
	{
		struct Line { float lower, upper, shift; };
		vector<Line> hLines;
		vector<Line> vLines;
	};
}