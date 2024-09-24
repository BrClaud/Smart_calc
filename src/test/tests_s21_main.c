#include "../tests.h"

START_TEST(test_1) {
  char *src = "2458.324234*4.53345435-5^22.234324+123.4543/2.1212321";

  double expected = -3476366391885870.520000000000;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-7);

  printf("\n");
}
END_TEST

START_TEST(test_2) {
  char *src = "log(45.236582*55522.85-583)";

  double expected = 6.39986071453;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-7);

  printf("\n");
}
END_TEST;

START_TEST(test_3) {
  char *src = "5226*6885-5185/5586/25522-684+(45222-54855/5452*3555)-256*44+2";

  double expected = 35978517.5617758098690562;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-7);

  printf("\n");
}
END_TEST;

START_TEST(test_4) {
  char *src = "tan(785852.355)";

  double expected = -4.24289256573;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-7);

  printf("\n");
}
END_TEST;

START_TEST(test_5) {
  char *src = "ln(785.695233)";

  double expected = 6.66656897296;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-7);

  printf("\n");
}
END_TEST;

START_TEST(test_6) {
  char *src = "785-968*624-32.99996-(78541*88965.32-99856)+(855*6944-326.55)";

  double expected = -6981991828.669961;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq(result, expected);

  printf("\n");
}
END_TEST;

START_TEST(test_7) {
  char *src = "atan234.235235";

  double expected = 1.566527;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_8) {
  char *src = "acos(0.123123213)";


  double expected = 1.447360;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);


}
END_TEST;

START_TEST(test_9) {
  char *src = "asin(0.4234234)";

  double expected = 0.437221;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_10) {
  char *src = "cos(0.4234234)";

  double expected = 0.911688;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);  
}
END_TEST;

START_TEST(test_11) {
  char *src = "sqrt(234.423423432432432)";

  double expected = 15.310892;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_12) {
  char *src = "10.00000mod3.0000000";

  double expected = 1.000000;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_13) {
  char *src = "-1";

  double expected = -1;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_14) {
  char *src = "sin89";

  double expected = 0.86006940581;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_15) {
  char *src = "+1";

  double expected = 1;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_16) {
  char *src = "(-1)";

  double expected = -1;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_17) {
  char *src = "(+1)";

  double expected = 1;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_18) {
  char *src = "2mod2";

  double expected = 0;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_19) {
  char *src = "(cos5)";

  double expected = 0.283662;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST;

START_TEST(test_21) {
  char *src = "ln18.00";

  double expected = 2.8903717;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST;

START_TEST(test_22) {
  char *src = "2/0.0";

  double expected = INFINITY;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq(result, expected);

  printf("\n");
}
END_TEST;

START_TEST(test_23) {
  char *src = "0/0";

  double expected = NAN;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_int_eq(result, expected);

  printf("\n");
}
END_TEST;

START_TEST(test_24) {
  char *src = ")(123 + 2)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);

  ck_assert_int_eq(status, FAILED);

  printf("\n");
}
END_TEST;

START_TEST(test_25) {
  char *src = "";

  double expected = 0;

  double result = 0;
  s21_smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq_tol(result, expected, 1e-6);

  printf("\n");
}
END_TEST;

START_TEST(test_26) {
  char *src = "((123 + 2)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);

  ck_assert_int_eq(status, FAILED);

  printf("\n");
}
END_TEST;

START_TEST(test_27) {
  char *src = "1*-2";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, FAILED);

  printf("\n");
}
END_TEST;

START_TEST(test_28) {
  char *src = "1*cos-2";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, FAILED);

  printf("\n");
}
END_TEST;

START_TEST(test_29) {
  char *src = "123..123123 + 2";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  ck_assert_int_eq(status, FAILED);

  printf("\n");
}
END_TEST;

START_TEST(test_30) {
  char *src = "-(-1)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  double expected = 1.;
  ck_assert_double_eq_tol(result, expected, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
  printf("\n");
}
END_TEST;

START_TEST(boobs_test) {
  char *src = "(.)(.)";
  double result = 0.;
  int status = s21_smart_calc(src, &result);
  double expected = 0.;
  ck_assert_double_eq_tol(result, expected, 1e-6);
  ck_assert_int_eq(status, FAILED);
  printf("\n");
}
END_TEST;


TCase *tests_s21_main(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);
  tcase_add_test(tcase, test_7);
  tcase_add_test(tcase, test_8);
  tcase_add_test(tcase, test_9);
  tcase_add_test(tcase, test_10);
  tcase_add_test(tcase, test_11);
  tcase_add_test(tcase, test_12);
  tcase_add_test(tcase, test_13);
  tcase_add_test(tcase, test_14);
  tcase_add_test(tcase, test_15);
  tcase_add_test(tcase, test_16);
  tcase_add_test(tcase, test_17);
  tcase_add_test(tcase, test_18);
  tcase_add_test(tcase, test_19);
  tcase_add_test(tcase, test_21);
  tcase_add_test(tcase, test_22);
  tcase_add_test(tcase, test_23);
  tcase_add_test(tcase, test_24);
  tcase_add_test(tcase, test_25);
  tcase_add_test(tcase, test_26);
  tcase_add_test(tcase, test_27);
  tcase_add_test(tcase, test_28);
  tcase_add_test(tcase, test_29);
  tcase_add_test(tcase, test_30);
  tcase_add_test(tcase, boobs_test);
  return tcase;
}
