#include "level.h"

Level::Level()
{
	camX = 0; camY = 0; camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 128 / 2, 192 - TILE_HEIGHT - 1);
	tileImage.initialize(&tileTexture, tileGridMask);

	unitTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
	unitAttackGridMask.initialize(0, 7, 96, 128, 0, 1, 58, 114);
	unitIdleGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	vector<GridMask> unitGridMasks = { 
		unitAttackGridMask, unitDieGridMask, unitIdleGridMask };
	vector<int> unitEndFrames = { 14, 21, 10, 8 };
	unitImage.initialize(&unitTexture, unitGridMasks, unitEndFrames);
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{
	if (input->isKeyDown('W')) camY -= 0.01;
	if (input->isKeyDown('S')) camY += 0.01;
	if (input->isKeyDown('A')) camX -= 0.01;
	if (input->isKeyDown('D')) camX += 0.01;
	if (input->isKeyDown('P')) camScale += 0.01;
	if (input->isKeyDown('O')) camScale -= 0.01;
}

void Level::render()
{
	SpriteData sdTile;
	sdTile.scale = camScale;
	tileImage.getSpriteData(sdTile, CoordI{ 12, 0 });
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			CoordF screenPos = gridToScreen(x, y);
			sdTile.screenX = screenPos.x;
			sdTile.screenY = screenPos.y;
			graphics->drawSprite(sdTile);
		}
	}
	SpriteData sdUnit;
	sdUnit.scale = camScale;
	CoordF screenPos = gridToScreen(camX, camY);
	sdUnit.screenX = screenPos.x;
	sdUnit.screenY = screenPos.y;
	unitImage.getSpriteData(sdUnit, CoordI{ 0, 0 });
	graphics->drawSprite(sdUnit);
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