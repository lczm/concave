#include "level.h"

Level::Level()
{
	camScale = 1;
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
	for (int y = 0; y < tileGrid.getRows(); y++)
		for (int x = 0; x < tileGrid.getCols(); x++)
			tileGrid.set(x, y, &tiles[1]);
	for (int y = 1; y < tileGrid.getRows() - 1; y++)
		for (int x = 1; x < tileGrid.getCols() - 1; x++)
			tileGrid.set(x, y, &tiles[0]);
	// Player
	positions.resize(1); collisions.resize(1); renders.resize(1);
	positions[0].grid = CoordF{ 5, 5 };
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
{
	// Player
	if (input->isKeyDown('W')) player.position->grid.y -= 0.01;
	if (input->isKeyDown('S')) player.position->grid.y += 0.01;
	if (input->isKeyDown('A')) player.position->grid.x -= 0.01;
	if (input->isKeyDown('D')) player.position->grid.x += 0.01;
	// Camera
	camCoord = player.position->grid;
	if (input->isKeyDown('O')) camScale -= 0.01;
	if (input->isKeyDown('P')) camScale += 0.01;
}

void Level::render()
{
	// Tiles
	for (int y = 0; y < tileGrid.getRows(); y++)
		for (int x = 0; x < tileGrid.getCols(); x++)
			graphics->drawSprite(
				tileGrid.get(x, y)->getSpriteData(), 
				gridToScreen(x, y), camScale);
	// Player
	player.position->screen = gridToScreen(player.position->grid);
	graphics->drawSprite(
		player.render->image->getSpriteData(player.render->coord),
		player.position->screen, camScale
	);
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
	float rx = (vy2 - vx2) / 2;
	float ry = (vy2 + vx2) / 2;
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