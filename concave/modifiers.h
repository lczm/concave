#pragma once
#include "players.h"
#include "projectiles.h"

// Increase max health by %% amount
void increaseMaxHealth(int index, Players& players, float amount);

// Increase max mana by %% amount
void increaseMaxMana(int index, Players& players, float amount);

// Increase speed of everything by %% amount
void increaseAttackSpeed(int index, Players& players, float amount);

// Increase movement speed
void increaseMovementSpeed(int index, Players& players, float amount);

// Increase maximum projectiles
void increaseProjectilesAmount(int index, Players& players, int amount);

// Increase projectile size
void increaseProjectilesSize(int index, Projectiles& projectiles, int amount);

// Increase projectile speed
void increaseProjectilesSpeed(int index, Projectiles& projectiles, int amount);

// Increase damage
void increaseDamage(int index, Players& players, float amount);

