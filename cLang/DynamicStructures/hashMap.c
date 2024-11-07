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
  t->length = 0;
  t->head = NULL;
}

void push(List *t, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->key = val;
    newNode->next = NULL;
    
    if(!t->head || val < t->head->key) {
      newNode->next = t->head;
      t->head = newNode;
    } else {
      Node *head = t->head;

      while(head->next && head->key < val) {
        head = head->next;
      }

      head->next = newNode;
    }

    t->length++;
  } else {
    printf("Memory allocation error...!");
  }
}

int popAtSpecific(List *t, int val) {
  Node *head = t->head;

  if(head) {
    Node *rm, *prev;

    if(head->key == val) {
      rm = t->head;
      t->head = rm->next;
      t->length--;
      return rm->key;
    }

    while(head->key != val) {
      prev = head;
      head = head->next;
    }

    if(!head->next && head->key != val) {
      printf("Element does'nt exist.");
      return 0;
    }

    rm = head;
    prev->next = head->next;
    t->length--;
    return rm->key;
  }

  printf("Empty list.\n\n");
  return 0;
}

int listSearch(List *t, int val) {
  Node *head = t->head;
  
  while(head && head->key != val) {
    head = head->next;
  }

  return head ? head->key : 0;
}

void listPrint(List *t) {
  Node *aux = t->head;

  printf(" Length: %d-> ", t->length);
  while(aux) {
    printf("%d-> ", aux->key);
    aux = aux->next;
  }
}

void tableInit(List t[]) {
  for(int i = 0; i < LENGTH; i++) {
    listInit(&t[i]);
  }
}

int hash(int key) {
  return key % LENGTH;
}

void insert(List t[], int val) {
  printf("Type a number: ");
  scanf("%d", &val);

  int id = hash(val);

  push(&t[id], val);
}

int toRemove(List t[], int val) {
  printf("Type a number to remove: ");
  scanf("%d", &val);

  int id = hash(val);
  printf("Index: %d\t", id);

  return popAtSpecific(&t[id], val);
}

int search(List t[], int val) {
  printf("Type a number to search: ");
  scanf("%d", &val);

  int id = hash(val);
  printf("Index: %d\t", id);

  return listSearch(&t[id], val);;
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
    printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Show table\n\t4 - Remove\n\t");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        insert(table, val);
      break;

      case 2:
        val = search(table, val);
        val ? printf("%d found.\n\n", val) : printf("Not found.\n\n");
      break;

      case 3:
        tablePrint(table);
      break;

      case 4:
        val = toRemove(table, val);
        val ? printf("Node %d removed.\n\n", val) : printf("Node not found\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice!\n\n") : printf("Bye Bye!!!");
    }
  } while(choice != 0);


  return 0;
}