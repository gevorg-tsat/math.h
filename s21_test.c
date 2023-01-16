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
    ck_assert_double_eq_tol(s21_fmod(a,b),fmod(a,b), 1e-6);
}
END_TEST

START_TEST(cos_tests)
{
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI_2), cos(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI_2), cos(-S21_PI_2), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MINUS_INF));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(30), cos(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-20), cos(-20), 1e-6);
}
END_TEST

START_TEST(sin_tests)
{
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI_2), sin(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI_2), sin(-S21_PI_2), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MINUS_INF));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_sin(30), sin(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-20), sin(-20), 1e-6);
}
END_TEST

START_TEST(tan_tests)
{
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_nan(s21_tan(S21_PI_2));
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
  ck_assert_ldouble_nan(s21_tan(-S21_PI_2));
  ck_assert_ldouble_nan(s21_tan(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MINUS_INF));
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_tan(30), tan(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-20), tan(-20), 1e-6);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_basic_trig = tcase_create("Tests_for_basic_trig");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_basic_trig);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, fabs_of_positive_double);
    tcase_add_test(tc_abs, fabs_of_negative_double);
    tcase_add_test(tc_abs, abs_of_zero);
    
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
    tcase_add_test(tc_fmod, fmod_with_numbers_less_then_zero);
    tcase_add_test(tc_fmod, fmod_with_one_numbers_less_and_one_more_then_zero);

  tcase_add_test(tc_basic_trig, cos_tests);
  tcase_add_test(tc_basic_trig, sin_tests);
  tcase_add_test(tc_basic_trig, tan_tests);
    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
