#pragma once
#include "EditComponent.h"

void EditComponent::readFromFile(std::string mapString, int map[mapWidth][mapHeight], int level)
{
	std::ifstream file("text\\" + std::to_string(level) + mapString);
	for (int r = 0; r < mapWidth; r++)
	{
		for (int c = 0; c < mapHeight; c++) {
			file >> map[r][c];
		}
	}
}

void EditComponent::writeToFile(int map[mapWidth][mapHeight])
{
	int random = rand();
	string filepath = "text\\" + to_string(random) + "save.txt";
	ofstream outputfile((filepath));
	for (int r = 0; r < mapWidth; r++)
	{
		for (int c = 0; c < mapHeight; c++) {
			outputfile << map[r][c] << " ";
		}
		outputfile << endl;
	}
	outputfile.close();

}
