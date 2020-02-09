#pragma once
#include "window.h"
#include "image.h"
#include "component.h"
#include "players.h"
#include "tiles.h"
#include <vector>
#include <cassert>
using namespace std;

class Level : public Window
{
private:
	// Camera
	CoordF camCoord; float camScale;
	// Tiles
	Texture tileTexture; GridMask tileGridMask; Image tileImage;
	Sprite floorSprite, wallSprite;
	// Player
	Texture unitTexture; GridMask unitGridMask; Image unitImage;
	Sprite unitSprite;
	// Components
	Tiles tiles;
	Players players;
	// Systems

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