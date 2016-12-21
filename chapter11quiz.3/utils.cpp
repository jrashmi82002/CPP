#include <cstdlib>
#include <ctime>
#include "utils.h"

int getRandomNumber(int min, int max)
{
static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
