#include <iostream>
#include <cassert>

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

  //print function
  void print()
  {
    for (int index = 0; index < m_length; ++index)
    {
      std::cout << m_data[index] << " ";
    }
  }

  //getter for the length of the array
  int getLength() {return m_length;}

  //delete the array entirelly
  void erase()
  {
    delete[] m_data;
    m_length = 0;
    m_data = nullptr;
  }

  // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
  void reallocate(int newLength)
  {
    erase();

    if(newLength <= 0)
    return;

    m_data = new int[newLength];
    m_length = newLength;
  }

//// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
void resize(int newLength)
{
  if (newLength == m_length)
  return;

  if (newLength <= 0)
  {
    erase();
    return;
  }

  int* data = new int[newLength];
  int indexToCopy = (m_length < newLength) ? m_length : newLength;
  for (int index = 0; index < indexToCopy; ++index)
  {
    data[index] = m_data[index];
  }

  delete[] m_data;

  m_data = data;
  m_length = newLength;
}
  //insert element with value value in the array at given index
  void insertBefore(int value, int index)
  {
    assert(index >= 0 && index <= m_length);

    int *data = new int[m_length + 1];
    for (int before = 0; before < index; ++before)
    {
      data[before] = m_data[before];
    }
    data[index] = value;
    for (int after = index + 1; after < m_length + 1; ++after)
    {
      data[after] = m_data[after - 1];
    }
    delete[] m_data;
    m_data = data;
    m_length += 1;
  }

  //remove the element from the array at the given index
  void remove(int index)
  {
    assert(index >= 0 && index < m_length);

    if (m_length == 1)
    {
      erase();
      return;
    }

    int* data = new int[m_length - 1];

    for (int before = 0; before < index; ++before)
    {
      data[before] = m_data[before];
    }
    for (int after = index + 1; after < m_length; ++after)
    {
      data[after - 1] = m_data[after];
    }
    delete[] m_data;

    m_data = data;
    m_length -= 1;
  }

  void insertAtEnd(int value) {insertBefore(value, m_length);}
  void insertAtBeginning(int value) {insertBefore(value, 0);}

};








int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i=0; i<10; i++)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int j=0; j<array.getLength(); j++)
        std::cout << array[j] << " ";

    return 0;
}
