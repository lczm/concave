#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
#include <set>
using namespace std;

class Projectiles
{
private:
	int capacity, size;
	float velocity;
	float projSize;
	// Position
	vector<CoordF> positionArray;
	// Animation
	vector<AnimImage*> animImageArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray;
	// Movement
	vector<float> rotationArray;
	vector<float> velocityArray;
	// Collision
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;
	// Size of sprite
	vector<float> sizeArray;
public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, Lines hLines, Lines vLines, float rotation);
	void pop(int index);
public:
	int getSize() { return size; }
	float& getVelocity() { return velocity; }
	float& getProjSize() { return projSize; }
	// Postition
	vector<CoordF>& getPositionArray() { return positionArray; }
	// Animation
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	// Movement
	vector<float>& getRotationArray() { return rotationArray; }
	vector<float>& getVelocityArray() { return velocityArray; }
	// Collision
	vector<Lines>& getHLinesArray() { return hLinesArray; }
	vector<Lines>& getVLinesArray() { return vLinesArray; }
	// Sprite data size
	vector<float>& getSizeArray() { return sizeArray; }
};