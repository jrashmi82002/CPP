#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray{

  int m_length;
  int* m_data;

public:

  //default constructow used when no parameter is given
  IntArray() : m_length(0), m_data(nullptr){}

  //constructor used when parameter is given
  IntArray(int length): m_length(length)
  {
    m_data = new int[m_length];
  }
  //destructor
  ~IntArray()
  {
    delete[] m_data;
  }

  //overloaded subscript operator
  int& operator[] (int index)
  {
    return m_data[index];
  }

  //getter for the length of the array
  int getLength() {return m_length;}

  void print();

  void erase();

  void reallocate(int newLength);

  void resize(int newLength);

  void insertBefore(int value, int index);

  void remove(int index);

  void insertAtEnd(int value) {insertBefore(value, m_length);}

  void insertAtBeginning(int value) {insertBefore(value, 0);}

};

#endif
