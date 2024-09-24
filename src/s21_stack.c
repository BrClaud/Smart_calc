#include "s21_calc.h"

int s21_init_stack(elem_node** head) {
  int status = SUCCESS;
  *head = (elem_node*)calloc(1, sizeof(elem_node));
  if (*head) {
    (*head)->data.type = EMPTY;
  } else {
    status = FAILED;
  }
  return status;
}

int s21_push(elem_node** head, long double value, elem_type type) {
  int status = SUCCESS;
  elem_node* temp = (elem_node*)calloc(1, sizeof(elem_node));
  if (temp) {
    temp->data.type = type;
    temp->data.value = value;
    temp->next = NULL;
    // if(*head){
    temp->prev = (*head);
    (*head)->next = temp;
    (*head) = temp;
    // }else
    // {
    //     *head = temp;
    // }
    // temp->value = value;
    // temp->type = type;
    // temp->priority = priority;
    // temp->prev = *head; // меняем указатели местами, текущий становится
    // головой, а предыдущая голова записывается в prev *head = temp;
  } else {
    status = FAILED;
  }
  return status;
}
// записывает в root корень стека с верхним элементом в head
// int find_root(elem_node ** head, elem_node** root){

// }

// int copy_stack_elem(elem_node* orig, elem_node* copy){
//     int status = SUCCESS;
//     if(orig && copy){
//         copy->prev = orig->prev;
//         copy->priority = orig->priority;
//         copy->type = orig->type;
//         copy->value = orig->value;
//     }else{
//         status = FAILED;
//     }
//     return status;
// }

// удаляет верхний элемент, возвращает статус удаления
int s21_pop(elem_node** head) {
  int status = SUCCESS;
  if (*head) {
    elem_node* old_head = (*head);
    (*head) = (*head)->prev;
    if (*head) (*head)->next = NULL;
    free(old_head);
    old_head = NULL;

  } else {
    status = FAILED;
  }
  return status;
}

int s21_free_stack(elem_node** head) {
  int status = SUCCESS;
  if (head && *head) {
    while ((*head) != NULL && !status) {
      status = s21_pop(head);
    }
  }
  return status;
}

// int print_stack(elem_node **head){
//     int status = SUCCESS;
//     if(*head){
//         elem_node*temp = *head;
//         while(temp){
//             printf("value: %lf\tpriority:%d\n",(temp)->data.value,
//             (temp)->data.type); (temp) = (temp)->prev;
//         }
//     }else
//     {
//         status = FAILED;
//     }
//     return status;
// }