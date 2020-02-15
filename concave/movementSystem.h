#pragma once
#include "constants.h"
#include <cmath>

float calculateDistanceSquared(CoordF src, CoordF dest);
float calculateDistance(CoordF src, CoordF dest);
bool fastSquareProximityCheck(CoordF src, CoordF dest, float length);

float calculateRotation(CoordF src, CoordF dest);
int rotationToDirection(float rotation, int n);
int rotationToDirection8(float rotation);
int rotationToDirection16(float rotation);
CoordF calculateUnitDelta(float rotation);

void updateDirectionArray(int size, vector<float>& rotationArray, vector<int>& directionArray);
void calculateDeltaArray(int size, vector<CoordF>& deltaArray, vector<float>& rotationArray, vector<float>& velocityArray, float frameTime);
void updatePositionArray(int size, vector<CoordF>& positionArray, vector<CoordF>& deltaArray);
