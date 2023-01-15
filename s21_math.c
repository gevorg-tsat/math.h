#include "s21_math.h"
//#include <math.h>
#include <stdio.h>

int s21_fact(int x) {
  int y = 1;
  if (x == 0) {
  } else for (int i = 1; i <= x; i++) {
    y = y * i;
  }
  return y;
}

int s21_abs(int x) {return (x < 0) ? ((-1) * x) : x;}

long double s21_fabs(double x) {return (x < 0) ? ((-1L) * x) : x;}

int main() {
  return 1;
}