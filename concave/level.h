#pragma once
#include "window.h"
#include "image.h"
#include "component.h"
#include "players.h"
#include "tiles.h"
#include "projectiles.h"
#include "collisionSystem.h"
#include <vector>
#include <cassert>
#include "playerState.h"
using namespace std;
using namespace STATE;

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
	//GridMask mageFireGridMask;

	// // Projectiles
	Texture projTexture; AnimImage projImage;
	GridMask projGridMask;

	// Components
	Tiles tiles;
	Players players;
	Projectiles projectiles;
	// Systems
	vector<State*> states;

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
	vector<State*> getStates() { return states; }
    float calculateRotation(CoordF src, CoordF dest);
    int rotationToDirection(float rotation);
	int modulo(int val, int m);
};