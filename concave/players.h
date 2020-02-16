#pragma once
#include "constants.h"
#include "image.h"

class Players
{
private:
	int capacity, size;
	// Position
	vector<CoordF> positionArray;
	vector<CoordF> destPositionArray;
	// Animation
	vector<AnimImage*> animImageArray;
	vector<int> stateArray;
	vector<int> directionArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray; // Temporary
	vector<FSM> fsmArray;
	// Movement
	vector<float> rotationArray;
	vector<float> velocityArray;
	// Collision
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;
	// Attributes
	vector<int> healthArray;
	vector<int> maxHealthArray;
	vector<int> manaArray;
	vector<int> maxManaArray;
	vector<int> damageArray;
	vector<int> noProjArray;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float velocity, Lines hLines, Lines vLines, int health, int maxHealth, int mana, int maxMana);
	void pop(int index);
public:
	int getSize() { return size; }
	// Position
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<CoordF>& getDestPositionArray() { return destPositionArray; }
	// Animation
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	vector<int>& getStateArray() { return stateArray; }
	vector<int>& getDirectionArray() { return directionArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	vector<FSM>& getFSMArray() { return fsmArray; }
	// Movement
	vector<float>& getRotationArray() { return rotationArray; }
	vector<float>& getVelocityArray() { return velocityArray; }
	// Collision
	vector<Lines>& getHLinesArray() { return hLinesArray; }
	vector<Lines>& getVLinesArray() { return vLinesArray; }
	// Attributes
	vector<int>& getHealthArray() { return healthArray; };
	vector<int>& getMaxHealthArray() { return maxHealthArray; };
	vector<int>& getManaArray() { return manaArray; };
	vector<int>& getMaxManaArray() { return maxManaArray; };
	vector<int>& getDamageArray() { return damageArray; }
	vector<int>& getNoProjArray() { return noProjArray; }
};