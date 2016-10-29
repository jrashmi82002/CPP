#include <iostream>
#include <cmath>

class Point2d {

    double m_x;
    double m_y;

  public:

    Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}

    void print()
    {
      std::cout << "Point2d(" << m_x << "," << m_y << ");" << std::endl;
    }

//add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance between them.
//Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as
//sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). The sqrt function lives in header cmath.
    double distanceTo(Point2d point)
    {
      return sqrt((m_x - point.m_x)*(m_x - point.m_x) + (m_y - point.m_y)*(m_y - point.m_y));
    }

    friend double distanceFrom(Point2d point1, Point2d point2);
};

//a non-member friend function distanceFrom” that takes two Points as parameters

double distanceFrom(Point2d point1, Point2d point2)
{
  return sqrt((point1.m_x - point2.m_x)*(point1.m_x - point2.m_x) + (point1.m_y - point2.m_y)*(point1.m_y - point2.m_y));
}



int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}
