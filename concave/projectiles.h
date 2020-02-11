#pragma once
#include "component.h"
#include <set>
using namespace std;

class Projectiles
{
private:
	int capacity, size;
	vector<CoordF> positions;
	set<LineI> hCollisions;
	set<LineI> vCollisions;
public:

};