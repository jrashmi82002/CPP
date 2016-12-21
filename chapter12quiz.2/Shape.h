#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
  public:

    //Shape():{}

    virtual std::ostream& print(std::ostream &out) = 0;

    friend std::ostream& operator<<(std::ostream &out, Shape &s)
    {
      return s.print(out);
    }

    virtual ~Shape() {}
};

#endif
