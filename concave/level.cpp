#include "level.h"

Level::Level()
{}

Level::~Level()
{}

void Level::initialize()
{	
	//tileImage.initialize(graphics,TILE_IMAGE, 160, 80);
}

void Level::releaseAll()
{
	//tileImage.onLostDevice();
}

void Level::resetAll()
{
	//tileImage.onResetDevice();
}

void Level::update()
{}

void Level::render()
{
	/*
	for (int y = 0; y < worldSize.y; y++)
	{
		for (int x = 0; x < worldSize.x; x++)
		{
			VECTOR2 world = ToScreen(x, y);
			tileImage.setX(world.x);
			tileImage.setY(world.y);
			tileImage.draw();
		}
	}
	*/

}

/*
VECTOR2 Level::ToScreen(int x, int y)
{
	VECTOR2 screenCoords;
	screenCoords.x = (origin.x * tileSize.x) + (x - y) * (tileSize.x / 2);
	screenCoords.y = (origin.y * tileSize.y) + (x + y) * (tileSize.y / 2);

	return screenCoords;
}
*/