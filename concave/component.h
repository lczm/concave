#pragma once
#include "image.h"
#include <vector>
using namespace std;

class Entity;

namespace Component
{
	struct Base
	{
		Entity* entity;
	};

	struct Position: Base
	{
		float gx, gy;
		float sx, sy;
	};

	struct Collision: Base
	{
		struct Line { float lower, upper, shift; Collision* cmpt; };
		vector<Line> hLines;
		vector<Line> vLines;
	};

	struct Render : Base
	{
		Image* image;
		CoordI coord;
	};

	//struct Movement
	//{
	//	float velocity;
	//	float rotation;
	//};

	//struct AnimRender
	//{
	//	AnimImage* image;
	//	int state, direction, frameNo;
	//};
}

struct Entity
{
	Component::Position* position;
	Component::Collision* collision;
	Component::Render* render;
};