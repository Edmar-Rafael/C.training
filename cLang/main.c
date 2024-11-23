#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
  int choice, val;
  List table[LENGTH];

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
        val ? printf("%d found.\n\n", val) : printf("Element not found.\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice!\n\n") : printf("Good bye!!!\n\n");
    }
  } while(choice != 0);

  tableInit(table);

  return 0;
}