#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
  int choice, val, after;
  char *option = "0 - Exit\n1 - insert at begin\n2 - Remove at begin\n3 - Print list\n";
  char *option2 = "4 - Insert at middle\n5 - Insert at specific pos\n6 - Insert at end\n";
  char *option3 = "7 - Remove at end\n8 - Remove specific Item\n9 - Clear list\n";
  char *option4 = "10 - Change elements\n11 - sort\n12 - List inverter\n13 - Find Element\n\n";
  List list;
  Node *remove;

  createList(&list);

  do {
    printf("%s%s%s%s", option, option2, option3, option4);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtBegin(&list, val);
      break;

      case 2:
        remove = removeAtBegin(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 3:
        printList(list);
      break;

      case 4:
        insertAtMiddle(&list, val);
      break;

      case 5:
        insertAtSpecificPos(&list, val, after);
      break;

      case 6:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtEnd(&list, val);
      break;

      case 7:
        remove = removeAtEnd(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 8:
        remove = removeAtSpecificPos(&list, val);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Item not found.\n\n");
      break;

      case 9:
        removeAll(&list);
        list.length == 0 ? printf("Nothing to remove.\n\n") : printf("list erased.\n\n");
      break;

      case 10:
        changePlace(&list, val, after);
      break;

      case 11:
        listSort(&list);
      break;

      case 12:
        listInverter(&list);
      break;

      case 13:
        remove = findItem(&list, val);
        remove ? printf("%d found.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
      break;

      default:
        choice != 0 ? printf("Invalid option!\n") : printf("Good bye!\n\n");
      break;
    }
  } while(choice != 0);

  return 0;
}