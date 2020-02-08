#pragma once
#include "component.h";
#include "constants.h";
#include "room.h"
#include <string>;
#include <fstream>;
#include <vector>;

using namespace std;

class EditComponent
{
public:
	void placeRoom(int map[mapWidth][mapHeight]);
	void readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level);
	void writeToFile(int map[mapWidth][mapHeight]);
};