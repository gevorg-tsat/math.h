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
/*
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
*/

int main() {
    Suite *s1 = suite_create("Tests_for_math");
    
    TCase *tc_abs = tcase_create("Tests_for_abs");
    TCase *tc_fmod = tcase_create("Tests_for_fmod");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_abs);
    suite_add_tcase(s1, tc_fmod);
    
    tcase_add_test(tc_abs, abs_of_positive_int);
    tcase_add_test(tc_abs, abs_of_negative_int);
    tcase_add_test(tc_abs, fabs_of_positive_double);
    tcase_add_test(tc_abs, fabs_of_negative_double);
    tcase_add_test(tc_abs, abs_of_zero);
    
    tcase_add_test(tc_fmod, fmod_with_numbers_more_then_zero);
//  tcase_add_test(tc_1, fmod_with_numbers_less_then_zero);
//  tcase_add_test(tc_1, fmod_with_one_numbers_less_and_one_more_then_zero);

    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
