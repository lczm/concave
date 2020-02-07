#pragma once
#include "window.h"
#include "component.h"
#include "constants.h"
#include "image.h"
#include "cellular.h"
#include <vector>
#include <fstream>

using namespace std;
using namespace Component;

class Level : public Window
{
private:
	// Components
	vector<Position> positions;
	vector<Movement> movements;
	vector<Collision> collisions;

	// Tiles
	Texture tileTexture;
	GridMask tileGridMask;
	Image tileImage;

	// Camera
	float camX, camY, camScale;
	int map[mapWidth][mapHeight];
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

	void levelEdit();
	void save();
	void readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level);
	void writeToFile(int map[mapWidth][mapHeight]);
};