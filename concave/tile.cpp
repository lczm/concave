#include "tile.h"

Tile::Tile()
{}

Tile::~Tile()
{}

void Tile::initialize(Image* image, CoordI coord, vector<Tile::Line> hLines, vector<Tile::Line> vLines)
{
	Tile::image = image;
	Tile::coord = coord;
	Tile::hLines = hLines;
	Tile::vLines = vLines;
}

TileGrid::TileGrid()
{}

TileGrid::~TileGrid()
{
	delete[] tiles;
}

void TileGrid::initialize(int rows, int cols)
{
	TileGrid::rows = rows;
	TileGrid::cols = cols;
	tiles = new Tile * [rows * cols];
}

void TileGrid::set(int row, int col, Tile* tile)
{
	tiles[mapIndex(row, col)] = tile;
}

Tile* TileGrid::get(int row, int col)
{
	return tiles[mapIndex(row, col)];
}

int TileGrid::mapIndex(int row, int col)
{
	assert(0 <= row && row < rows);
	assert(0 <= col && col < cols);
	return row * cols + col;
}