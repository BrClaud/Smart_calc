#include "s21_calc.h"



// перевод в обратную польскую нотацию
int convert_to_PRN(elem_node **head, char *src) {
  int status = SUCCESS;
  if (src && *src != 0) {
    elem_node *input_list;
    status = s21_init_stack(&input_list);
    elem_node *head_input = input_list;
    // заполнение input_list лексемами из строки
    status = input_list_from_src(&input_list, &src);

    if (status == SUCCESS) {
      status = s21_init_stack(head);
      elem_node *head_output = *head;
      if (!status) {
        // собираем нотацию
        status = polish_nottation(head_input, head);
        *head = head_output;
      }
    }
    s21_free_stack(&input_list);
  } else {
    status = ERROR_NOTATOIN;
  }
  return status;
}

// TODO написать функ polish_nottation (обозначенна в строке 18)
int input_list_from_src(elem_node **input_list, char **src) {
  int status = SUCCESS;
  while (**src != '\0' && status == 0) {
    // поиск чисел и точек и запись в input_list
    status = find_number(
        input_list,
        src);  // если точек больше 1 ошибка(1.23 - хорошо 1..23 ошибка)
    if (status == SUCCESS) {
      find_one_char(input_list, src);  // если подряд два знака тоже ошибка
    }
    if (!status) {
      find_func(input_list, src);
    }
    if (!status) {
      skip_space(src);
    }
  }
  return status;
}
// поиск в строке наибольшую последовательность из цифр и точек и запись в стек
int find_number(elem_node **input_list, char **src) {
  int status = SUCCESS;
  int length_number = strspn(*src, "1234567890.");
  double var = 0;
  if (length_number) {
    if (two_doubles(*src, length_number))
      status = FAILED;
    else {
      sscanf(*src, "%lf", &var);
      s21_push(input_list, var, NUMBER);
    }
  }
  *src += length_number;
  return status;
}
// проверка на две точки подряд
int two_doubles(char *str, int len) {
  int result = SUCCESS;
  for (int i = 0; len > 0; len--, i++) {
    if (str[i] == '.') result++;
  }
  return result >= 2 ? 1 : 0;
}

void find_one_char(elem_node **input_list, char **src) {
  if (**src == '+') {
    if (((*input_list)->prev == NULL) ||
        ((*input_list)->data.type == OPEN_BRCKT)) {
      s21_push(input_list, 0., UNARY_PLUS);
      (*src)++;
    } else {
      s21_push(input_list, 0., BINARY_PLUS);
      (*src)++;
    }
  }
  if (**src == '-') {
    if (((*input_list)->prev == NULL) ||
        ((*input_list)->data.type == OPEN_BRCKT)) {
      s21_push(input_list, 0., UNARY_MINUS);
      (*src)++;
    } else {
      s21_push(input_list, 0., BINARY_MINUS);
      (*src)++;
    }
  }
  if (**src == '/') {
    s21_push(input_list, 0., DIV);
    (*src)++;
  }
  if (**src == '*') {
    s21_push(input_list, 0., MUL);
    (*src)++;
  }
  if (**src == '(') {
    s21_push(input_list, 0., OPEN_BRCKT);
    (*src)++;
  }
  if (**src == ')') {
    s21_push(input_list, 0., CLOSE_BRCKT);
    (*src)++;
  }
  if (**src == 'x') {
    s21_push(input_list, 0., X_NUMBER);
    (*src)++;
  }
}
// int find_one_char(elem_node** input_list, char** src){
//     int status = SUCCESS;
//     if(**src == '+'){
//         if(((*input_list)->prev == NULL) || (*input_list)->data.type ==
//         OPEN_BRCKT){
//             s21_push(input_list,0.,UNARY_PLUS);
//             (*src)++;
//         }else{
//             if((*input_list)->data.type == UNARY_PLUS ||
//             (*input_list)->data.type == BINARY_PLUS){
//                 status = ERROR_NOTATOIN;
//             }else{
//                 s21_push(input_list,0., BINARY_PLUS);
//                 (*src)++;
//             }
//         }
//     }
//     if(**src == '-'){
//         if(((*input_list)->prev == NULL) || (*input_list)->data.type ==
//         OPEN_BRCKT){
//             s21_push(input_list,0.,UNARY_MINUS);
//             (*src)++;
//         }else{
//             if((*input_list)->data.type == UNARY_MINUS ||
//             (*input_list)->data.type == BINARY_MINUS){
//                 status = ERROR_NOTATOIN;
//             }else{
//                 s21_push(input_list,0., BINARY_MINUS);
//                 (*src)++;
//             }
//         }
//     }
//     if(**src == '/'){
//         if((*input_list)->data.type == DIV){
//             status = ERROR_NOTATOIN;
//         }else
//         {
//             s21_push(input_list,0.,DIV);
//             (*src)++;
//         }
//     }
//     if(**src == '*'){
//         if((*input_list)->data.type == MUL){
//             status = ERROR_NOTATOIN;
//         }else
//         {
//             s21_push(input_list,0.,MUL);
//             (*src)++;
//         }
//     }
//     if(**src == '('){
//         if((*input_list)->data.type == OPEN_BRCKT){
//             status = ERROR_NOTATOIN;
//         }else
//         {
//             s21_push(input_list,0.,OPEN_BRCKT);
//             (*src)++;
//         }
//     }
//     if(**src == ')'){
//         if((*input_list)->data.type == CLOSE_BRCKT){
//             status = ERROR_NOTATOIN;
//         }else
//         {
//             s21_push(input_list,0.,CLOSE_BRCKT);
//             (*src)++;
//         }
//     }
//     if(**src == 'x'){
//         if((*input_list)->data.type == X_NUMBER){
//             status = ERROR_NOTATOIN;
//         }else
//         {
//             s21_push(input_list,0.,X_NUMBER);
//             (*src)++;
//         }
//     }
//     return status;
// }

int polish_nottation(elem_node *input_list, elem_node **output_list) {
  int status = SUCCESS;
  elem_node *stack_list = NULL;
  s21_init_stack(&stack_list);

  while (input_list != NULL && status == SUCCESS) {
    // )
    if (input_list->data.type == CLOSE_BRCKT) {
      while (status == SUCCESS && (stack_list)->data.type != OPEN_BRCKT) {
        if ((stack_list)->data.type == EMPTY) {
          status = FAILED;
        } else {
          s21_push(output_list, (stack_list)->data.value,
                   stack_list->data.type);
          s21_pop(&stack_list);
        }
      }
      if (status == SUCCESS) {
        s21_pop(&stack_list);
      }
    }
    // если приоритет <= то выводим до ")" либо до начала строки
    if (status == SUCCESS && (priority(input_list) <= priority(stack_list)) &&
        (priority(input_list) != 0) && (priority(input_list) != 5) &&
        (input_list->data.type != UNARY_PLUS)) {
      while (status == SUCCESS && (stack_list)->data.type != OPEN_BRCKT &&
             (stack_list)->data.type != EMPTY &&
             priority(input_list) <= priority(stack_list)) {
        s21_push(output_list, (stack_list)->data.value,
                 (stack_list)->data.type);
        s21_pop(&stack_list);
      }
    }

    if (status == SUCCESS) {
      // распределяем из input в output или стек
      // если число, то распределяем в output_list
      if (input_list->data.type == NUMBER ||
          input_list->data.type == X_NUMBER) {
        s21_push(output_list, input_list->data.value, input_list->data.type);
      } else {
        // eсли с приоритетом != 0 чтобь исключить случай с числом и ")"
        if (priority(input_list) != 0 && input_list->data.type != CLOSE_BRCKT) {
          // для корректного вычисления добавляем 0 в  output_list
          if (input_list->data.type == UNARY_MINUS) {
            s21_push(output_list, 0., NUMBER);
            input_list->data.type = BINARY_MINUS;
          }
          if (input_list->data.type != UNARY_PLUS) {
            s21_push(&stack_list, input_list->data.value,
                     input_list->data.type);
          }
        }
      }
      input_list = input_list->next;
    }
  }
  // когда input_list закончен выводим все оставшееся
  while (status == SUCCESS && (stack_list)->data.type != EMPTY) {
    s21_push(output_list, (stack_list)->data.value, (stack_list)->data.type);
    s21_pop(&stack_list);
  }
  s21_free_stack(&stack_list);
  return status;
}

int priority(elem_node *cur) {
  int prior = 0;
  if (cur->data.type <= 5 && cur->data.type >= 2) {
    prior = 1;
  } else if (cur->data.type >= 6 && cur->data.type <= 8) {
    prior = 2;
  } else if (cur->data.type >= 9 && cur->data.type <= 17) {
    prior = 3;
  } else if (cur->data.type == 18) {
    prior = 4;
  } else if (cur->data.type > 18) {
    prior = 5;
  }
  return prior;
}

// Вычисляет значение выражения в обратной польской нотации.
// Эта функция принимает список в обратной польской нотации и вычисляет значение
// соответствующего выражения.
int calculate(elem_node *output_list, double *result, double x, int graph) {
  int status = SUCCESS;

  elem_node *stack = NULL;
  s21_init_stack(&stack);
  double buf = 0.;
  double buf2 = 0.;

  while (output_list != NULL && status == SUCCESS) {
    if (output_list->data.type == EMPTY) output_list = output_list->next;
    // если число - кладем в стек
    if (output_list->data.type == NUMBER ||
        output_list->data.type == X_NUMBER) {
      if (output_list->data.type == X_NUMBER) {
        s21_push(&stack, x, NUMBER);
        if (graph == GRAPH_OFF) status = GRAPH_X;
      } else {
        s21_push(&stack, output_list->data.value, output_list->data.type);
      }

    } else if (output_list->data.type != EMPTY && priority(output_list) != 5 &&
               status == SUCCESS) {
      if (!is_binary(output_list) && stack && stack->data.type == NUMBER) {
        buf = stack->data.value;
        status = for_unary(&(stack->data.value), output_list, buf);
      } else {
        if (stack && stack->prev && stack->prev->data.type == NUMBER &&
            stack->data.type == NUMBER) {
          buf = stack->data.value;
          buf2 = stack->prev->data.value;
          s21_pop(&stack);
          // if (buf2 == 0.) status =
          status = for_binary(&stack->data.value, output_list, buf2, buf);
        } else
          status = FAILED;
      }
    } else {
      status = FAILED;
    }
    output_list = output_list->next;
  }

  *result = stack->data.value;
  // проверка, что в стеке лежит только 1 значение - наш ответ, и одновременно
  // не менять ошибку на failed, если какая-то другая ошибка случилась раньше
  if (stack->prev && stack->prev->data.type != EMPTY && status == SUCCESS)
    status = FAILED;
  s21_free_stack(&stack);
  return status;
}

int is_binary(elem_node *cur) {
  int answer = 1;
  if (priority(cur) == 3) answer = 0;
  return answer;
}

int for_unary(double *res, elem_node *stack, double num_1) {
  int status = SUCCESS;
  elem_type oper = stack->data.type;

  *res = 0.;
  if (oper == SQRT) {
    if (num_1 >= 0) {
      *res = sqrt(num_1);
    } else {
      status = INCORRECT_VAL;
    }
  } else if (oper == SIN)
    *res = sin(num_1);
  else if (oper == COS)
    *res = cos(num_1);
  else if (oper == TAN)
    *res = tan(num_1);
  else if (oper == ASIN) {
    if (fabs(num_1) <= 1) {
      *res = asin(num_1);
    } else {
      status = INCORRECT_VAL;
    }
  } else if (oper == ACOS) {
    if (fabs(num_1) <= 1) {
      *res = acos(num_1);
    } else {
      status = INCORRECT_VAL;
    }
  } else if (oper == ATAN)
    *res = atan(num_1);
  else if (oper == LN) {  // natural logarithm
    if (num_1 > 0) {
      *res = log(num_1);
    } else {
      status = INCORRECT_VAL;
    }
  } else if (oper == LOG) {  // natural logarithm
    if (num_1 > 0) {
      *res = log10(num_1);
    } else {
      status = INCORRECT_VAL;
    }
  }

  return status;
}

int for_binary(double *res, elem_node *stack, double num_1, double num_2) {
  int status = SUCCESS;
  elem_type oper = stack->data.type;
  *res = 0.;

  if (oper == BINARY_PLUS)
    *res = num_1 + num_2;
  else if (oper == BINARY_MINUS)
    *res = num_1 - num_2;
  else if (oper == DIV) {
    if (num_2) {
      *res = num_1 / num_2;
    } else {
      status = INCORRECT_VAL;
      if (num_1)
        *res = INFINITY;
      else
        *res = NAN;
    }
  } else if (oper == MUL)
    *res = num_1 * num_2;
  else if (oper == MOD) {
    if (num_2) {
      *res = fmod(num_1, num_2);
    } else {
      status = INCORRECT_VAL;
    }
  } else if (oper == POW) {
    if (num_2 < 0. && num_1 == 0) {
      status = INCORRECT_VAL;
    } else {
      *res = pow(num_1, num_2);
    }
  }

  return status;
}
void skip_space(char **src) {
  while (**src == ' ') (*src)++;
}

int find_func(elem_node **input_list, char **src) {
  int status = FAILED;
  int length_number = 0;

  length_number = strspn(*src, "mod");
  if (length_number) {
    s21_push(input_list, 0., MOD);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  // подправить
  length_number = strspn(*src, "asin");
  if (length_number == 4) {
    s21_push(input_list, 0., ASIN);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "sin");
  if (length_number == 3) {
    s21_push(input_list, 0., SIN);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "acos");
  if (length_number == 4) {
    s21_push(input_list, 0., ACOS);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "cos");
  if (length_number == 3) {
    s21_push(input_list, 0., COS);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "atan");
  if (length_number == 4) {
    s21_push(input_list, 0., ATAN);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "tan");
  if (length_number == 3) {
    s21_push(input_list, 0., TAN);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "ln");
  if (length_number == 2) {
    s21_push(input_list, 0., LN);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "log");
  if (length_number == 3) {
    s21_push(input_list, 0., LOG);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "^");
  if (length_number == 1) {
    s21_push(input_list, 0., POW);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  length_number = strspn(*src, "sqrt");
  if (length_number == 4) {
    s21_push(input_list, 0., SQRT);
    *src += length_number;
    length_number = 0;
    status = SUCCESS;
  }

  return status;
}