#pragma once
#include "window.h"
#include "component.h"
#include "constants.h"
#include "image.h"
#include "cellular.h"
#include "room.h"
#include "EditComponent.h"
#include "renderLevel.h"
#include <vector>
#include <fstream>
#include <string>

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
	int map[mapWidth][mapHeight];

	int mapNo = 29229;

	//shld prob change this to another variable
	int type = 0;
	//prob need to change it to read component
	EditComponent * editComponent;

	RenderLevel renderLevel;
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
	void changeLevel();
	void readFromFile();
	void renderSprites();
	void writeToFile(int map[mapWidth][mapHeight]);
	void placeRoom();
};