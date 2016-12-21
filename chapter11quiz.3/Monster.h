#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Creature.h"

class Creature;

class Monster : public Creature
{

  public:

    struct MonsterData{
      std::string name;
      char symbol;
      int health;
      int damage;
      int gold;
    };

    enum Type{
      DRAGON,
      ORC,
      SLIM,
      MAX_TYPES
    };

    static MonsterData monsterData[MAX_TYPES];

    Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol,
      monsterData[type].health, monsterData[type].damage, monsterData[type].gold){}

    static Monster getRandomMonster();
};


#endif
