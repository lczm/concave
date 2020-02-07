#include "level.h"

Level::Level()
{
	camX = 0; camY = 0; camScale = 1;
}

Level::~Level()
{}

void Level::initialize()
{
	// Image
	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 128 / 2, 192 - TILE_HEIGHT - 1);
	tileImage.initialize(&tileTexture, tileGridMask);
	unitTexture.initialize(graphics, IMAGE_UNIT_WARRIOR);
	unitGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	unitImage.initialize(&unitTexture, unitGridMask);
	// Tiles
	tiles.resize(2);
	tiles[0].initialize(&tileImage, CoordI{ 12, 0 },
		vector<Tile::Line> {}, vector<Tile::Line> {});
	tiles[1].initialize(&tileImage, CoordI{ 6, 0 },
		vector<Tile::Line> { {0, 1, 0} }, vector<Tile::Line> {});
	tileGrid.initialize(10, 10);
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			tileGrid.set(x, y, &tiles[1]);
	for (int x = 1; x < 9; x++) 
		for (int y = 1; y < 9; y++) 
			tileGrid.set(x, y, &tiles[0]);
	// Player
	positions.resize(1); collisions.resize(1); renders.resize(1);
	positions[0].gx = 5; positions[0].gy = 5;
	collisions[0].hLines = vector<Collision::Line>{
		{ -0.4, 0.4, -0.2, &collisions[0] }, { -0.4, 0.4, 0.2, &collisions[0] } };
	collisions[0].vLines = vector<Collision::Line>{
		{ -0.4, 0.4, -0.2, &collisions[0] }, { -0.4, 0.4, 0.2, &collisions[0] } };
	renders[0].image = &unitImage; renders[0].coord = CoordI{ 0, 0 };
	player.position = &positions[0]; collisions[0].entity = &player;
	player.collision = &collisions[0]; collisions[0].entity = &player;
	player.render = &renders[0]; collisions[0].entity = &player;
}

void Level::releaseAll()
{}

void Level::resetAll()
{}

void Level::update()
{}

void Level::render()
{}

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