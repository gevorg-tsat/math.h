#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 15
#define S21_NAN 0.0/0.0
#define S21_MINUS_INF -1.0/0.0
#define S21_PLUS_INF 1.0/0.0
#define DBL_MAX 1.7976931348623158e+308
#define s21_inf __LONG_MAX__
#define S21_EPS 1e-9

long double s21_exp(double x){
    long double sum = 1;
    long double add_value = 1;
    for(int i = 1; add_value > S21_EPS; i++){
        add_value *= x/i;
        sum += add_value;
        if(sum > DBL_MAX){
            sum = s21_inf;
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
