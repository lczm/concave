#include "tiles.h"

Tiles::Tiles()
{}

Tiles::~Tiles()
{}

void Tiles::initialize(int rows, int cols)
{
	Tiles::rows = rows;
	Tiles::cols = cols;
	hLinesArray.resize(rows * cols);
	vLinesArray.resize(rows * cols);
	spriteArray.resize(rows * cols);
}

void Tiles::set(int row, int col, Lines hLines, Lines vLines, Sprite* sprite)
{
	setLines(row, col, hLines, vLines);
	setSprite(row, col, sprite);
}

void Tiles::setLines(int row, int col, Lines hLines, Lines vLines)
{
	hLinesArray[mapIndex(col, row)] = hLines; // Done intentionally
	vLinesArray[mapIndex(row, col)] = vLines;
}

void Tiles::setSprite(int row, int col, Sprite* sprite)
{
	spriteArray[mapIndex(row, col)] = sprite;
}

Lines& Tiles::getHLines(int row, int col)
{
	return hLinesArray[mapIndex(col, row)]; // (Again) Done intentionally
}

Lines& Tiles::getVLines(int row, int col)
{
	return vLinesArray[mapIndex(row, col)];
}

Sprite*& Tiles::getSprite(int row, int col)
{
	return spriteArray[mapIndex(row, col)];
}

int Tiles::mapIndex(int row, int col)
{
	return row * cols + col;
}