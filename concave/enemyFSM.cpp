#include "enemyFSM.h"

void enemyAttackState(Level* level, int index)
{}

void enemyDieState(Level* level, int index)
{
}

void enemyIdleState(Level* level, int index)
{

}

void enemyWalkState(Level* level, int index)
{
	float frameTime = level->frameTime;
	Players& players = level->getPlayers();
	CoordF& pPos = players.getPositionArray()[0];
	Enemies& enemies = level->getEnemies();
	CoordF& ePos = enemies.getPositionArray()[index];
	CoordF& eDestPos = enemies.getDestPositionArray()[index];
	AnimImage*& eAnimImage = enemies.getAnimImageArray()[index];
	int& eState = enemies.getStateArray()[index];
	int& eFrameNo = enemies.getFrameNoArray()[index];
	float& eTimer = enemies.getTimerArray()[index];
	float& eDelay = enemies.getDelayArray()[index];
	float& eRotation = enemies.getRotationArray()[index];
	//FSM& eFSM = enemies.getFSMArray()[index];

	//eDestPos = pPos;
	eRotation = calculateRotation(ePos, pPos);

	eTimer += frameTime;
	if (eTimer >= eDelay) {
		eTimer -= eDelay;
		eFrameNo += 1;
		if (eFrameNo >= eAnimImage->getEndFrame(eState)) {
			eFrameNo = 0;
		}
	}
}

void enemyGetHitState(Level* level, int index)
{}
