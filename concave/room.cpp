#include "room.h"

Room::Room()
{

}
Room::~Room()
{

}

bool Room::intersects(Room room)
{
	return(x1 < room.x2 && x2 >= room.x1 && 
		y1 <= room.y2 && y2 >= room.y1);
}

