#include "level.h"

Level::Level()
{
	camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{
	// Image / Sprite
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 64, 127);
	tileImage.initialize(&tileTexture, tileGridMask);
	floorSprite.initialize(&tileImage, CoordI{ 12, 0 });
	wallSprite.initialize(&tileImage, CoordI{ 6, 0 });
	unitTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
	unitGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	unitImage.initialize(&unitTexture, unitGridMask);
	unitSprite.initialize(&unitImage, CoordI{ 0, 0 });
	// Tiles
	tiles.initialize(10, 10);
	for (int y = 0; y < tiles.getRows(); y++)
		for (int x = 0; x < tiles.getCols(); x++)
			tiles.set(y, x, Collision{ { 0, 1, 0 } }, Collision{}, &wallSprite);
	for (int y = 1; y < tiles.getRows() - 1; y++)
		for (int x = 1; x < tiles.getCols() - 1; x++)
			tiles.set(y, x, Collision{}, Collision{}, &floorSprite);
	// Player
	players.initialize(1);
	players.push(
		CoordF{ 5, 5 }, 
		Collision{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } },
		Collision{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } },
		&unitSprite);
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{
	// Move Player
	CoordF coord = players.getPosition(0);
	if (input->isKeyDown('W')) coord.y -= 0.01;
	if (input->isKeyDown('S')) coord.y += 0.01;
	if (input->isKeyDown('A')) coord.x -= 0.01;
	if (input->isKeyDown('D')) coord.x += 0.01;
	players.setPosition(0, coord);
	// Collision
	/*for (int i = 0; i < players.getSize(); i++) {
		CoordF pPosition = players.getPosition(i);
		Collision pCollision = players.getCollision(i);
		for (Collision::Line line : pCollision.hLines) {
			Collision tCollision = tiles.getCollision(pPosition.y + line.shift, pPosition.x);
		}
	}*/

	// Move Camera
	camCoord = players.getPosition(0);
	if (input->isKeyDown('O')) camScale *= 1 - 0.01;
	if (input->isKeyDown('P')) camScale *= 1 + 0.01;
}

void Level::render()
{
	for (int y = 0; y < tiles.getRows(); y++)
		for (int x = 0; x < tiles.getCols(); x++)
			graphics->drawSprite(
				tiles.getRender(y, x)->getSpriteData(),
				gridToScreen(x, y), camScale);
	graphics->drawSprite(
		players.getRender(0)->getSpriteData(),
		gridToScreen(players.getPosition(0)), camScale);
}

CoordF Level::gridToScreen(float gx, float gy)
{
	float rx = gx - camCoord.x;
	float ry = gy - camCoord.y;
	float vx = TILE_WIDTH / 2 * (rx - ry);
	float vy = TILE_HEIGHT / 2 * (rx + ry);
	float sx = vx * camScale + GAME_WIDTH / 2;
	float sy = vy * camScale + GAME_HEIGHT / 2;
	return CoordF{ sx, sy };
}

CoordF Level::screenToGrid(float sx, float sy)
{
	float vx = (sx - GAME_WIDTH / 2) / camScale;
	float vy = (sy - GAME_HEIGHT / 2) / camScale;
	float vx2 = vx / (TILE_WIDTH / 2);
	float vy2 = vy / (TILE_HEIGHT / 2);
	float rx = (vy2 - vx2) / 2;
	float ry = (vy2 + vx2) / 2;
	float gx = rx + camCoord.x;
	float gy = ry + camCoord.y;
	return CoordF{ gx, gy };
}

CoordF Level::gridToScreen(CoordF gridCoord)
{
	return gridToScreen(gridCoord.x, gridCoord.y);
}

CoordF Level::screenToGrid(CoordF screenCoord)
{
	return screenToGrid(screenCoord.x, screenCoord.y);	
}