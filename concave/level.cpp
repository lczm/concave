#include "level.h"

Level::Level()
{
	camX = 0; camY = 0; camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{
	Position warriorPositionComponent;
	positions.push_back(warriorPositionComponent);
	warrior.initialize(graphics, input, &warriorPositionComponent);
}

void Level::releaseAll()
{
	warrior.onLostDevice();
}

void Level::resetAll()
{
	warrior.onLostDevice();
}

void Level::update()
{
	warrior.update(frameTime);
}

void Level::render()
{
	// CoordF screenPos = gridToScreen(camX, camY);
	// warrior.render(screenPos, camScale);

	SpriteData sd = warrior.getSpriteData();
	// CoordF warriorCoords = warrior.getGridCoords();
	// CoordF screenPos = gridToScreen(warriorCoords.x, warriorCoords.y);

	float screenX = positions.back().sx;
	float screenY = positions.back().sy;

	cout << screenX << " : " << screenY << endl;

	// Draw sprites
	graphics->drawSprite(sd, screenX, screenY, camScale);
}

CoordF Level::gridToScreen(float gx, float gy)
{
	float rx = gx - camX;
	float ry = gy - camY;
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
	float gx = rx + camX;
	float gy = ry + camY;
	return CoordF{ gx, gy };
}