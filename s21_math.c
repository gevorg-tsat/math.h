#include "s21_math.h"

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
        if(sum > DBL_MAX){
            sum = S21_PLUS_INF;
            break;
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


int main() {
    printf("%Lf", s21_ceil(S21_NAN));
    return 0;
}
