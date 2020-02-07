#include "cellular.h"


Cellular::Cellular() {};
Cellular::~Cellular() {};

//randomly selecting if cells are dead or alive
void Cellular::initializeMap(int(&map)[mapWidth][mapHeight])
{
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{	
			float num = randomFloat(1);
			if (num < getAlive())
			{
				map[x][y] = 1;
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

void Cellular::doSimulationStep(int(&map)[mapWidth][mapHeight], int(&newMap)[mapWidth][mapHeight])
{
	//to not alter the old map
	//loop over rows and cols
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			int cellNb = countNeighboursAlive(map, x, y);

			//if cell has not enough neighbours eliminate it
			if (map[x][y] == 1)
			{
				if (cellNb < deathLimit)
				{
					newMap[x][y] = 0;
				}

				else {
					newMap[x][y] = 1;
				}
			}
			//if cell is dead and has numberof neighbours to be alive
			else
			{
				if (cellNb > birthLimit)
				{
					newMap[x][y] = 1;
				}
				else
				{
					newMap[x][y] = 0;
				}
			}
		}
	}
}

int Cellular::countNeighboursAlive(int map[mapWidth][mapHeight], int x, int y)
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
				count = count + 1;
			}
			else if (map[neighbourX][neighbourY])
			{
				count = count + 1;
			}
		}
	}

	return count;
}

void Cellular::generateMap(int(&generateMap)[mapWidth][mapHeight])
{
	initializeMap(generateMap);
	for (int i = 0; i < numSteps; i++)
	{	
		//set this to all 0, we do not want the previous iteration to corrupt the new iteration
		int newArray[mapWidth][mapHeight];

		//set new array values to 0
		for (int x = 0; x < mapWidth; x++)
		{
			for (int y = 0; y < mapHeight; y++)
			{
				newArray[x][y] = 0;
			}
		}

		//process
		doSimulationStep(generateMap, newArray);

		//Copy newArray to generateMap
		for (int x = 0; x < mapWidth; x++)
		{
			for (int y = 0; y < mapHeight; y++)
			{
				generateMap[x][y] = newArray[x][y];
			}
		}
	}
		
}
