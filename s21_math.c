#include "s21_math.h"

#define TEST 10, -1.5

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
    int sign = (x > 0) ? 1: -1;
    x = s21_fabs(x);
    y = s21_fabs(y);
    if (y == 0)
        x = S21_NAN;
    else {
        while (x >= y)
            x -= y;
        x *= sign;
    }
    return x;
}

long double s21_exp(double x){
    long double sum = 1;
    long double add_value = 1;
    int flag = 0, i = 1;
    if (S21_isinf(x) && x < 0) {
        sum = 0;
        flag = 1;
    }
    if (S21_isnan(x)) {
        sum = S21_NAN;
        flag = 1;
    }
    while (s21_fabs(add_value) > S21_EPS && !flag) {
        add_value *= (x / i);
        i++;
        sum += add_value;
        if(sum > S21_MAX){
            sum = S21_PLUS_INF;
            flag = 1;
        }
    }
    return sum;
}

long double s21_ceil(double x){
    long double res = x;
    if (!S21_isnan(x) && !S21_isinf(x)) {
        res = (long long int)x;
        if(x != res && x > 0.)
            res+=1;
    }
    return res;
}
long double s21_floor(double x){
    long double res = x;
    if (!S21_isnan(x) && !S21_isinf(x)) {
        res = (long long int)x;
        if( x != res && x < 0.)
                res -= 1;
    }
    return(res);
}

long double s21_log(double x) {
    double res = 0;
    if (x == 0) {
        res = S21_MINUS_INF;
    } else if (x < 0) {
        res = S21_NAN;
    } else if (x < S21_PLUS_INF && x > S21_MINUS_INF) {
        int ex_pow = 0;
        long double result = 0;
        long double compare = 0;

        for (int i = 0; i < 100; i++) {
            compare = result;
            result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
        }
        res = result + ex_pow;
    } else if (x == S21_PLUS_INF || x == -S21_MINUS_INF) {
        res = S21_PLUS_INF;
    } else {
        res = S21_NAN;
    }
    return res;
}

long double s21_pow(double base, double exp){
    long double res = 1;
    if (exp == 0)
        res = 1;
    else if (base == 0) {
        if(S21_isnan(exp))
            res = S21_NAN;
        else
            res = 0;
    }
    else if (base == 1) {
        res = 1;
    }
    else if (S21_isinf(exp)) {
        if ((exp > 0 && s21_fabs(base) > 1) || (exp < 0 && s21_fabs(base) < 1))
            res = S21_PLUS_INF;
        else
            res = 0;
    }
    else if(base < 0.){
        if (exp == s21_floor(exp)) {
            if (exp > 0)
                for (long double i = 1; i <= exp; i++, res *= base);
            else
                for (long double i = -1; i >= exp; i--, res /= base);
        }
        else {
            res = S21_NAN;
        }
    }   
    else {
        res = s21_exp(exp * s21_log(base));
    }
    if (S21_isinf(res) && res < 0)
        res = S21_MINUS_INF;
    else if (S21_isinf(res) && res > 0)
        res = S21_PLUS_INF;
    return res;
}

long double s21_sin(double x) {
  long double q = x, sum = 0;
  int i = 1;
  while (s21_fabs(q) > S21_EPS) {
    sum += q;
    q = q * (-1) * (x * x) / ((2 * i + 1) * (2 * i));
    i++;
  }
  return sum;
}

long double s21_cos(double x) {
  return s21_sin(x + S21_PI_2);
}

long double s21_tan(double x) {
  return s21_sin(x) / s21_cos(x);
}

long double s21_asin(double x) {
  long double q = x, sum = 0;
  int i = 0;
  if (s21_fabs(x) < 0.5) {
    while (s21_fabs(q) > S21_EPS) {
      sum += q;
      q = q * (x * x * (2 * i + 1) * (2 * i + 1)) / (2 * (2 * i + 3) * (i + 1));
      i++;
    }
  } else if (s21_fabs(x) <= 1) {
    sum = S21_PI_2 - 2 * s21_asin(s21_sqrt((1 - x) / 2));
  } else 
    sum = S21_NAN;
  return sum;
}

long double s21_acos(double x) {
  return S21_PI_2 - s21_asin(x);
}

long double s21_atan(double x) {
  long double sum = S21_PI_2;
  if (!S21_isinf(x)) 
    sum = s21_asin(x / s21_sqrt(1 + x * x));
  return sum;
}
long double s21_sqrt(double x) {
    return s21_pow(x, 0.5);
}