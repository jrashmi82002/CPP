#include <iostream>


class Fraction{

  int m_numerator;
  int m_denominator;

public:

  Fraction(int numerator = 1, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
  {
    reduce();
  }

  friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
  friend Fraction operator*(const Fraction &fraction, int value);
  friend Fraction operator*(int value, const Fraction &fraction);
  friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
  friend std::istream& operator>>(std::istream &in, Fraction &fraction);

  void print()
  {
    std::cout << m_numerator << "/" << m_denominator << std::endl;
  }

  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

  void reduce()
  {
    int GCD = gcd(m_numerator, m_denominator);
    m_numerator /= GCD;
    m_denominator /= GCD;
  }

};


Fraction operator*(const Fraction &fraction1, const Fraction &fraction2)
{
  int fin_num = fraction1.m_numerator * fraction2.m_numerator;
  int fin_denom = fraction1.m_denominator * fraction2.m_denominator;

  return Fraction(fin_num, fin_denom);
}

Fraction operator*(const Fraction &fraction, int value)
{
  int fin_num = fraction.m_numerator * value;
  return Fraction(fin_num, fraction.m_denominator);
}

Fraction operator*(int value, const Fraction &fraction)
{
  return (fraction * value);
}

std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
{
  out << fraction.m_numerator << "/" << fraction.m_denominator ;
  return out;
}

std::istream& operator>>(std::istream &in, Fraction &fraction)
{
  char c;
  in >> fraction.m_numerator;
  in >> c; //ignore '/' separator
  in >> fraction.m_denominator;
  return in;
}


int main()
{

	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}
