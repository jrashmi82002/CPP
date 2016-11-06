#include "Money.h"
#include "CreditCard.h"

int main()
{
    /*Money m1;
    m1.print();

    m1.set_euro(3);
    m1.set_centime(99);
    m1.print();
    Money m2(5,99);
    Money m3;
    m3 = m1 + m2;
    m3.print();*/

    Money m(100,20);
    Money m1(18,45);
    //Money m1(5,1000);
    //(m+m+m).print();
    //(m-m1).print();
    CreditCard card("Marko", "12345", "jacket", m);
    //card.print();
    card.chargeCard1("shirt", m1);
    //card.print();
    card.chargeCard2("shooes", 85, 30);
    card.print();
    return 0;
}
