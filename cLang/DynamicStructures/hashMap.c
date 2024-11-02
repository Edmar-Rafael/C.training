#include <stdio.h>
#include <stdlib.h>

#define LENGTH 31

typedef struct Node {
  int key;
  struct Node *next;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;


void listInit(List *t) {
  t->head = NULL;
  t->length = 0;
}

void push(List *t, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->key = val;
    newNode->next = t->head;
    t->head = newNode;
    t->length++;
  } else {
    printf("Memory allocation error...!");
  }
}

int listSearch(List *t, int val) {
  Node *head = t->head;

  while(head && head->key != val) {
    head = head->next;
  }

  if(head) {
    return head->key;
  }

  return 0;
}

void listPrint(List *t) {
  Node *head = t->head;

  printf(" Length: %d -> ", t->length);
  while(head) {
    printf("%d-> ", head->key);
    head = head->next;
  }
}

int hash(int key) {
  return key % LENGTH;
}

void tableInit(List t[]) {
  for(int i = 0; i < LENGTH; i++) {
    listInit(&t[i]);
  }
}

void insert(List t[], int val) {
  printf("Type a number: ");
  scanf("%d", &val);

  int id = hash(val);

  push(&t[id], val);
}

int search(List t[], int val) {
  printf("\tType a number to search: ");
  scanf("%d", &val);

  int id = hash(val);

  printf("Index: %d\n", id);

  int el = listSearch(&t[id], val);

  return el;
}

void tablePrint(List t[]) {
  for(int i = 0; i < LENGTH; i++) {
    printf("%2d = ", i);
    listPrint(&t[i]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int choice, val;
  List table[LENGTH];

  tableInit(table);

  do {
    printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Show table\n\t");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        insert(table, val);
      break;

      case 2:
        val = search(table, val);
        val ? printf("{%d} found.\n\n", val) : printf("(x) Not found {%d}.\n\n", val);
      break;

      case 3:
        tablePrint(table);
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("Bye bye!!!\n\n");
    }
  } while(choice != 0);

  return 0;
}