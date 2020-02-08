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

void EditComponent::placeRoom(int map[mapWidth][mapHeight])
{	
	vector<Room> rooms;

	//temp placement
	int maxRooms = 5;
	int maxRoomSize = 4;
	int minRoomSize = 3;

	for (int i = 0; i < maxRooms; i++)
	{
		int w = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);
		int h = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);
		int x = rand() % (mapWidth - w - 1) + 1;
		int y = rand() % (mapWidth - h - 1) + 1;

		Room newRoom(x, y, w, h);

		bool failed = false;
		for (Room room : rooms)
		{
			if (newRoom.intersects(room))
			{
				failed = true;
				break;
			}
		}

		if (!failed)
		{
			//createRoom to carve the room
			rooms.emplace_back(newRoom);

			//setting four corners of the room (test)
			placeWall(map, newRoom);
		}

	}
}

void EditComponent::placeWall(int map[mapWidth][mapHeight], Room newRoom)
{	
	//setting the four corners
	map[newRoom.x1][newRoom.y1] = 6;
	map[newRoom.x2][newRoom.y1] = 5;

	map[newRoom.x1][newRoom.y2] = 4;
	map[newRoom.x2][newRoom.y2] = 0;


	for (int i = 1; i < (newRoom.roomWidth); i++)
	{
		map[newRoom.x1 + i][newRoom.y1] = 4;
		map[newRoom.x1 + i][newRoom.y2] = 4;
	}

	for (int j = 1; j < (newRoom.roomHeight); j++)
	{	
		//to be explained
		map[newRoom.x1][newRoom.y2 - j] = 5;
		map[newRoom.x2][newRoom.y1 + j] = 5;
	}
}