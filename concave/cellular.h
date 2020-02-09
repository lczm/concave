#pragma once
#include "constants.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       
using namespace std;


class Cellular
{
private:
	int ReturnMap[mapHeight][mapWidth];
	float chanceAlive = 0.4f;
	int deathLimit = 2;
	int birthLimit = 4;
	int numSteps = 20;

	//chance fo the cell to stay alive

public:
	Cellular();
	~Cellular();
	float getAlive() { return chanceAlive; }

	//function to randomly select alive or dead cells
	void initializeMap(int(&map)[mapWidth][mapHeight]);

	//generates a random float
	float randomFloat(float max);

	//checking the rules of cellular automa
	void doSimulationStep(int(&map)[mapWidth][mapHeight], int(&newMap)[mapWidth][mapHeight]); //we do not want to alter the original copy

	int countNeighboursAlive(int map[mapWidth][mapHeight], int x, int y);

	void generateMap(int (&generateMap)[mapWidth][mapHeight]);

	void floodFill();

	void placeItem();
};

