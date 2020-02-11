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
	set<LineI> hLineSet;
	set<LineI> vLineSet;
	vector<vector<set<LineI>::iterator>> hLineItersArray;
	vector<vector<set<LineI>::iterator>> vLineItersArray;
public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<Sprite*>& getSpriteArray() { return spriteArray; }
	set<LineI>& getHLinesSet() { return hLineSet; }
	set<LineI>& getVLinesSet() { return vLineSet; }
	vector<vector<set<LineI>::iterator>>& getHLineIteratorArray() { return hLineItersArray; }
	vector<vector<set<LineI>::iterator>>& getVLineIteratorArray() { return vLineItersArray; }
};