#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

class Objects
{
private:
	int capacity, size;
	// Position
	vector<CoordF> positionArray;
	// Sprite
	vector<Sprite*> spriteArray;
	// Collision
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;
public:
	Objects(); ~Objects();
	void initialize(int capacity);
	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	// Position
	vector<CoordF>& getPositionArray() { return positionArray; }
	// Sprite
	vector<Sprite*> getSpriteArray() { return spriteArray; }
	// Collision
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
};