#ifndef MONEY_H
#define MONEY_H

class Money{

  int m_euro;
  int m_centime;

 public:

    //constructor for both values and default constructor
    Money(int euro = 0, int centime = 0) : m_euro(euro), m_centime(centime)
    {
      if (m_centime >= 100)
      {
        int cent = m_centime%100;
        m_euro += m_centime/100;
        m_centime = cent;
      }
    }

    //get euros
    int get_euro(){return m_euro;}

    //get centimes
    int get_centime(){return m_centime;}

    //set euro
    void set_euro(int euro){m_euro = euro;}

    //set centime
    void set_centime(int centime){m_centime = centime;}

    void print();

    friend Money operator+(Money money1, Money money2);
    friend Money operator-(Money money1, Money money2);
};

#endif
