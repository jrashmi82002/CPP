#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Creature.h"

class Creature;

class Player : public Creature
{
  int m_level = 1;

public:

  //constructor The player has
  // a custom name (entered by the user), uses symbol '@', has 10 health, does 1 damage to start, and has no gold.
  Player(std::string name): Creature(name, '@', 10, 1, 0){}

    //function called levelUp() that increases the player's level and damage by 1.
  void levelUp();
  int getLevel() {return m_level;}
  bool hasWon();
};


#endif
