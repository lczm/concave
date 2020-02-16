#pragma once
#include "constants.h"
#include "gameInfoComponent.h"
#include "room.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class EditComponent
{

private:
	GameInfoComponent gm;

public:
	//room code
	void placeRoom(int map[mapWidth][mapHeight]);
	void placeItemRoom(Room room, int map[mapWidth][mapHeight]);
	void determineRoomTypes(Room &room);
	void placeWall(int map[mapWidth][mapHeight], Room newRoom);
	void placeBossRoom(int map[mapWidth][mapHeight]);

	//random funcs
	void changeObjects(int intial, int changeTo, int map[mapWidth][mapHeight], int PosX, int PosY);
	void animateObjects();
	int  random(int min, int max);

	//corridor functions
	void horizontalCorridor(int x1, int x2, int y, int map[mapWidth][mapHeight]);
	void verticalCorridor(int y1, int y2, int x, int map[mapWidth][mapHeight]);

	//file functions
	void readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level);
	void readFromFile2(std::string mapString, int map[roomTemplateWidth][roomTemplateHeight], int level);
	void writeToFile(int map[mapWidth][mapHeight], int i);
};