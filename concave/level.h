#pragma once
#include "window.h"
#include "image.h"
#include "tiles.h"
#include "players.h"
#include "enemies.h"
#include "projectiles.h"
#include "playerFSM.h"
#include "enemyFSM.h"
#include "collisionSystem.h"
#include "movementSystem.h"
#include "fsmSystem.h"
#include <vector>
#include <cassert>
using namespace std;

class Level : public Window
{
private:
	// Camera
	CoordF camCoord; float camScale;
	// Tiles
	Texture tileTexture; GridMask tileGridMask; Image tileImage;
	Sprite floorSprite, wallSprite;
	// Player
	Texture warriorTexture; AnimImage warriorAnimImage;
	GridMask warriorAttackGridMask;
	GridMask warriorDieGridMask;
	GridMask warriorIdleGridMask;
	GridMask warriorWalkGridMask;
	GridMask warriorGetHitGridMask;
	Texture mageTexture; AnimImage mageAnimImage;
	GridMask mageAttackGridMask;
	GridMask mageDieGridMask;
	GridMask mageIdleGridMask;
	GridMask mageWalkGridMask;
	GridMask mageGetHitGridMask;
	GridMask mageMagicFireGridMask;

	// Projectiles
	Texture projTexture; AnimImage projImage;
	GridMask projGridMask;
	// Components
	Tiles tiles;
	Players players;
	Projectiles projectiles;
	Enemies enemies;

public:
	Level();
	~Level();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();

	CoordF gridToScreen(float gx, float gy);
	CoordF screenToGrid(float sx, float sy);
	CoordF gridToScreen(CoordF gridCoord);
	CoordF screenToGrid(CoordF screenCoord);

	Players& getPlayers() { return players; }
	Enemies& getEnemies() { return enemies; }
	Projectiles& getProjectiles() { return projectiles; }

	AnimImage& getProjImage() { return projImage; }
};