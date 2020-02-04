#pragma once
#include "texture.h"
#include <vector>
using namespace std;

class AnimImage
{
private:
	Texture texture;
	vector<CoordI> origins;
	int gapWidth, gapHeight;
};