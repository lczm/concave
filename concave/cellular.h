#pragma once
#include "constants.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       
using namespace std;


class Cellular
{
private:
	bool ReturnMap[mapHeight][mapWidth];
	float chanceAlive = 0.4f;
	int deathLimit = 2;
	int birthLimit = 4;
	int numSteps = 8;

	//chance fo the cell to stay alive

public:
	Cellular();
	~Cellular();
	float getAlive() { return chanceAlive; }

	//function to randomly select alive or dead cells
	void initializeMap(bool(&map)[mapWidth][mapHeight]);

	//generates a random float
	float randomFloat(float max);

	//checking the rules of cellular automa
	void doSimulationStep(bool(&map)[mapWidth][mapHeight], bool(&newMap)[mapWidth][mapHeight]); //we do not want to alter the original copy

	int countNeighboursAlive(bool map[mapWidth][mapHeight], int x, int y);

	void generateMap(bool (&generateMap)[mapWidth][mapHeight]);

	void floodFill();

	void placeItem();
};

