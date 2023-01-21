#ifndef SRC_MATH_S21_MATH_H_
#define SRC_MATH_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_isnan(x) ((x) != x)
#define S21_isinf(x) (!S21_isnan(x) && S21_isnan(x - x))

#define S21_E 2.718281828459045L
#define S21_LOG2E 1.442695040888963L
#define S21_LOG10E 0.434294481903252L
#define S21_LN2 0.693147180559945L
#define S21_LN10 2.302585092994046L
#define S21_PI 3.141592653689793L
#define S21_PI_2 1.570796326794897L
#define S21_PI_4 0.785398163397448L
#define S21_1_PI 0.318309886183791L
#define S21_2_PI 0.636619772367581L
#define S21_2_SQRTPI 1.128379167095512L
#define S21_SQRT2 1.414213562373095L
#define S21_NAN 0. / 0.
#define S21_MINUS_INF -1. / 0.
#define S21_PLUS_INF 1. / 0.
#define S21_MAX 1.7976931348623158e+308
#define S21_EPS 1e-16

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);  // возвращает ближайшее целое число, не меньшее
                                 // заданного значения
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);  //  возвращает ближайшее целое число, не
                                  //  превышающее заданное значение
long double s21_fmod(double x,
                     double y);  // остаток операции деления с плавающей точкой
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_MATH_S21_MATH_H_
