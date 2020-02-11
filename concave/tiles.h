#pragma once
#include "component.h"

class Tiles
{
private:
	int rows, cols;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;
	vector<Sprite*> spriteArray;
public:
	Tiles(); ~Tiles();
	void initialize(int rows, int cols);
	void set(int row, int col, Lines hLines, Lines vLines, Sprite* sprite);
	void setLines(int row, int col, Lines hLines, Lines vLines);
	void setSprite(int row, int col, Sprite* sprite);
	Lines& getHLines(int row, int col);
	Lines& getVLines(int row, int col);
	Sprite*& getSprite(int row, int col);
private:
	int mapIndex(int row, int col);
public:
	int getRows() { return rows; }
	int getCols() { return cols; }
};