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

	// Initializing both warrior and mage is temporary
	// It should be initialized whenever the character picks whichever
	// they are playing
	unitTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
    unitAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 58, 114);
	unitDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 59, 71);
	unitIdleGridMask.initialize(0, 1045, 96, 96, 0, 1, 43, 81);
	unitWalkGridMask.initialize(2882, 1045, 96, 96, 0, 1, 44, 80);
	unitGetHitGridMask.initialize(4420, 1045, 96, 96, 0, 1, 44, 80);
	vector<GridMask> unitGridMasks = {
        unitAttackGridMask,
        unitDieGridMask,
        unitIdleGridMask,
        unitWalkGridMask,
		unitGetHitGridMask
	};
    vector<int> unitEndFrames = { 16, 21, 10, 8, 6 };
	unitImage.initialize(&unitTexture, unitGridMasks, unitEndFrames);

	unitMageTexture.initialize(graphics, IMAGE_UNIT_MAGE);
    unitMageAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 63, 110);
	unitMageDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 61, 81);
	unitMageIdleGridMask.initialize(0, 1045, 96, 96, 0, 1, 47, 79);
	unitMageWalkGridMask.initialize(2690, 1045, 96, 96, 0, 1, 47, 79);
	unitMageGetHitGridMask.initialize(4228, 1045, 96, 96, 0, 1, 47, 79);
	unitMageFireGridMask.initialize(0, 1827, 128, 128, 0, 1, 61, 108);
	vector<GridMask> unitMageGridMasks = {
        unitMageAttackGridMask,
        unitMageDieGridMask,
        unitMageIdleGridMask,
        unitMageWalkGridMask,
		unitMageGetHitGridMask,
		unitMageFireGridMask
	};
	vector<int> unitMageEndFrames = { 16, 20, 8, 8, 8, 12 };
	unitMageImage.initialize(&unitMageTexture, unitMageGridMasks, unitMageEndFrames);

	// unitGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	// unitImage.initialize(&unitTexture, unitGridMask);
	// unitSprite.initialize(&unitImage, CoordI{ 0, 0 });
	projTexture.initialize(graphics, IMAGE_PROJECTILE_FIREBALL);
	projGridMask.initialize(1, 1, 96, 96, 1, 1, 46, 46);
	projImage.initialize(&projTexture, projGridMask);
	projSprite.initialize(&projImage, CoordI { 0, 0 });
	// Tiles
	tiles.initialize(10, 10);
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
		getStates()->at(PLAYER::IDLE),
		&unitMageImage,
		PLAYER::IDLE,
		100,
		100);

	// Projectiles
	projectiles.initialize(1);
	CoordF jPos = CoordF{ 5, 5 };
	projectiles.push(
		jPos, &projSprite,
		translateHLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos),
		translateVLines(Lines{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, jPos));
}

void Level::releaseAll()
{
	tileTexture.onLostDevice();
	unitTexture.onLostDevice();
}

void Level::resetAll()
{
	tileTexture.onResetDevice(graphics);
	unitTexture.onResetDevice(graphics);
}

void Level::update()
{
	// Move Player
	// CoordF moveDelta{ 0, 0 };
	// if (input->isKeyDown('W')) moveDelta.y = -0.01;
	// if (input->isKeyDown('S')) moveDelta.y = 0.01;
	// if (input->isKeyDown('A')) moveDelta.x = -0.01;
	// if (input->isKeyDown('D')) moveDelta.x = 0.01;
	// players.getPositions()[0] += moveDelta;
	// Move Player Collision
	// updateHCollision(players.getHCollisions()[0], moveDelta);
	// updateVCollision(players.getVCollisions()[0], moveDelta);

	// Collision
	// CoordF* pPositions = players.getPositions();
	// CoordF* pDestPositions = players.getDestPositions();
	// Collision* pHCollisions = players.getHCollisions();
	// Collision* pVCollisions = players.getVCollisions();

	// vector<State*> pStates = players.getStateArray();
	vector<State*> pFsms = players.getFsmArray();
	// vector<RenderInfo>* pRenderInfos = &players.getImageInfoArray();
	for (int i = 0; i < players.getSize(); i++) {
		// pStates[i]->update(this, i);
		pFsms[i]->update(this, i);
	}

    // CoordF pPosition = pPositions[i];
    // CoordF delta{ 0, 0 };
    // Line hLine, vLine;
    // if (checkHCollisionToWallCollision(tiles, hLine, vLine, pHCollisions[i]))
    // 	delta.x = getDeltaXResponse(hLine, vLine, pPosition);
    // if (checkVCollisionToWallCollision(tiles, vLine, hLine, pVCollisions[i]))
    // 	delta.y = getDeltaYResponse(vLine, hLine, pPosition);
    // pPositions[i] += delta;
    // updateHCollision(pHCollisions[i], delta);
    // updateVCollision(pVCollisions[i], delta);

	// CoordF moveDelta{ 0, 0 };
	// if (input->isKeyDown('W')) moveDelta.y = -0.01;
	// if (input->isKeyDown('S')) moveDelta.y = 0.01;
	// if (input->isKeyDown('A')) moveDelta.x = -0.01;
	// if (input->isKeyDown('D')) moveDelta.x = 0.01;
	// players.getPositionArray()[0] += moveDelta;
	// // Move Player Lines
	// updateHLines(players.getHLinesArray()[0], moveDelta);
	// updateVLines(players.getVLinesArray()[0], moveDelta);
	// // Lines
	// vector<CoordF>& pPositionArray = players.getPositionArray();
	// vector<Lines>& pHLinesArray = players.getHLinesArray();
	// vector<Lines>& pVLinesArray = players.getVLinesArray();
	// for (int i = 0; i < players.getSize(); i++) {
	// 	CoordF pPosition = pPositionArray[i];
	// 	CoordF delta{ 0, 0 };
	// 	Line hLine, vLine;
	// 	if (checkHLinesToWallCollision(tiles, pHLinesArray[i], hLine, vLine))
	// 		delta.x = getDeltaXResponse(hLine, vLine, pPosition);
	// 	if (checkVLinesToWallCollision(tiles, pVLinesArray[i], vLine, hLine))
	// 		delta.y = getDeltaYResponse(vLine, hLine, pPosition);
	// 	pPositionArray[i] += delta;
	// 	updateHLines(pHLinesArray[i], delta);
	// 	updateVLines(pVLinesArray[i], delta);
	// }

	// // Move Projectiles
	// moveDelta.x = 0; moveDelta.y = 0;
	// if (input->isKeyDown('I')) moveDelta.y = -0.01;
	// if (input->isKeyDown('K')) moveDelta.y = 0.01;
	// if (input->isKeyDown('J')) moveDelta.x = -0.01;
	// if (input->isKeyDown('L')) moveDelta.x = 0.01;
	// projectiles.getPositionArray()[0] += moveDelta;
	// updateHLineISetIters(projectiles.getHLineISet(), projectiles.getHLineISetItersArray()[0], moveDelta);
	// updateVLineISetIters(projectiles.getVLineISet(), projectiles.getVLineISetItersArray()[0], moveDelta);
	// // Projectiles Collision
	// vector<CoordF>& jPositionArray = projectiles.getPositionArray();
	// vector<LineISetIters>& hLineISetItersArray = projectiles.getHLineISetItersArray();
	// vector<LineISetIters>& vLineISetItersArray = projectiles.getVLineISetItersArray();
	// for (int i = 0; i < players.getSize(); i++) {
	// 	CoordF jPos = jPositionArray[i];
	// 	CoordF delta{ 0, 0 };
	// 	LineI hLineI, vLineI;
	// 	if (checkHLineISetItersToWallCollision(tiles, hLineISetItersArray[i], hLineI, vLineI))
	// 		delta.x = getDeltaXResponse(hLineI, vLineI, jPos);
	// 	if (checkVLineISetItersToWallCollision(tiles, vLineISetItersArray[i], vLineI, hLineI))
	// 		delta.y = getDeltaYResponse(vLineI, hLineI, jPos);
	// 	jPositionArray[i] += delta;
	// 	updateHLineISetIters(projectiles.getHLineISet(), hLineISetItersArray[i], delta);
	// 	updateVLineISetIters(projectiles.getVLineISet(), vLineISetItersArray[i], delta);
	// }

	// // Move Camera
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
        // SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
        //     players.getStateArray()[i], players.getDirectionArray()[i],
        //     players.getFrameNoArray()[i]);

        // SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
        //     players.getStateArray()[i], rotationToDirection(players.getRotationArray()[i]),
        //     players.getFrameNoArray()[i]);

		// SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
		// 	players.getStateArray()[i],
		// 	int(rotationToDirection(players.getRotationArray()[i])),
		// 	players.getFrameNoArray()[i]);
		int x = rotationToDirection(players.getRotationArray()[i]);
		SpriteData sd = players.getAnimImageArray()[i]->getSpriteData(
			players.getStateArray()[i],
			rotationToDirection(players.getRotationArray()[i]),
			players.getFrameNoArray()[i]);

        graphics->drawSprite(sd,
            gridToScreen(players.getPositionArray()[i]), camScale);
	}

	graphics->drawSprite(
		projectiles.getSpriteArray()[0]->getSpriteData(),
		gridToScreen(projectiles.getPositionArray()[0]), camScale);
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
    // float dy = dest.y - src.y;
    // float dx = dest.x - src.x;
    // return atan2(dy, dx);
	float currentX = src.x;
	float currentY = src.y;

	float destX = dest.x;
	float destY = dest.y;

	float radAngle = atan2(abs(currentX - destX), abs(currentY - destY));
    float degAngle = radAngle * (180 / PI);
    if (destX > currentX && destY < currentY) {
    }
    else if (destX > currentX && destY > currentY) {
        degAngle = 180 - degAngle;
    }
    else if (destX < currentX && destY > currentY) {
        degAngle = 180 + degAngle;
    }
    else if (destX < currentX && destY < currentY) {
        degAngle = 360 - degAngle;
    }
    // Dimetric angle offset
    degAngle += 25.565;
	return degAngle;
}

float Level::rotationToDirection(float rotation)
{
    // rotation *= -1;
    // rotation -= PI / 4;
    // rotation = fmod(rotation, PI * 2);
    // rotation /= PI / 8;
    // return round(rotation);
	if (rotation <= 22.5) {
		return DIRECTION8::NORTH;
    }
    else if (rotation <= 67.5) {
		return DIRECTION8::NORTH_EAST;
    }
    else if (rotation <= 112.5) {
		return DIRECTION8::EAST;
    }
    else if (rotation <= 157.5) {
		return DIRECTION8::SOUTH_EAST;
    }
    else if (rotation <= 202.5) {
		return DIRECTION8::SOUTH;
    }
    else if (rotation <= 247.5) {
		return DIRECTION8::SOUTH_WEST;
    }
    else if (rotation <= 292.5) {
		return DIRECTION8::WEST;
    }
    else if (rotation <= 337.5) {
		return DIRECTION8::NORTH_WEST;
    }
    else {
		return DIRECTION8::NORTH;
    }

}