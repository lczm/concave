#pragma once
#include "constants.h"
#include <math.h>
#include <vector>
using namespace std;

class Room
{	
	//grid coordinates for each corner of the room
	struct RoomDimensions {
			int x1;
			int x2;
			int y1;
			int y2;
	};

	struct RoomItems {
		int left;
		int right;
		int top;
		int bottom;
		CoordI center;
		int flooring;
	};

private:


	//temporary variables 
	int maxRooms= 5;
	int maxRoomSize = 10;
	int minRoomSize = 8;

	//room info
	RoomType room;
	RoomDimensions roomDimensions;
	RoomItems roomItems;

	//width and height of the room
	int roomWidth;
	int roomHeight;

	//center of the room
	CoordI roomCenter;

public:

	Room();
	Room(int x, int y, int width, int height)
	{	
		/*
		x1 = x;
		x2 = x + width;
		y1 = y;
		y2 = y + height;
		*/

		roomDimensions.x1 = x;
		roomDimensions.x2 = x + width;
		roomDimensions.y1 = y;
		roomDimensions.y2 = y + height;


		roomWidth = width;
		roomHeight = height;

		roomCenter = { 
			(int)floor((roomDimensions.x1 + roomDimensions.x2)/2),
			(int)floor((roomDimensions.y1+ roomDimensions.y2)/2)
		};
		
	}
	~Room();

	//check if the room intersects with another room
	bool intersects(Room room);

	//room width and height
	int getRoomWidth(){ return roomWidth;}
	int getRoomHeight(){ return roomHeight;}

	//dimentions of the room
	RoomDimensions getDimensions() {return roomDimensions;}

	//set position of room items in a room
	RoomItems getRoomItems() { return roomItems; }

	//set room items of a room
	void setRoomItems(int left, int right, int top, int bottom, int flooring) 
	{
		roomItems.left = left;
		roomItems.right = right;
		roomItems.top = top;
		roomItems.bottom = bottom;
		roomItems.flooring = flooring;
	}

	void setDimensions(RoomDimensions changedDimensions) { roomDimensions = changedDimensions;}
	//center of room functions
	CoordI getCenterRoom(){ return roomCenter;}
	void setCenter(CoordI center){roomCenter = center;}
};