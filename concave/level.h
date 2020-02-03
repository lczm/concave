#pragma once
#include "window.h"
#include "component.h"
#include <vector>
using namespace std;
using namespace Component;

class Level : public Window
{
private:
	vector<Position> positions;
	vector<Movement> movements;
	vector<Collision> collisions;
public:
	Level();
	~Level();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};