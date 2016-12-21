#include <iostream>
#include <string>

class Vehicle{

  double m_consumption;
  double m_speed;
  std::string m_fuelType;

public:

  Vehicle(double consumption = 10, double speed = 100, std::string fuelType = "oil"):
    m_consumption(consumption), m_speed(speed), m_fuelType(fuelType){}

  //getters
  double getConsumption(){return m_consumption;}
  double getSpeed(){return m_speed;}
  std::string getFuelType(){return m_fuelType;}

  //setters
  void setConsumption(double consumption){m_consumption = consumption;}
  void setSpeed(double speed){m_speed = speed;}

  void print()
  {
    std::cout << "Average speed is " << m_speed << " km/h" << ", fuel consumption " << m_consumption <<
    " l/km, fuel type is " << m_fuelType << ".\n";
  }


};


int main()
{

  Vehicle car;
  car.print();


  return 0;
}
