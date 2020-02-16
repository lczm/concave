#include "level.h"

Level::Level()
{
	camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{
	////  Sprite Initialisation  ////
	// Tiles
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 64, 127);
	tileImage.initialize(&tileTexture, tileGridMask);
	floorSprite.initialize(&tileImage, CoordI{ 12, 0 });
	wallSprite.initialize(&tileImage, CoordI{ 6, 0 });
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

	////  Entities Initialisation  ////
	// Tiles
	tiles.initialize(20, 20);
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
	projectiles.initialize(100);
	// CoordF jPos = CoordF{ 5, 5 };
	// projectiles.push(
	// 	jPos, &projImage,
	// 	translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos),
	// 	translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos),
	// 	1);
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
}

void Level::render()
{
	for (int y = 0; y < tiles.getRows(); y++)
		for (int x = 0; x < tiles.getCols(); x++)
			graphics->drawSprite(
				tiles.getSprite(y, x)->getSpriteData(),
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

	for (int i = 0; i < projectiles.getSize(); i++) {
		SpriteData sd = projectiles.getAnimImageArray()[i]->getSpriteData(0, 
			11,
			projectiles.getFrameNoArray()[i]);
		graphics->drawSprite(sd,
			gridToScreen(projectiles.getPositionArray()[i]), camScale);
	}
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