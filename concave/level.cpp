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
			tiles.set(y, x, 
				translateHCollision(Collision{ { 0, 1, 0 } }, x, y), 
				translateVCollision(Collision{}, x, y),
				&wallSprite);
	for (int y = 1; y < tiles.getRows() - 1; y++)
		for (int x = 1; x < tiles.getCols() - 1; x++)
			tiles.set(y, x, 
				translateHCollision(Collision{}, x, y),
				translateVCollision(Collision{}, x, y), 
				&floorSprite);
	// States
	PlayerAttackState* playerAttackState = new PlayerAttackState(this);
	PlayerDieState* playerDieState = new PlayerDieState(this);
	PlayerIdleState* playerIdleState = new PlayerIdleState(this);
	PlayerWalkState* playerWalkState = new PlayerWalkState(this);
	states.push_back(playerAttackState);
	states.push_back(playerDieState);
	states.push_back(playerIdleState);
	states.push_back(playerWalkState);

	// Player
	players.initialize(1);
	CoordF pPos = CoordF{ 3, 3 };
	players.push(
		pPos,
		translateHCollision(Collision{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		translateVCollision(Collision{ { -0.4, 0.4, -0.2 }, { -0.4, 0.4, 0.2 } }, pPos),
		&unitSprite,
		playerIdleState);
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
	CoordF* pPositions = players.getPositions();
	CoordF* pDestPositions = players.getDestPositions();
	Collision* pHCollisions = players.getHCollisions();
	Collision* pVCollisions = players.getVCollisions();
	vector<State*> pStates = players.getStates();
	for (int i = 0; i < players.getSize(); i++) {
        PLAYER_STATE state = pStates[i]->update(frameTime, i, &players);
		// if (pStates[i]->state == PLAYER_STATE::IDLE && state == PLAYER_STATE::WALK) {
		// 	CoordF position = screenToGrid(players.getDestPositions(i));
		// 	std::cout << "Grid position : " << position.x << " | " << position.y << std::endl;
		// 	players.setDestPosition(i, screenToGrid(players.getDestPositions(i)));
		// }
		if (state != pStates[i]->state) {
			switch (state) {
			case PLAYER_STATE::ATTACK:
				players.setState(i, states[0]);
				break;
			case PLAYER_STATE::DIE:
				players.setState(i, states[1]);
				break;
			case PLAYER_STATE::IDLE:
				std::cout << "Switching states to idle" << std::endl;
				players.setState(i, states[2]);
				break;
			case PLAYER_STATE::WALK:
				std::cout << "Switching states to walk" << std::endl;
                CoordF position = gridToScreen(players.getPosition(i));
				players.setState(i, states[3]);
				break;
			default:
				break;
			}
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
	}

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