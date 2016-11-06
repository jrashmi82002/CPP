#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2{

  std::int16_t m_base;
  std::int8_t m_fraction;

public:

  //konstruktor
  FixedPoint2(std::int16_t base = 0, std::int8_t fraction = 0) : m_base(base), m_fraction(fraction){}

  //konstruktor
  FixedPoint2(double num)
  {
    m_base = static_cast<std::int16_t>(num);
    m_fraction = static_cast<std::int8_t>(round((num - m_base)*100));
  }

  friend std::ostream& operator<<(std::ostream &out, FixedPoint2 &f);

};

  std::ostream& operator<<(std::ostream &out, FixedPoint2 &f)
  {
    out << f.m_base << "." << static_cast<int>(f.m_fraction) << std::endl;
    return out;
  }


int main()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(9.617); // any decimal digits beyond 2 should be rounded to 2 decimals
	std::cout << b << '\n';

	FixedPoint2 c(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	/*FixedPoint2 d(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';*/

	return 0;
}
