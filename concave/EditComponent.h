#pragma once
#include "component.h";
#include "constants.h";
#include "room.h"
#include<algorithm> 
#include <string>;
#include <fstream>;
#include <vector>;

using namespace std;

class EditComponent
{
public:
	void placeRoom(int map[mapWidth][mapHeight]);
	void placeItemRoom();
	void horizontalCorridor(int x1, int x2, int y, int map[mapWidth][mapHeight]);
	void verticalCorridor(int y1, int y2, int x, int map[mapWidth][mapHeight]);
	void placeWall(int map[mapWidth][mapHeight], Room newRoom);
	void readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level);
	void writeToFile(int map[mapWidth][mapHeight]);
};