#include "s21_math.h"
#include <math.h>
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

long double s21_exp(double x){
    long double sum = 1;
    long double add_value = 1;
    for(int i = 1; add_value > S21_EPS; i++){
        add_value *= x/i;
        sum += add_value;
        if(sum > S21_MAX){
            sum = S21_PLUS_INF;
            break;
        }
    }
    return sum;
}

long double s21_ceil(double x){
    long double ceil_x = (long long int)x;
    if(x != ceil_x && x > 0.)
        ceil_x+=1;
    return(ceil_x);
}
long double s21_floor(double x){
    long double floor_x = (long long int)x;
    if( x != floor_x && x < 0.)
            floor_x -= 1;
    return(floor_x);
}

long double s21_log(double x){
    long double sum = 0;
    
    if(x <= 0.){
        if(x == 0.)
            sum = S21_MINUS_INF;
        else 
            sum = S21_NAN;
    }
    else{
        long double add_value = 0;
        for(int i = 0; i < 100; i++){
            add_value = 2*(x - s21_exp(sum))/(x + s21_exp(sum));
            sum += add_value;
        }
        
    }
    return sum;
}

long double s21_pow(double base, double exp){
    long double res = 0;
    // if(exp < 0.){
    //     base = 1/base;
    //     exp = -exp;
    //     printf("base: %f exp: %f\n", base, exp);
    // }
    if(base < 0.){
        base = -base;
        res = s21_exp(exp * s21_log(base));
        if(s21_fmod(exp, 2) != 0)
            res = -res;
    }   
    else{
        res = s21_exp(exp * s21_log(base));
    }
        
    return res;
}

long double s21_sin(double x) {
  long double q = x, sum = 0, i = 1;
  while (s21_fabs(q) > 0.0000001) {
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

int main() {
  return 0;
}
