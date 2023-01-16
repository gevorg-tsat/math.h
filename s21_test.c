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
int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_pow = tcase_create("Tests_for_pow");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_pow);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, fabs_of_positive_double);
    tcase_add_test(tc_abs, fabs_of_negative_double);
    tcase_add_test(tc_abs, abs_of_zero);
    
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
    tcase_add_test(tc_fmod, fmod_with_numbers_less_then_zero);
    tcase_add_test(tc_fmod, fmod_with_one_numbers_less_and_one_more_then_zero);

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



    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
