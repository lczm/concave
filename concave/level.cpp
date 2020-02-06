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
	tileSprite.initialize(&tileImage, CoordI{ 12, 0 });

	unitTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
	unitAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 58, 114);
	unitDieGridMask.initialize(2047, 7, 128, 95, 0, 1, 59, 71);
	unitIdleGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	unitWalkGridMask.initialize(2882, 1045, 96, 95, 0, 1, 44, 80);
	vector<GridMask> unitGridMasks = { 
		unitAttackGridMask, unitDieGridMask, unitIdleGridMask,
		unitWalkGridMask
	};
	vector<int> unitEndFrames = { 16, 21, 10, 8 };
	unitImage.initialize(&unitTexture, unitGridMasks, unitEndFrames);
	unitSprite.initialize(&unitImage, UNIT_STATE_IDLE, DIRECTION8::SOUTH, 0, 0.1, false);
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
	if (input->isKeyDown('P')) camScale += 0.01;
	if (input->isKeyDown('O')) camScale -= 0.01;
	if (unitSprite.getLoopComplete() ||
		(unitSprite.getState() != UNIT_STATE_ATTACK &&
		unitSprite.getState() != UNIT_STATE_DIE)) {
		unitSprite.setState(UNIT_STATE_WALK);
		unitSprite.setLoop(true);
		unitSprite.setLoopComplete(false);
		char dv = 0, dh = 0;
		if (input->isKeyDown('W')) {
			camY -= 0.01; dv--;
		}
		if (input->isKeyDown('S')) {
			camY += 0.01; dv++;
		}
		if (input->isKeyDown('A')) {
			camX -= 0.01; dh--;
		}
		if (input->isKeyDown('D')) {
			camX += 0.01; dh++;
		}
		switch (dv) {
		case -1:
			switch (dh) {
			case -1:
				unitSprite.setDirection(DIRECTION8::NORTH_WEST); break;
			case 0:
				unitSprite.setDirection(DIRECTION8::NORTH); break;
			case 1:
				unitSprite.setDirection(DIRECTION8::NORTH_EAST); break;
			}
			break;
		case 0:
			switch (dh) {
			case -1:
				unitSprite.setDirection(DIRECTION8::WEST); break;
			case 0:
				if (input->isKeyDown('K')) {
					unitSprite.setState(UNIT_STATE_ATTACK);
					unitSprite.setLoop(false);
					unitSprite.setLoopComplete(false);
					unitSprite.setTimer(0);
				}
				else if (input->isKeyDown('L')) {
					unitSprite.setState(UNIT_STATE_DIE);
					unitSprite.setLoop(false);
					unitSprite.setLoopComplete(false);
					unitSprite.setTimer(0);
				}
				else {
					unitSprite.setState(UNIT_STATE_IDLE);
					unitSprite.setLoop(true);
					unitSprite.setLoopComplete(false);
				}
				break;
			case 1:
				unitSprite.setDirection(DIRECTION8::EAST); break;
			}
			break;
		case 1:
			switch (dh) {
			case -1:
				unitSprite.setDirection(DIRECTION8::SOUTH_WEST); break;
			case 0:
				unitSprite.setDirection(DIRECTION8::SOUTH); break;
			case 1:
				unitSprite.setDirection(DIRECTION8::SOUTH_EAST); break;
			}
			break;
		}
	}
	if (!unitSprite.getLoopComplete()) unitSprite.updateFrame(frameTime);
}

void Level::render()
{
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			CoordF screenPos = gridToScreen(x, y);
			SpriteData sd = tileSprite.getSpriteData();
			graphics->drawSprite(
				sd,
				screenPos.x, screenPos.y, camScale);
		}
	}
	CoordF screenPos = gridToScreen(camX, camY);
	graphics->drawSprite(
		unitSprite.getSpriteData(), 
		screenPos.x, screenPos.y, camScale
	);
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