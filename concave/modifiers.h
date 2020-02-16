#pragma once
#include "players.h"

// Increase max health by %% amount
void increaseMaxHealth(int index, Players& players, float amount);

// Increase max mana by %% amount
void increaseMaxMana(int index, Players& players, float amount);

// Increase speed of everything by %% amount
void increaseSpeed(int index, Players& players, float amount);

// Increase maximum projectiles
void increaseProjectilesAmount(int index, Players& players, int amount);

// Increase damage
void increaseDamage(int index, Players& players, float amount);
