#include "Monster.h"
#include "Creature.h"
#include "utils.h"

Monster Monster::getRandomMonster()
{
  return Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES-1)));
}
