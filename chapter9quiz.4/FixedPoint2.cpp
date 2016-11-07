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

  FixedPoint2 operator-()
  {
    return FixedPoint2(-m_base, -m_fraction);
  }

  operator double()
  {
    return m_base + static_cast<double>(m_fraction)/100;
  }

  friend std::ostream& operator<<(std::ostream &out, FixedPoint2 &f);
  friend FixedPoint2 operator+(FixedPoint2 f1, FixedPoint2 f2);
  friend std::istream& operator>>(std::istream &in, FixedPoint2 &f);

};

  std::ostream& operator<<(std::ostream &out, FixedPoint2 &f)
  {
    out << f.m_base << ".";

    if (f.m_fraction < 10)
    {
      out << "0" ;
    }

    if (f.m_base < 0)
    {
        f.m_fraction *= -1;
    }

     out << static_cast<int>(f.m_fraction) << std::endl;
    return out;
  }

  std::istream& operator>>(std::istream &in, FixedPoint2 &f)
  {
    double temp;
    in >> temp;
    f = FixedPoint2(temp);
    return in;
  }

  FixedPoint2 operator+(FixedPoint2 f1, FixedPoint2 f2)
  {
    FixedPoint2 f3;
    f3.m_base = f1.m_base + f2.m_base;
    if (f1.m_fraction + f2.m_fraction >= 100)
    {
      f3.m_fraction = (f1.m_fraction + f2.m_fraction)%100;
      f3.m_base += (f1.m_fraction + f2.m_fraction)/100;
    }
    else {
    f3.m_fraction = f1.m_fraction + f2.m_fraction;
    }
    return f3;
  }


  void testAddition()
  {
  	// h/t to reader Sharjeel Safdar for this function
  	std::cout << std::boolalpha;
  	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
  	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50)) << '\n';
  	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
  	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
  	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
  	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
  	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
  	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
  }

  int main()
  {
  	testAddition();

  	FixedPoint2 a(34, 56);
  	std::cout << a << '\n';

  	std::cout << -a << '\n';

  	std::cout << "Enter a number: "; // enter 5.678
  	std::cin >> a;

  	std::cout << "You entered: " << a << '\n';

  	return 0;
  }
