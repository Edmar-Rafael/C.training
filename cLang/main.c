#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


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