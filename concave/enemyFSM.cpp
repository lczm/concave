#include "enemyFSM.h"

void enemyAttackState(Level* level, int index)
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
	FSM& eFSM = enemies.getFSMArray()[index];

	eTimer += frameTime;
	if (eTimer >= eDelay) {
		eTimer -= eDelay;
		eFrameNo += 1;
		if (eFrameNo >= eAnimImage->getEndFrame(eState)) {
			eTimer = 0; eFrameNo = 0;
			eFSM = enemyWalkState;
			eState = UNIT_STATE_WALK;
		}
	}
}

void enemyDieState(Level* level, int index)
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
	FSM& eFSM = enemies.getFSMArray()[index];
	int& health = enemies.getHealthArray()[index];

	eTimer += frameTime;
	if (eTimer >= eDelay) {
		eTimer -= eDelay;
		eFrameNo += 1;
		if (eFrameNo >= eAnimImage->getEndFrame(eState)) {
			level->getEnemies().pop(index);
		}
	}
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
	FSM& eFSM = enemies.getFSMArray()[index];
	int& range = enemies.getRangeArray()[index];
	int& health = enemies.getHealthArray()[index];

	//eDestPos = pPos;
	eRotation = calculateRotation(ePos, pPos);

	if (fastSquareProximityCheck(ePos, pPos, range)) {
		eTimer = 0; eFrameNo = 0;
		eFSM = enemyAttackState;
		eState = UNIT_STATE_ATTACK;
		return;
	}

	if (health <= 0) {
		eFSM = enemyDieState;
		eState = UNIT_STATE_DIE;
		return;
	}

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
	FSM& eFSM = enemies.getFSMArray()[index];
	int& range = enemies.getRangeArray()[index];
	int& health = enemies.getHealthArray()[index];

	eTimer += frameTime;
	if (eTimer >= eDelay) {
		eTimer -= eDelay;
		eFrameNo += 1;
		if (eFrameNo >= eAnimImage->getEndFrame(eState)) {
			eTimer = 0; eFrameNo = 0;
			eFSM = enemyWalkState;
			eState = UNIT_STATE_WALK;
		}
	}
}
