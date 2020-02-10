#pragma once
#include "constants.h"
#include <math.h>
#include <vector>
using namespace std;

class Room
{	
private:
	//grid coordinates for each corner of the room

	//width and height of the room

	//center

	//temporary variables 
	int maxRooms= 5;
	int maxRoomSize = 10;
	int minRoomSize = 8;


public:
	int roomWidth;
	int roomHeight;
	CoordI center;
	int x1;
	int x2;
	int y1;
	int y2;

	Room();
	Room(int x, int y, int width, int height)
	{
		x1 = x;
		x2 = x + width;
		y1 = y;
		y2 = y + height;

		roomWidth = width;
		roomHeight = height;

		center = { 
			(int)floor((x1+x2)/2),
			(int)floor((y1+y2)/2)
		};
		
	}
	~Room();

	//check if the room intersects with another room
	bool intersects(Room room);
};