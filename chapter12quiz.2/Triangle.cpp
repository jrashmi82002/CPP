#include "Triangle.h"


std::ostream& Triangle::print(std::ostream &out)
{
  out << "Triangle(" << m_p1 << " " << m_p2 << " " << m_p3 << ")";
  return out;
}
