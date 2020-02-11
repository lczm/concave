#include "tiles.h"

Tiles::Tiles()
{}

Tiles::~Tiles()
{}

void Tiles::initialize(int rows, int cols)
{
	Tiles::rows = rows;
	Tiles::cols = cols;
	spriteArray.resize(rows * cols);
	hLinesArray.resize(rows * cols);
	vLinesArray.resize(rows * cols);
}

void Tiles::set(int row, int col, Sprite* sprite, Lines hLines, Lines vLines)
{
	setSprite(row, col, sprite);
	setLines(row, col, hLines, vLines);
}

void Tiles::setSprite(int row, int col, Sprite* sprite)
{
	spriteArray[mapIndex(row, col)] = sprite;
}

void Tiles::setLines(int row, int col, Lines hLines, Lines vLines)
{
	hLinesArray[mapIndex(col, row)] = hLines; // Done intentionally
	vLinesArray[mapIndex(row, col)] = vLines;
}

Sprite*& Tiles::getSprite(int row, int col)
{
	return spriteArray[mapIndex(row, col)];
}

Lines& Tiles::getHLines(int row, int col)
{
	return hLinesArray[mapIndex(col, row)]; // (Again) Done intentionally
}

Lines& Tiles::getVLines(int row, int col)
{
	return vLinesArray[mapIndex(row, col)];
}

int Tiles::mapIndex(int row, int col)
{
	return row * cols + col;
}