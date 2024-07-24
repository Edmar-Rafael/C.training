#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* #include "practice.c"
 */
typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node* push(Node *stk, int data) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->val = data;
    newNode->next = stk;
    return newNode;
  }

  printf("Memory allocation error...!");
  return NULL;
}

Node* pop(Node **stk) {
  Node *rm = NULL;

  if(*stk) {
    rm = *stk;
    *stk = rm->next;
  } else {
    printf("Stack underflow.");
  }

  return rm;
}

void printStack(Node *stk) {
  printf("\t------ stack --------\n");

  while(stk) {
    printf("\t%d\n", stk->val);
    stk = stk->next;
  }

  printf("\t------- end ----------\n");
}

int factorial(int num) {
  Node *rm, *stack = NULL;

  while(num > 1) {
    stack = push(stack, num);
    num--;
  }

  printStack(stack);

  while(stack) {
    rm = pop(&stack);
    num = num * rm->val;

    free(rm);
  }

  return num;
}

int main() {
  int choice;

  printf("Type a number higher than zero.");
  scanf("%d", &choice);
  printf("factorial of %d is: %d\n", choice, factorial(choice));
  
  return 0;
}
 