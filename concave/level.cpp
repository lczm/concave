#include "level.h"

Level::Level()
{
	camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{	
	for (int i = 0; i < 5; i++)
	{
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
		editComponent->writeToFile(map, i);
	}
	editComponent->readFromFile("save.txt", map, 0);

	////  Sprite Initialisation  ////
	// Tiles
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 64, 127);
	tileImage.initialize(&tileTexture, tileGridMask);


	//church sprites
	floorSprite.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchFloor));
	wallSprite.initialize(&tileImage, CoordI{ 6,0 });
	wallEast.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchWallEast));
	wallWest.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchWallWest));
	blood.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchBlood));
	door.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchDoor));
	WallConnect.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchWallConnect));
	wallPath.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchWallPath));
	chest.initialize(&tileImage, IMAGE_MAP.at(ImageType::churchChest));





	// Warrior
	warriorTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
	warriorAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 58, 114);
	warriorDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 59, 71);
	warriorIdleGridMask.initialize(0, 1045, 96, 96, 0, 1, 43, 81);
	warriorWalkGridMask.initialize(2882, 1045, 96, 96, 0, 1, 44, 80);
	warriorGetHitGridMask.initialize(4420, 1045, 96, 96, 0, 1, 44, 80);
	warriorAnimImage.initialize(&warriorTexture, {
		warriorAttackGridMask, warriorDieGridMask, warriorIdleGridMask,
		warriorWalkGridMask, warriorGetHitGridMask, warriorAttackGridMask }, 
		{ 16, 21, 10, 8, 6, 20 });
	// Mage
	mageTexture.initialize(graphics, IMAGE_UNIT_MAGE);
	mageAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 63, 110);
	mageDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 61, 81);
	mageIdleGridMask.initialize(0, 1045, 96, 96, 0, 1, 47, 79);
	mageWalkGridMask.initialize(2690, 1045, 96, 96, 0, 1, 47, 79);
	mageGetHitGridMask.initialize(4228, 1045, 96, 96, 0, 1, 47, 79);
	mageMagicFireGridMask.initialize(0, 1827, 128, 128, 0, 1, 61, 108);
	mageAnimImage.initialize(&mageTexture, {
		mageAttackGridMask, mageDieGridMask,
		mageIdleGridMask, mageWalkGridMask,
		mageGetHitGridMask, mageMagicFireGridMask}, 
		{ 16, 20, 8, 8, 8, 12 });
	// Fireball
	projTexture.initialize(graphics, IMAGE_PROJECTILE_FIREBALL);
	projGridMask.initialize(1, 1, 96, 96, 1, 1, 46, 46);
	projImage.initialize(&projTexture, { projGridMask }, { 15 });
	//initialize the values
	//renderLevel.initialize(graphics, input, type);
	ifstream fout("text\\gameInfo.csv", std::ofstream::out | std::ofstream::trunc);
	fout.close();

	////  Entities Initialisation  ////
	// Tiles
	tiles.initialize(mapWidth, mapHeight);

	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			switch (map[x][y])
			{
				//changing between textures
			case ImageType::churchBlood:
				tiles.set(x,y, &blood, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchFloor:
				tiles.set(x, y, &floorSprite, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchDoor:
				tiles.set(x, y, &door, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchChest:
				tiles.set(x, y, &chest, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchWallEast:
				tiles.set(x, y, &wallEast, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchWallWest:
				tiles.set(x, y, &wallWest, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchWallConnect:
				tiles.set(x, y, &WallConnect, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
			case ImageType::churchWallPath:
				tiles.set(x, y, &wallPath, translateHLines(Lines{ {} }, x, y),
					translateVLines(Lines{}, x, y));
				break;
				//test object
			}
		}
	}

	/*
	for (int y = 0; y < tiles.getRows(); y++)
		for (int x = 0; x < tiles.getCols(); x++)
			tiles.set(y, x, &wallSprite,
				translateHLines(Lines{ { 0, 1, 0 } }, x, y),
				translateVLines(Lines{}, x, y));
	for (int y = 1; y < tiles.getRows() - 1; y++)
		for (int x = 1; x < tiles.getCols() - 1; x++)
			tiles.set(y, x, &floorSprite,
				translateHLines(Lines{}, x, y),
				translateVLines(Lines{}, x, y));
	for (int y = 7; y < tiles.getRows() - 7; y++)
		for (int x = 7; x < tiles.getCols() - 7; x++)
			tiles.set(y, x, &wallSprite,
				translateHLines(Lines{ { 0, 1, 0 } }, x, y),
				translateVLines(Lines{}, x, y));
	*/

	// Player
	players.initialize(1);
	CoordF pPos = CoordF{ 3, 3 };
	players.push(
		pPos, &mageAnimImage, UNIT_STATE_IDLE, 
		playerIdleState, 0, 0, 
		translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		0, 0, 0, 0);

	// Enemy
	enemies.initialize(1);
	CoordF ePos = CoordF{ 5, 5 };
	enemies.push(
		ePos, &warriorAnimImage, UNIT_STATE_WALK,
		enemyWalkState, 0, 0.5,
		translateHLines(Lines{ { -0.4, 0.4, -0.4 }, { -0.4, 0.4, 0.4 } }, ePos),
		translateVLines(Lines{ { -0.4, 0.4, -0.4 }, { -0.4, 0.4, 0.4 } }, ePos));
	// Projectiles
	/*projectiles.initialize(1);
	CoordF jPos = CoordF{ 5, 5 };
	projectiles.push(
		jPos, &projImage,
		translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos),
		translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos));*/
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{
	// Player
	updateFSMArray(this, players.getSize(), players.getFSMArray());
	vector<CoordF> pDeltaArray(players.getSize());
	calculateDeltaArray(players.getSize(), pDeltaArray, players.getRotationArray(), players.getVelocityArray(), frameTime);
	updatePositionArray(players.getSize(), players.getPositionArray(), pDeltaArray);
	updateLinesArray(players.getSize(), players.getHLinesArray(), players.getVLinesArray(), pDeltaArray);

	// Enemy
	updateFSMArray(this, enemies.getSize(), enemies.getFSMArray());
	vector<CoordF> eDeltaArray(enemies.getSize());
	calculateDeltaArray(enemies.getSize(), eDeltaArray, enemies.getRotationArray(), enemies.getVelocityArray(), frameTime);
	updatePositionArray(enemies.getSize(), enemies.getPositionArray(), eDeltaArray);
	updateLinesArray(enemies.getSize(), enemies.getHLinesArray(), enemies.getVLinesArray(), eDeltaArray);

	// Wall Collision (Temporary!) (Callback not yet implemented!)
	updateAllWallCollision(tiles, players.getSize(), players.getHLinesArray(), players.getVLinesArray(), players.getPositionArray());
	updateAllWallCollision(tiles, enemies.getSize(), enemies.getHLinesArray(), enemies.getVLinesArray(), enemies.getPositionArray());

	// Move Camera
	camCoord = players.getPositionArray()[0];
	if (input->isKeyDown('O')) camScale *= 1 - 0.01;
	if (input->isKeyDown('P')) camScale *= 1 + 0.01;
	levelEdit();
	changeLevel();

}

	
void Level::render()
{
	for (int x = 0; x < tiles.getRows(); x++)
		for (int y = 0; y < tiles.getCols(); y++)
			graphics->drawSprite(
				tiles.getSprite(x, y)->getSpriteData(),
				gridToScreen(x, y), camScale);

	// Player (Temporary)
	int playerState = players.getStateArray()[0];
	int playerDirection = players.getDirectionArray()[0];
	int playerFrameNo = players.getFrameNoArray()[0];
	CoordF playerPos = players.getPositionArray()[0];
	SpriteData playerSD = players.getAnimImageArray()[0]->getSpriteData(playerState, playerDirection, playerFrameNo);
	graphics->drawSprite(
		playerSD, gridToScreen(playerPos), camScale);

	// Enemies (Temporary)
	int enemyState = enemies.getStateArray()[0];
	int enemyDirection = enemies.getDirectionArray()[0];
	int enemyFrameNo = enemies.getFrameNoArray()[0];
	CoordF enemyPos = enemies.getPositionArray()[0];
	SpriteData enemySD = enemies.getAnimImageArray()[0]->getSpriteData(enemyState, enemyDirection, enemyFrameNo);
	graphics->drawSprite(
		enemySD, gridToScreen(enemyPos), camScale);

	//for (int i = 0; i < players.getSize(); i++) {
	//	// Temporary solution to make it not blurry
	//	// CoordF screenCoords = gridToScreen(players.getPositionArray()[i]);
	//	SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
	//		players.getStateArray()[i],
	//		rotationToDirection(players.getRotationArray()[i]),
	//		players.getFrameNoArray()[i]);

 //       graphics->drawSprite(sd,
 //           gridToScreen(players.getPositionArray()[i]), camScale);
	//}
	//for (int i = 0; i < projectiles.getSize(); i++) {
	//	SpriteData sd = projectiles.getAnimImageArray()[i]->getSpriteData(
	//		0, projectiles.getRotationArray()[i],
	//		projectiles.getFrameNoArray()[i]);
	//	graphics->drawSprite(sd,
	//		gridToScreen(projectiles.getPositionArray()[i]), camScale);
	//}
	//will be moved to another file I hope
	//renderSprites();
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
	float rx = (vy2 + vx2) / 2;
	float ry = (vy2 - vx2) / 2;
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


void Level::levelEdit()
{
	if (input->getMouseLButton() && input->isKeyDown(0x51))
	{
		input->setMouseLButton(false);
		CoordF mouse = { input->getMouseX(), input->getMouseY() };
		CoordF gridPos1 = screenToGrid(mouse.x, mouse.y);
		CoordI gridPos = { gridPos1.x, gridPos1.y };
		++map[gridPos.x][gridPos.y] %= 15;
		input->clearCharIn();
	}

	if (input->wasKeyPressed(0x52))
	{
		writeToFile(map);
	}


	if (input->getMouseLButton())
	{
		input->setMouseLButton(false);
		CoordF mouse = { input->getMouseX(), input->getMouseY() };
		CoordF gridPos1 = screenToGrid(mouse.x, mouse.y);
		CoordI gridPos = { gridPos1.x, gridPos1.y };

		//door
		// 10 is open door (add to constants)
		editComponent->changeObjects(ImageType::churchDoor, 10, map, gridPos.x, gridPos.y);

		input->clearCharIn();
	}

}

void Level::readFromFile()
{	
	++mapNo %= 4;
	editComponent->readFromFile("save.txt", map, mapNo);
}

void Level::writeToFile(int map[mapWidth][mapHeight])
{	
	int random = rand() % 1000;
	editComponent->writeToFile(map, random);
}

void Level::changeLevel()
{
	if (input->wasKeyPressed(0x45))
	{
		//woahh
		//mapNo = 29229;
		input->clearKeyPress(0x45);
		editComponent->animateObjects();
		level.readFromFile();
		//level.initialize();
	}
}
/*
void Level::renderSprites()
{	
	//Must be a more elegant way to write this
	for (int x = 0; x < mapWidth; x++) {
		for (int y = 0; y < mapHeight; y++) {
			CoordF screenPos = gridToScreen(x, y);
			SpriteData sd;

			//pass to renderLevel class
			renderLevel.getTileImage().getSpriteData(IMAGE_MAP.at(ImageType::churchFloor));
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
*/

void Level::placeRoom()
{
	editComponent->placeRoom(map);
}