#ifndef CREATURE_H
#define CREATURE_H
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

  void reduceHealth(int healthReducer);
  bool isDead();
  void addGold(int gold);
  
};

  #endif
