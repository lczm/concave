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
		warriorWalkGridMask, warriorGetHitGridMask }, { 16, 21, 10, 8, 6 });
	// Mage
	mageTexture.initialize(graphics, IMAGE_UNIT_MAGE);
	mageAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 63, 110);
	mageDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 61, 81);
	mageIdleGridMask.initialize(0, 1045, 96, 96, 0, 1, 47, 79);
	mageWalkGridMask.initialize(2690, 1045, 96, 96, 0, 1, 47, 79);
	mageGetHitGridMask.initialize(4228, 1045, 96, 96, 0, 1, 47, 79);
	//mageFireGridMask.initialize(0, 1827, 128, 128, 0, 1, 61, 108);
	mageAnimImage.initialize(&mageTexture, {
		mageAttackGridMask, mageDieGridMask,
		mageIdleGridMask, mageWalkGridMask,
		mageGetHitGridMask }, { 16, 20, 8, 8, 8, 12 });
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

	// States
	states.push_back(new PlayerAttackState());
	states.push_back(new PlayerDieState());
	states.push_back(new PlayerIdleState());
	states.push_back(new PlayerWalkState());
	states.push_back(new PlayerGetHitState());
	states.push_back(new PlayerFireState());

	// Player
	players.initialize(1);
	CoordF pPos = CoordF{ 3, 3 };
	players.push(pPos,
		translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		getStates().at(PLAYER::IDLE),
		&mageAnimImage,
		PLAYER::IDLE,
		100,
		100);

	// Projectiles
	projectiles.initialize(1);
	CoordF jPos = CoordF{ 5, 5 };
	projectiles.push(
		jPos, &projImage,
		translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos),
		translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos));
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{
	// Move Player
	CoordF moveDelta{ 0, 0 };

	// Collision
	vector<CoordF>& pPositions = players.getPositionArray();
	vector<CoordF>& pDydx = players.getDyDxArray();
	// vector<CoordF> pDestPositions = players.getDestPositionArray();
	// Collision* pHCollisions = players.getHCollisions();
	// Collision* pVCollisions = players.getVCollisions();
	vector<State*>& pFsms = players.getFsmArray();
	// vector<RenderInfo>* pRenderInfos = &players.getImageInfoArray();
	for (int i = 0; i < players.getSize(); i++) {
		pFsms[i]->update(this, i);
		pPositions[i] += pDydx[i];
	}

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
	for (int i = 0; i < players.getSize(); i++) {
		// Temporary solution to make it not blurry
		// CoordF screenCoords = gridToScreen(players.getPositionArray()[i]);
		SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
			players.getStateArray()[i],
			rotationToDirection(players.getRotationArray()[i]),
			players.getFrameNoArray()[i]);

        graphics->drawSprite(sd,
            gridToScreen(players.getPositionArray()[i]), camScale);
	}
	for (int i = 0; i < projectiles.getSize(); i++) {
		SpriteData sd = projectiles.getAnimImageArray()[i]->getSpriteData(
			0, projectiles.getRotationArray()[i],
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

float Level::calculateRotation(CoordF src, CoordF dest)
{
    float dx = dest.x - src.x;
    float dy = dest.y - src.y;
    return atan2(dy, dx);
}

int Level::rotationToDirection(float rotation)
{
	int direction;
	// Offset dimetric angle
	rotation += 0.4461934;
    rotation -= PI / 2;
    rotation /= PI / 4;
	direction = round(rotation);
	direction = modulo(direction, 8);
	return direction;
}

int Level::modulo(int val, int m)
{
	int mod = val % m;
	if (val < 0) mod += m;
	return mod;
}
