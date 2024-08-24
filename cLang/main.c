#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
  int choice, val, after;
  char option1[] = "0 - Exit\n1 - insert at begin\n2 - Remove\n3 - Print\n4 - insert at end\n";
  char option2[] = "5 - insert at middle\n6 - insert at specific\n7 - Remove at end\n";
  char option3[] = "8 - Clear list\n\n";
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s", option1, option2, option3);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtBegin(&list, val);
      break;

      case 2:
        remove = removeAtbegin(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 3:
        printList(list);
      break;

      case 4:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtEnd(&list, val);
      break;

      case 5:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtMiddle(&list, val);
      break;

      case 6:
        printf("Type a number: ");
        scanf("%d", &val);
        printf("insert after: ");
        scanf("%d", &after);
        insertAtSpecificPos(&list, val, after);
      break;

      case 7:
        remove = removeAtEnd(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 8:
        remove = removeAll(&list);
        if(remove) {
          printf("Erased items: ");
          printList(remove);
        } else {
          printf("Nothing to remove!\n\n");
        }
      break;

      default:
        choice != 0 ? printf("All good!\n") : printf("Good bye!\n\n");
    }
  } while(choice != 0);
  
  return 0;
}