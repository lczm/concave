#pragma once
#include "image.h"
#include <vector>
using namespace std;

class Components
{
	virtual void initialize(int size) = 0;
	virtual void pop(int index) = 0;
};

class Collisions: Components
{
private:
	vector<Line>* hLinesArray;
	vector<Line>* vLinesArray;
public:
	void initialize(int size);
	void pop(int index);
	vector<Line> getHLines(int index);
	vector<Line> getVLines(int index);
};

class Renders: Components
{
private:
	Sprite* spriteArray;
public:
	void initialize(int size);
	void pop(int index);
	Sprite getSprite(int index);
};