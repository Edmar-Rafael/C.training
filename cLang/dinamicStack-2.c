#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
  int day, month, year;
} Date;

typedef struct Person {
  char name[25];
  Date date;
} Person;

typedef struct Node {
  Person p;
  struct Node *next;
} Node;

typedef struct Stack {
  int length;
  Node *top;
} Stack;

void createStack(Stack *stk) {
  stk->top = NULL;
  stk->length = 0;
}

Person readPerson() {
  Person person;

  printf("Type Name: ");
  fgets(person.name, sizeof(person.name), stdin);

  printf("\nType birthday dd mm yyyy: ");
  scanf("%d%d%d", &person.date.day, &person.date.month, &person.date.year);
  return person;
}

void printPerson(Person p) {
  printf("\nName: %s\nDate: %2d/%2d/%4d\n", p.name, p.date.day, p.date.month, p.date.year);
}

void push(Stack *stk) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->p = readPerson();
    newNode->next = stk->top;
    stk->top = newNode;
    stk->length++;
  } else {
    printf("\nMemory allocation error...!\n");
  }
}

Node* pop(Stack *stk) {
  if(stk->top) {
    Node *rm = stk->top;
    stk->top = rm->next;
    stk->length--;
    return rm;
  }

  printf("Stack Underflow");
  return NULL;
}

void printStack(Stack *stk) {
  Node *aux = stk->top;  
  printf("\n---------stack length: %d ----------\n", stk->length);

  while(aux) {
    printPerson(aux->p);
    aux = aux->next;
  }

  printf("\n-----------end of stack-------------\n");
}

int main() {
  Node *remove;
  Stack stk;
  int choice;

  createStack(&stk);

  do {
    printf("\n0 - Exit\n1 - Push\n2 - Pop\n3 - To print\n");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&stk);
      break;
      
      case 2: 
        remove = pop(&stk);
        if(remove) {
          printf("\nElement removing successfully!\n");
          printPerson(remove->p);

          free(remove);
        } else {
          printf("\nNo Node to remove!\n");
        }
      break;
      
      case 3:
        printStack(&stk);
      break;

      default:
        choice != 0 ? printf("Invalid option!\n") : printf("All good!\n");
    }
  } while(choice != 0);

  return 0;
}
 