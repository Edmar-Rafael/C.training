#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>
#include "practice.c"

typedef struct Date {
  int day, month, year;
} Date;

typedef struct Person {
  char name[25];
  Date date;
} Person;

typedef struct Node {
  Person person;
  struct Node *next;
} Node;

Person readPerson() {
  Person person;

  printf("Type Name: ");
  fgets(person.name, sizeof(person.name), stdin);
  
  printf("\nType birthday dd/mm/yyyy: ");
  scanf("%d/%d/%d", &person.date.day, &person.date.month, &person.date.year);
  return person;
}

void printPerson(Person p) {
  printf("\nName: %s\nDate: %2d/%2d/%4d.\n", p.name, p.date.day, p.date.month, p.date.year);
}

Node* push(Node *top) {
  Node *new = (struct Node *) malloc(sizeof(Node));

  if(new) {
    new->person = readPerson();
    new->next = top;
    return new;
  } else {}

  printf("\nMemory allocation error...!\n");
  return NULL;
}

Node* pop(Node **top) {
  if(*top == NULL) {
    printf("Stack Underflow");
    return NULL;
  }

  Node *rm = *top;
  *top = rm->next;
  return rm;
}

void printStack(Node *top) {
  printf("\n--------------stack----------------\n");

  while(top) {
    printPerson(top->person);
    top = top->next;
  }

  printf("\n-----------end of stack-------------\n");
}

int main() {
  Node *remove, *top = NULL;
  int choice;

  do {
    printf("\n0 - Exit\n1 - Push\n2 - Pop\n3 - To print\n");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        top = push(top);
      break;
      
      case 2: 
        remove = pop(&top);
        if(remove) {
          printf("\nElement removing successfully!\n");
          printPerson(remove->person);

          free(remove);
        } else {
          printf("\nNo Node to remove!\n");
        }
      break;
      
      case 3:
        printStack(top); 
      break;

      default:
        if(choice > 3) {
          printf("\nInvalid option!!!\n");
        }
      break;
    }
  } while(choice != 0);

  return 0;
}
 