#pragma once
#include "component.h"
#include <vector>
#include <set>
using namespace std;

class Projectiles
{
private:
	int capacity, size;
	vector<CoordF> positionArray;
	vector<Sprite*> spriteArray;
	LineSet hLineSet;
	LineSet vLineSet;
	vector<LineSetIters> hLineItersArray;
	vector<LineSetIters> vLineItersArray;
public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<Sprite*>& getSpriteArray() { return spriteArray; }
	LineSet& getHLinesSet() { return hLineSet; }
	LineSet& getVLinesSet() { return vLineSet; }
	vector<LineSetIters>& getHLineIteratorArray() { return hLineItersArray; }
	vector<LineSetIters>& getVLineIteratorArray() { return vLineItersArray; }
};