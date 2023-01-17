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

START_TEST(cos_tests_infinity)
{
  ck_assert_ldouble_nan(s21_cos(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MINUS_INF));
}
END_TEST

START_TEST(cos_tests_nan)
{
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
}
END_TEST

START_TEST(cos_tests_pi_2)
{
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI_2), cos(-S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI_2), cos(S21_PI_2), 1e-6);
}
END_TEST

START_TEST(cos_tests_pi)
{
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI), cos(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
}
END_TEST

START_TEST(cos_tests_random_numbers)
{
  ck_assert_ldouble_eq_tol(s21_cos(30), cos(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-20), cos(-20), 1e-6);
}
END_TEST

START_TEST(sin_tests_infinity)
{
  ck_assert_ldouble_nan(s21_sin(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MINUS_INF));
}
END_TEST

START_TEST(sin_tests_nan)
{
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(sin_tests_pi_2)
{
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI_2), sin(-S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI_2), sin(S21_PI_2), 1e-6);
}
END_TEST

START_TEST(sin_tests_pi)
{
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
}
END_TEST

START_TEST(sin_tests_random_numbers)
{
  ck_assert_ldouble_eq_tol(s21_sin(17.5), sin(17.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-15), sin(-15), 1e-6);
}
END_TEST

START_TEST(tan_tests_infinity)
{
  ck_assert_ldouble_nan(s21_tan(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MINUS_INF));
}
END_TEST

START_TEST(tan_tests_nan)
{
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
}
END_TEST

START_TEST(tan_tests_pi_2)
{
  ck_assert_ldouble_nan(s21_tan(-S21_PI_2));
  ck_assert_ldouble_nan(s21_tan(S21_PI_2));
}
END_TEST

START_TEST(tan_tests_pi)
{
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI), tan(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
}
END_TEST

START_TEST(tan_tests_random_numbers)
{
  ck_assert_ldouble_eq_tol(s21_tan(15.6), tan(15.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-17.2), tan(-17.2), 1e-6);
}
END_TEST

START_TEST(acos_tests_infinity)
{
  ck_assert_ldouble_nan(s21_acos(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MINUS_INF));
}
END_TEST

START_TEST(acos_tests_nan)
{
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
}
END_TEST

START_TEST(acos_tests_one)
{
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
}
END_TEST

START_TEST(acos_tests_zero)
{
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
}
END_TEST

START_TEST(acos_tests_point_five)
{
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
}
END_TEST

START_TEST(acos_tests_random_numbers)
{
  ck_assert_ldouble_nan(s21_acos(15.6));
  ck_assert_ldouble_nan(s21_acos(-17.2));
}
END_TEST

START_TEST(asin_tests_infinity)
{
  ck_assert_ldouble_nan(s21_asin(S21_PLUS_INF));
  ck_assert_ldouble_nan(s21_asin(S21_MINUS_INF));
}
END_TEST

START_TEST(asin_tests_nan)
{
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
}
END_TEST

START_TEST(asin_tests_one)
{
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
}
END_TEST

START_TEST(asin_tests_zero)
{
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
}
END_TEST

START_TEST(asin_tests_point_five)
{
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
}
END_TEST

START_TEST(asin_tests_random_numbers)
{
  ck_assert_ldouble_nan(s21_asin(15.6));
  ck_assert_ldouble_nan(s21_asin(-17.2));
}
END_TEST

START_TEST(atan_tests_infinity)
{
  ck_assert_ldouble_eq_tol(s21_atan(S21_PLUS_INF), atan(S21_PLUS_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_MINUS_INF), atan(S21_MINUS_INF), 1e-6);
}
END_TEST

START_TEST(atan_tests_nan)
{
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
}
END_TEST

START_TEST(atan_tests_one)
{
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
}
END_TEST

START_TEST(atan_tests_zero)
{
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
}
END_TEST

START_TEST(atan_tests_point_five)
{
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
}
END_TEST

START_TEST(atan_tests_random_numbers)
{
  ck_assert_ldouble_eq_tol(s21_atan(100), atan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-200), atan(-200), 1e-6);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_basic_trigonometry = tcase_create("Tests_for_basic_trigonometry");
    TCase *tc_inverse_trigonometry = tcase_create("Tests_for_inverse_trigonometry");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_basic_trigonometry);
    suite_add_tcase(s1, tc_inverse_trigonometry);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, fabs_of_positive_double);
    tcase_add_test(tc_abs, fabs_of_negative_double);
    tcase_add_test(tc_abs, abs_of_zero);
    
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
    tcase_add_test(tc_fmod, fmod_with_numbers_less_then_zero);
    tcase_add_test(tc_fmod, fmod_with_one_numbers_less_and_one_more_then_zero);

  tcase_add_test(tc_basic_trigonometry, cos_tests_infinity);
  tcase_add_test(tc_basic_trigonometry, cos_tests_nan);
  tcase_add_test(tc_basic_trigonometry, cos_tests_pi_2);
  tcase_add_test(tc_basic_trigonometry, cos_tests_pi);
  tcase_add_test(tc_basic_trigonometry, cos_tests_random_numbers);

  tcase_add_test(tc_basic_trigonometry, sin_tests_infinity);
  tcase_add_test(tc_basic_trigonometry, sin_tests_nan);
  tcase_add_test(tc_basic_trigonometry, sin_tests_pi_2);
  tcase_add_test(tc_basic_trigonometry, sin_tests_pi);
  tcase_add_test(tc_basic_trigonometry, sin_tests_random_numbers);

  tcase_add_test(tc_basic_trigonometry, tan_tests_infinity);
  tcase_add_test(tc_basic_trigonometry, tan_tests_nan);
  tcase_add_test(tc_basic_trigonometry, tan_tests_pi_2);
  tcase_add_test(tc_basic_trigonometry, tan_tests_pi);
  tcase_add_test(tc_basic_trigonometry, tan_tests_random_numbers);

  tcase_add_test(tc_inverse_trigonometry, acos_tests_infinity);
  tcase_add_test(tc_inverse_trigonometry, acos_tests_nan);
  tcase_add_test(tc_inverse_trigonometry, acos_tests_zero);
  tcase_add_test(tc_inverse_trigonometry, acos_tests_point_five);
  tcase_add_test(tc_inverse_trigonometry, acos_tests_one);
  tcase_add_test(tc_inverse_trigonometry, acos_tests_random_numbers);

  tcase_add_test(tc_inverse_trigonometry, asin_tests_infinity);
  tcase_add_test(tc_inverse_trigonometry, asin_tests_nan);
  tcase_add_test(tc_inverse_trigonometry, asin_tests_zero);
  tcase_add_test(tc_inverse_trigonometry, asin_tests_point_five);
  tcase_add_test(tc_inverse_trigonometry, asin_tests_one);
  tcase_add_test(tc_inverse_trigonometry, asin_tests_random_numbers);

  tcase_add_test(tc_inverse_trigonometry, atan_tests_infinity);
  tcase_add_test(tc_inverse_trigonometry, atan_tests_nan);
  tcase_add_test(tc_inverse_trigonometry, atan_tests_zero);
  tcase_add_test(tc_inverse_trigonometry, atan_tests_point_five);
  tcase_add_test(tc_inverse_trigonometry, atan_tests_one);
  tcase_add_test(tc_inverse_trigonometry, atan_tests_random_numbers);
    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
