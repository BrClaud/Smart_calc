#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include <check.h>

#include "s21_calc.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

TCase *tests_s21_main(void);
TCase *tests_s21_invalid_val_math(void);


#endif  // SRC_S21_TEST_H_
