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
	// Camera
	float camX, camY, camScale;
	// Tiles
	Texture tileTexture;
	GridMask tileGridMask;
	Image tileImage;
	Sprite tileSprite;
	// Unit
	Texture unitTexture;
	GridMask unitAttackGridMask;
	GridMask unitDieGridMask;
	GridMask unitIdleGridMask;
	GridMask unitWalkGridMask;
	vector<GridMask> unitGridMasks;
	vector<int> unitEndFrames;
	AnimImage unitImage;
	AnimSprite unitSprite;
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