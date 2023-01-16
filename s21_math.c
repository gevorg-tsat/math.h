#include "s21_math.h"
//#include <math.h>
#include <stdio.h>

unsigned long long s21_fact(unsigned int x) {
    int y = 1;
    for (unsigned int i = 1; i <= x; i++, y *= i); 
    return y;
}

int s21_abs(int x) {
    if (x < 0)
        x = -x;
    return x;
}

long double s21_fabs(double x) {
    if (x < 0)
        x = - 1L * x;
    return x;
}

long double s21_fmod(double x, double y) {
    while (x >= y)
        x -= y;
    return x;
}

