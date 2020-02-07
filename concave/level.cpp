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

	//Cellular cellgenerate;
	//cellgenerate.generateMap(map);
	readFromFile();
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{

	if (input->isKeyDown('P')) camScale += 0.01;
	if (input->isKeyDown('O')) camScale -= 0.01;


	levelEdit();
	changeLevel();
	
}

void Level::render()
{	
	//will be moved to another file I hope
	renderSprites();
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


void Level::levelEdit()
{	
	if (input->getMouseLButton() && input->isKeyDown(0x51))
	{	
		input->setMouseLButton(false);
		CoordF mouse = { input->getMouseX(), input->getMouseY()};
		CoordF gridPos1 = screenToGrid(mouse.x, mouse.y);
		CoordI gridPos = { gridPos1.x, gridPos1.y };
		++map[gridPos.y][gridPos.x] %= 6;
		input->clearCharIn();
	}

	if (input->wasKeyPressed(0x52))
	{
		writeToFile(map);
	}

}

void Level::readFromFile()
{
	editComponent->readFromFile("save.txt", map, mapNo);
}

void Level::writeToFile(int map[mapWidth][mapHeight])
{	
	editComponent->writeToFile(map);
}

void Level::changeLevel()
{
	if (input->wasKeyPressed(0x45))
	{
		//woahh
		mapNo = 15776;
		level.initialize();
	}
}

void Level::renderSprites()
{
	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			CoordF screenPos = gridToScreen(x, y);
			SpriteData sd;

			switch (x)
			{
			case 0:
				tileImage.getSpriteData(sd, CoordI{ 5, 0 });
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			}
			switch (y)
			{
			case 0:
				tileImage.getSpriteData(sd, CoordI{ 6, 0 });
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			}

			switch (map[x][y])
			{
			case 0:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchBlood));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			case 1:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchFloor));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			case 2:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchDoor));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			case 3:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchChest));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			case 4:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::chruchWallEast));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			case 5:
				tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::chruchWallWest));
				graphics->drawSprite(
					sd,
					screenPos.x, screenPos.y, camScale);
				break;
			}
		}
	}
}