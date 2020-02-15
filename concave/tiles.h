#pragma once
#include "constants.h"
#include "image.h"

class Tiles
{
private:
	int rows, cols;
	vector<Sprite*> spriteArray;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;
public:
	Tiles(); ~Tiles();
	void initialize(int rows, int cols);
	void set(int row, int col, Sprite* sprite, Lines hLines, Lines vLines);
	void setSprite(int row, int col, Sprite* sprite);
	void setLines(int row, int col, Lines hLines, Lines vLines);
	Sprite*& getSprite(int row, int col);
	Lines& getHLines(int row, int col);
	Lines& getVLines(int row, int col);
private:
	int mapIndex(int row, int col);
public:
	int getRows() { return rows; }
	int getCols() { return cols; }
};