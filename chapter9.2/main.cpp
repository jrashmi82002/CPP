#include <iostream>


class Fraction{

  int m_numerator;
  int m_denominator;

public:

  Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
  {
    reduce();
  }

  friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
  friend Fraction operator*(const Fraction &fraction, int value);
  friend Fraction operator*(int value, const Fraction &fraction);

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



int main()
{
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}
