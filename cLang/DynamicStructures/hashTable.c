#include <stdio.h>
#include <stdlib.h>

#define LENGTH 31

void tableInit(int t[]) {
  for(int i = 0; i < LENGTH; i++) {
    t[i] = 0;
  }
}

int hash(int key) {

  return key % LENGTH;
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

int delete(int t[], int val) {
  printf("Type a number to delete: ");
  scanf("%d", &val);

  int id = hash(val);

  while(t[id] != val && t[id] != 0) {
    id = hash(id + 1);
  }

  val = t[id];

  t[id] = 0;

  return val ? val : t[id];
}

void tablePrint(int t[]) {
  for(int i = 0; i < LENGTH; i++) {
    printf("%2d: %d\n", i, t[i]);
  }
  printf("\n");
}

int search(int t[], int key) {
  printf("Type a number to search: ");
  scanf("%d", &key);

  int id = hash(key);

  while(t[id] != 0) {
    if(t[id] == key) {
      return t[id];
    }
    
    id = hash(id + 1);
  }

  return 0;
}


int main() {
  int choice, val, table[15];

  tableInit(table);

  do {
    printf("\t0 - Exit\n\t1 - Insert\n\t2 - Delete\n\t3 - Show table\n\t4 - Search\n\n");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        insert(table, val);
      break;

      case 2:
        val = delete(table, val);
        val ? printf("%d deleted.\n\n", val) : printf("Element not found.\n\n");
      break;

      case 3:
        tablePrint(table);
      break;

      case 4:
        val = search(table, val);
        val ? printf("%d found,\n\n", val) : printf("Element not found\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("Bye Bye!!!\n\n");
    }
  } while(choice != 0);

  return 0;
}