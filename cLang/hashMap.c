#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

typedef struct Node {
  int key;
  struct Node *next;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;

void listInit(List *l) {
  l->length = 0;
  l->head = NULL;
}

void push(List *l, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->key = val;
    newNode->next = l->head;
    l->head = newNode;
    l->length++;
  } else {
    printf("Memory allocation error...!");
  }
}

int listSearch(List *l, int val) {
  Node *head = l->head;

  while(head && head->key != val) {
    head = head->next;
  }

  if(head) {
    return head->key;
  }

  return 0;
}

void listPrint(List *l) {
  Node *head = l->head;
  printf("  Size: %d: ", l->length);

  while(head) {
    printf("%d -> ", head->key);
    head = head->next;
  }
}

void tableInit(List t[]) {
  for(int i = 0; i < SIZE; i++) {
    listInit(&t[i]);
  }
}

int hash(int key) {
  return key % SIZE;
}

void insert(List t[], int val) {
  printf("Type a number to insert: ");
  scanf("%d", &val);

  int id = hash(val);

  push(&t[id], val);
}

int search(List t[], int key) {
  printf("Type a number to search: ");
  scanf("%d", &key);

  int id = hash(key);
  printf("\tindex: %d\n", id);

  int el = listSearch(&t[id], key);

  return el;
}

void tablePrint(List t[]) {
  for(int i = 0; i < SIZE; i++) {
    printf("%2d = ", i);
    listPrint(&t[i]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int choice, val;
  List table[SIZE];

  tableInit(table);
  
  do {
    printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print\n\t4 - Show List\n\n\t");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        insert(table, val);
      break;

      case 2:
        val = search(table, val);
        val != 0 ? printf("%d found.\n\n", val) : printf("(x) element not found.\n\n");
      break;

      case 3:
        tablePrint(table); 
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("All good.\n\n");
    }
  }while(choice != 0);

  return 0;
}