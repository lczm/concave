#pragma once
#include "constants.h"
#include "image.h"
#include <cassert>

class Tile
{
public:
	struct Line { float lower, upper, shift; };
private:
	Image* image;
	CoordI coord;
	vector<Line> hLines;
	vector<Line> vLines;
public:
	Tile();
	~Tile();
	void initialize(Image* image, CoordI coord, vector<Line> hLines, vector<Line> vLines);
	SpriteData getSpriteData();
};

class TileGrid
{
private:
	Tile** tiles;
	int rows, cols;
public:
	TileGrid();
	~TileGrid();
	void initialize(int rows, int cols);
	void set(int row, int col, Tile* tile);
	Tile* get(int row, int col);
	int getRows() { return rows; }
	int getCols() { return cols; }
private:
	int mapIndex(int row, int col);
};