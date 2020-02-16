#include "modifiers.h"

// Increase max health by %% amount
void increaseMaxHealth(int index, Players& players, float amount) {
    int& maxHealth = players.getMaxHealthArray()[index];
    maxHealth *= amount;
}

// Increase max mana by %% amount
void increaseMaxMana(int index, Players& players, float amount) {
    int& maxMana = players.getMaxManaArray()[index];
    maxMana *= amount;
}

// Increase speed of everything by %% amount
void increaseAttackSpeed(int index, Players& players, float amount) {
    float& delay = players.getDelayArray()[index];
    delay *= amount;
}

// Increase movement speed
void increaseMovementSpeed(int index, Players& players, float amount) {
    float& velocity = players.getStaticVelocityArray()[index];
    velocity *= amount;
}

// Increase maximum projectiles
void increaseProjectilesAmount(int index, Players& players, int amount) {
    int& currentAmount = players.getNoProjArray()[index];
    currentAmount = amount;
}

void increaseProjectileSize(int index, Projectiles& projectiles, int amount)
{
    float& size = projectiles.getSizeArray()[index];
    size *= amount;
}

// Increase damage
void increaseDamage(int index, Players& players, float amount) {
    float& damage = players.getDamageArray()[index];
    damage *= amount;
}
