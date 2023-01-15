#include "s21_math.h"
//#include <math.h>
#include <stdio.h>

int s21_fact(int argument) {
  int factorial = 1;
  if (argument == 0) {
  } else for (int i = 1; i <= argument; i++) {
    factorial = factorial * i;
  }
  return factorial;
}

int main() {
  return 1;
}