#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"

int main() {
  char *menu1 = "0 - Exit\n1 - Insert at begin\n2 - Remove at begin\n3 - show\n4 - Insert at end\n";
  char *menu2 = "5 - Insert at middle\n6 - Insert after specific position\n7 - Remove at end\n";
  char *menu3 = "8 - Remove specific item\n9 - Clear list\n10 - To sort list\n11 - To reverse\n\n";
  int choice, val, key;
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s", menu1, menu2, menu3);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&list, val);
      break;

      case 2:
        remove = pop(&list);
        remove ? printf("%d Removed successfully!\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 3:
        showList(list);
      break;

      case 4:
        printf("Type a number: ");
        scanf("%d", &val);
        getchar();
        pushAtEnd(&list, val);
      break;

      case 5:
        pushAtMiddle(&list, val);
      break;

      case 6:
        pushAtSpecificPos(&list, val, key);
      break;

      case 7:
        remove = popAtEnd(&list);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
        free(remove);
      break;

      case 8:
        remove = popAtSpecificPos(&list, val);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 9:
        remove = popAll(&list);
        remove ? printf("List erased.\n\n") : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 10:
        list = insertionSort(&list);
      break;

      case 11:
        list = listReverter(&list);
        list ? printf("Your list was reversed.\n\n") : printf("Not enough items.\n\n");
      break;

      default:
        !choice ? printf("Wrong choice.") : printf("All good!");
    }
  }while(choice != 0);
  
  return 0;
}