#include "movementSystem.h"

float calculateDistanceSquared(CoordF src, CoordF dest)
{
	float dx = dest.x - src.x;
	float dy = dest.y - src.y;
	return dx * dx + dy * dy;
}

float calculateDistance(CoordF src, CoordF dest)
{
	return sqrt(calculateDistanceSquared(src, dest));
}

bool fastSquareProximityCheck(CoordF src, CoordF dest, float length)
{
	return ((abs(src.x - dest.x) < length) && (abs(src.y - dest.y) < length));
}

int modulo(int val, int m) {
	int mod = val % m;
	if (val < 0) mod += m;
	return mod;
}

float calculateRotation(CoordF src, CoordF dest)
{
	float dx = dest.x - src.x;
	float dy = dest.y - src.y;
	return atan2(dy, dx);
}

int rotationToDirection(float rotation, int n)
{
	int direction;
	rotation -= PI / 2;
	rotation /= PI * 2 / n;
	direction = round(rotation);
	direction = modulo(direction, n);
	return direction;
}

int rotationToDirection8(float rotation)
{
	rotation += 25.565;
	return rotationToDirection(rotation, 8);
}

int rotationToDirection16(float rotation)
{
	rotation += 51.13;
	return rotationToDirection(rotation, 16);
}

CoordF calculateUnitDelta(float rotation)
{
	float dx = cos(rotation);
	float dy = sin(rotation);
	return CoordF{ dx, dy };
}

void updateDirectionArray(int size, vector<float>& rotationArray, vector<int>& directionArray)
{
	for (int i = 0; i < size; i++) {
		directionArray[i] = rotationToDirection8(rotationArray[i]);
	}
}

void calculateDeltaArray(int size, vector<CoordF>& deltaArray, vector<float>& rotationArray, vector<float>& velocityArray, float frameTime)
{
	for (int i = 0; i < size; i++) {
		deltaArray[i] = calculateUnitDelta(rotationArray[i]) * velocityArray[i] * frameTime;
	}
}

void updatePositionArray(int size, vector<CoordF>& positionArray, vector<CoordF>& deltaArray)
{
	for (int i = 0; i < size; i++) {
		positionArray[i] += deltaArray[i];
	}
}