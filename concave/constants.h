#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

//-----------------------------------------------
//                   Data
//-----------------------------------------------
// Coordinates / Positions
template<typename T>
struct Coord
{
	T x, y;
	Coord operator+(const Coord& coord) { return Coord{ x + coord.x, y + coord.y }; }
	Coord operator-(const Coord& coord) { return Coord{ x - coord.x, y - coord.y }; }
	Coord& operator+=(const Coord& coord) { x += coord.x; y += coord.y; return *this; }
	Coord& operator-=(const Coord& coord) { x -= coord.x; y -= coord.y; return *this; }
	Coord operator*(T val) { return Coord{ x * val, y * val }; }
};
typedef Coord<int> CoordI;
typedef Coord<float> CoordF;
// Line (Collision)
struct Line {
	float lower, upper, shift;
	Line() {}
	Line(float lower, float upper, float shift) { Line::lower = lower; Line::upper = upper; Line::shift = shift; }
	bool operator<(const Line& other) const { return shift < other.shift; }
};
struct LineI : Line {
	int id;
	LineI() {}
	LineI(Line line, int id) : Line(line) { LineI::id = id; }
	LineI(float lower, float upper, float shift, int id) : Line(lower, upper, shift) { LineI::id = id; }
};
typedef vector<Line> Lines;
typedef set<LineI> LineISet;
typedef LineISet::iterator LineISetIter;
typedef vector<LineISetIter> LineISetIters;

// Direction
namespace DIRECTION8 {
	enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST }; }
namespace DIRECTION16 {
	enum DIRECTION16 { SOUTH, SOUTH_SOUTH_WEST, SOUTH_WEST, WEST_SOUTH_WEST, WEST, WEST_NORTH_WEST, NORTH_WEST, NORTH_NORTH_WEST, NORTH, NORTH_NORTH_EAST, NORTH_EAST, EAST_NORTH_EAST, EAST, EASE_SOUTH_EAST, SOUTH_EAST, SOUTH_SOUTH_EAST }; }

// State Function Pointer
class Level;
typedef void (*FSM)(Level* level, int index);

//struct RenderInfo
//{
//	int state;
//	int direction;
//	int frameNo;
//	float timer = 0;
//	float delay = float(1.00);
//};

//struct Movement
//{
//	float moveX;
//	float moveY;
//	float rotation;
//};

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

//namespace STATE {
//    enum PLAYER { ATTACK, DIE, IDLE, WALK, GET_HIT, FIRE };
//}

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
const char IMAGE_BARRELITEMS_DUNGEON[] = "sprites/items.png";
const char IMAGE_DEADITEMS_DUNGEON[] = "sprites/deadMan.png";
const char IMAGE_ARMOURITEMS_DUNGEON[] = "sprites/armour.png";
const char IMAGE_WITCHITEMS_DUNGEON[] = "sprites/witchStuff.png";

//-----------------------------------------------
//                Image (Units)
//-----------------------------------------------
const char IMAGE_UNIT_WARRIOR[] = "sprites/unit_warrior.png";
const char IMAGE_UNIT_MAGE[] = "sprites/unit_mage.png";

//-----------------------------------------------
//              Image (Projectiles)
//-----------------------------------------------
const char IMAGE_PROJECTILE_FIREBALL[] = "sprites/projectile_fireball.png";

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

const double PI = 3.1415926535897;


//-----------------------------------------------
//               Room Generation
//-----------------------------------------------
const int noSpritesChruch = 11;
const int noSpritesCave = 2;
const int itemsToSpawn = 1;


enum RoomType
{
	loot =2,
	trap = 3,
	barrel = 4,
	armoury = 1
};


enum roomTypesCsv
{
	roomtypes = 0,
	accessible = 1,
	no = 2,
	left = 3,
	right = 4,
	top = 5,
	bottom = 6,
	assign = 7,
	flooring = 8,
	file = 9
};

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
	//add church door open here
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


const const char ROOM_INFO[] = "text\\roomTypes.csv";