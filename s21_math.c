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
    while (s21_fabs(add_value) > S21_EPS && !flag) {
        add_value *= (x / i);
        i++;
        sum += add_value;
        if (sum > DBL_MAX) {
            sum = S21_PLUS_INF;
            flag = 1;
        }
    }
    return sum;
}

long double s21_ceil(double x){
    long double res = x;
    if (!isnan(x) && !isinf(x)) {
        res = (long long int)x;
        if(x != res && x > 0.)
            res+=1;
    }
    return res;
}
long double s21_floor(double x){
    long double res = x;
    if (!isnan(x) && !isinf(x)) {
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
    
    if(base < 0.){
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
    if (res < - DBL_MAX + 1 && !(isnan(res)))
        res = S21_MINUS_INF;
    else if (res > DBL_MAX && !(isnan(res)))
        res = S21_MINUS_INF;
    return res;
}

long double s21_sqrt(double x) {
    return s21_pow(x, 0.5);
}

int main() {
    printf("%Lf %f", s21_fmod(TEST) , fmod(TEST));
    return 0;
}