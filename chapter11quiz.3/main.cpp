#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "utils.h"

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
};



void attackMonster(Monster &m, Player &p)
{
  if (p.isDead()) return;
  std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
  m.reduceHealth(p.getDamage());

  if (m.isDead())
  {
    std::cout << "You killed the " << m.getName() << ".\n";
    p.levelUp();
    std::cout << "You are now level " << p.getLevel() << ".\n";
    std::cout << "You found " << m.getGold() << " gold.\n";
    p.addGold(m.getGold());
  }
}

void attackPlayer(Monster &m, Player &p)
{
  if (m.isDead()) return;

  std::cout << "Monster " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
  p.reduceHealth(m.getDamage());
  std::cout << "Now you have " << p.getHealth() << " health.\n";
}

void fightMonster(Player &p)
{
  // First randomly generate a monster
  Monster m = Monster::getRandomMonster();
  std::cout << "(fightMonster)You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
  // While the monster isn't dead and the player isn't dead, the fight continues
  while(!p.isDead() && !m.isDead())
  {
    char choice;
    std::cout << "(R)un or (F)ight:";
    std::cin >> choice;
    if (choice == 'R' || choice == 'r')
    {
      // in case of "run" 50% chance of fleeing successfully
      if (getRandomNumber(1,2) == 1)
      {
        std::cout << "You successfully fled!.\n";
        return;
      }
      else
      {
        std::cout << "You failed to flee.\n";
        attackPlayer(m, p);
        continue;
      }
    }

    if (choice == 'F' or choice == 'f')
    {
      attackMonster(m, p);
      attackPlayer(m, p);
    }
  // In case of "fight" Player attacks first, monster attacks second
  }
}


int main()
{
  srand(static_cast<unsigned int>(time(0)));
	rand();
  /*for (int i = 0; i<10; ++i)
  {
    std::cout << getRandomNumber(0,2) << std::endl;
  }
  return 0;*/

  std::string name;
  std::cout << "Enter your name: " ;
  std::cin >> name;
  Player p(name);
  std::cout << "Welcome, " << name << ".\n";

  while (!p.isDead() && !p.hasWon())
    fightMonster(p);

  if (p.isDead())
  {
    std::cout << "You died at level " << p.getLevel() << " with " << p.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  else
  {
    std::cout << "You won the game with " << p.getGold() << " gold!\n";
  }

	//return 0;
}
