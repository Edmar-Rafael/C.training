#include <stdio.h>
#include <stdlib.h>

#define SIZE 31

void tableInit(int t[]) {
  for(int i = 0; i < SIZE; i++) {
    t[i] = 0;
  }
}

int hash(int key) {
  return key % SIZE;
}

void insert(int t[], int val) {
  printf("Type a number to insert: ");
  scanf("%d", &val);

  int id = hash(val);

  while(t[id] != 0) {
    id = hash(id + 1);
  }

  t[id] = val;
}

int search(int t[], int key) {
  printf("Type a number to search: ");
  scanf("%d", &key);

  int id = hash(key);
  printf("\tindex: %d\n", id);

  while(t[id] != 0) {
    if(t[id] == key) {
      return t[id];
    } else {
      id = hash(id + 1);
    }
  }

  return 0;
}

void printTable(int t[]) {
  for(int i = 0; i < SIZE; i++) {
    printf("%d = %d\n", i, t[i]);
  }
}

int main() {
  int choice, val;
  int table[SIZE];

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
        printTable(table); 
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("All good.\n\n");
    }
  }while(choice != 0);

  return 0;
}