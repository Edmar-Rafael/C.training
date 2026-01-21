#ifndef practice
#define practice
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>

#include "../String/String.c"
#include "../Any/charToInt.c"
#include "styles.c"

#define Error(str) (printf("(\"%s\") isnt a correct choice. You fuckin dumbastard!!!\n\n", str))
#define catch() (printf("Just numbers! You asshole!\n\n"));

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;


int i = 0, j;

#endif 