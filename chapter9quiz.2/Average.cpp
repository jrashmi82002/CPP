#include <iostream>
#include <cstdint>

class Average{

  std::int32_t m_sum = 0;
  std::int8_t m_counter = 0;

public:

  Average()
  {
    //m_sum += number;
    //m_counter += 1;
  }

  double calculate_average()
  {
    double average = static_cast<double>(m_sum)/m_counter;
    //std::cout << "average= " << average << std::endl;
    return average;
  }

  Average& operator+=(int num)
  {
    m_sum += num;
    m_counter += 1;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, Average &aver);

};

std::ostream& operator<<(std::ostream& out, Average &aver)
{
  out << aver.calculate_average();
  return out;
}


int main()
{
	Average avg;
  std::cout << avg << '\n';
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
