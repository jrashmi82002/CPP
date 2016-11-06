/*First, write a struct named StudentGrade that contains the student’s name
(as a std::string) and grade (as a char).*/
#include <iostream>
#include <vector>

struct StudentGrade{
  std::string name;
  char grade;


};

/*Write an overloaded operator[] for this class. This function should take a std::string parameter,
and return a reference to a char. In the body of the function, first iterate through the vector to see if
the student’s name already exists (you can use a for-each loop for this). If the student exists, return a
reference to the grade and you’re done. Otherwise, use the std::vector::push_back() function to add a
StudentGrade for this new student. When you do this, std::vector will add a copy of your StudentGrade to
itself (resizing if needed). Finally, we need to return a reference to the grade for the student we just
added to the std::vector.
We can access the student we just added using the std::vector::back() function.*/

class GradeMap{

std::vector<StudentGrade> m_map;

public:

  GradeMap(){}

  char& operator[](std::string name)
  {
    for (StudentGrade &student : m_map)
    {
      if (student.name == name){return student.grade;}
    }

    StudentGrade temp;
    temp.name = name;
    temp.grade = ' ';

    m_map.push_back(temp);
    return m_map.back().grade;

  }

};


int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
