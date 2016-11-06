/*Define a CreditCard class. Each object should contain the following information: owner name
(string), card number (string) and a map of transactions. Each transaction should include an item
name (string), and a cost (Money class). Pay special attention to writing appropriate
constructors/destructors. Write a print( ) method that prints out all the transaction history of the credit
card, and two charge methods which add new transactions to the card. One charge method should take
as parameters a string (the item name) and a Money object. The other should take a string and two
integers (describing the price in euros, centimes).*/
#include <iostream>
#include <string>
#include "Money.h"
#include "CreditCard.h"

void CreditCard::print()
  {
    std::cout << "Cardnumber: " << m_number << "\nCardholder: " << m_name << "\nTransactions:" << std::endl;
    std::map<std::string, Money>::iterator it;
    for(it = m_transactions.begin(); it!=m_transactions.end(); ++it)
    {
      std::cout << it->first << " : " ;
      it->second.print();
      std::cout << std::endl;
    }
  }

  //one charge method take as parameters a string (the item name) and a Money object

  void CreditCard::chargeCard1(std::string item, Money cost)
  {
    m_transactions.insert(std::pair<std::string, Money>(item, cost));
  }

  //second charge method take a string and two integers (describing the price in euros, centimes)

  void CreditCard::chargeCard2(std::string item, int euros, int cents)
  {
    Money cost(euros, cents);
    m_transactions.insert(std::pair<std::string, Money>(item, cost));
  }
