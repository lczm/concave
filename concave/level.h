#pragma once
#include "window.h"
#include "image.h"
#include "tiles.h"
#include "players.h"
#include "enemies.h"
#include "projectiles.h"
#include "objects.h"
#include "animObjects.h"
#include "playerFSM.h"
#include "enemyFSM.h"
#include "collisionSystem.h"
#include "movementSystem.h"
#include "fsmSystem.h"
#include "modifiers.h"
#include "audioEngine.h"

#include "cellular.h"
#include "EditComponent.h"
#include "renderLevel.h"
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

class Level : public Window
{
private:
	// AudioEngine
	AudioEngine* audioEngine;
	// Camera
	CoordF camCoord; float camScale;
	// Tiles
	Texture tileTexture; GridMask tileGridMask; Image tileImage;
	Sprite floorSprite,
		wallSprite, blood, door, chest,
		wallEast, wallWest, WallConnect,
		wallPath, barrel, fireItem, torch,
		book, dead, dead2, dead3, dead4, dead5,
		armour, witch, banner, cabinet, 
		bloodPool, store, cow;

	/* Tile texture, masks and images*/
	Texture itemTexture;	  GridMask itemGridMask;      Image itemImage;
	Texture manyItemsTexture; GridMask manyItemsGridMask; Image manyItemsImage;
	Texture cabinetTexture;   GridMask cabinetGridMask;   Image cabinetImage;
	Texture deadTexture;      GridMask deadPeopleGridMask;Image deadPeopleImage;
	Texture bannerTexture;    GridMask bannerGridMask;    Image bannerImage;
	Texture armourTexture;    GridMask armourGridMask;	  Image armourImage;
	Texture witchTexture;     GridMask witchGridMask;     Image witchImage;
	Texture flameTexture;  GridMask flameGridMask;   Image flameImage;
	GridMask fireGridMask;    Image fireImage;
	GridMask bookGridMask;    Image bookImage;
	Texture bloodPoolTexture;GridMask  bloodPoolGridMask; Image bloodPoolImage;

	Texture torchTexture;  GridMask torchGridMask;   Image torchImage;
	Texture storeTexture;	  GridMask storeGridMask;      Image storeImage;
	Texture cowTexture;  GridMask cowGridMask;   Image cowImage;


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
	GridMask mageMagicSmokeGridMask;

	// Enemy
	Texture balrogTexture; AnimImage balrogAnimImage;
	GridMask balrogAttackGridMask;
	GridMask balrogDieGridMask;
	GridMask balrogIdleGridMask;
	GridMask balrogWalkGridMask;
	GridMask balrogGetHitGridMask;

	// Projectiles
	Texture projTexture; AnimImage projImage;
	GridMask projGridMask;
	// Components
	Tiles underTiles;
	Tiles tiles;
	Players players;
	Projectiles projectiles;
	Enemies enemies;
	Objects objects;
	AnimObjects animObjects;

	AnimImage doorAnim;
	AnimImage fireBurning;
	AnimImage chestAnim;
	AnimImage barrelAnim;
	AnimImage bloodPoolAnim;
	AnimImage fireItemAnim;
	AnimImage torchAnim;
	AnimImage cowAnim;
	// Camera
	int map[mapWidth][mapHeight];

	int mapNo = 0;

	//shld prob change this to another variable
	//int type = 0;
	//prob need to change it to read component
	EditComponent* editComponent;


	//RenderLevel renderLevel;
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

	void levelEdit();
	void changeLevel();
	void readFromFile();
	//void renderSprites();
	void writeToFile(int map[mapWidth][mapHeight]);
	void placeRoom();
	void tilesInitialize();
};