#include <iostream>

class Point{

    double m_x, m_y, m_z;

  public:

    Point(double x = 0.0, double y = 0.0, double z=0.0): m_x(x), m_y(y), m_z(z) {}

    double getx(){return m_x;}
    double gety(){return m_y;}
    double getz(){return m_z;}

    //overload unary operator+
    Point operator+()
    {
      if (m_x < 0) {m_x = -m_x;}
      if (m_y < 0) {m_y = -m_y;}
      if (m_z < 0) {m_z = -m_z;}
      return Point(m_x, m_y, m_z);
    }

    void print()
    {
      std::cout << "(" << m_x << "," << m_y << "," << m_z << ")" << std::endl;
    }
};


int main()
{
  Point p1(4.9,2.0,3.1);
  p1.print();
  Point p2(-2.2, 3.3, -4.4);
  p2.print();
  (+p2).print();

  return 0;
}
