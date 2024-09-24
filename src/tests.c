#include "tests.h"

#define PREC 1e-2
#define PREC_7 1e-7

START_TEST(test_12) {
  long double pay_for_month_min = 0;
  long double pay_for_month_max = 0;
  long double total_payment = 0;
  long double overpay = 0;

  s21_diff_calculation(3520000, 7, 15, &pay_for_month_min, &pay_for_month_max,
                       &total_payment, &overpay);

  ck_assert_ldouble_eq_tol(pay_for_month_min, 509142.86, PREC);
  ck_assert_ldouble_eq_tol(pay_for_month_max, 546857.14, PREC);
  ck_assert_ldouble_eq_tol(total_payment, 3696000.00, PREC);
  ck_assert_ldouble_eq_tol(overpay, 176000, PREC);
}
END_TEST

START_TEST(test_13) {
  long double pay_for_month = 0;
  long double total_payment = 0;
  long double overpay = 0;

  long double credit_amount = 3500000;
  long double month = 7;
  long double interest = 15;

  s21_annuity_calculation(credit_amount, month, interest, &pay_for_month,
                          &total_payment, &overpay);

  ck_assert_ldouble_eq_tol(pay_for_month, 525310.52, PREC);
  ck_assert_ldouble_eq_tol(total_payment, 3677173.64, PREC);
  ck_assert_ldouble_eq_tol(overpay, 177173.64, PREC);
}

START_TEST(test_14) {
  double initial_deposit = 125896;
  int period_in_months = 120;
  double initial_interest = 15;
  int payment_periodicity = 12;
  int is_capitalized = 1;
  double replenishment_amount = 1258;
  double withdraw_amount = 0;
  double tax_interest = 35;
  double accured_interest = 0, tax_amount = 0, deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);
  ck_assert_double_eq_tol(581112.90, accured_interest, PREC);
  ck_assert_double_eq_tol(203389.51, tax_amount, PREC);
  ck_assert_double_eq_tol(654579.38, deposit_amount, PREC);
}

START_TEST(test_15) {
  double initial_deposit = 45827;
  int period_in_months = 11;
  double initial_interest = 1.5;
  int payment_periodicity = 1;
  int is_capitalized = 0;
  double replenishment_amount = 15288;
  double withdraw_amount = 15;
  double tax_interest = 38;
  double accured_interest = 0, tax_amount = 0, deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);
  ck_assert_double_eq_tol(1680.14, accured_interest, PREC);
  ck_assert_double_eq_tol(638.45, tax_amount, PREC);
  ck_assert_double_eq_tol(214871.69, deposit_amount, PREC);
}

START_TEST(test_16) {
  double initial_deposit = 4582;
  int period_in_months = 11;
  double initial_interest = 1.5;
  int payment_periodicity = 1;
  int is_capitalized = 1;
  double replenishment_amount = 15288;
  double withdraw_amount = 15;
  double tax_interest = 38;
  double accured_interest = 0, tax_amount = 0, deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);
  ck_assert_double_eq_tol(1117.36, accured_interest, PREC);
  ck_assert_double_eq_tol(424.60, tax_amount, PREC);
  ck_assert_double_eq_tol(173277.77, deposit_amount, PREC);
}

START_TEST(test_17) {
  double initial_deposit = 200000;
  int period_in_months = 48;
  double initial_interest = 7;
  int payment_periodicity = 12;
  int is_capitalized = 1;
  double replenishment_amount = 1000;
  double withdraw_amount = 10;
  double tax_interest = 22;
  double accured_interest = 0;
  double tax_amount = 0;
  double deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);

  ck_assert_ldouble_eq_tol(tax_amount, 15569.464546, PREC);
  ck_assert_ldouble_eq_tol(accured_interest, 70770.293389, PREC);
  ck_assert_ldouble_eq_tol(deposit_amount, 302720.828843, PREC);
}

START_TEST(test_18) {
  double initial_deposit = 200000;
  int period_in_months = 8;
  double initial_interest = 7;
  int payment_periodicity = 12;
  int is_capitalized = 1;
  double replenishment_amount = 1000;
  double withdraw_amount = 10;
  double tax_interest = 22;
  double accured_interest = 0;
  double tax_amount = 0;
  double deposit_amount = 0;
  int status = s21_deposit_calc(
      initial_deposit, period_in_months, initial_interest, payment_periodicity,
      is_capitalized, replenishment_amount, withdraw_amount, tax_interest,
      &accured_interest, &tax_amount, &deposit_amount);
  ck_assert_int_eq(FAILED, status);
  ck_assert_ldouble_eq_tol(tax_amount, 0, PREC);
  ck_assert_ldouble_eq_tol(accured_interest, 0, PREC);
  ck_assert_ldouble_eq_tol(deposit_amount, 0, PREC);
}

START_TEST(test_19) {
  double initial_deposit = 3000;
  int period_in_months = 12;
  double initial_interest = 3;
  int payment_periodicity = 1;
  int is_capitalized = 1;
  double replenishment_amount = 500;
  double withdraw_amount = 0;
  double tax_interest = 20;
  double accured_interest = 0;
  double tax_amount = 0;
  double deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);
  ck_assert_ldouble_eq_tol(deposit_amount, 9139.551403, PREC);
  ck_assert_ldouble_eq_tol(tax_amount, 34.887851, PREC);
  ck_assert_ldouble_eq_tol(accured_interest, 174.439253, PREC);
}

START_TEST(test_20) {
  double initial_deposit = 10000;
  int period_in_months = 10;
  double initial_interest = 5;
  int payment_periodicity = 1;
  int is_capitalized = 0;
  double replenishment_amount = 2000;
  double withdraw_amount = 0;
  double tax_interest = 15;
  double accured_interest = 0;
  double tax_amount = 0;
  double deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);
  ck_assert_ldouble_eq_tol(deposit_amount, 30672.916667, PREC);
  ck_assert_ldouble_eq_tol(tax_amount, 118.75000, PREC);
  ck_assert_ldouble_eq_tol(accured_interest, 791.666667, PREC);
}

START_TEST(test_21) {
  double initial_deposit = 5000;
  int period_in_months = 24;
  double initial_interest = 5;
  int payment_periodicity = 12;
  int is_capitalized = 0;
  double replenishment_amount = 200;
  double withdraw_amount = 50;
  double tax_interest = 15;
  double accured_interest = 0;
  double tax_amount = 0;
  double deposit_amount = 0;
  s21_deposit_calc(initial_deposit, period_in_months, initial_interest,
                   payment_periodicity, is_capitalized, replenishment_amount,
                   withdraw_amount, tax_interest, &accured_interest,
                   &tax_amount, &deposit_amount);

  ck_assert_ldouble_eq_tol(tax_amount, 113.250000, PREC);
  ck_assert_ldouble_eq_tol(accured_interest, 755.000000, PREC);
  ck_assert_ldouble_eq_tol(deposit_amount, 9241.750000, PREC);
}

TCase *Credit_Debet(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_12);
  tcase_add_test(tcase, test_13);
  tcase_add_test(tcase, test_14);
  tcase_add_test(tcase, test_15);
  tcase_add_test(tcase, test_16);
  tcase_add_test(tcase, test_17);
  tcase_add_test(tcase, test_18);
  tcase_add_test(tcase, test_19);
  tcase_add_test(tcase, test_20);
  tcase_add_test(tcase, test_21);

  return tcase;
}

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  suite_add_tcase(suite, tests_s21_main());
  suite_add_tcase(suite, tests_s21_invalid_val_math());
  suite_add_tcase(suite, Credit_Debet());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

