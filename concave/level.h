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
	vector<Collision> collisions;
	vector<Render> renders;
	// Camera
	CoordF camCoord;
	float camScale;
	// Tiles
	Texture tileTexture; GridMask tileGridMask; Image tileImage;
	// Player
	Texture unitTexture; GridMask unitGridMask; Image unitImage;
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
	CoordF gridToScreen(CoordF gridCoord);
	CoordF screenToGrid(CoordF screenCoord);
};