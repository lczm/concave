#pragma once
#include "component.h"

class Players
{
private:
	int capacity, size;
	vector<CoordF> positionArray;
	vector<Sprite*> spriteArray;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, Lines hLines, Lines vLines, Sprite* sprite);
	void pop(int index);
public:
	int getSize() { return size; }
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<Sprite*>& getSpriteArray() { return spriteArray; }
	vector<Lines>& getHLinesArray() { return hLinesArray; }
	vector<Lines>& getVLinesArray() { return vLinesArray; }
};