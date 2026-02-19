#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {

  int copy = candidate;
  int count = 0;
  while (copy != 0) {
    copy /= 10;
    count++;
  }
  copy = candidate;
  int sum = 0;
  while (copy != 0) {
    sum += pow((copy % 10), count);
    copy /= 10;
  }
  return candidate == sum;
}
