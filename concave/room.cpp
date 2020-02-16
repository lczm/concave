#include "room.h"

Room::Room()
{

}
Room::~Room()
{

}

bool Room::intersects(Room room)
{
	return(
			roomDimensions.x1 < room.getDimensions().x2 &&
			roomDimensions.x2 >= room.getDimensions().x1 &&
			roomDimensions.y1 <= room.getDimensions().y2 && 
			roomDimensions.y2 >= room.getDimensions().y1
		);
}

