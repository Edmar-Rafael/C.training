#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"

int main() {
  int choice, val, key;
  char *m = "0 - Exit\n1 - Insert at begin\n2 - Insert at end\n3 - Show List\n4 - Insert at middle\n";
  char *m2 = "5 - Insert at specific position\n6 - Remove at begin\n7 - Remove at end\n";
  char *m3 = "8 - Remove specific element\n9 - Swap elements\n\n";
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s", m, m2, m3);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&list, val);
      break;

      case 2:
        pushAtEnd(&list, val); 
      break;

      case 3:
        printList(list);
      break;

      case 4:
        pushAtMiddle(&list, val);
      break;

      case 5:
        pushAtSpecificPos(&list, val, key);
      break;

      case 6:
        remove = pop(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 7:
        remove = popAtEnd(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 8:
        remove = popAtSpecificPos(&list, val);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 9:
        swapper(&list, val, key);
      break;

      default:
        choice != 0 ? printf("All good!\n\n") : printf("Invalid choice.\n\n");
      break;
    }
  } while(choice != 0);
  return 0;
}