#include <iostream>
#include <string>

class Creature{

protected:

  std::string m_name;
  char m_symbol;
  int m_health;
  int m_damage;
  int m_gold;

public:
  //constructor
  Creature(std::string name, char symbol, int health = 0, int damage = 0, int gold = 0):
    m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold){}

  //getters
  std::string getName() {return m_name;}
  char getSymbol() {return m_symbol;}
  int getHealth() {return m_health;}
  int getDamage() {return m_damage;}
  int getGold() {return m_gold;}

  void reduceHealth(int healthReducer)
  {
    m_health -= healthReducer;
  }

  bool isDead()
  {
    return m_health <= 0;
  }

  void addGold(int gold)
  {
    m_gold += gold;
  }

};

class Player : public Creature
{
  int m_level;

public:

  //constructor The player has
  // a custom name (entered by the user), uses symbol '@', has 10 health, does 1 damage to start, and has no gold.
  Player(std::string name): Creature(name, '@', 10, 1, 0){}

    //function called levelUp() that increases the player's level and damage by 1.
  void levelUp()
    {
      m_level += 1;
      m_damage += 1;
    }

    int getLevel() {return m_level;}

    //function called hasWon() that returns true if the player has reached level 20.
    bool hasWon()
    {
      return m_level >= 20;
    }

};



int main()
{
  std::string name;
	Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

  std::cout << "Enter your name: " ;
  std::cin >> name;

  Player player(name);
  std::cout << "Welcome, " << name << ".\n";
  std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";


	return 0;
}
