#include <string>
#include <iostream>

class Monster {

public:

  enum MonsterType {
    MONSTERTYPE_DRAGON,
    MONSTERTYPE_GOBLIN,
    MONSTERTYPE_OGRE,
    MONSTERTYPE_ORC,
    MONSTERTYPE_SKELETON,
    MONSTERTYPE_TROLL,
    MONSTERTYPE_VAMPIRE,
    MONSTERTYPE_ZOMBIE,
    MONSTERTYPE_MAX_MONSTER_TYPES
  };

private:

  MonsterType m_type;
  std::string m_name;
  std::string m_roar;
  int m_hitPoints;

public:

  Monster(MonsterType type, std::string name, std::string roar, int hitPoints) :
  m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints) {}

  std::string getTypeString()
  {
    std::string monsterName;
    if (m_type == 0){return monsterName = "Dragon";}
    else if (m_type == 1){return monsterName = "Goblin";}
    else if (m_type == 2){return monsterName = "Ogre";}
    else if (m_type == 3){return monsterName = "Orc";}
    else if (m_type == 4){return monsterName = "Skeleton";}
    else if (m_type == 5){return monsterName = "Troll";}
    else if (m_type == 6){return monsterName = "Vampire";}
    else if (m_type == 7){return monsterName = "Zombie";}
    else {return monsterName = "Don't know this Monster type!\n";}
  }

  void print()
  {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
  }

};

class MonsterGenerator{

public:

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
static int getRandomNumber(int min, int max)
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  // evenly distribute the random number across our range
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

static Monster generateMonster()
{
  int randomMonsterType = getRandomNumber(0,Monster::MONSTERTYPE_MAX_MONSTER_TYPES-1);
  Monster::MonsterType type = static_cast<Monster::MonsterType>(randomMonsterType);

  int randomHitPoints = getRandomNumber(1, 100);
  static std::string s_names[6]{"Randolph", "Zeno", "Mike", "Mickey", "Tina", "Derek"};
  static std::string s_roars[6]{"grrrrr", "auuuuuu", "grhhhhhh", "hhhhhhhhh", "psssss", "siiiksiik"};
  return Monster(type, s_names[getRandomNumber(0,5)], s_roars[getRandomNumber(0,5)], randomHitPoints);
}

};

int main()
{
  //Monster skele(Monster::MONSTERTYPE_SKELETON, "Bones", "*rattle*", 4);
  //skele.print();
  //Monster skele1(Monster::MONSTERTYPE_VAMPIRE, "BloodDrinker", "*hhhhhhhhhh*", 7);
  //skele1.print();
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand(); // If using Visual Studio, discard first random value

  Monster m = MonsterGenerator::generateMonster();
  m.print();

  return 0;
}
