/*Define a Money class, suitable for storing money information. Class objects should contain two int
fields: euros and centimes. Write for the class appropriate constructors and get/set methods to allow the
user to access its data. Also write a print methods that prints out an object's info. Overload the +
operator, so that adding two objects of this class works. As an added requirement, after adding two
Money objects, values of more than 100 centimes should be converted to euros.
As an example: once your class is ready the piece of code Money m(2,99); (m+m+m).print(); should
produce the following output: “8,97 Euros”*/
#include <iostream>
#include "Money.h"

void Money::print()
{
    std::cout << m_euro << "," << m_centime << " Euros" << std::endl;
}

Money operator+(Money money1, Money money2)
{
  int eur = 0;
  int cent = 0;
  Money sum;
  sum.m_euro = money1.m_euro + money2.m_euro;
  sum.m_centime = money1.m_centime + money2.m_centime;

  if (sum.m_centime > 100)
  {
      cent = sum.m_centime % 100;
      eur = sum.m_centime / 100;
      sum.m_euro += eur;
      sum.m_centime = cent;
  }

  return sum;
}

Money operator-(Money money1, Money money2)
{
  Money dif;

  if(money2.m_centime > money1.m_centime)
  {
    int cent = (money1.m_centime - money2.m_centime + 100)%100;
    std::cout << "cent= " << cent << std::endl;
    int eur = money2.m_centime/100 + 1;
    std::cout << "eur= " << eur << std::endl;
    dif.m_euro = money1.m_euro - money2.m_euro - eur;
    dif.m_centime = cent;
  }
  else
  {
    dif.m_euro = money1.m_euro - money2.m_euro;
    dif.m_centime = money1.m_centime -money2.m_centime;
  }

  return dif;
}
