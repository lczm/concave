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
	int maxRooms = 4;
	int maxRoomSize = 10;
	int minRoomSize = 8;

	//for (int i = 0; i < maxRooms; i++)
	//{
	while (rooms.size() < maxRooms)
	{

		int w = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);
		int h = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);

		int x = rand() % (mapWidth - w - 1) + 1;
		int y = rand() % (mapHeight - h - 1) + 1;

		Room newRoom(x, y, w, h);

		bool failed = false;
		for (Room room : rooms)
		{	
			//modify intersects algo design
			if (newRoom.intersects(room))
			{
				failed = true;
				break;
			}
		}

		//add code to run until max rooms added
		if (!failed)
		{
			//createRoom to carve the room
			rooms.emplace_back(newRoom);

			//setting four corners of the room (test)
			placeWall(map, newRoom);

			//building the corridors 
			CoordI newCenter = newRoom.center;
			if (rooms.size() != 1)
			{
				Room prevRoom = rooms[rooms.size() - 2];
				CoordI prevCenter = prevRoom.center;

				int random = rand() % 2;
				if (random == 1)
				{
					horizontalCorridor(prevCenter.x, newCenter.x, prevCenter.y, map);
					verticalCorridor(prevCenter.y, newCenter.y, newCenter.x, map);
				}
				else
				{
					verticalCorridor(prevCenter.y, newCenter.y, newCenter.x, map);
					horizontalCorridor(prevCenter.x, newCenter.x, prevCenter.y, map);
				}
			}

		}

	}

	//}
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

void EditComponent::horizontalCorridor(int x1, int x2, int y, int map[mapWidth][mapHeight])
{
	int minX = fmin(x1, x2);
	int maxX = fmax(x1, x2);

	for (int i = minX; i < maxX + 1; i++)
	{
		map[i][y] = 7;
	}

}

void EditComponent::verticalCorridor(int y1, int y2, int x, int map[mapWidth][mapHeight])
{
	int minY = (y1 < y2) ? y1 : y2;
	int maxY = (y1 > y2) ? y1 : y2;

	for (int i = minY; i < maxY + 1; i++)
	{
		map[x][i] = 7;
	}
}

//add code to place items into rooms
//specify boss/loot rooms maybe NPC rooms
void EditComponent::placeItemRoom()
{

}