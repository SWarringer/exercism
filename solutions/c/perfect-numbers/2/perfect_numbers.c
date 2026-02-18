#include "perfect_numbers.h"

int classify_number(int value) {
  if (value < 1) {
    return ERROR;
  }
  int sum = 0;
  for (int i = 1; i < value; i++) {
    if (value % i == 0) {
      sum += i;
    }
  }
  if (sum > value) {
    return ABUNDANT_NUMBER;
  }
  if (sum < value) {
    return DEFICIENT_NUMBER;
  }
  return PERFECT_NUMBER;
}
