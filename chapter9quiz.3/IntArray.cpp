/*Write your own integer array class named IntArray from scratch (do not use std::array or std::vector).
Users should pass in the size of the array when it is created, and the array should be dynamically allocated.
Use assert statements to guard against bad data.*/

#include <iostream>
#include <cassert>

class IntArray{

  int m_length;
  int* m_array;

public:

  //konstruktor
  IntArray(int length) : m_length(length)
  {
    m_array = new int[m_length];
  }

  //destruktor
  ~IntArray()
  {
    delete[] m_array;
  }

  //overloaded subscript opeartor[]
  int& operator[] (int index)
  {
    assert (index >= 0);
    return m_array[index];
  }

  //copy constructor for deep copying
  IntArray(const IntArray& array) : m_length(array.m_length)
  {
    if (array.m_array)
    {
      m_array = new int[m_length];

      for (int i = 0; i < m_length; ++i)
      {
        m_array[i] = array.m_array[i];
      }
    }
    else
    {
      m_array = 0;
    }
  }

  //overloaded assignement operator= for deep assignement
  IntArray& operator=(IntArray &array)
  {
    //guard for selfassignement
    if (&array == this)
    return *this;

    delete[] m_array;
    m_length = array.m_length;

    if (array.m_array)
    {
      m_array = new int[m_length];
      for (int i = 0; i < m_length; ++i)
      {
        m_array[i] = array.m_array[i];
      }
    }
    else
    {
      m_array = 0;
    }
    return *this;
  }

  //declaration of friend function for overloaded operator<<
  friend std::ostream& operator<<(std::ostream &out, IntArray &array);

};


//overloaded operator<<
std::ostream& operator<<(std::ostream &out, IntArray &array)
{
  for(int i = 0; i < array.m_length; ++i)
  {
    out << array.m_array[i] << " ";
  }
  return out;
}


IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
