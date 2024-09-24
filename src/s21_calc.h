#ifndef S21_CALC_H
#define S21_CALC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILED 1
#define ERROR_NOTATOIN 2  // ошибка в записи
#define INCORRECT_VAL 3

#define GRAPH_ON 1
#define GRAPH_OFF 0
#define GRAPH_X -3

#define SPACE " \n\t\v\f\r"
typedef enum {
  EMPTY = -1,
  // приоритет 0
  NUMBER,
  X_NUMBER,
  // приоритет - 1
  BINARY_PLUS,
  BINARY_MINUS,
  UNARY_MINUS,
  UNARY_PLUS,
  // приоритет - 2
  MUL,
  DIV,
  MOD,
  // приоритет - 3
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  // приоритет - 4
  POW,
  // приоритет - 5
  OPEN_BRCKT,
  CLOSE_BRCKT,
} elem_type;

typedef struct node {
  elem_type type;
  double value;
} node_t;

typedef struct elem {
  struct elem *prev;
  struct elem *next;
  node_t data;
} elem_node;

typedef struct struct_credit {
  double monthlyPayment;
  double monthlyPaymentFirst;
  double monthlyPaymentLast;
  double overPayment;
  double totalPayment;
} creditValues;

typedef struct struct_deposit {
  double totalInterestAmount;
  double taxAmount;
  double finalAmount;
} depositValues;

typedef struct amountChangeStruct {
  int day;
  int month;
  int year;
  double summ;
} replenishmentsListValues;

typedef struct date_struct {
  int day;
  int month;
  int year;
} dateStruct;

//-----------STACK
int s21_push(elem_node **head, long double value, elem_type type);
// int copy_stack_elem(elem_node* orig, elem_node* copy);
int s21_pop(elem_node **head);
int s21_free_stack(elem_node **head);
int print_stack(elem_node **head);
int s21_init_stack(elem_node **head);
//-----------PRN
int priority(elem_node *cur);
int polish_nottation(elem_node *input_list, elem_node **head);
void find_one_char(elem_node **input_list, char **src);
int two_doubles(char *str, int len);
int find_number(elem_node **input_list, char **src);
int input_list_from_src(elem_node **input_list, char **src);
int convert_to_PRN(elem_node **head, char *src);
int is_binary(elem_node *cur);
int for_unary(double *res, elem_node *stack, double num_1);
int for_binary(double *res, elem_node *stack, double num_1, double num_2);
int s21_smart_calc(char *src, double *result);
int calculate(elem_node *output_list, double *result, double x, int graph);
int find_func(elem_node **input_list, char **src);
void skip_space(char **src);

//-----------deposit
int s21_deposit_calc(double initial_deposit, int period_in_months,
                     double initial_interest, int payment_periodicity,
                     int is_capitalized, double replenishment_amount,
                     double withdraw_amount, double tax_interest,
                     double* accured_interest, double* tax_amount,
                     double* deposit_amount);

//-----------credit
void s21_annuity_calculation(long double credit_amount, long double month,
                             long double interest, long double *pay_for_month,
                             long double *total_payment, long double *overpay);

void s21_diff_calculation(long double credit_amount, long double month,
                          long double interest, long double *pay_for_month_min,
                          long double *pay_for_month_max,
                          long double *total_payment, long double *overpay); 

#endif