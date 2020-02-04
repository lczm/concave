#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//-----------------------------------------------
//                Our Constants
//-----------------------------------------------
struct CoordI { int x, y; };
enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
// enum DIRECTION16 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };

//-----------------------------------------------
//               Other Constants
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