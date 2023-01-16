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

START_TEST(fabs_of_nun)
{
    ck_assert_float_nan(s21_fabs(S21_NAN));
    ck_assert_float_nan(fabs(NAN));
}
END_TEST

START_TEST(fabs_of_plus_inf)
{
    ck_assert_double_infinite(s21_fabs(S21_PLUS_INF));
    ck_assert_double_infinite(s21_fabs(S21_MINUS_INF));
    ck_assert_double_infinite(fabs(INFINITY));
}
END_TEST

START_TEST(fmod_a_more_then_b_more_then_zero)
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

START_TEST(ceil_of_nun)
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

START_TEST(floor_of_nun)
{
    ck_assert_float_nan(s21_floor(S21_NAN));
    ck_assert_float_nan(floor(NAN));
}
END_TEST

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fabs = tcase_create("Tests_for_fabs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    TCase *tc_celi = tcase_create("Tests_for_celi");
    TCase *tc_floor = tcase_create("Tests_for_floor");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fabs);
    suite_add_tcase(s1, tc_fmod);
    suite_add_tcase(s1, tc_celi);
    suite_add_tcase(s1, tc_floor);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, abs_of_zero);
    //tcase_add_test(tc_abs, abs_of_nun);
    
    tcase_add_test(tc_fabs, fabs_of_positive_double);
    tcase_add_test(tc_fabs, fabs_of_negative_double);
    tcase_add_test(tc_fabs, fabs_of_zero);
    tcase_add_test(tc_fabs, fabs_of_nun);
    tcase_add_test(tc_fabs, fabs_of_plus_inf);
    
    tcase_add_test(tc_fmod, fmod_a_more_then_b_more_then_zero);
    tcase_add_test(tc_fmod, fmod_b_more_then_a_more_then_zero);
    tcase_add_test(tc_fmod, fmod_a_more_then_zero_more_then_b);
    tcase_add_test(tc_fmod, fmod_b_more_then_zero_more_then_a);
    tcase_add_test(tc_fmod, fmod_a_less_then_b_less_then_zero);
    tcase_add_test(tc_fmod, fmod_b_less_then_a_less_then_zero);
    
    tcase_add_test(tc_celi, ceil_of_positive_double);
    tcase_add_test(tc_celi, ceil_of_negative_double);
    tcase_add_test(tc_celi, ceil_of_zero);
    tcase_add_test(tc_celi, ceil_of_nun);
    
    tcase_add_test(tc_floor, floor_of_positive_double);
    tcase_add_test(tc_floor, floor_of_negative_double);
    tcase_add_test(tc_floor, floor_of_zero);
    tcase_add_test(tc_floor, floor_of_nun);

    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
