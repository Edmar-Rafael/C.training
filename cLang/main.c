#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"

int main() {
  char *menu1 = "0 - Exit\n1 - Insert at begin\n2 - Remove at begin\n3 - show\n4 - Insert at end\n";
  char *menu2 = "5 - Insert at middle\n6 - Remove at end\n7 - Remove specific\n8 - Clear list\n\n";
  int choice, val;
  Node *remove, *list = NULL;

  do {
    printf("%s%s", menu1, menu2);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&list, val);
      break;

      case 2:
        remove = pop(&list);
        remove ? printf("%d Removed successfully!\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 3:
        showList(list);
      break;

      case 4:
        pushAtEnd(&list, val);
      break;

      case 5:
        pushAtMiddle(&list, val);
      break;

      case 6:
        remove = popAtEnd(&list);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
      break;

      case 7:
        remove = popAtSpecificPos(&list, val);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 8:
        remove = popAll(&list);
        remove ? printf("List erased.\n\n") : printf("Nothing to remove.\n\n");
      break;

      default:
        !choice ? printf("Wrong choice.") : printf("All good!");
    }
  }while(choice != 0);
  
  return 0;
}