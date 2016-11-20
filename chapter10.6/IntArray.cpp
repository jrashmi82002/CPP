#include <iostream>
#include <cassert>
#include "IntArray.h"

  //print function
  void IntArray::print()
  {
    for (int index = 0; index < m_length; ++index)
    {
      std::cout << m_data[index] << " ";
    }
  }

  //delete the array entirelly
  void IntArray::erase()
  {
    delete[] m_data;
    m_length = 0;
    m_data = nullptr;
  }

  // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
  void IntArray::reallocate(int newLength)
  {
    erase();

    if(newLength <= 0)
    return;

    m_data = new int[newLength];
    m_length = newLength;
  }

//// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
void IntArray::resize(int newLength)
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
  void IntArray::insertBefore(int value, int index)
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
  void IntArray::remove(int index)
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
  
