#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <map>

class CreditCard{

  std::string m_name;
  std::string m_number;
  std::map<std::string, Money> m_transactions;

public:

  CreditCard(std::string name, std::string number, std::string item, Money cost) :
  m_name(name), m_number(number)
  {
    m_transactions.insert(std::pair<std::string, Money>(item, cost));
  }

  void print();
  //one charge method take as parameters a string (the item name) and a Money object
  void chargeCard1(std::string item, Money cost);
  //second charge method take a string and two integers (describing the price in euros, centimes)
  void chargeCard2(std::string item, int euros, int centimes);

};

#endif
