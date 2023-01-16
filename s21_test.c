#include <stdlib.h>
#include <check.h>
#include <math.h>
#include "s21_math.h"
START_TEST(abs_of_positive_int)
{
    int a = rand();
    ck_assert_int_eq(s21_abs(a*a),abs(a*a));
}
END_TEST
START_TEST(abs_of_negative_int)
{
    int a = rand();
    ck_assert_int_eq(s21_abs(-a*a),abs(-a*a));
}
END_TEST
START_TEST(abs_of_zero)
{
    ck_assert_int_eq(s21_abs(0),abs(0));
}
END_TEST
START_TEST(fabs_of_positive_double)
{
    int min = 1;
    int max = 10000;
    double a = (double) rand() / RAND_MAX * (max - min) + min;
    ck_assert_double_eq_tol(s21_fabs(a),fabs(a),1e-6);
}
END_TEST
START_TEST(fabs_of_negative_double)
{
    int min = -10000;
    int max = -1;
    double a = (double) rand() / RAND_MAX * (max - min) + min;
    ck_assert_double_eq_tol(s21_fabs(a),fabs(a),1e-6);
}
END_TEST
START_TEST(fmod_with_numbers_more_then_zero)
{
    int min = 1;
    int max = 10000;
    double a = (double) rand() / RAND_MAX * (max - min) + min;
    double b = (double) rand() / RAND_MAX * (max - min) + min;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST

START_TEST(fmod_with_numbers_less_then_zero)
{
    int min = -10000;
    int max = -1;
    double a = (double) rand() / RAND_MAX * (max - min) + min;
    double b = (double) rand() / RAND_MAX * (max - min) + min;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
}
END_TEST
START_TEST(fmod_with_one_numbers_less_and_one_more_then_zero)
{
    double a = 9.;
    double b = -6.;
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b),1e-6);
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

START_TEST(exp_minus_inf)
{
    long double power = S21_MINUS_INF;
    ck_assert_ldouble_eq_tol(s21_exp(power), exp(power), 1e-6);
}

START_TEST(exp_nan)
{
    long double power = S21_NAN;
    ck_assert_ldouble_nan(s21_exp(power));
    ck_assert_double_nan(exp(power));
}

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs_and_fabs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_exp = tcase_create("Tests_for_exp");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_exp);

    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, fabs_of_positive_double);
    tcase_add_test(tc_abs, fabs_of_negative_double);
    tcase_add_test(tc_abs, abs_of_zero);
    
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
    tcase_add_test(tc_fmod, fmod_with_numbers_less_then_zero);
    tcase_add_test(tc_fmod, fmod_with_one_numbers_less_and_one_more_then_zero);

    tcase_add_test(tc_exp, exp_zero);
    tcase_add_test(tc_exp, exp_double_positive);
    tcase_add_test(tc_exp, exp_double_negative);
    tcase_add_test(tc_exp, exp_inf);
    tcase_add_test(tc_exp, exp_minus_inf);
    tcase_add_test(tc_exp, exp_nan);

    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
