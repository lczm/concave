#pragma once
#include "constants.h"
#include "level.h"
#include "enemies.h"
#include "movementSystem.h"

void enemyAttackState(Level* level, int index);
void enemyDieState(Level* level, int index);
void enemyIdleState(Level* level, int index);
void enemyWalkState(Level* level, int index);
void enemyGetHitState(Level* level, int index);