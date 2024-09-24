#include "../tests.h"

START_TEST(test_1) {
  char *src = "255*6mod0";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

START_TEST(test_2) {
  char *src = "sqrt(-20/5)+39.6";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

START_TEST(test_3) {
  char *src = "228-0^(-2)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
}
END_TEST

START_TEST(test_4) {
  char *src = "asin(9/10+4)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

START_TEST(test_5) {
  char *src = "acos(-7)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

START_TEST(test_6) {
  char *src = "ln(0.)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

START_TEST(test_7) {
  char *src = "log(-5)*ln(-10)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, INCORRECT_VAL);
  printf("\n");
}
END_TEST

TCase *tests_s21_invalid_val_math(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);
  tcase_add_test(tcase, test_7);

  return tcase;
}