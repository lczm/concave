#include "cellular.h"


Cellular::Cellular() {};
Cellular::~Cellular() {};

//randomly selecting if cells are dead or alive
void Cellular::initializeMap(bool map[mapWidth][mapHeight])
{
	for (int x = 0; x < mapHeight; x++)
	{
		for (int y = 0; y < mapWidth; y++)
		{	
			float num = randomFloat(1);
			if (num < getAlive())
			{
				map[x][y] = false;
			}
			
		}
	}
}

//max number generated is max
float Cellular::randomFloat(float max)
{
	float generated = ((float) rand() / (float)(RAND_MAX)) * max;
	return generated;
}

void Cellular::doSimulationStep(bool map[mapWidth][mapHeight], bool newMap[mapHeight][mapWidth])
{
	//to not alter the old map
	//loop over rows and cols
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			int cellNb = countNeighboursAlive(map, x, y);

			//if cell has not enough neighbours eliminate it
			if (!map[x][y] == false)
			{
				if (cellNb < deathLimit)
				{
					newMap[x][y] == true;
				}

				else {
					newMap[x][y] == false;
				}
			}
			//if cell is dead and has numberof neighbours to be alive
			else
			{
				if (cellNb > birthLimit)
				{
					newMap[x][y] = false;
				}
				else
				{
					newMap[x][y] = true;
				}
			}
		}
	}
}

int Cellular::countNeighboursAlive(bool map[mapWidth][mapHeight], int x, int y)
{
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int neighbourX = x + i;
			int neighbourY = y + j;

			if (i == 0 && j == 0) {}
			else if (neighbourX < 0 || neighbourY < 0 || neighbourX >= mapWidth || neighbourY >= mapHeight)
			{
				count += 1;
			}
			else if (map[neighbourX][neighbourY])
			{
				count += 1;
			}
		}
	}
	return count;
}

void Cellular::generateMap(bool generateMap[mapWidth][mapHeight])
{
	bool cellMap[mapWidth][mapHeight];
	initializeMap(cellMap);
	for (int i = 0; i < numSteps; i++)
	{
		doSimulationStep(cellMap, generateMap);
	}
}