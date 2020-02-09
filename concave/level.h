#pragma once
#include "window.h"
#include "component.h"
#include "image.h"
#include <vector>
using namespace std;
using namespace Component;

class Level : public Window
{
private:
	// Components
	vector<Position> positions;
	vector<Movement> movements;
	vector<Collision> collisions;
	HUD* playerHUD;
	// Camera
	float camX, camY, camScale;
public:
	Level();
	~Level();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();

	CoordF gridToScreen(float gx, float gy);
	CoordF screenToGrid(float sx, float sy);
};