#include "s21_calc.h"

int s21_smart_calc(char *src, double *result) {
  int status = SUCCESS;
  *result = 0.;
  elem_node *output_list = NULL;
  status = convert_to_PRN(&output_list, src);
  if (status == SUCCESS) status = calculate(output_list, result, 0., GRAPH_OFF);
  s21_free_stack(&output_list);

  return status;
}