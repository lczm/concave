#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//-----------------------------------------------
//                   Data
//-----------------------------------------------
struct CoordI { int x, y; };
struct CoordF { float x, y; };

enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
// enum DIRECTION16 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
//namespace DIRECTION8 {
//	const int
//		SOUTH = 0, SOUTH_WEST = 1, WEST = 2, NORTH_WEST = 3,
//		NORTH = 4, NORTH_EAST = 5, EAST = 6, SOUTH_EAST = 7;}

//-----------------------------------------------
//                   Tiles
//-----------------------------------------------
const int TILE_WIDTH = 128;
const int TILE_HEIGHT = 64;

const int mapWidth = 48;
const int mapHeight = 48;


//-----------------------------------------------
//                   Units
//-----------------------------------------------
const int UNIT_STATE_ATTACK = 0;
const int UNIT_STATE_DIE = 1;
const int UNIT_STATE_IDLE = 2;
const int UNIT_STATE_WALK = 3;
const int UNIT_STATE_GET_HIT = 4;
// Players
const int PLAYER_STATE_MAGIC_FIRE = 5;
const int PLAYER_STATE_MAGIC_LIGHTNING = 6;
const int PLAYER_STATE_MAGIC_SMOKE = 7;
const int PLAYER_STATE_BLOCK = 8;
const int PLAYER_STATE_IDLE_TOWN = 9;
const int PLAYER_STATE_WALK_TOWN = 10;
// Enemy
const int ENEMY_STATE_SPECIAL = 5;

//-----------------------------------------------
//                Image (Tiles)
//-----------------------------------------------
const int IMAGE_TILES_ORIGIN_X = 0;
const int IMAGE_TILES_ORIGIN_Y = 0;
const int IMAGE_TILES_WIDTH = 128;
const int IMAGE_TILES_HEIGHT = 192;
const int IMAGE_TILES_GAP_WIDTH = 1;
const int IMAGE_TILES_GAP_HEIGHT = 1;

const char IMAGE_TILES_DUNGEON[] = "sprites/tiles_church_dungeon.png";
const char IMAGE_TILES_CAVE[] = "sprites/tiles_cave_dungeon.png";

//const char IMAGE_ITEMS_DUNGEON[] = "sprites/items.png";
const char IMAGE_ITEMS_DUNGEON[] = "sprites/items2.png";


//-----------------------------------------------
//                Image (Units)
//-----------------------------------------------
const char IMAGE_UNIT_WARRIOR[] = "sprites/unit_warrior.png";

//-----------------------------------------------
//					  Other
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) {ptr->onLostDevice();}}
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) {ptr->onResetDevice();}}

// Transparent color (white)
#define TRANSCOLOR graphicsNS::WHITE

// window
const char CLASS_NAME[] = "Concave";
const char GAME_TITLE[] = "Concave";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 1440;               // width of game in pixels
const UINT GAME_HEIGHT = 900;               // height of game in pixels

// game
const float FRAME_RATE = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations



const int noSpritesChruch = 8;
const int noSpritesCave = 2;

enum ImageType {
	//church
	churchBlood = 0,
	churchFloor = 1,
	churchDoor = 2,
	churchChest = 3,
	churchWallEast = 4,
	churchWallWest = 5,
	churchWallConnect = 6,
	churchWallPath = 7
};

enum ImageTypeCave
{
	//cave
	caveLava = 0,
	caveFloor = 1
};

//enum
#include <map>
const std::map<ImageType, CoordI> IMAGE_MAP
{
	//name - coordinates

	//church tiles
	{ImageType::churchWallEast,  CoordI{ 19,3 }},
	{ImageType::churchWallWest, CoordI{ 18,3 }},
	{ImageType::churchBlood, CoordI{ 10, 8 }},
	{ImageType::churchDoor, CoordI{ 4,1 }},
	{ImageType::churchFloor,  CoordI{ 12,0 }},
	{ImageType::churchChest, CoordI{ 10, 6 }},
	{ImageType::churchWallConnect, CoordI{ 3, 0 }},
	{ImageType::churchWallPath, CoordI{ 14, 6 }},

};

const std::map<ImageTypeCave, CoordI> IMAGE_MAP_CAVE
{
	//name - coordinates

	//cave tiles
	{ImageTypeCave::caveLava,  CoordI{ 12,1 }},
	{ImageTypeCave::caveFloor, CoordI{6,0}},
};


