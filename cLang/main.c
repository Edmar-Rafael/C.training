#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
  int choice, val, after, pos;
  char option1[] = "0 - Exit\n1 - insert at begin\n2 - Remove at begin\n3 - Print\n4 - insert at end\n";
  char option2[] = "5 - insert at middle\n6 - insert at specific\n7 - Remove at end\n";
  char option3[] = "8 - Remove at specific position\n9 - Clear list\n10 - change positions\n";
  char option4[] = "11 - To invert\n12 - sort\n\n";
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s%s", option1, option2, option3, option4);
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
        printf("Type a number to remove: ");
        scanf("%d", &pos);
        remove = removeAtSpecificPos(&list, pos);
        remove ? printf("%d removed.\n\n", remove->data) : printf("%d not found.\n\n", pos);
      break;

      case 9:
        remove = removeAll(&list);
        if(remove) {
          printf("Erased items: ");
          printList(remove);
        } else {
          printf("Nothing to remove!\n\n");
        }
      break;

      case 10:
        printf("Type the first node: ");
        scanf("%d", &val);
        printf("Type the node to change with the first: ");
        scanf("%d", &after);
        changePlace(&list, val, after);
      break;

      case 11:
        list = listInverter(&list);
        list ? printf("List was inverted.\n\n") : printf("Nothing to invert.\n\n");
      break;

      case 12:
        listSort(&list);
      break;

      default:
        choice != 0 ? printf("invalid option!\n") : printf("Good bye!\n\n");
    }
  } while(choice != 0);
  
  return 0;
}