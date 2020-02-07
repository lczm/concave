#pragma once
#include "component.h";
#include "constants.h";
#include <string>;
#include <fstream>;
#include <vector>

using namespace std;

class EditComponent
{
private:
	vector<CoordI> ChruchTiles;
	vector<CoordI> caveTiles;

public:
	void readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level);
	void writeToFile(int map[mapWidth][mapHeight]);
};