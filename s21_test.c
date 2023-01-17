#include <check.h>
#include <math.h>
#include "s21_math.h"

START_TEST(abs_of_positive_int)
{
    ck_assert_int_eq(s21_abs(1),abs(1));
}
END_TEST

START_TEST(abs_of_negative_int)
{
    ck_assert_int_eq(s21_abs(-1),abs(-1));
}
END_TEST

START_TEST(abs_of_zero)
{
    ck_assert_int_eq(s21_abs(0),abs(0));
}
END_TEST

START_TEST(fabs_of_positive_double)
{
    ck_assert_double_eq_tol(s21_fabs(1.001),fabs(1.001),1e-6);
}
END_TEST

START_TEST(fabs_of_negative_double)
{
    ck_assert_double_eq_tol(s21_fabs(-1.001),fabs(-1.001),1e-6);
}
END_TEST

START_TEST(fabs_of_zero)
{
    ck_assert_double_eq_tol(s21_fabs(0.),fabs(0.),1e-6);
}
END_TEST

START_TEST(fabs_of_plus_inf)
{
    ck_assert_double_infinite(s21_fabs(S21_PLUS_INF));
    ck_assert_double_infinite(s21_fabs(S21_MINUS_INF));
    ck_assert_double_infinite(fabs(INFINITY));
}
END_TEST

START_TEST(fabs_of_inf)
{
    double arg = S21_PLUS_INF;
    ck_assert_ldouble_infinite(s21_fabs(arg));
    ck_assert_double_infinite(fabs(arg));
    arg = S21_MINUS_INF;
    ck_assert_ldouble_infinite(s21_fabs(arg));
    ck_assert_double_infinite(fabs(arg));

}
END_TEST

START_TEST(fabs_of_nan)
{
    double arg = S21_NAN;
    ck_assert_ldouble_nan(s21_fabs(arg));
    ck_assert_double_nan(fabs(arg));

}
END_TEST

START_TEST(fmod_with_numbers_more_then_zero)
{
    double a = 14.1;
    double b = 3.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_b_more_then_a_more_then_zero)
{
    double a = 3.1;
    double b = 14.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_a_more_then_zero_more_then_b)
{
    double a = 14.1;
    double b = -3.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_b_more_then_zero_more_then_a)
{
    double a = -14.1;
    double b = 3.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_a_less_then_b_less_then_zero)
{
    double a = -14.1;
    double b = -3.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_b_less_then_a_less_then_zero)
{
    double a = -3.1;
    double b = -14.1;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_inf)
{
    double arg1 = S21_PLUS_INF, arg2 = 4;
    ck_assert_ldouble_nan(s21_fmod(arg1, arg2));
    ck_assert_double_nan(fmod(arg1, arg2));
    arg1 = 4;
    arg2 = S21_PLUS_INF;
    ck_assert_ldouble_eq_tol(s21_fmod(arg1, arg2), fmod(arg1, arg2), 1e-6);
    arg1 = S21_PLUS_INF, arg2 = S21_PLUS_INF;
    ck_assert_ldouble_nan(s21_fmod(arg1, arg2));
    ck_assert_double_nan(fmod(arg1, arg2));
}
END_TEST

START_TEST(fmod_nan)
{
    double arg1 = S21_NAN, arg2 = 4;
    ck_assert_ldouble_nan(s21_fmod(arg1, arg2));
    ck_assert_double_nan(fmod(arg1, arg2));
    arg1 = S21_NAN;
    arg2 = S21_PLUS_INF;
    ck_assert_ldouble_nan(s21_fmod(arg1, arg2));
    ck_assert_double_nan(fmod(arg1, arg2));
}
END_TEST

START_TEST(exp_zero)
{
    double power = 0;
    ck_assert_ldouble_eq_tol(s21_exp(power),exp(power),1e-6);
}
END_TEST

START_TEST(exp_double_positive)
{
    double power = 10.5;
    ck_assert_ldouble_eq_tol(s21_exp(power),exp(power),1e-6);
}
END_TEST

START_TEST(exp_double_negative)
{
    double power = -10.5;
    ck_assert_ldouble_eq_tol(s21_exp(power),exp(power),1e-6);
}
END_TEST

START_TEST(exp_inf)
{
    long double power = S21_PLUS_INF;
    ck_assert_double_infinite(exp(power));
    ck_assert_ldouble_infinite(s21_exp(power));
}
END_TEST

START_TEST(exp_minus_inf)
{
    long double power = S21_MINUS_INF;
    ck_assert_ldouble_eq_tol(s21_exp(power), exp(power), 1e-6);
} END_TEST

START_TEST(exp_nan)
{
    long double power = S21_NAN;
    ck_assert_ldouble_nan(s21_exp(power));
    ck_assert_double_nan(exp(power));
} END_TEST

START_TEST(exp_small_positive)
{
    double power = 0.7;
    ck_assert_ldouble_eq_tol(s21_exp(power),exp(power),1e-6);
}
END_TEST

START_TEST(exp_small_negative)
{
    double power = -0.7;
    ck_assert_ldouble_eq_tol(s21_exp(power),exp(power),1e-6);
}
END_TEST

START_TEST(pow_with_positive_integer_number)
{
    double a = 9.;
    double b = 6.;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_with_positive_double_number)
{
    double a = 9.;
    double b = 3.2;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_with_positive_double_number_in_litte_exp)
{
    double a = 9.;
    double b = 0.7;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_with_negative_integer_number_in_native_exp)
{
    double a = -9.;
    double b = 5.;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_with_negative_double_number)
{
    double a = -4.3;
    double b = -3.2;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(pow_with_negative_double_number_in_litte_negative_exp)
{
    double a = -1.;
    double b = -0.7;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
   
}
END_TEST

START_TEST(pow_NAN_in_litte_negative_exp)
{
    double a = S21_NAN;
    double b = 2;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(pow_int_in_NAN)
{
    double a = 2;
    double b = S21_NAN;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(pow_one_in_NAN)
{
    double a = 1;
    double b = S21_NAN;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_zero_in_double)
{
    double a = 0.;
    double b = 2.1;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_zero_in_zero)
{
    double a = 0.;
    double b = 0.;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(log_double_positive)
{
    long double arg = 100;
    ck_assert_ldouble_eq_tol(s21_log(arg), log(arg), 1e-6);
}
END_TEST

START_TEST(log_double_negative)
{
    long double arg = -0.1;
    ck_assert_ldouble_nan(s21_log(arg));
    ck_assert_double_nan(log(arg));
}
END_TEST

START_TEST(log_zero)
{
    long double arg = 0;
    ck_assert_ldouble_infinite(s21_log(arg));
    ck_assert_double_infinite(log(arg));
}
END_TEST

START_TEST(log_plus_inf)
{
    long double arg = S21_PLUS_INF;
    ck_assert_ldouble_infinite(s21_log(arg));
    ck_assert_double_infinite(log(arg));
}
END_TEST

START_TEST(log_minus_inf)
{
    long double arg = S21_MINUS_INF;
    ck_assert_ldouble_nan(s21_log(arg));
    ck_assert_double_nan(log(arg));
}
END_TEST

START_TEST(log_small) {
    long double arg = 0.1;
    ck_assert_ldouble_eq_tol(s21_log(arg), log(arg), 1e-6);
}
END_TEST

START_TEST(pow_zero_in_inf)
{
    double a = 0.;
    double b = S21_PLUS_INF;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_zero_in_minus_inf)
{
    double a = 0.;
    double b = S21_MINUS_INF;
    ck_assert_ldouble_infinite(s21_pow(a,b));
    ck_assert_ldouble_infinite(pow(a,b));
}
END_TEST

START_TEST(pow_zero_in_nan)
{
    double a = 0.;
    double b = S21_NAN;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(pow_base_less_one_in_nan)
{
    double a = 0.12;
    double b = S21_NAN;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(pow_base_less_one_in_minus_inf)
{
    double a = 0.;
    double b = S21_MINUS_INF;
    ck_assert_ldouble_infinite(s21_pow(a,b));
    ck_assert_ldouble_infinite(pow(a,b));
}
END_TEST

START_TEST(pow_base_less_one_in_inf)
{
    double a = 0.;
    double b = S21_PLUS_INF;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_base_more_one_in_inf)
{
    double a = -1.2;
    double b = S21_PLUS_INF;
    ck_assert_ldouble_infinite(s21_pow(a,b));
    ck_assert_ldouble_infinite(pow(a,b));
}
END_TEST

START_TEST(pow_base_more_one_in_minus_inf)
{
    double a = 0.;
    double b = S21_PLUS_INF;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_base_more_one_in_nan)
{
    double a = 0.;
    double b = S21_PLUS_INF;
    ck_assert_ldouble_eq_tol(s21_pow(a,b),pow(a,b),1e-6);
}
END_TEST

START_TEST(pow_nan_in_nan)
{
    double a = S21_NAN;
    double b = S21_NAN;
    ck_assert_ldouble_nan(s21_pow(a,b));
    ck_assert_ldouble_nan(pow(a,b));
}
END_TEST

START_TEST(sqrt_nan)
{
    double a = S21_NAN;
    ck_assert_ldouble_nan(s21_sqrt(a));
    ck_assert_ldouble_nan(sqrt(a));
}
END_TEST

START_TEST(sqrt_inf)
{
    double a = S21_PLUS_INF;
    ck_assert_ldouble_infinite(s21_sqrt(a));
    ck_assert_ldouble_infinite(sqrt(a));
}
END_TEST

START_TEST(sqrt_minus_inf)
{
    double a = S21_MINUS_INF;
    ck_assert_ldouble_infinite(s21_sqrt(a));
    ck_assert_ldouble_infinite(sqrt(a));
}
END_TEST

START_TEST(sqrt_double)
{
    double a = 6.25;
    ck_assert_ldouble_eq_tol(s21_sqrt(a),sqrt(a),1e-6);
}
END_TEST

START_TEST(sqrt_minus_double)
{
    double a = -6.25;
    ck_assert_ldouble_eq_tol(s21_sqrt(a),sqrt(a),1e-6);
}
END_TEST

START_TEST(sqrt_zero)
{
    double a = 0.;
    ck_assert_ldouble_eq_tol(s21_sqrt(a),sqrt(a),1e-6);
}
END_TEST

START_TEST(ceil_of_positive_double)
{
    ck_assert_double_eq_tol(s21_ceil(1.001),ceil(1.001),1e-6);
}
END_TEST

START_TEST(ceil_of_negative_double)
{
    ck_assert_double_eq_tol(s21_ceil(-1.001),ceil(-1.001),1e-6);
}
END_TEST

START_TEST(ceil_of_zero)
{
    ck_assert_double_eq_tol(s21_ceil(0),ceil(0),1e-6);
}
END_TEST

START_TEST(ceil_of_nan)
{
    ck_assert_float_nan(s21_ceil(S21_NAN));
    ck_assert_float_nan(ceil(NAN));
}
END_TEST

START_TEST(floor_of_positive_double)
{
    ck_assert_double_eq_tol(s21_floor(1.001),floor(1.001),1e-6);
}
END_TEST

START_TEST(floor_of_negative_double)
{
    ck_assert_double_eq_tol(s21_floor(-1.001),floor(-1.001),1e-6);
}
END_TEST

START_TEST(floor_of_zero)
{
    ck_assert_double_eq_tol(s21_floor(0),floor(0),1e-6);
}
END_TEST

START_TEST(floor_of_nan)
{
    ck_assert_float_nan(s21_floor(S21_NAN));
    ck_assert_float_nan(floor(NAN));
}
END_TEST

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_exp = tcase_create("Tests_for_exp");
    TCase *tc_pow = tcase_create("Tests_for_pow");
    TCase *tc_log = tcase_create("Tests_for_log");
    TCase *tc_sqrt = tcase_create("Tests_for_sqrt");
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fabs = tcase_create("Tests_for_fabs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_celi = tcase_create("Tests_for_celi");
    TCase *tc_floor = tcase_create("Tests_for_floor");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fabs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_exp);
    suite_add_tcase(s1, tc_pow);
    suite_add_tcase(s1, tc_log);
    suite_add_tcase(s1, tc_celi);
    suite_add_tcase(s1, tc_floor);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, abs_of_zero);

    tcase_add_test(tc_exp, exp_zero);
    tcase_add_test(tc_exp, exp_double_positive);
    tcase_add_test(tc_exp, exp_double_negative);
    tcase_add_test(tc_exp, exp_inf);
    tcase_add_test(tc_exp, exp_minus_inf);
    tcase_add_test(tc_exp, exp_nan);
    tcase_add_test(tc_exp, exp_small_positive);
    tcase_add_test(tc_exp, exp_small_negative);
    //tcase_add_test(tc_abs, abs_of_nun);
    
    tcase_add_test(tc_fabs, fabs_of_positive_double);
    tcase_add_test(tc_fabs, fabs_of_negative_double);
    tcase_add_test(tc_fabs, fabs_of_zero);
    tcase_add_test(tc_fabs, fabs_of_nan);
    tcase_add_test(tc_fabs, fabs_of_plus_inf);
    tcase_add_test(tc_fabs, fabs_of_inf);

    tcase_add_test(tc_fmod, fmod_b_more_then_a_more_then_zero);
    tcase_add_test(tc_fmod, fmod_a_more_then_zero_more_then_b);
    tcase_add_test(tc_fmod, fmod_b_more_then_zero_more_then_a);
    tcase_add_test(tc_fmod, fmod_a_less_then_b_less_then_zero);
    tcase_add_test(tc_fmod, fmod_b_less_then_a_less_then_zero);
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
    tcase_add_test(tc_fmod, fmod_inf);
    tcase_add_test(tc_fmod, fmod_nan);
    
    tcase_add_test(tc_celi, ceil_of_positive_double);
    tcase_add_test(tc_celi, ceil_of_negative_double);
    tcase_add_test(tc_celi, ceil_of_zero);
    tcase_add_test(tc_celi, ceil_of_nan);
    
    tcase_add_test(tc_floor, floor_of_positive_double);
    tcase_add_test(tc_floor, floor_of_negative_double);
    tcase_add_test(tc_floor, floor_of_zero);
    tcase_add_test(tc_floor, floor_of_nan);

    tcase_add_test(tc_pow, pow_with_positive_integer_number);
    tcase_add_test(tc_pow, pow_with_positive_double_number);
    tcase_add_test(tc_pow, pow_with_positive_double_number_in_litte_exp);
    tcase_add_test(tc_pow, pow_with_negative_integer_number_in_native_exp);
    tcase_add_test(tc_pow, pow_with_negative_double_number);
    tcase_add_test(tc_pow, pow_with_negative_double_number_in_litte_negative_exp);
    tcase_add_test(tc_pow, pow_NAN_in_litte_negative_exp);
    tcase_add_test(tc_pow, pow_int_in_NAN);
    tcase_add_test(tc_pow, pow_one_in_NAN);
    tcase_add_test(tc_pow, pow_zero_in_double);
    tcase_add_test(tc_pow, pow_zero_in_zero);
    tcase_add_test(tc_pow, pow_zero_in_inf);
    tcase_add_test(tc_pow, pow_zero_in_minus_inf);
    tcase_add_test(tc_pow, pow_zero_in_nan);
    tcase_add_test(tc_pow, pow_base_less_one_in_nan);
    tcase_add_test(tc_pow, pow_base_less_one_in_minus_inf);
    tcase_add_test(tc_pow, pow_base_less_one_in_inf);
    tcase_add_test(tc_pow, pow_base_more_one_in_inf);
    tcase_add_test(tc_pow, pow_base_more_one_in_minus_inf);
    tcase_add_test(tc_pow, pow_base_more_one_in_nan);
    tcase_add_test(tc_pow, pow_nan_in_nan);

    tcase_add_test(tc_log, log_double_positive);
    tcase_add_test(tc_log, log_double_negative);
    tcase_add_test(tc_log, log_zero);
    tcase_add_test(tc_log, log_plus_inf);
    tcase_add_test(tc_log, log_minus_inf);
    tcase_add_test(tc_log, log_small);

    tcase_add_test(tc_sqrt, sqrt_nan);
    tcase_add_test(tc_sqrt, sqrt_inf);
    tcase_add_test(tc_sqrt, sqrt_minus_inf);
    tcase_add_test(tc_sqrt, sqrt_double);
    tcase_add_test(tc_sqrt, sqrt_minus_double);
    tcase_add_test(tc_sqrt, sqrt_zero);

    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
