#include <iostream>
#include <string>

class Fruit{

  std::string m_name;
  std::string m_collor;

public:

  Fruit(std::string name, std::string collor) : m_name(name), m_collor(collor){}

  std::string getName(){return m_name;}
  std::string getCollor(){return m_collor;}

};

class Apple : public Fruit
{
  double m_fiber;

public:

  Apple(std::string name, std::string color, double fiber):
  Fruit(name, color), m_fiber(fiber){}

  double getFiber(){return m_fiber;}
  friend std::ostream& operator<<(std::ostream &out, Apple &apple);

};

std::ostream& operator<<(std::ostream &out, Apple &apple)
{
  out << "Apple(" << apple.getName() << ", " << apple.getCollor() << ", " << apple.getFiber() << ")" << std::endl;
  return out;
}

class Banana : public Fruit
{
public:
  
  Banana(std::string name, std::string color): Fruit(name, color){}

  friend std::ostream& operator<<(std::ostream &out, Banana &banana);
};

std::ostream& operator<<(std::ostream &out, Banana &banana)
{
  out << "Banana(" << banana.getName() << ", " << banana.getCollor() << ")" << std::endl;
  return out;
}


int main()
{
	Apple a("Red delicious", "red", 4.2);
	std::cout << a;

  Banana b("Cavendish", "yellow");
	std::cout << b;

	return 0;
}
