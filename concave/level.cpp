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
	//initialize the values
	renderLevel.initialize(graphics, input, type);
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			map[x][y] = 0;
		}
	}
	/* No delete this code*/
	Cellular cellgenerate;
	cellgenerate.generateMap(map);
	//readFromFile();

	/* No delete this code*/
	placeRoom();
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{
	if (input->isKeyDown('W')) camY -= 0.1;
	if (input->isKeyDown('S')) camY += 0.1;
	if (input->isKeyDown('A')) camX -= 0.1;
	if (input->isKeyDown('D')) camX += 0.1;
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
		CoordF mouse = { input->getMouseX(), input->getMouseY() };
		CoordF gridPos1 = screenToGrid(mouse.x, mouse.y);
		CoordI gridPos = { gridPos1.x, gridPos1.y };
		++map[gridPos.y][gridPos.x] %= 9;
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
		//mapNo = 29229;
		level.initialize();
	}
}

void Level::renderSprites()
{	
	//Must be a more elegant way to write this
	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			CoordF screenPos = gridToScreen(x, y);
			SpriteData sd;

			//pass to renderLevel class
			renderLevel.getTileImage().getSpriteData(sd, IMAGE_MAP.at(ImageType::churchFloor));
			graphics->drawSprite(
				sd,
				screenPos.x, screenPos.y, camScale);
		}
	}


	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			CoordF screenPos = gridToScreen(x, y);
			SpriteData sd;

			//pass to renderLevel class
			renderLevel.renderMap(map, x, y, sd, type);
			graphics->drawSprite(
				sd,
				screenPos.x, screenPos.y, camScale);
		}
	}
}

void Level::placeRoom()
{
	editComponent->placeRoom(map);
}