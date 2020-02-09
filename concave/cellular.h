#pragma once
#include "constants.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       
using namespace std;


class cellular
{
private:
	bool ReturnMap[mapHeight][mapWidth];
	float chanceAlive = 0.45f;
	int deathLimit = 3;
	int birthLimit = 4;
	int numSteps = 2;

	//chance fo the cell to stay alive

public:
	cellular();
	~cellular();
	float getAlive() { return chanceAlive; }

	//function to randomly select alive or dead cells
	
	void initializeMap(bool map[mapWidth][mapHeight]);

	//generates a random float
	float randomFloat(float max);

	//checking the rules of cellular automa
	void doSimlulationStep(bool map[mapWidth][mapHeight], bool newMap[mapHeight][mapWidth]); //we do not want to alter the original copy

	int countNeighboursAlive(bool map[mapWidth][mapHeight], int x, int y);

	void generateMap(bool map[mapWidth][mapHeight]);
};
