#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
    Point m_p1;
    int m_r;

  public:

    Circle(const Point &p1, int r): m_p1(p1), m_r(r){}

    virtual std::ostream& print(std::ostream &out) override;

		int getRadius() {return m_r;}
};


#endif
