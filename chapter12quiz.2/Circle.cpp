#include "Circle.h"

std::ostream& Circle::print(std::ostream &out)
{
  out << "Circle(" << m_p1 << " radius " << m_r << ")";
  return out;
}
