#pragma once
#include "input.h"
#include "component.h"

class State;

class Players
{
private:
	int capacity, size;
	// CoordF* positions;
	// CoordF* destinationPositions;
	// Collision* hCollisions;
	// Collision* vCollisions;
	// RenderAnim* renders;
	// RenderInfo* rendersInfos;

    // Movement* movements;
	// Health* healths;
	// Mana* manas;

	vector<CoordF> positionArray;
	vector<CoordF> destPositionArray;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;

	vector<State*> stateArray;
	vector<AnimImage*> imageArray;
	vector<RenderInfo> imageInfoArray;

	vector<Movement> movementArray;
	vector<Health> healthArray;
	vector<Mana> manaArray;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* image, RenderInfo imageInfo, 
		State* state, Lines hLines, Lines vLines);
 	void pop(int index);

	// void setPosition(int index, CoordF position);
	// void setDestPosition(int index, CoordF position);
	// void setCollision(int index, Collision hCollision, Collision vCollision);
	// void setRender(int index, RenderAnim);
	// void setState(int index, State* state);
    // void setMovement(int index, Movement movement);
	// CoordF getPosition(int index);
	// CoordF getDestPositions(int index);
	// Collision getHCollision(int index);
	// Collision getVCollision(int index);
	// RenderAnim getRender(int index);
	// RenderInfo getRenderInfo(int index);
    // Movement getMovements(int index);
	// Health getHealth(int index);
	// Mana getMana(int index);
public:
	void setPosition(int index, CoordF position);
	void setDestPosition(int index, CoordF destPosition);
	void setMovement(int index, Movement movement);
public:
	int getSize() { return size; }
 	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<CoordF>& getDestPositionArray() { return destPositionArray; }
 	vector<Lines>& getHLinesArray() { return hLinesArray; }
 	vector<Lines>& getVLinesArray() { return vLinesArray; }
	vector<State*>& getStateArray() { return stateArray; }
 	vector<AnimImage*>& getImageArray() { return imageArray; }
	vector<RenderInfo>& getImageInfoArray() { return imageInfoArray; }
	vector<Movement>& getMovementArray() { return movementArray; }

	// CoordF* getPositions() { return positions; }
	// CoordF* getDestPositions() { return destinationPositions; }
	// Collision* getHCollisions() { return hCollisions; }
	// Collision* getVCollisions() { return vCollisions; }
	// vector<State*> getStates() { return states; }
	// RenderAnim* getRenders() { return renders; }
	// RenderInfo* getRenderInfos() { return rendersInfos; }
	// Health* getHealths() { return healths; }
	// Mana* getManas() { return manas; }
};

// public:
// 	Players(); ~Players();
// 	void initialize(int capacity);
// 	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
// 	void pop(int index);
// public:
// 	int getSize() { return size; }
// 	vector<CoordF>& getPositionArray() { return positionArray; }
// 	vector<Sprite*>& getSpriteArray() { return spriteArray; }
// 	vector<Lines>& getHLinesArray() { return hLinesArray; }
// 	vector<Lines>& getVLinesArray() { return vLinesArray; }
// };
// 