#include "level.h"

Level::Level()
{
	camX = 0; camY = 0; camScale = 1;
}

Level::~Level()
{
	
}

void Level::initialize()
{	
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 128 / 2, 192 - TILE_HEIGHT - 1);
	tileImage.initialize(&tileTexture, tileGridMask);

	Cellular cellgenerate;
	cellgenerate.generateMap(map);
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{

	if (input->isKeyDown('P')) camScale += 0.01;
	if (input->isKeyDown('O')) camScale -= 0.01;

	if (input->getMouseLButton())
	{
		CoordF mouse = { input->getMouseX(), input->getMouseY()};
		CoordF gridPos1 = screenToGrid(mouse.x, mouse.y);
		CoordI gridPos = { gridPos1.x, gridPos1.y };

		map[gridPos.y][gridPos.x] = true;
	}
}

void Level::render()
{
		for (int x = 0; x < mapWidth; x++) {
			for (int y = 0; y < mapHeight; y++) {
				CoordF screenPos = gridToScreen(x, y);
				SpriteData sd; 

				/*
				switch (y)
				{
					case 0:
						tileImage.getSpriteData(sd, CoordI{9,0});
						graphics->drawSprite(
							sd,
							screenPos.x, screenPos.y, camScale);
				}

				switch (x)
				{
					case 0:
						tileImage.getSpriteData(sd, CoordI{8,0});
						graphics->drawSprite(
							sd,
							screenPos.x, screenPos.y, camScale);
						break;
				}
				*/

				if (map[x][y])
				{
					tileImage.getSpriteData(sd, CoordI{6,0});
				}
				else {
					tileImage.getSpriteData(sd, CoordI{12,1});
				}

				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
			}
		}
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
