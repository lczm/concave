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
#include "playerAttackState.h"
#include "playerDieState.h"
#include "playerIdleState.h"
#include "playerWalkState.h"
#include "playerGetHitState.h"
#include "playerFireState.h"
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
	Texture unitTexture; AnimImage unitImage;
	GridMask unitAttackGridMask;
	GridMask unitDieGridMask;
	GridMask unitIdleGridMask;
	GridMask unitWalkGridMask;
	GridMask unitGetHitGridMask;

	Texture unitMageTexture; AnimImage unitMageImage;
	GridMask unitMageAttackGridMask;
	GridMask unitMageDieGridMask;
	GridMask unitMageIdleGridMask;
	GridMask unitMageWalkGridMask;
	GridMask unitMageGetHitGridMask;
	GridMask unitMageFireGridMask;

	// Texture unitTexture; GridMask unitGridMask; Image unitImage;
	// Sprite unitSprite;
	// // Projectiles
	Texture projTexture; GridMask projGridMask; Image projImage;
	Sprite projSprite;

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

	Players* getPlayers() { return &players; }
	vector<State*>* getStates() { return &states; }
};