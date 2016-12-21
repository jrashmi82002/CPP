#include <iostream>
#include <vector>
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"


int getLargestRadius(std::vector<Shape*> v)
{
	int max_radius = 0;
	for (unsigned int i=0; i<v.size(); ++i)
	{
		Circle *c = dynamic_cast<Circle*>(v[i]);
		if (c == 0) continue;
		int radius = c->getRadius();
		if (radius > max_radius)
		 	max_radius = radius;
	}
	return max_radius;
}




int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	// print each shape in vector v on its own line here
	for (unsigned int i=0; i<v.size(); ++i)
	{
		std::cout << *(v[i]) << std::endl;
	}

       std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	for (unsigned int i = 0; i < v.size(); ++i)
	delete v[i];

    return 0;
}
