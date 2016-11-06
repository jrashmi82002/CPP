#include <iostream>
#include <string>

class Mystring{

  std::string m_string;

public:

  Mystring(std::string string) : m_string(string){}

  std::string operator()(int begin, int end)
  {
    std::string substring = "";
    std::cout << "begin= " << begin << " end= " << end << std::endl;
    for (int i = begin; i < begin + end; ++i)
    {
      substring += m_string[i];
    }

    return substring;
  }

};


int main()
{
    Mystring string("Today was really beautiful day.");
    std::cout << string(10, 9) << std::endl; // start at index 7 and return 5 characters

    return 0;
}
