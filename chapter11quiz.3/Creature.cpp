#include "Creature.h"

void Creature::reduceHealth(int healthReducer)
{
  m_health -= healthReducer;
}

bool Creature::isDead()
{
  return m_health <= 0;
}

void Creature::addGold(int gold)
{
  m_gold += gold;
}
