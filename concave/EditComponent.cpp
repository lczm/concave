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

void EditComponent::writeToFile(int map[mapWidth][mapHeight], int i)
{
	int random = rand();
	//string filepath = "text\\" + to_string(random) + "save.txt";
	string filepath = "text\\" + to_string(i) + "save.txt";

	std::vector<std::string> record;

	record.push_back(to_string(i) + "save.txt");
	record.push_back("0");
	record.push_back("No");

	gm.writeRecord("text\\gameInfo.csv", record);
	
	//gm.writeRecord("text\\gameInfo.csv",to_string(i) + "save.txt", "0", "No");

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
	int maxRooms = 9;
	int maxRoomSize = 12;
	int minRoomSize = 9;

	for (int i = 0; i < maxRooms; i++)
	//{
	//while (rooms.size() < maxRooms)
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
			CoordI newCenter = newRoom.getCenterRoom();
			if (rooms.size() != 1)
			{
				Room prevRoom = rooms[rooms.size() - 2];
				CoordI prevCenter = prevRoom.getCenterRoom();

				/*
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
				*/
			}

			//place items into the room
			placeItemRoom(newRoom, map);
		}
	}
}

void EditComponent::placeWall(int map[mapWidth][mapHeight], Room newRoom)
{
	//setting the four corners
	map[newRoom.getDimensions().x1][newRoom.getDimensions().y1] = ImageType::churchWallConnect;
	map[newRoom.getDimensions().x2][newRoom.getDimensions().y1] = ImageType::churchWallWest;

	map[newRoom.getDimensions().x1][newRoom.getDimensions().y2] = ImageType::churchWallEast;
	map[newRoom.getDimensions().x2][newRoom.getDimensions().y2] = ImageType::churchFloor;


	for (int i = 1; i < (newRoom.getRoomWidth()); i++)
	{
		map[newRoom.getDimensions().x1 + i][newRoom.getDimensions().y1] = ImageType::churchWallEast;
		map[newRoom.getDimensions().x1 + i][newRoom.getDimensions().y2] = ImageType::churchWallEast;
	}

	for (int j = 1; j < (newRoom.getRoomHeight()); j++)
	{
		//to be explained
		map[newRoom.getDimensions().x1][newRoom.getDimensions().y2 - j] = ImageType::churchWallWest;
		map[newRoom.getDimensions().x2][newRoom.getDimensions().y1 + j] = ImageType::churchWallWest;
	}

}
//switch names 
void EditComponent::horizontalCorridor(int x1, int x2, int y, int map[mapWidth][mapHeight])
{
	int minX = fmin(x1, x2);
	int maxX = fmax(x1, x2);

	for (int i = minX; i < maxX + 1; i++)
	{
		map[i][y] = ImageType::churchWallPath;
	}
}

void EditComponent::verticalCorridor(int y1, int y2, int x, int map[mapWidth][mapHeight])
{
	int minY = (y1 < y2) ? y1 : y2;
	int maxY = (y1 > y2) ? y1 : y2;

	for (int i = minY; i < maxY + 1; i++)
	{
		map[x][i] = ImageType::churchWallPath;
	}
}


/* First iteration: place some random chest */
/* second iteration specitfy rooms to place specific items */
/* 3rd iteration specify what type of objects can spawn where */

// boundary within the room
	/* --------------------------> (X)
	|
	|	(X1, Y1)			(X2, Y1)
	|		-------------------
	|		- ############### -
	|		- ############### -
	|		- ############### -
	|		-------------------
	|	(X1, Y2)			(X2, Y2)
	|
	(Y)

*/
void EditComponent::placeItemRoom(Room room, int map[mapWidth][mapHeight])
{
	//walls occupy the first and last X values
	int x1 = room.getDimensions().x1 + 1;
	int x2 = room.getDimensions().x2 - 1;

	//walls occupy the first and last Y positions 
	int y1 = room.getDimensions().y1 + 1;
	int y2 = room.getDimensions().y2 - 1;

	int areaToPlace = ((room.getRoomWidth() - 2) * (room.getRoomHeight() - 2)) * 0.2;

	//percentage of chests 
	int noChests = areaToPlace * 0.2;

	for (int i = 0; i < noChests; i++)
	{
		//Testing code
		int randX = random(x1, x2);
		int randY = random(y1, y2);

		//chests
		map[x1][randY] = 3;
	}
}

//Random number
int EditComponent::random(int min, int max) {
	int random = rand() % (max + 1 - min) + min;
	return random;
}

//changes object look
void EditComponent::changeObjects(int initial, int changeTo, int map[mapWidth][mapHeight], int PosX, int PosY)
{
	int mapPos = map[PosX][PosY];
	//door code
	if (mapPos == initial) { mapPos = changeTo; }
	else if (mapPos == changeTo) { mapPos = initial; }

	//set to intended
	map[PosX][PosY] = mapPos;
}

//changes object look
void EditComponent::animateObjects()
{
	gm.editRecord("text\\gameInfo.csv",0,2,3, "0save.txt", "blah");
	gm.editRecord("text\\gameInfo.csv", 0, 2, 3, "1save.txt", "blah");
	gm.editRecord("text\\gameInfo.csv", 1, 1, 3, "0", "1");
	gm.editRecord("text\\gameInfo.csv", 2, 2, 3, "No", "1");
	gm.editRecord("text\\gameInfo.csv", 0, 1, 3, "", "test");
	gm.editRecord("text\\gameInfo.csv", 0, 2, 3, "", "wo");

}