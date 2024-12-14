#include <stdio.h>
#include <stdlib.h>
#include "practice.c"

typedef struct Node {
  char value;
  struct Node *next;
} Node;

Node* push(Node *top, char val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->value = val;
    newNode->next = top;
    return newNode;
  }

  printf("Memory allocation error...!");
  return NULL;
}

Node* pop(Node **top) {
  if(*top == NULL) {
    printf("Stack underflow!\n");
    return NULL;
  }

  Node *rm = *top;
  *top = rm->next;
  return rm;
}

void printStack(Node *top) {
  printf("\tStack\n");

  while(top) {
    printf("\t%d\n", top->value);
    top = top->next;
  }

  printf("\tEnd of Stack.\n");
}

void stringInverter(char *str) {
  int i = 0;
  Node *remove, *top = NULL;

  while(str[i] != '\0') {
    if(str[i] != ' ') {
      top = push(top, str[i]);
    } else {
      while(top) {
        remove = pop(&top);
        printf("%c", remove->value);
        free(remove);
      } 
      printf(" ");
    }
    i++;
  }

  while(top) {
    remove = pop(&top);
    printf("%c", remove->value);
    free(remove);
  }
  printf("\n");
}

int main() {
  char *s = "hello world";
  
  stringInverter(s);

  return 0;
}