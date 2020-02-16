#pragma once
#include "constants.h"
#include "level.h"
#include "players.h"
#include "movementSystem.h"

void playerAttackState(Level* level, int index);
void playerDieState(Level* level, int index);
void playerIdleState(Level* level, int index);
void playerWalkState(Level* level, int index);
void playerGetHitState(Level* level, int index);
void playerMagicFireState(Level* level, int index);
void playerMagicSmokeState(Level* level, int index);
