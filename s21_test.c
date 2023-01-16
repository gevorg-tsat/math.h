#include <stdlib.h>
#include <check.h>
#include <math.h>
#include "s21_math.h"
/*
int s21_abs(int x) {
    if (x < 0)
        x = -x;
    return x;
}*/
START_TEST(abs_of_positive_number)
{
    int a = 1;
    ck_assert_int_eq(s21_abs(a),abs(a));
}
END_TEST
START_TEST(abs_of_negative_number)
{
    int a = -1;
    ck_assert_int_eq(s21_abs(a),abs(a));
}
END_TEST

int main() {
    Suite *s1 = suite_create("Tests");
    TCase *tc_1 = tcase_create("Tests_for_math");
    SRunner *sr = srunner_create(s1);
    
    suite_add_tcase(s1, tc_1);
    
    tcase_add_test(tc_1, abs_of_positive_number);
    tcase_add_test(tc_1, abs_of_negative_number);
    
    srunner_run_all(sr, CK_ENV);
    int a = srunner_ntests_failed(sr);
    srunner_free(sr);

    return a == 0 ? 0 : 1;
}
