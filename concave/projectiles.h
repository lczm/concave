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
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;
public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<Sprite*>& getSpriteArray() { return spriteArray; }
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
};